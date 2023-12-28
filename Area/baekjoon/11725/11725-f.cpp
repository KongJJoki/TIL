#include <iostream>
#include <vector>
#include <map>

int main()
{
    int nN{};
    std::vector<bool> vecExist{};              // 해당 숫자 나왔나 안나왔나 체크하는 용도의 배열
    std::map<int, std::vector<int>> mapTree{}; // 부모 : {자식들} 형태의 맵
    std::vector<int> vecResult{};

    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        vecExist.push_back(false); // 체크용 배열 다 false로 초기화
        vecResult.push_back(0);
    }

    if (nN == 2)
    {
        int nTmp1{};
        int nTmp2{};

        std::cin >> nTmp1;
        std::cin >> nTmp2;
        
        std::cout << 1;
    }
    else
    {
        for (int i = 0; i < nN - 1; i++) // n-1 개의 줄에 정점이 주어진다
        {
            int nTmp1{};
            int nTmp2{};

            std::cin >> nTmp1;
            std::cin >> nTmp2;

            if (vecExist[nTmp2 - 1] == true) // 해당 숫자에 맞는 체크용 배열에 갔는데 이미 true = 전에 나온적 있는 숫자 = nTmp2가 nTmp1에 연결된게 아니고 nTmp1이 nTmp2에 연결되어 있다
            {
                // mapTree[nTmp2].push_back(nTmp1); // nTmp2의 자식으로 nTmp1 연결하기
                vecExist[nTmp1 - 1] = true;
                vecResult[nTmp1 - 1] = nTmp2;
            }
            else if (vecExist[nTmp2 - 1] == false) // 해당 숫자에 맞는 체크용 배열에 갔는데 false = 전에 나온적 없는 숫자 = nTmp2가 nTmp1에 연결되어 있다
            {
                // mapTree[nTmp1].push_back(nTmp2); // nTmp1의 자식으로 nTmp2 연결하기
                vecExist[nTmp1 - 1] = true; // 나왔으니까 체크용 배열에 가서 true로 한번 나왔다고 체크해주기
                vecResult[nTmp2 - 1] = nTmp1;
            }
        }

        for (int i = 1; i < vecResult.size(); i++)
        {
            if (vecResult[i] != 0)
            {
                std::cout << vecResult[i] << '\n';
            }
        }
    }

    // std::map<int,std::vector<int>>::iterator iter;
    // for(iter = mapTree.begin(); iter != mapTree.end(); iter++)
    // {
    //     std::cout << iter->first << ' ';
    //     for(int i = 0; i < iter->second.size(); i++)
    //     {
    //         std::cout << iter->second[i];
    //     }
    //     std::cout << '\n';
    // }
}