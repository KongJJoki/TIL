#include <iostream>

int main()
{
    int nCount{};
    int nStart{};
    int nInputN{};
    int nSixMul{};
    int nMin{};

    nCount = 1;
    nStart = 1;
    nSixMul = 1;
    nMin = 1;

    std::cin >> nInputN;

    while (nMin < nInputN)
    {
        nCount++;
        nMin += 6 * nSixMul;
        nSixMul++;
    }

    std::cout << nCount;
}