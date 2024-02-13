#include <iostream>

int main()
{
    int nWinNum{};
    int nMaxScore{};

    for(int i = 0; i < 5; i++)
    {
        int nMyNum{};
        int nMyScore{};

        nMyNum = i + 1;

        for(int j = 0; j < 4; j++)
        {
            int nTmp{};
            std::cin >> nTmp;
            nMyScore += nTmp;
        }

        if(nMaxScore < nMyScore)
        {
            nWinNum = nMyNum;
            nMaxScore = nMyScore;
        }
    }

    std::cout << nWinNum << ' ' << nMaxScore;
}