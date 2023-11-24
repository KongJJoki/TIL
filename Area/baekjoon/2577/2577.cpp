#include <iostream>
#include <string>

int main()
{
    int arrNumber[10]{};
    std::string strNumber{};
    int nNumberLength{};
    
    int nA{};
    int nB{};
    int nC{};

    int nMultiple{};

    std::cin >> nA >> nB >> nC;

    nMultiple = nA * nB * nC;

    strNumber = std::to_string(nMultiple);

    nNumberLength = strNumber.length();

    for (int i = 0; i < nNumberLength; i++)
    {
        int nTmp{};
        nTmp = strNumber[i] - '0';
        arrNumber[nTmp]++;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << arrNumber[i] << '\n';
    }
}