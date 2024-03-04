#include <iostream>

int main()
{
    int nDay{};
    int nResult{};
    int arrCar[5]{};

    std::cin >> nDay;

    for (int i = 0; i < 5; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        arrCar[i] = nTmp;
    }

    for (int i = 0; i < 5; i++)
    {
        if (arrCar[i] % 10 == nDay)
        {
            nResult++;
        }
    }

    std::cout << nResult;
}