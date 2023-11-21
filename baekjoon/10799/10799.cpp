#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string strTmp{};
    std::stack<char> stcCh{};
    int nBarCount{};

    std::cin >> strTmp;

    for (int i = 0; i < strTmp.length(); i++)
    {
        if (strTmp[i] == '(')
        {
            stcCh.push('(');
        }
        else
        {
            if (strTmp[i - 1] == '(') // 바로 앞이 ( 면 레이저
            {
                stcCh.pop(); // 일단 레이저의 ( 들어간거 빼주고
                nBarCount += stcCh.size(); // 레이저 나왔으면 아래 있는 막대기들 아무튼 다 잘림 -> 레이저가 지나간 막대기 갯수만큼 잘린 조각이 생긴다
                                           // 즉 지금까지 스택에 들어감 ( 의 수 = 레이저가 지나간 막대의 수니까 스택의 사이즈를 잘린 조각수에 + 해주기
            }
            else // 막대의 끝일때
            {
                stcCh.pop(); // 막대기 끝났으니까 ( 하나 빼주고
                nBarCount++; // 막대기 끝남 -> 막대기 하나가 레이저 2번 만났으면? 일단 조각 2개인데 이제 막대기 끝나면 마지막 부분도 조각이니까 조각 개수 +1
            }
        }
    }

    std::cout << nBarCount;

}