#include <iostream>

int main()
{
	int nCount{};
	std::cin >> nCount;

	for (int i = 0; i < nCount; i++)
	{
		int nTmp{};
		nTmp = nCount - i - 1;
		for (int j = 0; j < nTmp; j++)
		{
			std::cout << ' ';
		}
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
}