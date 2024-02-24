#include <iostream>
#include <string>

int main()
{
    int nResult{};
    std::string strTest{};

    std::cin >> strTest;
    
    for (int i = 0; i < strTest.length(); i++)
    {
        if (strTest[i] == 'a' || strTest[i] == 'e' || strTest[i] == 'i' || strTest[i] == 'o' || strTest[i] == 'u')
        {
            nResult++;
        }
    }

    std::cout << nResult;
}
