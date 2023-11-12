#include <iostream>

int main()
{
    int nInputA{};
    int nInputB{};

    std::cin >> nInputA;
    std::cin >> nInputB;

    std::cout << nInputA + nInputB;
    std::cout << '\n';
    std::cout << nInputA - nInputB;
    std::cout << '\n';
    std::cout << nInputA * nInputB;
    std::cout << '\n';
    std::cout << nInputA / nInputB;
    std::cout << '\n';
    std::cout << nInputA % nInputB;
}