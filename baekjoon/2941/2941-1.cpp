#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

int main()
{
	int nStrLength{};
	int nTmp{};
	int nCount{};
	std::string strCroatia{};

	std::cin >> strCroatia;
	nStrLength = strCroatia.length();

	while (nTmp < nStrLength)
	{
		char cTmp1{};
		char cTmp2{};

		cTmp1 = strCroatia[nTmp];
		cTmp2 = strCroatia[nTmp + 1];

		if (cTmp1 == 'c')
		{
			if (cTmp2 == '=' || cTmp2 == '-')
			{
				nCount++;
				nTmp += 2;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else if (cTmp1 == 'd')
		{
			if (cTmp2 == '-')
			{
				nCount++;
				nTmp += 2;
			}
			else if (cTmp2 == 'z' && strCroatia[nTmp + 2] == '=')
			{
				nCount++;
				nTmp += 3;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else if (cTmp1 == 'l')
		{
			if (cTmp2 == 'j')
			{
				nCount++;
				nTmp += 2;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else if (cTmp1 == 'n')
		{
			if (cTmp2 == 'j')
			{
				nCount++;
				nTmp += 2;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else if (cTmp1 == 's')
		{
			if (cTmp2 == '=')
			{
				nCount++;
				nTmp += 2;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else if (cTmp1 == 'z')
		{
			if (cTmp2 == '=')
			{
				nCount++;
				nTmp += 2;
			}
			else
			{
				nCount++;
				nTmp++;
			}
		}
		else
		{
			nCount++;
			nTmp++;
		}
	}

	std::cout << nCount;
}