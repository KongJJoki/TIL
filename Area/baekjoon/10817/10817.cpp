#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vecNum{};

    for(int i = 0; i < 3; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNum.push_back(nTmp);
    }

    std::sort(vecNum.begin(), vecNum.end());

    std::cout << vecNum[1];
}