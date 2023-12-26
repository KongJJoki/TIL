#include <iostream>
#include <algorithm>

int arNum[2250010]{};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int nN{};
    std::cin >> nN;

    for(int i = 0; i < nN * nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        arNum[i] = nTmp;
    }

    std::sort(&arNum[0], &arNum[nN*nN], std::greater<int>());
    std::cout << arNum[nN - 1];
}