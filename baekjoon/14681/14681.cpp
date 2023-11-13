#include <iostream>

int main()
{
    int nInputX{};
    int nInputY{};

    std::cin >> nInputX;
    std::cin >> nInputY;

    if (nInputX > 0 && nInputY > 0)
    {
        std::cout << '1';
    }
    else if (nInputX > 0 && nInputY < 0)
    {
        std::cout << '4';
    }
    else if (nInputX < 0 && nInputY > 0)
    {
        std::cout << '2';
    }
    else
    {
        std::cout << '3';
    }
}