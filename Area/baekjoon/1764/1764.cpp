#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int nN{};
    int nM{};
    int nResultSize{};
    std::vector<std::string> vecNoListen{};
    std::vector<std::string> vecNoSee{};
    std::vector<std::string> vecResult{};
    std::vector<std::string>::iterator iter{};

    std::cin >> nN;
    std::cin >> nM;

    for(int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        vecNoListen.push_back(strTmp);
    }
    for(int i = 0; i < nM; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        vecNoSee.push_back(strTmp);
    }
    std::sort(vecNoListen.begin(), vecNoListen.end());
    std::sort(vecNoSee.begin(), vecNoSee.end());

    vecResult.resize(nN+nM);
    iter = std::set_intersection(vecNoListen.begin(),vecNoListen.end(),vecNoSee.begin(),vecNoSee.end(),vecResult.begin());
    vecResult.resize(iter - vecResult.begin());

    nResultSize = vecResult.size();
    std::sort(vecResult.begin(),vecResult.end());

    std::cout << nResultSize << '\n';
    for(int i = 0; i < nResultSize; i++)
    {
        std::cout << vecResult[i] << '\n';
    }
}