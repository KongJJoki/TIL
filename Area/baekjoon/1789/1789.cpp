#include <iostream>

int main()
{
    long long nS{};
    int nResult{};
    int nPivot{};
    std::cin >> nS;
    nPivot = 1;

    while (nS > 0)
    {
        nS -= nPivot;

        if (nS < 0)
        {
            break;
        }
        else
        {
            nPivot++;
            nResult++;
        }
    }

    std::cout << nResult;
}