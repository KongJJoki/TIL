#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::string strTmp{};
    std::vector<char> vecNum{};

    std::cin >> strTmp;

    for(int i = 0; i < strTmp.length(); i++)
    {
        vecNum.push_back(strTmp[i]);
    }

    std::sort(vecNum.begin(), vecNum.end(),std::greater());

    for(int i = 0; i < vecNum.size(); i++)
    {
        std::cout << vecNum[i];
    }
}