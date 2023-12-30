#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nN{};
    std::stack<int> stcNum{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        if (nTmp == 1) // 정수 X를 스택에 넣는다
        {
            int nNum{};
            std::cin >> nNum;

            stcNum.push(nNum);
        }
        else if (nTmp == 2) // 정수가 있다면 맨위의 정수를 빼고 출력한다 / 없으면 -1 출력
        {
            if (stcNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                int nTmpNum{};
                nTmpNum = stcNum.top();
                stcNum.pop();
                std::cout << nTmpNum << '\n';
            }
        }
        else if (nTmp == 3) // 스택에 들어있는 정수의 개수 출력
        {
            std::cout << stcNum.size() << '\n';
        }
        else if (nTmp == 4) // 비어있으면 1, 아니면 0 출력
        {
            if (stcNum.empty())
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else if(nTmp ==5) // 스택에 정수가 있다면 맨 위의 정수 출력 / 없으면 -1 출력
        {
            if (stcNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << stcNum.top() << '\n';
            }
        }
    }
}