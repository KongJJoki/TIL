#include <iostream>

int main()
{
    int nInputA{};
    int nInputB{};
    int nInputC{};

    std::cin >> nInputA;
    std::cin >> nInputB;
    std::cin >> nInputC;

    std::cout << (nInputA + nInputB) % nInputC << '\n';
    std::cout << ((nInputA % nInputC) + (nInputB % nInputC)) % nInputC << '\n';
    std::cout << (nInputA * nInputB) % nInputC << '\n';
    std::cout << ((nInputA % nInputC) * (nInputB % nInputC)) % nInputC;
}