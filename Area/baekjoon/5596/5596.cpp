#include <iostream>

int main()
{
    int nMingookTotal{};
    int nManseTotal{};

    for(int i = 0 ; i < 4; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        nMingookTotal+=nTmp;
    }
    for(int i = 0 ; i < 4; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        nManseTotal+=nTmp;
    }

    if(nMingookTotal > nManseTotal)
    {
        std::cout << nMingookTotal;
    }
    else
    {
        std::cout << nManseTotal;
    }
}