#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    int nResult{};
    std::vector<int> vecA{};
    std::vector<int> vecB{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecA.push_back(nTmp);
    }

        for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecB.push_back(nTmp);
    }

    std::sort(vecA.begin(), vecA.end(), std::greater<int>());
    std::sort(vecB.begin(), vecB.end());

    for(int i = 0; i < nN; i++)
    {
        nResult += vecA[i] * vecB[i];
    }

    std::cout << nResult;
}