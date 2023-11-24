#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nCoordLength{};
    std::vector<int> vecCoordOrigin{};
    std::vector<int> vecSort{};

    std::cin >> nCoordLength;

    for (int i = 0; i < nCoordLength; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecCoordOrigin.push_back(nTmp);
        vecSort.push_back(nTmp);
    }

    std::sort(vecSort.begin(), vecSort.end());
    vecSort.erase(std::unique(vecSort.begin(), vecSort.end()),vecSort.end());

    for (int i = 0; i < nCoordLength; i++)
    {
        std::cout << std::lower_bound(vecSort.begin(), vecSort.end(), vecCoordOrigin[i]) - vecSort.begin() << ' ';
    }
}