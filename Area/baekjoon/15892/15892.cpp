#include <iostream>
#include <string>
#include <cmath>

int main()
{
    long long nResult{};
    int nStrLength{};
    long long nM{};
    long long nPow{};
    std::string strInput{};

    nM = 1234567891;
    nPow = 1;
    std::cin >> nStrLength;
    std::cin >> strInput;

    for (int i = 0; i < nStrLength; i++)
    {
        long long nTmp{};
        char cTmp{};

        cTmp = strInput[i];
        nTmp = cTmp - 96; // 알파벳 소문자 숫자로 만들기

        nResult += nTmp * nPow;

        nResult %= nM;

        nPow = nPow * 31 % nM;
    }

    std::cout << nResult;
}