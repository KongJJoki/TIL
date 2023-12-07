#include <iostream>
#include <string>
#include <stack>

int main()
{
    int nT{};
    std::cin >> nT;

    for(int i = 0; i < nT; i++)
    {
        int nStrLen{};
        bool isOne{};
        std::stack<char> stcVPS{};
        std::string strBracket{};

        std::cin >> strBracket;

        nStrLen = strBracket.length();

        for(int j = 0; j < nStrLen; j++)
        {
            if(strBracket[j]=='(')
            {
                stcVPS.push('(');
            }
            else if(strBracket[j]==')')
            {
                if(!stcVPS.empty() && stcVPS.top()=='(')
                {
                    stcVPS.pop();
                }
                else
                {
                    stcVPS.push(')');
                }
            }
        }

        if (stcVPS.empty())
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}