#include <iostream>

int main()
{
    int nTestCase{};
    int nK{};
    int nN{};
    int arPepleCount[15][15]{};

    for (int i = 0; i < 15; i++)
    {
        arPepleCount[0][i] = i;
    }

    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            arPepleCount[i][j] = arPepleCount[i][j - 1] + arPepleCount[i - 1][j]; // 내 앞 호수 사람 + 내 층 아래 호수 사람  내 앞 호수 사람이 이미 그 아래 층 사람들 자기거까지 쭉 더해놨음!
        }
    }

    std::cin >> nTestCase;

    for (int i = 0; i < nTestCase; i++)
    {
        std::cin >> nK;
        std::cin >> nN;

        std::cout << arPepleCount[nK][nN] << '\n';
    }
}
