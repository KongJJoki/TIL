#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool ComparePair(std::pair<int,int> pair1, std::pair<int,int> pair2);
void SortMap(std::map<int,int>& map);

std::map<int,int> mapIndex{}; // 숫자들 들어온 인덱스 따로 저장해서 앞이 숫자 뒤에가 들어온 순서로 해서 count 같으면 들어온 순서로 비교할라고 map 선언, compare 안에서 사용해야 해서 어쩔수 없이 전역변수로..

int main()
{
    int nN{};
    int nC{};
    std::map<int,int> mapNumbers{};

    std::cin >> nN;
    std::cin >> nC;

    for(int i = 0;i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        mapNumbers[nTmp]++; // 1이 들어오면 인덱스 0에 ++ 해야하니까 인덱스에는 - 1 해주기
        if(mapIndex[nTmp] == 0) // 들어온 숫자에 대한 인덱스 맵이 0 = 처음 들어온 숫자
        {
            mapIndex[nTmp] = i + 1; // 이 숫자는 몇 번째로 들어온거야! 하고 표시해주기
        }
    }

    SortMap(mapNumbers);
}

bool ComparePair(std::pair<int,int> pair1, std::pair<int,int> pair2)
{
    if(pair1.second == pair2.second)
    {
        return mapIndex[pair1.first] < mapIndex[pair2.first]; // 만약 count가 같으면 들어온 순서 지키기
    }

    return pair1.second > pair2.second;
}

void SortMap(std::map<int,int>& map)
{
    std::vector<std::pair<int,int>> vecTmp{};
    std::map<int,int>::iterator iter{};
    int nLength{};

    for(iter = map.begin(); iter != map.end(); iter++)
    {
        std::pair<int,int> tmpPair{};
        tmpPair.first = iter->first;
        tmpPair.second = iter->second;
        vecTmp.push_back(tmpPair);
        nLength++;
    }

    std::sort(vecTmp.begin(),vecTmp.end(),ComparePair);

    for(int i = 0; i < nLength; i++)
    {
        int nA{};
        int nB{};
        nA = vecTmp[i].first;
        nB = vecTmp[i].second;

        for(int i = 0; i < nB; i++)
        {
            std::cout << nA << ' ';
        }
    }
}