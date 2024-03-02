#include <iostream>
#include <string>

int main()
{
    std::string strK{};
    std::string strD{};
    std::string strA{};

    int nK{};
    int nD{};
    int nA{};

    int nCursor{};

    std::string strTmp{};

    std::cin >> strTmp;

    for(int i = 0; i < strTmp.length(); i++)
    {
        if(strTmp[i] == '/')
        {
            nCursor++;
            continue;
        }
        if(nCursor == 0)
        {
            strK += strTmp[i];
        }
        else if(nCursor == 1)
        {
            strD += strTmp[i];
        }
        else if(nCursor == 2)
        {
            strA += strTmp[i];
        }
    }

    nK = std::stoi(strK);
    nD = std::stoi(strD);
    nA = std::stoi(strA);

    if((nK + nA) < nD || nD == 0)
    {
        std::cout << "hasu";
    }
    else
    {
        std::cout << "gosu";
    }
}