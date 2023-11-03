#include <iostream>
#include <string>

int main()
{
    int nInputN{};
    int nCount{};
    int nNowNumber{};

    nNowNumber = 666;
    nCount = 1;

    std::cin >> nInputN;

    while (nCount != nInputN)
    {
        std::string strTmp{};

        nNowNumber++;

        strTmp = std::to_string(nNowNumber);
        if (strTmp.find("666") != std::string::npos)
        {
            nCount++;
        }
    }

    std::cout << nNowNumber;
}