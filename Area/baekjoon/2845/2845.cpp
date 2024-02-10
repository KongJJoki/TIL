#include <iostream>

int main()
{
    int nL{};
    int nP{};
    int nRealCount{};
    int arrNews[5]{};

    std::cin >> nL;
    std::cin >> nP;

    nRealCount = nL * nP;

    for(int i = 0; i < 5; i++)
    {
        std::cin >> arrNews[i];
        arrNews[i] =  arrNews[i] - nRealCount;
    }

    for(int i = 0; i < 5; i++)
    {
        std::cout << arrNews[i] << ' ';
    }
}