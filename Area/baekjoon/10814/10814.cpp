#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool Compare(std::pair<int,std::string> pairOne, std::pair<int,std::string> pairTwo);

int main()
{
    int nN{};

    std::vector<std::pair<int,std::string>> vecTmp{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::string strTmp{};
        std::pair<int,std::string> pairTmp{};

        std::cin >> nTmp;
        std::cin >> strTmp;

        pairTmp.first = nTmp;
        pairTmp.second = strTmp;

        vecTmp.push_back(pairTmp);
    }

    std::stable_sort(vecTmp.begin(), vecTmp.end(), Compare);

    for(int i = 0; i < nN; i++)
    {
        std::cout << vecTmp[i].first << ' ' << vecTmp[i].second << '\n';
    }

}

bool Compare(std::pair<int,std::string> pairOne, std::pair<int,std::string> pairTwo)
{
    return pairOne.first < pairTwo.first;
}