#include <iostream>

int main()
{
    int nA{};
    int nB{};
    int nTestCount{};

    std::cin >> nTestCount;

    for (int i = 0; i < nTestCount; i++)
    {
        std::cin >> nA;
        std::cin >> nB;
        std::cout << nA + nB << '\n';
    }
}