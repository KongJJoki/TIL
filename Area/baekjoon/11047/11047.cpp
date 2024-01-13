#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nN{};
    int nK{};
    int nResult{};
    int nCursor{};
    std::vector<int> vecCoins{};

    std::cin >> nN;
    std::cin >> nK;

    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecCoins.push_back(nTmp);
    }

    while (nCursor <= nN - 1 && vecCoins[nCursor] <= nK)
    {
        nCursor++;
    }
    nCursor--;

    while (nK > 0 && nCursor >= 0)
    {
        while (vecCoins[nCursor] <= nK)
        {
            nK -= vecCoins[nCursor];
            nResult++;
        }
        nCursor--;
    }

    std::cout << nResult;
}