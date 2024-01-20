#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	// WSAStartup

	WSADATA wsa;
	int nResult{};

	nResult = WSAStartup(MAKEWORD(2, 2), &wsa);

	if (nResult != 0)
	{
		std::cout << "WSAStartup 에러" << '\n';
		return -1;
	}

	// socket

	// 소켓 생성
	SOCKET mySocket = socket(AF_INET, SOCK_STREAM, 0); // UDP에서는 2번째 인자가 SOCK_DGRAM이지만 TCP에서는 SOCK_STREAM으로 변경
	if (mySocket == INVALID_SOCKET)
	{
		std::cout << "Socket 생성 에러" << '\n';

		WSACleanup();
		return -1;
	}

	// 수신자의 주소 설정
	sockaddr_in recvAddr{};
	recvAddr.sin_family = AF_INET;
	recvAddr.sin_port = htons(12345);
	recvAddr.sin_addr.s_addr = INADDR_ANY;

	inet_pton(AF_INET, "127.0.0.1", &recvAddr.sin_addr);

	// 바인딩이랑 listen은 서버가하는거니까 없애기

	// 연결 시도
	nResult = connect(mySocket, (sockaddr*)&recvAddr, sizeof(recvAddr));

	if (nResult == SOCKET_ERROR)
	{
		cout << "연결 에러" << '\n';
		closesocket(mySocket);
		WSACleanup();
		return -1;
	}

	cout << "서버에 연결됨" << '\n';

	while (true)
	{
		string msg;

		cout << "입력 : ";
		getline(cin, msg);
		
		if (msg == "exit")
		{
			break;
		}

		send(mySocket, msg.c_str(), msg.length()+1, 0); // msg.c_str()은 문자열의 처음 위치라는 뜻

		char buffer[512]{};
		int recvByte = recv(mySocket, buffer, sizeof(buffer), 0); // UDP는 sendto, recvfrom이라는 함수였는데 TCP는 그냥 send, recv 함수

		if (recvByte <= 0) // recvByte가 0이 나오면 연결이 끊긴거
		{
			cout << "연결 문제" << '\n';
			break;
		}
		cout << "수신 메세지 : " << buffer << '\n';
	}

	system("pause");

	// recv send


	closesocket(mySocket);
	WSACleanup();
}