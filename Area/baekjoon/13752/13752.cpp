#include <iostream>

int main()
{
    int nN{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nK{};
        std::cin >> nK;
        for(int j = 0; j < nK; j++)
        {
            std::cout << "=";
        }
        std::cout << '\n';
    }
}