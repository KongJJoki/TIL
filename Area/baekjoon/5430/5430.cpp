#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

void ToArray(std::string strTmp, std::deque<std::string>& deqArray);
void StartFunc(std::string strFunc, std::deque<std::string>& deqArray, bool* bError);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nCaseCount{};
    std::cin >> nCaseCount;

    for (int i = 0; i < nCaseCount; i++)
    {
        std::string strFunc{};
        int nArrayLength{};
        std::string strTmp{};
        std::deque<std::string> deqArray{};
        bool bError{};
        bError = false;

        std::cin >> strFunc;
        std::cin >> nArrayLength;
        std::cin >> strTmp;

        ToArray(strTmp, deqArray);
        StartFunc(strFunc, deqArray, &bError);
        if (bError)
        {
            std::cout << "error" << '\n';
        }
        else
        {
            std::cout << "[";
            if (!deqArray.empty())
            {
                for (int j = 0; j < deqArray.size() - 1; j++)
                {
                    std::cout << deqArray[j] << ',';
                }
                std::cout << deqArray[deqArray.size() - 1] << ']' << '\n';
            }
            else
            {
                std::cout << ']' << '\n';
            }
        }
    }

}

void ToArray(std::string strTmp, std::deque<std::string>& deqArray)
{
    std::string str{};
    for (int i = 0; i < strTmp.length(); i++)
    {
        if (strTmp[i] == ',' || strTmp[i] == ']')
        {
            if (str != "")
            {
                deqArray.push_back(str);
                str = "";
            }
        }
        else if (strTmp[i] == '[')
        {
            
        }
        else
        {
            str += strTmp[i];
        }
    }
}

void StartFunc(std::string strFunc, std::deque<std::string>& deqArray, bool* bError)
{
    bool bReverse{};
    bReverse = false;

    for (int i = 0; i < strFunc.length(); i++)
    {
        if (strFunc[i] == 'R') // 뒤집기
        {
            bReverse = !bReverse;
        }
        else if (strFunc[i] == 'D') // 버리기
        {
            if (deqArray.empty()) // 배열이 빈 경우
            {
                *bError = true;
                return;
            }
            else if(bReverse)
            {
                deqArray.pop_back();
            }
            else if (!bReverse)
            {
                deqArray.pop_front();
            }
        }
    }
    if (bReverse)
    {
        std::reverse(deqArray.begin(), deqArray.end());
    }
}