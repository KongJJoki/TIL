#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    std::vector<int> vecNum{};
    std::cin >> nN;

    for(int i = 0; i < nN+1; i++)
    {
        vecNum.push_back(0);
    }

    for(int i = 0; i < nN ; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNum[i] = nTmp;
    }
    std::sort(vecNum.begin(),vecNum.end(),std::greater<int>());

    for(int i = 0; i < nN*(nN-1); i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        vecNum[nN] = nTmp;

        std::sort(vecNum.begin(),vecNum.end(),std::greater<int>());
    }

    std::cout << vecNum[nN-1];
}