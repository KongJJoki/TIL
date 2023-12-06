#include <iostream>

int main()
{
    int nT{};
    std::cin >> nT;

    for(int i=0;i<nT;i++)
    {
        int nA{};
        int nB{};
        std::cin >> nA;
        std::cin >> nB;

        std::cout << "Case #" << i+1 << ": " << nA+nB << '\n';
    }
}