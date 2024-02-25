#include <iostream>

int main()
{
    int nYoung{};
    int nSecond{};

    std::cin >> nYoung;
    std::cin >> nSecond;

    std::cout << nSecond + (nSecond - nYoung);
}