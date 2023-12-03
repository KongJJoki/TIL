#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nT{};
    std::cin >> nT;

    for (int i = 0; i < nT; i++)
    {
        int nA{};
        int nB{};

        std::cin >> nA;
        std::cin >> nB;

        std::cout << nA + nB << '\n';
    }
}