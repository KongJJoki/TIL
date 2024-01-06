#include <iostream>
#include <string>
#include <vector>

int main()
{
    int nN{};
    std::vector<std::string> vecName{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;
        for (int j = 0; j < strTmp.size(); j++)
        {
            strTmp[j] = std::tolower(strTmp[j]);
        }
        vecName.push_back(strTmp);
    }

    for (int i = 0; i < vecName.size(); i++)
    {
        std::cout << vecName[i] << '\n';
    }
}