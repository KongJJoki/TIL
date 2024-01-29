#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<int> vecNumbers{};

    int nN{};
    int nM{};

    std::cin >> nN;
    std::cin >> nM;

    for (int i = 0; i < nN + nM; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNumbers.push_back(nTmp);
    }

    std::sort(vecNumbers.begin(), vecNumbers.end());

    for (int i = 0; i < nN + nM; i++)
    {
        std::cout << vecNumbers[i] << ' ';
    }
}