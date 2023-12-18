#include <iostream>
#include <deque>
#include <string>

int main()
{
    int nN{};
    std::deque<int> deqNum{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        if(strTmp == "push_front")
        {
            int nTmp{};
            std::cin >> nTmp;
            deqNum.push_front(nTmp);
        }
        else if(strTmp == "push_back")
        {
            int nTmp{};
            std::cin >> nTmp;
            deqNum.push_back(nTmp);
        }
        else if(strTmp == "pop_front")
        {
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                int nTmpPop{};
                nTmpPop = deqNum.front();
                deqNum.pop_front();
                std::cout << nTmpPop << '\n';
            }
        }
        else if(strTmp == "pop_back")
        {
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                int nTmpPop{};
                nTmpPop = deqNum.back();
                deqNum.pop_back();
                std::cout << nTmpPop << '\n';
            }
        }
        else if(strTmp == "size")
        {
            std::cout << deqNum.size() << '\n';
        }
        else if(strTmp == "empty")
        {
            if(deqNum.empty())
            {
                std::cout <<  1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else if(strTmp == "front")
        {
            if(deqNum.empty())
            {
                std::cout <<  -1 << '\n';
            }
            else
            {
                std::cout << deqNum.front() << '\n';
            }
        }
        else if(strTmp == "back")
        {
            if(deqNum.empty())
            {
                std::cout <<  -1 << '\n';
            }
            else
            {
                std::cout << deqNum.back() << '\n';
            }
        }
    }
}