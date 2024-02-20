#include <iostream>

int main()
{
    int nR1{};
    int nR2{};
    int nS{};

    std::cin >> nR1;
    std::cin >> nS;

    nR2 = (nS * 2) - nR1;

    std::cout << nR2;
}