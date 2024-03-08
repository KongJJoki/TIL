#include <iostream>

int main()
{
	int nM{};
	int nF{};

	while (true)
	{
		std::cin >> nM;
		std::cin >> nF;
		if (nM == 0 && nF == 0)
		{
			break;
		}
		std::cout << nM + nF << '\n';
	}
}