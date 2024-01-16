#include <iostream>
#include <vector>

int main()
{
    int nN{};
    int nK{};
    std::vector<int> vecMeasure{};

    std::cin >> nN;
    std::cin >> nK;

    for(int i = 1; i <= nN; i++)
    {
        if(nN % i == 0)
        {
            vecMeasure.push_back(i);
        }
    }

    if(vecMeasure.size() < nK)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << vecMeasure[nK-1];
    }
}