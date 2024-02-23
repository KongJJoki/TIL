#include <iostream>

int main()
{
    int nMonth{};
    int nDay{};
    std::cin >> nMonth;
    std::cin >> nDay;

    if(nMonth == 2)
    {
        if(nDay == 18)
        {
            std::cout << "Special";
        }
        else if(nDay > 18)
        {
            std::cout << "After";
        }
        else
        {
            std::cout << "Before";
        }
    }
    else if(nMonth > 2)
    {
        std::cout << "After";
    }
    else
    {
        std::cout << "Before";
    }
}