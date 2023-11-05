#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nInputLength{};
    std::vector<std::pair<int,int>> vecPair{};

    std::cin >> nInputLength;

    for (int i = 0; i < nInputLength; i++)
    {
        std::pair<int,int> pairTmp{};
        std::cin >> pairTmp.first >> pairTmp.second;
        vecPair.push_back(pairTmp);
    }

    std::sort(vecPair.begin(), vecPair.end());

    for (int i = 0; i < nInputLength; i++)
    {
        std::cout << vecPair[i].first << ' ' << vecPair[i].second << '\n';
    }
}