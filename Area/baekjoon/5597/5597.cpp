#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vecStudents{};

    for(int i = 0; i < 30; i++)
    {
        vecStudents.push_back(0);
    }

    for(int i = 0; i < 28; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecStudents[nTmp-1]++;
    }

    for(int i = 0; i < 30; i++)
    {
        if(vecStudents[i]==0)
        {
            std::cout << i + 1 << '\n';
        }
    }
}