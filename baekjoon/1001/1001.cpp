#include <iostream>

int main()
{
    int nA{};
    int nB{};
    int nTotal{};

    std::cin >> nA;
    std::cin >> nB;

    nTotal = nA - nB;

    std::cout << nTotal;
}