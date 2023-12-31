#include <iostream>
#include <algorithm>

int main()
{
    int nTmp{};
    int nTmpMax{};
    int arNum[3]{};

    for (int i = 0; i < 3; i++)
    {
        std::cin >> arNum[i];
    }
    
    std::sort(arNum, arNum + 3);

    for (int i = 0; i < 3; i++)
    {
        std::cout << arNum[i] << ' ';
    }
}