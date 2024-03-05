#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string strTest{};
    std::string strTmp{};

    std::cin >> strTest;

    strTmp = strTest;
    std::reverse(strTmp.begin(), strTmp.end());

    if (strTest == strTmp)
    {
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }
}