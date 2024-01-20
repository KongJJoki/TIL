#include <iostream>

int fibonacci(int n);

int main()
{
    int arrDP[41] = {0,1,1};
    for(int i = 3; i < 41; i++)
    {
        arrDP[i] = arrDP[i-1] + arrDP[i-2];
    }

    int nT{};
    std::cin >> nT;

    for(int i = 0; i <nT; i++)
    {
        int nN{};
        std::cin >> nN;
        
        if(nN == 0)
        {
            std::cout << 1 << ' ' << 0 << '\n';
        }
        else if(nN == 1)
        {
            std::cout << 0 << ' ' << 1 << '\n';
        }
        else
        {
            std::cout << arrDP[nN-1] << ' ' << arrDP[nN] << '\n';
        }
    }
}

int fibonacci(int n) 
{
    if (n == 0) 
    {
        std::cout << "0";
        return 0;
    } 
    else if (n == 1) 
    {
        std::cout << "1";
        return 1;
    } 
    else 
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}