#include <iostream>

int main()
{
    int nInputN{};
    int nRemainder{};
    int nQuotient{};
    int nDivider{};

    std::cin >> nInputN;

    nDivider = 2;

    while (nInputN != 1)
    {
        nRemainder = nInputN % nDivider;
        nQuotient = nInputN / nDivider;

        if (nRemainder == 0)
        {
            while (nInputN % nDivider == 0)
            {
                nInputN /= nDivider;
                std::cout << nDivider << '\n';
            }
        }

        nDivider++;
    }
}