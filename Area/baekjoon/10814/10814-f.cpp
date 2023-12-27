#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

bool CompareMap(std::pair<std::string, int>& pairOne, std::pair<std::string, int>& pairTwo);

std::map<std::string,int> mapIndex{};

int main()
{
    int nN{};
    int nCount{};
    std::map<std::string, int> mapUser{};
    std::vector<std::pair<std::string, int>> vecTmp{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::string strTmp{};

        std::cin >> nTmp;
        std::cin >> strTmp;

        mapUser[strTmp] = nTmp;
        mapIndex[strTmp] = i; 
    }

    std::map<std::string, int>::iterator iter{};

    for(iter = mapUser.begin(); iter != mapUser.end(); iter++)
    {
        std::pair<std::string, int> tmpPair{};
        tmpPair.first = iter->first;
        tmpPair.second = iter->second;
        vecTmp.push_back(tmpPair);
        nCount++;
    }

    std::sort(vecTmp.begin(), vecTmp.end(), CompareMap);

    for(int i = 0; i < nCount; i++)
    {
        std::cout << vecTmp[i].second << ' ' << vecTmp[i].first << '\n';
    }

}

bool CompareMap(std::pair<std::string, int>& pairOne, std::pair<std::string, int>& pairTwo)
{
    if(pairOne.second != pairTwo.second)
    {
        return pairOne.second < pairTwo.second;
    }

    int nTmp1{};
    int nTmp2{};

    nTmp1 = mapIndex[pairOne.first];
    nTmp2 = mapIndex[pairTwo.first];

    return nTmp1 < nTmp2;
}