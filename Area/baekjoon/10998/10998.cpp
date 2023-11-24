#include <iostream>

int main()
{
    int nInputA{};
    int nInputB{};
    int nResult{};

    std::cin >> nInputA;
    std::cin >> nInputB;

    nResult = nInputA * nInputB;

    std::cout << nResult;
}