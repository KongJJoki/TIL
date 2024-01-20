#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>

using namespace std;
#pragma comment (lib, "Ws2_32.lib") // 위에 헤더들의 실제 실행파일인 cpp 파일

struct ClientInfo
{
	WSAOVERLAPPED overlapped{};
	SOCKET socket{};
	char buffer[512]{};
	WSABUF dataBuf{};
	DWORD recvByte{};
	DWORD flags{};
};

void CALLBACK RecvCallBackFunc(DWORD _error, DWORD _recvLen, LPWSAOVERLAPPED _overlapped, DWORD _inflags);
void CALLBACK SendCallBackFunc(DWORD _error, DWORD _recvLen, LPWSAOVERLAPPED _overlapped, DWORD _inflags);

void CALLBACK RecvCallBackFunc(DWORD _error, DWORD _recvLen, LPWSAOVERLAPPED _overlapped, DWORD _inflags) // 콜백함수 생성 CALLBACK 써줘야함(메모리처리명시) 매개변수들은 그냥 정해져있는듯 외..워?
{
	ClientInfo* info = (ClientInfo*)_overlapped; // info 구조체 안에 있는 정보들 쓰기위해서

	std::cout << "받았다" << '\n';

	if (_recvLen == 0) // recvLen이 0 이면 연결 끊긴거라서 종료처리
	{
		std::cout << "클라 연결 종료" << '\n';
		closesocket(info->socket);

		delete info; // info 사용 끝났으니까 동적할당 삭제

		return;
	}

	if (_error == 0) // 종료도 아니고 에러도 없으면
	{
		std::cout << "수신 내용 : " << info->buffer << '\n';

		// 핑퐁 ..
		WSASend(info->socket, &info->dataBuf, 1, &info->recvByte, 0, &info->overlapped, SendCallBackFunc);

		// 한번 받고 또 받으려면 WSARecv 재호출 필요
	}
}

void CALLBACK SendCallBackFunc(DWORD _error, DWORD _recvLen, LPWSAOVERLAPPED _overlapped, DWORD _inflags)
{
	ClientInfo* info = (ClientInfo*)_overlapped;

	//수신대기
	int nResult = WSARecv(info->socket, &info->dataBuf, 1, &info->recvByte, &info->flags, &info->overlapped, RecvCallBackFunc);

	if (nResult == SOCKET_ERROR) // 비동기라서 바로나옴?
	{
		if (WSAGetLastError() == WSA_IO_PENDING) // 에러나면 얘가 에러코드 반환해줌 WSA_IO_PENDING이 나오면 정상인거
		{
			std::cout << "비동기 처리 완료" << '\n';
		}
	}
}

int main()
{
	// 결과가 오면 AAA라는 함수를 OS 니가 호출해
	// CallBack : OS가 대신 호출해주는 함수

	// WSAStartup

	WSADATA wsa{};
	int nResult{};

	nResult = WSAStartup(MAKEWORD(2, 2), &wsa); // MAKEWORD WORD를 만듬 WORD는 윈도우가 쓰는 부호없는 2바이트 정수형
	// 2,2 인 이유 : 소켓 버전? 2.2 소켓을 넣은거

	if (nResult != 0)
	{
		std::cout << "WSAStartup 에러" << '\n';
		return -1;
	}

	// MAKEWORD(2,2) -> 2바이트를 1바이트씩 쪼개서? 2를 넣는다? 


	// 소켓 생성 -> mySocket 생성부분이 동기랑 다름

	SOCKET mySocket = WSASocket(PF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
	// AF_INET처럼 PF_INET도 있음 둘이 같은거다? 프로토콜 패밀리? / TCP라서 SOCK_STREAM / WSA_FLAG_OVERLAPPED 가 비동기 IO할거라는 뜻
	// 0, nullptr 이런거는 옛날거라서 이제 안쓰는 것들

	if (mySocket == INVALID_SOCKET)
	{
		std::cout << "소켓 생성 에러" << '\n';
		WSACleanup();
		return -1;
	}


	// 바인딩 -> 동기랑 똑같음

	// 수신 정보 입력
	sockaddr_in receiverAddr{};
	receiverAddr.sin_family = PF_INET; // PF_INET이랑 AF_INET이랑 같음 PF는 프로토콜 패밀리 AF는 어드레스 패밀리
	receiverAddr.sin_port = htons(12345);
	receiverAddr.sin_addr.s_addr = INADDR_ANY;

	nResult = bind(mySocket, (sockaddr*)&receiverAddr, sizeof(receiverAddr));

	if (nResult != 0)
	{
		std::cout << "바인딩 에러" << '\n';

		closesocket(mySocket);
		WSACleanup();
		return -1;
	}


	// listen -> 동기랑 똑같음

	if (listen(mySocket, SOMAXCONN) == SOCKET_ERROR)
	{
		std::cout << "listen 에러" << '\n';

		closesocket(mySocket);
		WSACleanup();
		return -1;
	}

	// accept -> 동기랑 다름?

	SOCKET clientSocket{}; // 선언은 밖으로 빼줘야함 while 안에 있으면 계속 생성해서?

	while (true)
	{
		std::cout << "연결 대기 시작" << '\n';

		clientSocket = accept(mySocket, nullptr, nullptr);

		if (clientSocket == INVALID_SOCKET)
		{
			std::cout << "aceept 에러" << '\n';

			closesocket(clientSocket);
			WSACleanup();
			return -1;
		}

		// 여기까지 오면 클라 연결 성공한것
		std::cout << "클라이언트 연결 성공" << "\n";

		// 서버를 비동기를 바꾸는거라서 클라는 어제 만든 TCP_Client 사용

		ClientInfo* info = new ClientInfo{}; // ClientInfo 구조체 형으로 선언
		info->socket = clientSocket;
		info->dataBuf.buf = info->buffer;
		info->dataBuf.len = 512;
		info->flags = 0;
		info->recvByte = 0;

		//char buffer[512]{}; // 512자 받을거면 513짜리 선언
		//WSABUF dataBuf{}; // 문자열 배열의 이름, 길이를 가짐
		//dataBuf.buf = buffer;
		//dataBuf.len = sizeof(buffer);

		//DWORD recvByte{}; // DWORD 사용해야함 DWORD는 그냥 unsigned long
		//DWORD flags{};

		//OVERLAPPED overlapped{};

		// 수신 대기

		// 이 줄에서 WSARecv함수를 호출하고 메인스레드인 나는 일단 지나감. 비동기 함수이기 때문에 OS한테 일시켜놓고 내려가게된다
		//nResult = WSARecv(clientSocket, &dataBuf, 1, &recvByte, &flags, &overlapped, RecvCallBackFunc);
		nResult = WSARecv(info->socket, &info->dataBuf, 1, &info->recvByte, &info->flags, &info->overlapped, RecvCallBackFunc); // info 구조체의 변수들로 바꿈
		// 소켓, 데이터 입력받을 버퍼(LPWSABUF형태), 버퍼 몇개야?, recvByte의 주소, 플래그, overlapped, 콜백함수 이름

		if (nResult == SOCKET_ERROR) // 비동기라서 바로나옴?
		{
			if (WSAGetLastError() == WSA_IO_PENDING) // 에러나면 얘가 에러코드 반환해줌 WSA_IO_PENDING이 나오면 정상인거
			{
				std::cout << "비동기 처리 완료" << '\n';
			}
			else // 진짜 에러난 상황
			{
				return -1;
			}
		}
	}


	// 송신






	// 해제

	closesocket(clientSocket);
	closesocket(mySocket);
	WSACleanup();
	return 0;
}