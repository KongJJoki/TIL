#include <iostream>

int main()
{
    int nN1{};
    int nN2{};

    std::cin >> nN1;

    nN2 = nN1 - 1;
    if (nN2 < 0)
    {
        nN2 = 0;
    }

    std::cout << nN1 * nN2;
}