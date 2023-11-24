#include <iostream>

int main()
{
    int nInputA{};
    int nInputB{};

    std::cin >> nInputA;
    std::cin >> nInputB;

    if (nInputA > nInputB)
    {
        std::cout << '>';
    }
    else if (nInputA < nInputB)
    {
        std::cout << '<';
    }
    else
    {
        std::cout << "==";
    }
}