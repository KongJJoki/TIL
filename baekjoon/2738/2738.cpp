#include <vector>
#include <iostream>

int main()
{
    int nRow{};
    int nColumn{};

    std::cin >> nRow;
    std::cin >> nColumn;

    std::vector<std::vector<int>> vecMatrix1(nRow, std::vector<int>(nColumn, 0));
    std::vector<std::vector<int>> vecMatrix2(nRow, std::vector<int>(nColumn, 0));
    std::vector<std::vector<int>> vecMatrixTotal(nRow, std::vector<int>(nColumn, 0));

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            int nTmp{};
            std::cin >> nTmp;

            vecMatrix1[i][j] = nTmp;
        }
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            int nTmp{};
            std::cin >> nTmp;

            vecMatrix2[i][j] = nTmp;
        }
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            vecMatrixTotal[i][j] = vecMatrix1[i][j] + vecMatrix2[i][j];
        }
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            std::cout << vecMatrixTotal[i][j];
            std::cout << ' ';
        }
        std::cout << '\n';
    }




}