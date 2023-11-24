#include <iostream>

int main()
{
    int nInputN{};
    int nTotal{};

    std::cin >> nInputN;

    for (int i = 1; i < nInputN + 1; i++)
    {
        nTotal += i;
    }

    std::cout << nTotal;
}