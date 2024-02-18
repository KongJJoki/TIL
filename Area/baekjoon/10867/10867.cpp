#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    std::vector<int> vecNumbers{};
    std::vector<int>::iterator iter{};

    std::cin >> nN;
    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNumbers.push_back(nTmp);
    }

    std::sort(vecNumbers.begin(), vecNumbers.end());
    iter = std::unique(vecNumbers.begin(), vecNumbers.end());
    vecNumbers.erase(iter, vecNumbers.end());

    for (int i = 0; i < vecNumbers.size(); i++)
    {
        std::cout << vecNumbers[i] << ' ';
    }
}