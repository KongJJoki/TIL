#include <iostream>
#include <cmath>
#include <string>

int main()
{
    std::string strNum{};
    int nResult{};

    std::cin >> strNum;

    for(int i = 0; i < 5; i++)
    {
        std::string strTmp{};
        strTmp = strNum[i];
        nResult += std::pow(std::stoi(strTmp),5);
    }

    std::cout << nResult;
}
