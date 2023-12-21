#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int nN{};
    std::stack<std::pair<int, int>> stcTower{};
    std::vector<int> vecTower{};
    std::vector<int> vecResult{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        vecResult.push_back(0);
    }

    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        vecTower.push_back(nTmp);
    }

    for (int i = 0; i < nN; i++)
    {
        int nTower{};
        nTower = vecTower[i];

        while (!stcTower.empty())
        {
            if (stcTower.top().second > nTower)
            {
                vecResult[i] = stcTower.top().first;

                std::pair<int, int> pairTmp{};
                pairTmp.first = i + 1;
                pairTmp.second = nTower;
                stcTower.push(pairTmp);
                break;
            }
            stcTower.pop();
        }

        if (stcTower.empty()) // while 문에서 break로 탈출한건지 스택이 비어서 탈출한건지 모르니까 한번 더 스택 비었나 체크
        {
            vecResult[i] = 0; // 만약 비어있으면 앞에 원하는 탑 없으니까 0 으로 해주기
        }

        // 비어있지 않으면 break로 나온거거나 일 다해서 나온거라서 vecResult에 답 넣었을거니까 vecResult는 안건드려도 됌
        // 그냥 현재 탑만 스택에 push 해주기
        std::pair<int, int> pairTmp{};
        pairTmp.first = i + 1;
        pairTmp.second = nTower;
        stcTower.push(pairTmp);
    }

    for (int i = 0; i < nN; i++)
    {
        std::cout << vecResult[i] << ' ';
    }
}