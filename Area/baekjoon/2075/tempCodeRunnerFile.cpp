#include <iostream>
#include <algorithm>


int main()
{

    int arNum[2250010]{};
    int nN{};
    std::cin >> nN;

    for(int i = 0; i < nN * nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        arNum[i] = nTmp;
    }

    std::sort(arNum, arNum + nN*nN);
    std::cout << arNum[nN*nN-nN];
}