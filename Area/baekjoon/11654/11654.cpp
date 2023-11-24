#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	char nASCII{};
	bool bInRange{};

	while (!bInRange)
	{
		std::cin >> nASCII;

		if (nASCII >= 48 && nASCII <= 57)
		{
			bInRange = true;
		}
		else if (nASCII >= 65 && nASCII <= 90)
		{
			bInRange = true;
		}
		else if (nASCII >= 97 && nASCII <= 122)
		{
			bInRange = true;
		}
	}

	if (nASCII >= 48 && nASCII <= 57)
	{
		std::cout << (int)nASCII;
	}
	else
	{
		std::cout << (int)nASCII;
	}
}