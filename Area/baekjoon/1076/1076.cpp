#include <iostream>
#include <map>
#include <string>
#include <cmath>

int main()
{
    std::map<std::string, int> mapNum{};
    std::map<std::string, long> mapMultiply{};
    std::string strTmp[3]{};
    long nResult{};

    mapNum["black"] = 0;
    mapNum["brown"] = 1;
    mapNum["red"] = 2;
    mapNum["orange"] = 3;
    mapNum["yellow"] = 4;
    mapNum["green"] = 5;
    mapNum["blue"] = 6;
    mapNum["violet"] = 7;
    mapNum["grey"] = 8;
    mapNum["white"] = 9;

    std::map<std::string,int>::iterator iter{};
    for(iter = mapNum.begin(); iter != mapNum.end(); iter++)
    {
        mapMultiply[iter->first] = std::pow(10, iter->second);
    }

    for(int i = 0; i < 3; i++)
    {
        std::cin >> strTmp[i];
    }

    nResult = (mapNum[strTmp[0]] * 10 + mapNum[strTmp[1]]) * mapMultiply[strTmp[2]];

    std::cout << nResult;
}