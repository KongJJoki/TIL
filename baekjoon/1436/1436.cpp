#include <iostream>

int main()
{
    int nNowCount{};
    int nInputN{};
    int nTmp{};
    bool bIs666{};

    std::cin >> nInputN;

    while (nNowCount != nInputN)
    {
        nTmp++;
        while (nTmp != 0 && !bIs666)
        {
            if (nTmp % 1000 == 666)
            {
                nNowCount++;
                bIs666 = true;
            }
            else
            {
                nTmp /= 10;
            }
        }
    }

    std::cout << nTmp;
}