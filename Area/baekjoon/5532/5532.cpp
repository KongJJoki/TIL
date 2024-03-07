#include <iostream>

int main()
{
    int nL{};
    int nA{};
    int nB{};
    int nC{};
    int nD{};
    int nKorean{};
    int nMath{};
    int nBigger{};

    std::cin >> nL;
    std::cin >> nA;
    std::cin >> nB;
    std::cin >> nC;
    std::cin >> nD;

    if (nA % nC == 0)
    {
        nKorean = nA / nC;
    }
    else
    {
        nKorean = nA / nC + 1;
    }

    if (nB % nD == 0)
    {
        nMath = nB / nD;
    }
    else
    {
        nMath = nB / nD + 1;
    }

    if (nKorean > nMath)
    {
        nBigger = nKorean;
    }
    else
    {
        nBigger = nMath;
    }

    std::cout << nL - nBigger;
}