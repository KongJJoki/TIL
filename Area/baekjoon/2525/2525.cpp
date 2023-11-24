#include <iostream>

int main()
{
    int nHour{};
    int nMinute{};
    int nTime{};

    std::cin >> nHour;
    std::cin >> nMinute;
    std::cin >> nTime;

    nMinute += nTime;

    while (nMinute >= 60)
    {
        nMinute -= 60;
        nHour++;
    }

    while (nHour >= 24)
    {
        nHour -= 24;
    }

    std::cout << nHour << ' ' << nMinute;
}