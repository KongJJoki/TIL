#include <iostream>

int Factorial(int nNum)
{
    if (nNum == 1)
    {
        return 1;
    }

    return nNum * Factorial(nNum-1);
}

int main()
{
    int nN{};
    int nK{};

    std::cin >> nN;
    std::cin >> nK;

    if (nN == 1 || nK == 0 || nN == nK)
    {
        std::cout << 1;
    }
    else
    {
        int nTmp{};
        nTmp = Factorial(nN) / (Factorial(nN - nK) * Factorial(nK));
        std::cout << nTmp;
    }
}