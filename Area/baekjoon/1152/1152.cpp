#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int nNumber{};
	int nCount{};
	int nStrLength{};
	std::string strTest{};
	char cSpace{};

	cSpace = ' ';

	std::getline(std::cin, strTest);

	nStrLength = strTest.length();

	for (int i = 0; i < nStrLength; i++)
	{
		if (strTest[i] == cSpace)
		{
			nCount++;
		}
	}

	if (strTest[0] == cSpace)
	{
		nCount--;
	}

	if (strTest[nStrLength - 1] == cSpace)
	{
		nCount--;
	}


	std::cout << nCount + 1;
}