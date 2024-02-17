#include <iostream>

int main()
{
    int nTotal{};
    for(int i = 0; i < 5; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        if(nTmp < 40)
        {
            nTmp = 40;
        }
        nTotal += nTmp;
    }

    std::cout << nTotal / 5;
}