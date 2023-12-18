#include <iostream>
#include <queue>
#include <string>

int main()
{
    int nN{};
    std::queue<int> queNum{};

    std::cin >> nN;
    for(int i =0; i < nN; i++)
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
                std::cout << -1 << '\n';
            }
            else
            {
                int nTmpPop{};
                nTmpPop = queNum.front();
                queNum.pop();
                std::cout << nTmpPop << '\n';
            }
        }
        else if(strTmp == "size")
        {
            std::cout << queNum.size() << '\n';
        }
        else if(strTmp == "empty")
        {
            if(queNum.empty()==true)
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else if(strTmp == "front")
        {
            if(queNum.empty()==true)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << queNum.front() << '\n';
            }
        }
        else if(strTmp == "back")
        {
            if(queNum.empty()==true)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << queNum.back() << '\n';
            }
        }
    }
}