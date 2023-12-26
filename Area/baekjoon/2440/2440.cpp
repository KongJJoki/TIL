#include <iostream>

int main()
{
    int nN{};
    std::cin >> nN;

    for (int i = nN; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}