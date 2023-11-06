#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arrSort[10001]{};
    int nN{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        arrSort[nTmp]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        int nTmp{};
        nTmp = arrSort[i];
        for (int j = 0; j < nTmp; j++)
        {
            std::cout << i << '\n';
        }
    }
}