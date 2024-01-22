#include <iostream>

int main()
{
    int nMoney{};
    int nRemain{};
    int nCount{};

    std::cin >> nMoney;

    nRemain = 1000 - nMoney;

    while (nRemain >= 500)
    {
        nRemain -= 500;
        nCount++;
    }
    while (nRemain >= 100)
    {
        nRemain -= 100;
        nCount++;
    }
    while (nRemain >= 50)
    {
        nRemain -= 50;
        nCount++;
    }
    while (nRemain >= 10)
    {
        nRemain -= 10;
        nCount++;
    }
    while (nRemain >= 5)
    {
        nRemain -= 5;
        nCount++;
    }
    while (nRemain >= 1)
    {
        nRemain -= 1;
        nCount++;
    }
    std::cout << nCount;
}