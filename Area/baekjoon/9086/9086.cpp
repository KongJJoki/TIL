#include <iostream>
#include <string>

int main()
{
    int nT{};
    std::cin >> nT;

    for(int i = 0; i < nT; i++)
    {
        int nEnd{};
        std::string strTmp{};
        std::cin >> strTmp;
        nEnd = strTmp.length();
        std::cout<< strTmp[0] << strTmp[nEnd-1] << '\n';
    }
}