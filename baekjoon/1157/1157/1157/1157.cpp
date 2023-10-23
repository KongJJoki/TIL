#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

int main()
{
	int nStrLength{};
	int nAlphabet[26]{};
	int nBig{};
	int nBigAlphabet{};
	bool bIsSame{};
	std::string strWord{};

	std::cin >> strWord;
	nStrLength = strWord.length();

	for (int i = 0; i < nStrLength; i++)
	{
		int nWord{};
		nWord = strWord[i];
		if (nWord >= 65 && nWord <= 90)
		{
			nWord -= 65;
		}
		else if (nWord >= 97 && nWord <= 122)
		{
			nWord -= 97;
		}
		nAlphabet[nWord]++;
	}

	nBig = nAlphabet[0];
	for (int i = 0; i < 26; i++)
	{
		if (nBig < nAlphabet[i])
		{
			nBig = nAlphabet[i];
			nBigAlphabet = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (nBig == nAlphabet[i])
		{
			if (i != nBigAlphabet)
			{
				bIsSame = true;
			}
		}
	}

	if (bIsSame)
	{
		std::cout << '?';
	}
	else
	{
		std::cout << (char)(nBigAlphabet + 65);
	}
}