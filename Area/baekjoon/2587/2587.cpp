#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vecNumbers{};
    int nAvg{};

    for (int i = 0; i < 5; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNumbers.push_back(nTmp);
        nAvg += nTmp;
    }
    std::sort(vecNumbers.begin(), vecNumbers.end());

    std::cout << nAvg / 5 << '\n';
    std::cout << vecNumbers[2];
}