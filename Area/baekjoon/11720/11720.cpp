#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

int main()
{
	int nNumberCount{};
	int nTotal{};
	std::string strNumbers{};

	std::cin >> nNumberCount;
	while (nNumberCount < 1 || nNumberCount > 100)
	{
		std::cin >> nNumberCount;
	}

	std::cin >> strNumbers;

	for (int i = 0; i < nNumberCount; i++)
	{
		nTotal += strNumbers[i] - '0';
	}

	std::cout << nTotal;
}