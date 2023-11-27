#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int nN{};
    int nRmCount{};
    int nTotal{};
    std::deque<int> deqSolved{};

    std::cin >> nN;

    if (nN == 0)
    {
        std::cout << '0';
    }
    else
    {
        nRmCount = std::round((double)nN * 0.15);

        for (int i = 0; i < nN; i++)
        {
            int nTmp{};
            std::cin >> nTmp;
            deqSolved.push_back(nTmp);
        }

        std::sort(deqSolved.begin(), deqSolved.end());

        for (int i = 0; i < nRmCount; i++)
        {
            deqSolved.pop_front();
        }
        for (int i = 0; i < nRmCount; i++)
        {
            deqSolved.pop_back();
        }

        nN -= nRmCount * 2;

        for (int i = 0; i < nN; i++)
        {
            nTotal += deqSolved[i];
        }

        std::cout << std::round((double)nTotal / (double)nN);
    }
}