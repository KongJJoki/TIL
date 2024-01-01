#include <iostream>

int main()
{
	int nA{};
	int nNewA{};
	int nB{};
	int nC{};
	int nD{};

	nNewA = -1;

	std::cin >> nA;
	std::cin >> nB;
	std::cin >> nC;
	std::cin >> nD;

	nC += nD;

	while (nC >= 60)
	{
		nC -= 60;
		nB++;
	}
	while (nB >= 60)
	{
		nB -= 60;
		nA++;
	}
	while (nA >= 24)
	{
		nA %= 24;
	}

	std::cout << nA << ' ' << nB << ' ' << nC;
}