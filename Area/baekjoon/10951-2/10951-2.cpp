#include <iostream>

int main()
{
    int nA{};
    int nB{};

    while (std::cin >> nA >> nB)
    {
        std::cout << nA + nB << '\n';
    }
}