#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    std::vector<int> vecNum{};

    std::cin >> nN;
    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNum.push_back(nTmp);
    }

    std::sort(vecNum.begin(), vecNum.end(), std::greater<>());

    for(int i = 0; i < nN; i++)
    {
        std::cout << vecNum[i] << '\n';
    }
}