#include <iostream>

int main()
{
    int nN{};
    int nM{};

    std::cin >> nN;
    std::cin >> nM;

    nN *= 100;

    if (nN >= nM)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
}