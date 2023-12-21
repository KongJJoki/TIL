#include <iostream>
#include <vector>

int main()
{
    int nN{};
    std::vector<int> vecTower{};
    std::vector<int> vecResult{};

    std::cin >> nN;
    
    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecTower.push_back(nTmp);
        vecResult.push_back(0);
    }

    for(int i = nN-1; i > 0; i--)
    {
        int nNow{};
        nNow = vecTower[i];
        for(int j = i-1; j > -1; j--)
        {
            if(vecTower[j]>nNow)
            {
                vecResult[i] = j + 1;
                break;
            }
        }
    }

    for(int i = 0; i < nN; i++)
    {
        std::cout << vecResult[i] << ' ';
    }
}