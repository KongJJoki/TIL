#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <map>
using namespace std;

#pragma comment(lib, "Ws2_32.lib") // Ws2_32.lib 라는 라이브러리 파일을 포함해라 -> 이거 안하면 링크 에러남

// UTF8 -> UNICODE(widechar) -> ANSI
void UTF8to_ANSI(char buffer[], int _byteSize)
{
	// 1. 받은 데이터를 wide character로 변환
	// 문자열 크기 측정
	int wideBufferSize = MultiByteToWideChar(CP_UTF8, 0, buffer, _byteSize, nullptr, 0);
	// 크기만큼의 유니코드형 문자열 동적 할당
	wchar_t* wideBuffer = new wchar_t[wideBufferSize + 1];
	// UTF8 -> UNICODE
	MultiByteToWideChar(CP_UTF8, 0, buffer, _byteSize, wideBuffer, wideBufferSize);
	// NULL 문자
	wideBuffer[wideBufferSize] = L'\0'; // L이 wideChar로 만드는 접두사??

	// 2. wide char을 char로 변환
	// 유니코드로 바꾼 문자열의 크기 측정
	int ansiLength = WideCharToMultiByte(CP_ACP, 0, wideBuffer, -1, NULL, 0, NULL, NULL);
	// 그것을 buffer에 변환해서 적용(UNICODE -> ANSI)
	WideCharToMultiByte(CP_ACP, 0, wideBuffer, -1, buffer, ansiLength, NULL, NULL);
	// NULL 문자
	buffer[ansiLength] = L'\0';

	wideBuffer = nullptr; // 초가 넣은 코드.. 
	delete[] wideBuffer; // 동적할당 한거 해제
}

int main()
{
	// WSA 초기화
	WSADATA wsa;
	int nResult{};

	nResult = WSAStartup(MAKEWORD(2, 2), &wsa);

	if (nResult != 0) // 이게 0이면 에러임
	{
		std::cout << "WSAStartup 에러" << '\n';
	}

	// 소켓 생성
	SOCKET mySocket = socket(AF_INET, SOCK_DGRAM, 0); // 소켓 생성함수 
	if (mySocket == SOCKET_ERROR) // SOCKET_ERROR는 그냥 -1 define 에러 잡을려고 쓰는 값
	{
		std::cout << "Socket 생성 에러" << '\n';

		WSACleanup(); // 에러면 종료
	}

	// 수신
	sockaddr_in recvAddr{};
	recvAddr.sin_family = AF_INET;
	recvAddr.sin_port = htons(12345); // 보통 IP는 INADDR_ANY 많이 쓰지만 포트는 꼭 맞춰줘야함
	recvAddr.sin_addr.s_addr = INADDR_ANY; // 수신할 IP는 컴퓨터에 붙여진 모든 IP 라는 의미

	// 바인딩
	nResult = bind
	(
		mySocket,
		(sockaddr*)&recvAddr,
		sizeof(recvAddr)
	);

	if (nResult != 0) // bind는 0이어야 성공이기 때문에 0이 아니면 에러
	{
		std::cout << "바인딩 에러" << '\n';
		closesocket(mySocket);
		WSACleanup();
	}

	// 송신
	sockaddr_in destAddr{}; // 도착지 주소설정
	destAddr.sin_family = AF_INET; // 주소 체계 정하기
	destAddr.sin_port = htons(12345); // 포트번호 설정 -> 그냥 12345 포트라고 쓸 수는 없기 때문에 htons를 이용해서 바꿔주는것

	inet_pton(AF_INET, "127.0.0.1", &destAddr.sin_addr); // Ws2tcpip.h 를 추가하지 않으면 이 함수에 에러남

	std::cout << "서버 시작" << '\n';

	map<string, sockaddr_in> userList{};

	while (true)
	{
		// 수신 처리
		char buffer[1024]{};
		sockaddr_in senderAddr{}; // 보내는 사람 주소
		socklen_t senderAddrLen = sizeof(senderAddr);

		int receivedBytes = recvfrom // reveivedBytes는 에러메세지 들어오는거임 원래! -1 들어오면 에러임
		(
			mySocket,
			buffer,
			sizeof(buffer),
			0,
			(sockaddr*)&senderAddr, // 보낸 사람
			&senderAddrLen
		);

		// IP : Port 로 문자열 만들고
		char senderIP[256]{};
		inet_ntop(AF_INET, &senderAddr.sin_addr, senderIP, sizeof(senderIP));

		//새로운 유저 정보 저장하기
		char userInfo[256]{};
		sprintf_s(userInfo, "%s:%d", senderIP, senderAddr.sin_port); // 수를 문자열로 변환?
		// senderIP : senderAddr.sin_port를 문자열로 만들어서 userInfo에 넣기-> "127.0.0.1:12345" 로 userInfo에 들어감

		//// map에 있는 것인지 확인한 후 없으면 추가
		//map<string, sockaddr_in>::iterator finder{};
		//finder = userList.find(userInfo);

		//if (finder == userList.end()) // 자료구조 안에 해당 유저 정보가 없으면
		//{
		//	userList.insert(make_pair(userInfo, senderAddr));
		//}
		//// userList[userInfo] = senderAddr; -> 위에 iterator 선언하고~ if 문 안까지 코드 그냥 이렇게 쓸 수도 있긴함..

		if (receivedBytes < 0) // 이 메세지가 -1 이면 에러임 + 0 도 에러 있긴함?
		{
			int errCode = WSAGetLastError(); // 무슨 에러가 난건지 잡기

			// 강종된 사람이 발견됨
			if (errCode == WSAECONNRESET)
			{
				userList.erase(userInfo);
				std::cout << userInfo << " : 연결해제" << '\n';
				continue;
			}
		}
		else // 에러가 아닐때만 추가
		{
			// map에 있는 것인지 확인한 후 없으면 추가
			map<string, sockaddr_in>::iterator finder{};
			finder = userList.find(userInfo);

			if (finder == userList.end()) // 자료구조 안에 해당 유저 정보가 없으면
			{
				userList.insert(make_pair(userInfo, senderAddr));
			}
		}

		map<string, sockaddr_in>::iterator iter{};
		for (iter = userList.begin(); iter != userList.end(); iter++)
		{
			sendto
			(
				mySocket,
				buffer,
				strlen(buffer),
				0,
				(sockaddr*)&iter->second, // 받을 사람
				sizeof(iter->second)
			);
		}

		// 위에는 송신하는거니까 송신은 그냥 UTF8로 보내고 받을 때 변환하기
		// 로그로 남는 거에 대해 한글이 이상해지지 않도록!
		// UTF8 -> ANSI 변환
		UTF8to_ANSI(buffer, sizeof(buffer));

		// 수신된 주소와 내용 출력
		std::cout << "수신된 내용 : " << buffer << '\n';

		// 어떤 소켓 쓸지, 어떤 메시지 보낼지(실제로는 문자열로 관리할때는 사이즈가 늘어남), 보내는 문자열 사이즈, 토큰값0, 목적지주소, 목적지주소의 바이트 크기

		//if (strcmp(buffer, "quit") == 0) // quit 입력시 while 탈출
		//{
		//	break;
		//}
		// 채팅 서버 식으로 하면 이름 : 문자열 방식으로 오기 때문에 strcmp 로 quit 찾으면 못찾음

		if (strstr(buffer, "quit") != nullptr) // strstr 써서 문자열에 quit이 있으면 탈출
		{
			break;
		}
	}


	// 뒤처리
	closesocket(mySocket); // 소켓 닫기
	WSACleanup(); // API cleanup
}