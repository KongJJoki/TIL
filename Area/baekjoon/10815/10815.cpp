#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::map<int,int> mapCard{};
    int nN{};
    int nM{};

    std::cin >> nN;
    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        mapCard[nTmp] = 1;
    }

    std::cin >> nM;
    for(int i = 0; i < nM; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        if(mapCard[nTmp])
        {
            std::cout << mapCard[nTmp] << ' ';
        }
        else
        {
            std::cout << 0 << ' ';
        }
    }
}