#include <iostream>

int main()
{
    int nInputH{};
    int nInputM{};

    std::cin >> nInputH;
    std::cin >> nInputM;

    nInputM -= 45;

    if (nInputM < 0)
    {
        nInputH--;
        nInputM += 60;
    }

    if (nInputH < 0)
    {
        nInputH += 24;
    }

    std::cout << nInputH << ' ' << nInputM;
}