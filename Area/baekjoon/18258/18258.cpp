#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nN{};
    std::queue<int> queNum{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        if(strTmp == "push")
        {
            int nTmp{};
            std::cin >> nTmp;

            queNum.push(nTmp);
        }
        else if(strTmp == "pop")
        {
            if(queNum.empty())
            {
                std::cout << "-1" << '\n';
            }
            else
            {
                int nFront{};
                nFront = queNum.front();
                queNum.pop();
                std::cout << nFront << '\n';
            }
        }
        else if(strTmp == "size")
        {
            std::cout << queNum.size() << '\n';
        }
        else if(strTmp == "empty")
        {
            if(queNum.empty())
            {
                std::cout << "1" << '\n';
            }
            else
            {
                std::cout << "0" << '\n';
            }
        }
        else if(strTmp == "front")
        {
            if(queNum.empty())
            {
                std::cout << "-1" << '\n';
            }
            else
            {
                std::cout << queNum.front() << '\n';
            }
        }
        else if(strTmp == "back")
        {
            if(queNum.empty())
            {
                std::cout << "-1" << '\n';
            }
            else
            {
                std::cout << queNum.back() << '\n';
            }
        }
    }
}