#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int nTestCase{};
    std::vector<int> vecResult{};
    std::cin >> nTestCase;
    
    for(int i = 0; i < nTestCase; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecResult.push_back(nTmp);
    }

    std::sort(vecResult.begin(), vecResult.end());

    for(int i = 0; i < nTestCase; i++)
    {
        std::cout << vecResult[i] << '\n';
    }
}