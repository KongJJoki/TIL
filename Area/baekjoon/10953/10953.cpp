#include <iostream>
#include <string>

int main()
{
    int nT{};

    std::cin >> nT;

    for (int i = 0; i < nT; i++)
    {
        int nNum1{};
        int nNum2{};
        std::string strTmp{};
        std::cin >> strTmp;

        nNum1 = strTmp[0] - '0';
        nNum2 = strTmp[2] - '0';
        std::cout << nNum1 + nNum2 << '\n';
    }
}