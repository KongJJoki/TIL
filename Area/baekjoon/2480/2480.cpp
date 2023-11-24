#include <stdio.h>
#include <iostream>

int main()
{
	int nNumber1{};
	int nNumber2{};
	int nNumber3{};
	int nSameCount{};
	int nSameNum{};
	int nResult{};

	scanf_s("%d", &nNumber1);
	while (nNumber1 < 1 || nNumber1>6)
	{
		scanf_s("%d", &nNumber1);
	}
	scanf_s("%d", &nNumber2);
	while (nNumber2 < 1 || nNumber2>6)
	{
		scanf_s("%d", &nNumber2);
	}
	scanf_s("%d", &nNumber3);
	while (nNumber3 < 1 || nNumber3>6)
	{
		scanf_s("%d", &nNumber3);
	}

	/*a==b&&b==c
	a==b||a==c
	b==c*/

	if (nNumber1 == nNumber2 && nNumber1 == nNumber3) //다 같을때
	{
		nSameNum = nNumber1;
		nResult = 10000 + (nSameNum * 1000);
	}
	else if (nNumber1 == nNumber2 || nNumber1 == nNumber3) // 2개만 같을때, 3개 같은거는 위에서 걸러짐
	{
		nSameNum = nNumber1;
		nResult = 1000 + (nSameNum * 100);
	}
	else if (nNumber2 == nNumber3) // 2개만 같을때
	{
		nSameNum = nNumber2;
		nResult = 1000 + (nSameNum * 100);
	}
	else // 다 다를때
	{
		int maxn = std::max(nNumber1, std::max(nNumber2, nNumber3));
		nResult = maxn * 100;

		int nBigNum{};
		nBigNum = nNumber1;
		if (nNumber2 > nBigNum)
		{
			nBigNum = nNumber2;
			if (nNumber3 > nBigNum)
			{
				nBigNum = nNumber3;
			}
		}
		else if (nNumber3 > nBigNum)
		{
			nBigNum = nNumber3;
		}
		nResult = nBigNum * 100;

		printf("%d %d\n", maxn, nBigNum);
	}

	printf("%d", nResult);
}