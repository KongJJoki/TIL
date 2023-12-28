#include <iostream>
#include <vector>

bool arVisited[100001]{};
std::vector<int> vecTree[100001]{};
int arParent[100001]{};

void DFS(int nStart);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int nN{};

    std::cin >> nN;

    for(int i = 0; i < nN-1; i++)
    {
        int nTmp1{};
        int nTmp2{};

        std::cin >> nTmp1;
        std::cin >> nTmp2;

        vecTree[nTmp1].push_back(nTmp2);
        vecTree[nTmp2].push_back(nTmp1);
    }

    DFS(1);

    for(int i = 2; i <= nN; i++)
    {
        std::cout << arParent[i] << '\n';
    }
}

void DFS(int nStart)
{
    arVisited[nStart] = true; // 지금 방문하니까 방문리스트에 참으로 바꾸기

    for(int i = 0; i < vecTree[nStart].size(); i++) // 트리가 맵이라서 맵의 맨 앞 key인 1부터 마지막 key인 트리사이즈+1 까지 순회
    {
        int nTmp{};
        nTmp = vecTree[nStart][i];

        if(!arVisited[nTmp])
        {
            arParent[nTmp] = nStart;
            DFS(nTmp);
        }
    }
}