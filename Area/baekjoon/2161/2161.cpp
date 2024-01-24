#include <iostream>
#include <queue>

int main()
{
    int nN{};
    int nCardCount{};
    std::queue<int> queCards{};
    std::cin >> nN;

    nCardCount = nN;
    for(int i = 1; i < nN+1; i++)
    {
        queCards.push(i);
    }

    while(nCardCount > 1)
    {
        int nTmp{};
        nTmp = queCards.front();
        queCards.pop();
        int nFront{};
        nFront = queCards.front();
        queCards.push(nFront);
        queCards.pop();
        nCardCount--;
        std::cout << nTmp << ' ';
    }
    std::cout << queCards.front();
}