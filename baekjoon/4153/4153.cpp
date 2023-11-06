#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    int arrTriangle[3]{};

    for (int i = 0; i < 3; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        arrTriangle[i] = nTmp;
    }

    while (arrTriangle[0] != 0 || arrTriangle[1] != 0 || arrTriangle[2] != 0)
    {
        std::sort(arrTriangle, arrTriangle+3);
        double nPow1{};
        double nPow2{};
        double nPow3{};

        nPow1 = pow(arrTriangle[0], 2);
        nPow2 = pow(arrTriangle[1], 2);
        nPow3 = pow(arrTriangle[2], 2);

        if (nPow1 + nPow2 == nPow3)
        {
            std::cout << "right" << '\n';
        }
        else
        {
            std::cout << "wrong" << '\n';
        }

        for (int i = 0; i < 3; i++)
        {
            int nTmp{};
            std::cin >> nTmp;
            arrTriangle[i] = nTmp;
        }
    }
}