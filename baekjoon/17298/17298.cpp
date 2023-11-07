#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arrInput[1000001]{};
    int arrNGE[1000001]{};
    std::stack<int> stcTmp{};

    int nArrLength{};

    std::cin >> nArrLength;

    for (int i = 0; i < nArrLength; i++)
    {
        std::cin >> arrInput[i];
    }

    for (int i = nArrLength - 1; i > -1; i--) // 뒤에서부터 검사하기
    {
        while (!stcTmp.empty() && stcTmp.top() <= arrInput[i])
        {
            stcTmp.pop();
        }
        if (stcTmp.empty())
        {
            arrInput[i] = -1;
        }
        else
        {
            arrInput[i] = stcTmp.top();
        }
        stcTmp.push(arrInput[i]);
    }

    for (int i = 0; i < nArrLength; i++)
    {
        std::cout << arrInput[i] << ' ';
    }
}