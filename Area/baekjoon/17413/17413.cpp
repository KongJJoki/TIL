#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int nCount{};
    int nVecCount{};
    bool bIsWord{};
    std::string strTest{};
    std::string strTmp{};
    std::vector<std::string> vecResult{};

    std::getline(std::cin, strTest);
    bIsWord = true;
    nCount = strTest.length();

    for (int i = 0; i < nCount; i++)
    {
        char cTmp{};
        cTmp = strTest[i];

        if (bIsWord || cTmp == '>')
        {
            if (cTmp == '<')
            {
                bIsWord = false;
                if(!strTmp.empty())
                {
                    std::reverse(strTmp.begin(), strTmp.end());
                    vecResult.push_back(strTmp);
                    nVecCount++;
                    strTmp.clear();
                }
                vecResult.push_back("<");
                nVecCount++;
            }
            else if (cTmp == '>')
            {
                bIsWord = true;
                vecResult.push_back(">");
                nVecCount++;
            }
            else if (cTmp == ' ')
            {
                std::reverse(strTmp.begin(), strTmp.end());
                vecResult.push_back(strTmp);
                vecResult.push_back(" ");
                nVecCount += 2;
                strTmp.clear();
            }
            else if(i == nCount - 1)
            {
                strTmp.push_back(cTmp);
                std::reverse(strTmp.begin(), strTmp.end());
                vecResult.push_back(strTmp);
                nVecCount++;
            }
            else
            {
                strTmp.push_back(cTmp);
            }
        }
        else
        {
            std::string strChar{};
            strChar = cTmp;
            vecResult.push_back(strChar);
            nVecCount++;
        }
    }

    for(int i = 0; i < nVecCount; i++)
    {
        std::cout << vecResult[i];
    }
}