#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    int nBefore{};
    int nResult{};
    std::vector<int> vecATM{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecATM.push_back(nTmp);
    }

    std::sort(vecATM.begin(),vecATM.end());

    for(int i = 0; i < nN; i++)
    {
        nResult += nBefore + vecATM[i];
        nBefore = nBefore + vecATM[i];
    }

    std::cout << nResult;
}