#include <iostream>
#include <queue>

int main()
{
	int nVectorLength{};
	int nNumberK{};
	std::queue<int> qCircle{};

	std::cin >> nVectorLength;
	std::cin >> nNumberK;

	for (int i = 0; i < nVectorLength; i++)
	{
		int nTmp{};
		nTmp = i + 1;
		qCircle.push(nTmp);
	}

	std::cout << '<';

	while (qCircle.size() != 1)
	{
		for (int i = 0; i < nNumberK - 1; i++)
		{
			int nTmp{};
			nTmp = qCircle.front();
			qCircle.push(nTmp);
			qCircle.pop();
		}

		std::cout << qCircle.front() << ',' << ' ';
		qCircle.pop(); // 출력한 값인 맨 앞 값은 pop으로 빼줘야함! 아니면 계속 큐가 같은 길이임
	}

	std::cout << qCircle.front() << '>';
}