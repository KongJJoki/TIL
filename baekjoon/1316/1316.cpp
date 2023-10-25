#include <string>
#include <iostream>
#include <stdio.h>

int main()
{
    int nWorkNum{};
    int nGroupNum{};
    int nTmpStrLength{};
    std::string strTmp{};

    std::cin >> nWorkNum;

    for (int i = 0; i < nWorkNum; i++)
    {
        bool bIsGroup{};
        bool bIsAlphabet[26]{};
        std::cin >> strTmp;
        nTmpStrLength = strTmp.length();
        bIsGroup = true;

        bIsAlphabet[strTmp[0] - 97] = true;

        for (int j = 1; j < nTmpStrLength; j++)
        {
            char cTmp{};
            cTmp = strTmp[j];

            if (cTmp != strTmp[j - 1])
            {
                if (!bIsAlphabet[cTmp - 97])
                {
                    bIsAlphabet[cTmp - 97] = true;
                }
                else
                {
                    bIsGroup = false;
                }
            }
        }

        if (bIsGroup)
        {
            nGroupNum++;
        }
    }

    std::cout << nGroupNum;
}