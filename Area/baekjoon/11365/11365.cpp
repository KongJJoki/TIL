#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string strTmp{};

    while (true)
    {
        std::getline(std::cin, strTmp);
        if (strTmp == "END")
        {
            break;
        }

        std::reverse(strTmp.begin(), strTmp.end());

        std::cout << strTmp << '\n';
    }
}