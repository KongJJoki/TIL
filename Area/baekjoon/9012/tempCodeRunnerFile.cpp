#include <iostream>
#include <string>
#include <stack>

int main()
{
    int nT{};
    std::cin >> nT;

    for(int i = 0; i < nT; i++)
    {
        std::stack<char> stcVPS{};
        std::string strBracket{};
        std::cin >> strBracket;
        for(int j = 0; j < strBracket.length(); j++)
        {
            if(strBracket[j]=='(')
            {
                stcVPS.push('(');
            }
            else
            {
                stcVPS.pop();
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