#include <iostream>
#include <vector>

int main()
{
    int nN{};
    int nM{};
    int nJ{};
    int nBasketStart{};
    int nBasketEnd{};
    int nMoveCount{};
    std::vector<int> vecApple{};

    std::cin >> nN;
    std::cin >> nM;
    std::cin >> nJ;
    for(int i = 0; i < nJ; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecApple.push_back(nTmp);
    }

    nBasketStart = 1;
    nBasketEnd = nM;

    for(int i = 0; i < nJ; i++)
    {
        int nTmp{};
        nTmp = vecApple[i];

        if(nTmp < nBasketStart)
        {
            while(nBasketStart != nTmp)
            {
                nBasketStart--;
                nBasketEnd--;
                nMoveCount++;
            }
        }
        else if(nTmp > nBasketEnd)
        {
            while(nBasketEnd != nTmp)
            {
                nBasketEnd++;
                nBasketStart++;
                nMoveCount++;
            }
        }
    }

    std::cout << nMoveCount;
}