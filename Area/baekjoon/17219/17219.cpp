#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nN{};
    int nM{};
    std::map<std::string, std::string> mapPasswd{};

    std::cin >> nN;
    std::cin >> nM;

    for (int i = 0; i < nN; i++)
    {
        std::string strSite{};
        std::string strPasswd{};

        std::cin >> strSite;
        std::cin >> strPasswd;

        mapPasswd[strSite] = strPasswd;
    }

    for (int j = 0; j < nM; j++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        std::cout << mapPasswd[strTmp] << '\n';
    }
}