
#include <iostream>

int main()
{
	int nNumber{};
	int nResult{};
	bool arrBool[100][100]{};

	std::cin >> nNumber;

	for (int i = 0; i < nNumber; i++)
	{
		int nWidth{};
		int nHeight{};

		std::cin >> nWidth >> nHeight;

		for (int j = nWidth; j < nWidth + 10; j++)
		{
			for (int k = nHeight; k < nHeight + 10; k++)
			{
				arrBool[j][k] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arrBool[i][j])
			{
				nResult++;
			}
		}
	}

	std::cout << nResult;
}