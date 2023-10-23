#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int nVectorLength{};
	int nSwapTime{};
	int nStartNum{};
	int nEndNum{};
	std::vector<int> vBaguni{};

	scanf("%d", &nVectorLength);
	while (nVectorLength < 1 || nVectorLength>100)
	{
		scanf("%d", &nVectorLength);
	}
	scanf("%d", &nSwapTime);

	for (int i = 0; i < nVectorLength; i++)
	{
		vBaguni.push_back(i + 1);
	}

	for (int i = 0; i < nSwapTime; i++)
	{
		scanf("%d", &nStartNum);
		scanf("%d", &nEndNum);
		while (nStartNum < 1 || nStartNum>nEndNum)
		{
			scanf("%d", &nStartNum);
		}
		while (nEndNum < nStartNum || nEndNum>100)
		{
			scanf("%d", &nEndNum);
		}

		std::reverse(vBaguni.begin() + (nStartNum - 1), vBaguni.begin() + nEndNum);
	}

	for (int i = 0; i < nVectorLength; i++)
	{
		printf("%d ", vBaguni[i]);
	}
}