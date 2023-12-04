#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int nN{};
    int nM{};
    std::vector<std::string> vecPoketmon{};
    std::vector<std::string> vecQuestion{};
    std::vector<std::string> vecAnswer{};
    std::cin >> nN;
    std::cin >> nM;

    for(int i=0;i<nN;i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        vecPoketmon.push_back(strTmp);
    }

    for(int i=0;i<nM;i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;
        vecQuestion.push_back(strTmp);
    }

    for(int i =0;i<nM;i++)
    {
        std::string strTmp{};
        strTmp=vecQuestion[i];
        if(strTmp[0]>57)    // 숫자 아스키코드는 48~57 이니까 이거보다 크면 그냥 string
        {
            int nTmp1{};
            std::string strTmpAnswer1{};
            nTmp1=find(vecPoketmon.begin(),vecPoketmon.end(),strTmp)-vecPoketmon.begin();
            strTmpAnswer1 = std::to_string(nTmp1+1);
            vecAnswer.push_back(strTmpAnswer1);
        }
        else    // 숫자인 경우
        {
            int nTmp2{};
            std::string strTmpAnswer2{};
            nTmp2=stoi(strTmp);
            strTmpAnswer2=vecPoketmon[nTmp2-1];
            vecAnswer.push_back(strTmpAnswer2);
        }
    }

    for(int i =0;i<nM;i++)
    {
        std::cout << vecAnswer[i] << '\n';
    }
}