#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::string strWord{};
	int nCount{};
	int nNumberI{};

	std::cin >> strWord;
	nCount = strWord.length();

	while (nCount > 1000)
	{
		std::cin >> strWord;
		nCount = strWord.length();
	}

	std::cin >> nNumberI;
	while (nNumberI<1 || nNumberI>nCount)
	{
		std::cin >> nNumberI;
	}

	std::cout << strWord.at(nNumberI - 1);
}