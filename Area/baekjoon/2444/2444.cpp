#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

int main()
{
	int nNumber{};
	int nSpace{};
	int nStarNum{};
	std::stack<int> arrNumber{};

	std::cin >> nNumber;
	nSpace = nNumber - 1;

	for (int i = 1; i < nNumber + 1; i++)
	{
		nStarNum = 2 * i - 1;
		for (int j = 0; j < nSpace; j++)
		{
			std::cout << ' ';
		}
		for (int j = 0; j < nStarNum; j++)
		{
			std::cout << '*';
		}
		arrNumber.push(nStarNum);
		nSpace--;
		std::cout << '\n';
	}

	arrNumber.pop();
	nSpace = 1;

	for (int i = nNumber + 1; i < 2 * nNumber; i++)
	{
		int nTmp{};
		nTmp = arrNumber.top();
		for (int j = 0; j < nSpace; j++)
		{
			std::cout << ' ';
		}
		for (int j = 0; j < nTmp; j++)
		{
			std::cout << '*';
		}
		arrNumber.pop();
		nSpace++;
		std::cout << '\n';
	}
}