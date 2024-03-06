#include <iostream>

int main()
{
    int nTime{};
    int nX{};
    int nY{};

    for(int i = 0; i < 4; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        nTime += nTmp;
    }

    while(nTime >= 60)
    {
        nTime -= 60;
        nX++;
    }
    nY = nTime;

    std::cout << nX << '\n' << nY;
}