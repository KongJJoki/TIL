#include <iostream>

int main()
{
    int nTmp{};

    std::cin >> nTmp;

    for (int i = 1; i < 10; i++)
    {
        std::cout << nTmp << " * " << i << " = " << nTmp * i << '\n';
    }
}