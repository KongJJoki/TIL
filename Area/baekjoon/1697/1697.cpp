#include <iostream>
#include <queue>

int arVisited[100004] {};

void Bfs(int nN)
{
    std::queue<int> tmpQue{};
    tmpQue.push(nN);
    while(!tmpQue.empty()) // 큐가 비어있지 않은동안 계속 돌리기
    {
        nN = tmpQue.front();
        tmpQue.pop();
        int arTmp[3] = { nN+1, nN-1, nN*2 }; // 숫자 한개에서 나올 수 있는 3가지 경우 +1, -1, *2 를 배열로 만들기
        for(int i = 0; i < 3; i++)
        {
            if(arTmp[i] >=0 && arTmp[i] <= 100000) // 0보다 작거나 10000보다 큰 수는 볼 필요 없음
            {
                if(arVisited[arTmp[i]] == 0) // arTmp[i] 에 해당하는 숫자가 전에 나온적이 없으면
                {
                    tmpQue.push(arTmp[i]); // 큐에 이 숫자 넣기
                    arVisited[arTmp[i]] = arVisited[nN] + 1; // visited 배열에 내가 몇번째 깊이에서 나온 숫자인지 써놓기
                }
            }
        }
    }
}

int main()
{
    int nN{};
    int nK{};

    std::cin >> nN >> nK;
    arVisited[nN] = 1; // 첫 숫자(수빈이의 첫 위치)를 1번째 깊이라고 설정하기 -> 0이라고 하면 Bfs 함수에서 방문한 숫자인지 아닌지 판별을 못하기 때문에 그냥 1로 하기
    Bfs(nN); // 들어온 수빈이 위치로 BFS 돌리기
    std::cout << arVisited[nK] - 1; // 원하는 목적지 k가 몇번째 깊이에서 나온 숫자인지 찾기 -> -1 하는 이유는 첫번째 위치 숫자를 편의를 위해 1로 설정했기 때문에!
}