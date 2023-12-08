#include <iostream>
#include <string>

bool Is_vowel(char cTmp);
bool CheckString(std::string& strTmp);

int main()
{
    while(true)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        if(strTmp == "end")
        {
            break;
        }
        else
        {
            if(CheckString(strTmp))
            {
                std::cout << '<' << strTmp << "> is acceptable.\n";
            }
            else
            {
                std::cout << '<' << strTmp << "> is not acceptable.\n";
            }
        }
    }
}

bool Is_vowel(char cTmp)
{
    if (cTmp == 'a' || cTmp == 'e' || cTmp == 'i' || cTmp == 'o' || cTmp == 'u')
    {
        return true;
    }
    return false;
}

bool CheckString(std::string& strTmp)
{
    bool isVowel{};
    int nConContinueCount{};
    int nVowContinueCount{};

    isVowel = false;

    for(int i = 0; i < strTmp.length(); i++)
    {
        if(Is_vowel(strTmp[i])) // 문자가 모음일때
        {
            isVowel = true;         // 모음 하나라도 있으면 첫번째 조건 통과
            nVowContinueCount++;    // 연속되는 모음 수 1개 증가
            nConContinueCount = 0;  // 연속되는 자음 수 0개로 초기화
        }
        else // 문자가 자음일때
        {
            nConContinueCount++;    // 연속되는 자음 수 1개 증가
            nVowContinueCount = 0;  // 연속되는 모음 수 0개로 초기화
        }

        if(nConContinueCount >= 3 || nVowContinueCount >=3) // 자음 모음 연속 3개 이상인 조건 거르기
        {
            return false;
        }

        if(i > 0 && strTmp[i-1] == strTmp[i] && !(strTmp[i] == 'e' || strTmp[i] == 'o')) // i가 0일때는 i-1하면 범위 밖이라 오류나니까 빼고 i가 1일때부터 검사, 앞 문자랑 지금 문자랑 같은데(연속되는데) 그 문자가 ee나 oo가 아닌경우 거르기
        {
            return false;
        }
    }
    
    if(!isVowel) // 문자열 다 돌았는데도 모음이 없는 경우
    {
        return false;
    }

    return true;    // 이 모든 조건을 다 통과한 경우만 true
}