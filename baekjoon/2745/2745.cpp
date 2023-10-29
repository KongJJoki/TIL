#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int nBinaryNum{};
    int nStrLength{};
    int nResult{};
    std::string strTest{};

    std::cin >> strTest;
    std::cin >> nBinaryNum;

    nStrLength = strTest.length();

    for (int i = 0; i < nStrLength; i++)
    {
        char cTmp{};
        int nTmp{};
        cTmp = strTest[i];
        nTmp = nStrLength - i - 1;
        if (cTmp >= 48 && cTmp <= 57) //숫자 일때
        {
            cTmp -= 48;
            nResult += pow(nBinaryNum, nTmp) * cTmp;
        }
        else if (cTmp >= 56 && cTmp <= 90) //A~Z 일때
        {
            cTmp -= 55;
            nResult += pow(nBinaryNum, nTmp) * cTmp;
        }
    }

    std::cout << nResult;
}