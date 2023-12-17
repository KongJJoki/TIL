#include <iostream>

int main()
{
    int nA{};
    int nB{};

    while (true)
    {

        std::cin >> nA;
        std::cin >> nB;

        if (std::cin.eof() == true)
        {
            break;
        }

        std::cout << nA + nB << '\n';
    }
}