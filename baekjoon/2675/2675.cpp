#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

int main()
{
	int nCaseNumber{};
	std::vector<int> vecCaseNumber{};
	std::vector<std::string> vecStrings{};

	std::cin >> nCaseNumber;

	for (int i = 0; i < nCaseNumber; i++)
	{
		int nTmp{};
		std::string strTmp{};
		std::cin >> nTmp;
		vecCaseNumber.push_back(nTmp);
		std::cin >> strTmp;
		vecStrings.push_back(strTmp);
	}

	for (int i = 0; i < nCaseNumber; i++)
	{
		for (int k = 0; k < vecStrings[i].length(); k++)
		{
			for (int j = 0; j < vecCaseNumber[i]; j++)
			{
				std::cout << vecStrings[i][k];
			}
		}
		std::cout << '\n';
	}
}