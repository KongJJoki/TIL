#include <iostream>

int main()
{
    int nK{};
    int nN{};
    int nM{};
    int nResult{};

    std::cin >> nK;
    std::cin >> nN;
    std::cin >> nM;

    nResult = (nK * nN) - nM;

    if(nResult < 0)
    {
        nResult = 0;
    }

    std::cout << nResult;
}