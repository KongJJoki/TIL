#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

int main()
{
	int nStrLength{};
	bool bPass{};
	std::string strWord{};
	int arrAlphabet[26]{};

	for (int i = 0; i < 26; i++)
	{
		arrAlphabet[i] = -1;
	}

	std::cin >> strWord;
	nStrLength = strWord.length();

	while (!bPass || nStrLength > 100)
	{
		for (int i = 0; i < nStrLength; i++)
		{
			if (strWord[i] > 97 && strWord[i] < 123)
			{
				bPass = true;
			}
		}
	}

	for (int i = 0; i < nStrLength; i++)
	{
		if (arrAlphabet[strWord[i] - 97] == -1)
		{
			arrAlphabet[strWord[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << arrAlphabet[i] << ' ';
	}
}