#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int nNameCount{};
    std::vector<std::string> vecNames{};
    std::vector<std::string> vecIncrease{};
    std::vector<std::string> vecDecrease{};

    std::cin >> nNameCount;

    for(int i = 0; i < nNameCount; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;
        vecNames.push_back(strTmp);
        vecIncrease.push_back(strTmp);
        vecDecrease.push_back(strTmp);
    }

    std::sort(vecIncrease.begin(), vecIncrease.end(), std::less<std::string>());
    std::sort(vecDecrease.begin(), vecDecrease.end(), std::greater<std::string>());

    if(vecNames == vecIncrease)
    {
        std::cout << "INCREASING";
    }
    else if(vecNames == vecDecrease)
    {
        std::cout << "DECREASING";
    }
    else
    {
        std::cout << "NEITHER";
    }
    
}