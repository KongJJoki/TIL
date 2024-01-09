#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    int nN{};
    int nNowMax{};
    std::string strResult{};

    std::map<std::string, int> mapBooks{};
    std::map<std::string, int>::iterator iter{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        if (mapBooks[strTmp]) // 이미 맵에 이 책 있으면
        {
            mapBooks[strTmp]++; // 이 책 갯수 1 추가
        }
        else // 맵에 이 책이 없으면
        {
            mapBooks[strTmp] = 1; // 등록하고 1권 있다고 추가
        }
    }

    for (iter = mapBooks.begin(); iter != mapBooks.end(); iter++)
    {
        if (nNowMax < iter->second)
        {
            nNowMax = iter->second;
            strResult = iter->first;
        }
    }

    std::cout << strResult;
}