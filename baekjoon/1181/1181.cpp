#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

bool lenCompare(std::string str1, std::string str2);

int main()
{
    int nLength{};
    std::set<std::string> setStr{};

    std::cin >> nLength;

    for (int i = 0; i < nLength; i++)
    {
        std::string tmpStr{};
        std::cin >> tmpStr;
        setStr.insert(tmpStr);
    }

    std::vector<std::string> vecStr(setStr.begin(),setStr.end());
    std::sort(vecStr.begin(), vecStr.end(), lenCompare);

    nLength = vecStr.size();

    for (int i = 0; i < nLength; i++)
    {
        std::cout << vecStr[i] << '\n';
    }
}

bool lenCompare(std::string str1, std::string str2)
{
    if (str1.length() == str2.length())
    {
        return str1 < str2;
    }
    else
    {
        return str1.length() < str2.length();
    }
}