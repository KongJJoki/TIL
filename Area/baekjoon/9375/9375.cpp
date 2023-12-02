#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    int nTestCase{};
    std::vector<int> vecResult{};

    std::cin >> nTestCase;

    for (int i = 0; i < nTestCase; i++)
    {
        int nClothCount{};
        int nTypeCount{};
        int nResult{};

        nResult = 1;
        std::map<std::string, int> mapCloth{};

        std::cin >> nClothCount;

        for (int j = 0; j < nClothCount; j++)
        {
            std::string strTmpCloth{};
            std::string strTmpType{};

            std::cin >> strTmpCloth;
            std::cin >> strTmpType;

            if (mapCloth.find(strTmpType) != mapCloth.end()) // 이미 있는 옷 종류인 경우
            {
                mapCloth[strTmpType]++;
            }
            else // 없는 옷 종류일 경우
            {
                mapCloth[strTmpType] = 1;
                nTypeCount++;
            }
        }

        for (std::map<std::string, int>::iterator j = mapCloth.begin(); j != mapCloth.end(); j++)
        {
            nResult *= (j->second + 1);
        }

        vecResult.push_back(nResult - 1);
    }

    for (int i = 0; i < vecResult.size(); i++)
    {
        std::cout << vecResult[i] << '\n';
    }
}