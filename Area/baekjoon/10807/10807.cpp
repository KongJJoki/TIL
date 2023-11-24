#include <stdio.h>
#include <iostream>
#include <list>

int main()
{
	int nIntNum{};
	int nFindNum{};
	int nFindCount{};

	scanf_s("%d", &nIntNum);
	while (nIntNum < 1 || nIntNum>100)
	{
		scanf_s("%d", &nIntNum);
	}

	int* nArray = new int[nIntNum];

	for (int i = 0; i < nIntNum; i++)
	{
		scanf_s("%d", &nArray[i]);
		while (nArray[i] < -100 || nArray[i] > 100)
		{
			scanf_s("%d", &nArray[i]);
		}
	}

	scanf_s("%d", &nFindNum);
	while (nFindNum < -100 || nFindNum > 100)
	{
		scanf_s("%d", &nFindNum);
	}

	for (int i = 0; i < nIntNum; i++)
	{
		if (nFindNum == nArray[i])
		{
			nFindCount++;
		}
	}

	delete[] nArray;

	printf("%d", nFindCount);
}