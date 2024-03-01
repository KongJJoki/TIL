#include <iostream>

int main()
{
    while (true)
    {
        int nNum1{};
        int nNum2{};

        std::cin >> nNum1;
        std::cin >> nNum2;

        if (nNum1 == 0 && nNum2 == 0)
        {
            break;
        }

        if (nNum1 > nNum2)
        {
            std::cout << "Yes" << '\n';
        }
        else
        {
            std::cout << "No" << '\n';
        }
    }
}