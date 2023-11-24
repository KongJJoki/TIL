#include <stdio.h>
#include <iostream>

int main()
{
	int nNumArray[9]{};
	int nArrayLength{};
	int nBigNum{};
	int nBigIndex{};

	nArrayLength = 9;
	for (int i = 0; i < nArrayLength; i++)
	{
		scanf_s("%d", &nNumArray[i]);
		while (nNumArray[i] < 1 || nNumArray[i]>100)
		{
			scanf_s("%d", &nNumArray[i]);
		}

		if (nNumArray[i] > nBigNum)
		{
			nBigNum = nNumArray[i];
			nBigIndex = i + 1;
		}
	}

	printf("%d\n", nBigNum);
	printf("%d", nBigIndex);
}