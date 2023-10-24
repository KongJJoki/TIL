#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

int main()
{
	int nTime{};
	int nStrLength{};
	std::string strWord{};

	std::cin >> strWord;
	nStrLength = strWord.length();

	for (int i = 0; i < nStrLength; i++)
	{
		char cTmp{};
		cTmp = strWord[i];

		if (cTmp >= 'A' && cTmp <= 'C')
		{
			nTime += 3;
		}
		else if (cTmp >= 'D' && cTmp <= 'F')
		{
			nTime += 4;
		}
		else if (cTmp >= 'G' && cTmp <= 'I')
		{
			nTime += 5;
		}
		else if (cTmp >= 'J' && cTmp <= 'L')
		{
			nTime += 6;
		}
		else if (cTmp >= 'M' && cTmp <= 'O')
		{
			nTime += 7;
		}
		else if (cTmp >= 'P' && cTmp <= 'S')
		{
			nTime += 8;
		}
		else if (cTmp >= 'T' && cTmp <= 'V')
		{
			nTime += 9;
		}
		else if (cTmp >= 'W' && cTmp <= 'Z')
		{
			nTime += 10;
		}
	}

	std::cout << nTime;
}