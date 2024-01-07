#include <iostream>
#include <vector>
#include <string>

int main()
{
    int nN{};
    std::vector<std::string> vecName{};
    std::cin >> nN;
    std::cin.ignore();

    for (int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::getline(std::cin, strTmp);
        vecName.push_back(strTmp);
    }

    for (int i = 0; i < nN; i++)
    {
        std::cout << i + 1 << ". " << vecName[i] << '\n';
    }
}