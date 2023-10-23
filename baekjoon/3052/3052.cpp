#include <stdio.h>
#include <iostream>

int main()
{
	int arrNumberB[10]{};
	int arrSameRemain[42]{};
	int nArrayLength{};
	int nArrayRemainLength{};
	int nCount{};
	int nDifCount{};

	nArrayLength = 10;
	nArrayRemainLength = 42;

	for (int i = 0; i < nArrayLength; i++)
	{
		int nTmp{};

		scanf_s("%d", &nTmp);
		while (nTmp > 1000 || nTmp < 0)
		{
			scanf_s("%d", &nTmp);
		}

		arrNumberB[i] = nTmp % 42;
	}

	for (int i = 0; i < 10; i++)
	{
		arrSameRemain[arrNumberB[i]]++;
	}

	for (int i = 0; i < nArrayRemainLength; i++)
	{
		if (arrSameRemain[i] != 0)
		{
			nDifCount++;
		}
	}

	printf("%d", nDifCount);
}