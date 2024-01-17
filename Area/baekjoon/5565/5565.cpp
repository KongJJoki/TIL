#include <iostream>

int main()
{
    int nTotal{};

    std::cin >> nTotal;

    for (int i = 0; i < 9; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        nTotal -= nTmp;
    }

    std::cout << nTotal;
}