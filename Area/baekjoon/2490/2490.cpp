#include <iostream>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int nZeroCount{};
        for (int j = 0; j < 4; j++)
        {
            int nTmp{};
            std::cin >> nTmp;
            if (nTmp == 0)
            {
                nZeroCount++;
            }
        }

        if (nZeroCount == 1)
        {
            std::cout << "A" << '\n';
        }
        else if (nZeroCount == 2)
        {
            std::cout << "B" << '\n';
        }
        else if (nZeroCount == 3)
        {
            std::cout << "C" << '\n';
        }
        else if (nZeroCount == 4)
        {
            std::cout << "D" << '\n';
        }
        else if (nZeroCount == 0)
        {
            std::cout << "E" << '\n';
        }
    }
}