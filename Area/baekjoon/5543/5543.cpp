#include <iostream>

int main()
{
    int nBurguer1{};
    int nBurguer2{};
    int nBurguer3{};
    int nCola{};
    int nCider{};

    int nMinBurger{};
    int nMinSoda{};
    int nResult{};

    std::cin >> nBurguer1;
    std::cin >> nBurguer2;
    std::cin >> nBurguer3;
    std::cin >> nCola;
    std::cin >> nCider;

    nMinBurger = nBurguer1;
    nMinSoda = nCola;

    if(nMinBurger > nBurguer2)
    {
        nMinBurger = nBurguer2;
    }
    if(nMinBurger > nBurguer3)
    {
        nMinBurger = nBurguer3;
    }
    if(nMinSoda > nCider)
    {
        nMinSoda = nCider;
    }

    std::cout << nMinBurger + nMinSoda - 50;
}