#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int nN{};
    std::deque<int> deqNum{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        if(nTmp == 1)
        {
            int nTmpNum{};
            std::cin >> nTmpNum;

            deqNum.push_front(nTmpNum);
        }
        if(nTmp == 2)
        {
            int nTmpNum{};
            std::cin >> nTmpNum;

            deqNum.push_back(nTmpNum);
        }
        if(nTmp == 3)
        {
            int nTmpPop{};
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                nTmpPop = deqNum.front();
                deqNum.pop_front();
                std::cout << nTmpPop << '\n';
            }
        }
        if(nTmp == 4)
        {
            int nTmpPop{};
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                nTmpPop = deqNum.back();
                deqNum.pop_back();
                std::cout << nTmpPop << '\n';
            }
        }
        if(nTmp == 5)
        {
            std::cout << deqNum.size() << '\n';
        }
        if(nTmp == 6)
        {
            if(deqNum.empty())
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        if(nTmp == 7)
        {
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << deqNum.front() << '\n';
            }
        }
        if(nTmp == 8)
        {
            if(deqNum.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << deqNum.back() << '\n';
            }
        }
    }
}