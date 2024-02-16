#include <iostream>

int main()
{
    int nAngle1{};
    int nAngle2{};
    int nAngle3{};
    int nTotal{};

    std::cin >> nAngle1;
    std::cin >> nAngle2;
    std::cin >> nAngle3;

    nTotal = nAngle1 + nAngle2 + nAngle3;

    if(nTotal == 180)
    {
        if(nAngle1 == nAngle2 && nAngle2 == nAngle3)
        {
            std::cout << "Equilateral";
        }
        else if(nAngle1 == nAngle2)
        {
            std::cout << "Isosceles";
        }
        else if(nAngle1 == nAngle3)
        {
            std::cout << "Isosceles";
        }
        else if(nAngle2 == nAngle3)
        {
            std::cout << "Isosceles";
        }
        else
        {
            std::cout << "Scalene";
        }
    }
    else
    {
        std::cout << "Error";
    }
}