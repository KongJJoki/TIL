#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vecA{};
    std::vector<int> vecB{};

    int nACount{};
    int nBCount{};
    
    std::cin >> nACount;
    std::cin >> nBCount;

    std::vector<int> vecAB(nACount + nBCount);

    for(int i = 0; i < nACount; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecA.push_back(nTmp);
    }
    for(int i =0; i < nBCount; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecB.push_back(nTmp);
    }

    std::sort(vecA.begin(), vecA.end());
    std::sort(vecB.begin(), vecB.end());

    auto iter = std::set_difference(vecA.begin(),vecA.end(),vecB.begin(),vecB.end(),vecAB.begin());
    vecAB.erase(iter, vecAB.end());

    std::sort(vecAB.begin(),vecAB.end());

    std::cout << vecAB.size() << '\n';
    for(int i = 0; i < vecAB.size(); i++)
    {
        std::cout << vecAB[i] << ' ';
    }
}