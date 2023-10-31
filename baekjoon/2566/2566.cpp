#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
    int nRowCount{};
    int nColumnCount{};

    nRowCount = 9;
    nColumnCount = 9;

    int nBigNum{};
    int nBigRow{};
    int nBigColumn{};

    std::vector<std::vector<int>> vecArray(nRowCount, std::vector<int>(nColumnCount, 0));

    for (int i = 0; i < nRowCount; i++)
    {
        for (int j = 0; j < nColumnCount; j++)
        {
            int nTmp{};
            std::cin >> nTmp;
            vecArray[i][j] = nTmp;
        }
    }

    nBigNum = vecArray[0][0];
    nBigRow = 1;
    nBigColumn = 1;

    for (int i = 0; i < nRowCount; i++)
    {
        for (int j = 0; j < nColumnCount; j++)
        {
            if (nBigNum < vecArray[i][j])
            {
                nBigNum = vecArray[i][j];
                nBigRow = i + 1;
                nBigColumn = j + 1;
            }
        }
    }

    std::cout << nBigNum << '\n' << nBigRow << ' ' << nBigColumn;
}