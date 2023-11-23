#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int nLength{};
    std::vector<int> vecTmp{};

    std::cin >> nLength;

    for (int i = 0; i < nLength; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecTmp.push_back(nTmp);
    }

    std::sort(vecTmp.begin(), vecTmp.end());

    for (int i = 0; i < nLength; i++)
    {
        std::cout << vecTmp[i] << '\n';
    }
}