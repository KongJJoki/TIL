#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string strTest{};
    std::vector<std::string> vecStr{};
    int nVecLength{};
    int nCursor{};

    std::cin >> strTest;

    if (strTest.length() % 10 == 0)
    {
        nVecLength = strTest.length() / 10;
    }
    else
    {
        nVecLength = (strTest.length()) / 10 + 1;
    }

    for (int i = 0; i < nVecLength; i++)
    {
        std::string strTmp{};
        if (i != nVecLength - 1)
        {
            for (int j = nCursor; j < 10 * (i + 1); j++)
            {
                strTmp += strTest[j];
            }
            vecStr.push_back(strTmp);
            nCursor = 10 * (i + 1);
        }
        else
        {
            for (int j = nCursor; j < strTest.length(); j++)
            {
                strTmp += strTest[j];
            }
            vecStr.push_back(strTmp);
        }
    }

    for (int i = 0; i < nVecLength; i++)
    {
        std::cout << vecStr[i] << '\n';
    }
}