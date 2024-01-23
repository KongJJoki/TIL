#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nFruitNum{};
    int nMyLength{};
    int nNowFruitIndex{};
    std::vector<int> vecFruits{};

    std::cin >> nFruitNum;
    std::cin >> nMyLength;
    for (int i = 0; i < nFruitNum; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecFruits.push_back(nTmp);
    }

    std::sort(vecFruits.begin(), vecFruits.end());

    while (nNowFruitIndex < nFruitNum)
    {
        int nNowFruitPos{};
        nNowFruitPos = vecFruits[nNowFruitIndex];
        if (nMyLength >= nNowFruitPos)
        {
            nMyLength++;
            nNowFruitIndex++;
        }
        else
        {
            break;
        }
    }

    std::cout << nMyLength;
}