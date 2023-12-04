#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
    int nN{};
    int nM{};
    std::vector<std::string> vecPoketmon{};
    std::map<std::string,int> mapPoketmon{};
    std::vector<std::string> vecAnswer{};

    std::cin >> nN;
    std::cin >> nM;

    for(int i =0;i<nN;i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;
        vecPoketmon.push_back(strTmp);
        mapPoketmon[strTmp]=i+1;
    }

    for(int i=0;i<nM;i++)
    {
        std::string strTmpQuestion{};
        std::cin >> strTmpQuestion;

        if(strTmpQuestion[0]>=65 && strTmpQuestion[0]<=90)  // 아스키코드가 65~90 인경우 = 글자 -> 포켓몬 이름이 주어진 경우
        {
            vecAnswer.push_back(std::to_string(mapPoketmon[strTmpQuestion]));
        }
        else    // 숫자가 주어진경우
        {
            vecAnswer.push_back(vecPoketmon[std::stoi(strTmpQuestion)-1]);
        }
    }

    for(int i=0;i<nM;i++)
    {
        std::cout << vecAnswer[i]<<'\n';
    }
}