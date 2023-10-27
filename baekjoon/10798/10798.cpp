#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
	std::string strRead[5]{};

	for (int i = 0; i < 5; i++)
	{
		std::cin >> strRead[i];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (strRead[j].length() > i)
			{
				std::cout << strRead[j][i];
			}
		}
	}
}