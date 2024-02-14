#include <iostream>
#include <string>

int main()
{
    std::string strA{};
    std::string strB{};
    std::string strC{};
    std::string strD{};

    long long nAB{};
    long long nCD{};

    std::cin >> strA;
    std::cin >> strB;
    std::cin >> strC;
    std::cin >> strD;

    nAB = std::stoll(strA + strB);
    nCD = std::stoll(strC + strD);

    std::cout << nAB + nCD;
}