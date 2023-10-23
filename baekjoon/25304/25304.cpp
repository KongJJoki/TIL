#include <stdio.h>
#include <iostream>

int main()
{
	int nSumPrice{};
	int nTypeNum{};
	int nPrice{};
	int nCount{};
	int nRealPrice{};
	scanf_s("%d", &nSumPrice);
	while (nSumPrice < 1 || nSumPrice > 1000000000)
	{
		scanf_s("%d", &nSumPrice);
	}
	scanf_s("%d", &nTypeNum);
	while (nTypeNum < 1 || nTypeNum > 100)
	{
		scanf_s("%d", &nTypeNum);
	}

	for (int i = 0; i < nTypeNum; i++)
	{
		int nTmpPrice{};
		scanf_s("%d %d", &nPrice, &nCount);
		while (nPrice < 1 || nPrice > 1000000)
		{
			scanf_s("%d", &nPrice);
		}
		while (nCount < 1 || nCount > 10)
		{
			scanf_s("%d", &nCount);
		}
		nTmpPrice = nPrice * nCount;
		nRealPrice += nTmpPrice;
	}

	if (nSumPrice == nRealPrice)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}