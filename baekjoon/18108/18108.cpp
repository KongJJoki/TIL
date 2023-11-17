#include <iostream>

int main()
{
    int nInputBulgiYear{};
    int nSeogiYear{};
    int nYeolbanYear{};

    nYeolbanYear = 543;

    std::cin >> nInputBulgiYear;

    nSeogiYear = nInputBulgiYear - nYeolbanYear;

    std::cout << nSeogiYear;
}