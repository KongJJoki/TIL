#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    int nN{};
    int nCount{};
    std::map<std::string, std::string, std::greater<std::string>> mapName{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        std::string tmpName{};
        std::string tmpEL{};

        std::cin >> tmpName;
        std::cin >> tmpEL;

        if (tmpEL == "enter")
        {
            std::pair<std::string, std::string> tmpPair{};
            tmpPair.first = tmpName;
            tmpPair.second = tmpEL;

            mapName.insert(tmpPair);

            nCount++;
        }
        else if (tmpEL == "leave")
        {
            mapName.erase(tmpName);

            nCount--;
        }
    }

    std::map<std::string, std::string, std::greater<std::string>>::iterator iter;
    for (iter = mapName.begin(); iter != mapName.end(); iter++)
    {
        std::cout << iter->first << '\n';
    }
}
