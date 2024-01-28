#include <iostream>

int Min(int nA, int nB);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int DP[1000001]{}; // 0~1000000까지 선언

    DP[1] = 0; // 1은 연산 안하고도 1이 되니까 0으로 꼭 만들어야함
    DP[2] = 1;
    DP[3] = 1; //  2, 3 은 한번만에 1로 갈수있음

    int nX{};

    std::cin >> nX;

    // nX가 1이 되려면 nX가 3으로 나눠지는 count는 nX / 3이 1이 되는 count에서 추가로 / 3을 한번 한거니까 + 1만 해준 count가 nX가 1이 되는데 걸리는 count
    // 또는 !!! -1 했을 때로 가서 1로 가는 경우가 더 count가 작을 수도 있으니까 비교해서 선택하기
    // 2로 나눠질때도 동일
    // 3으로도 2로도 나눠질때는 더 작은 경우로 가기
    // nX가 2로도 3으로도 나눠지지 않으면 -1 해야하니까 nX-1이 1이 되는 count + 1 이 nX가 1이 되는 count
    for (int i = 4; i <= nX; i++)
    {
        if (i % 2 == 0 && i % 3 ==0) // 2로도 나눠지고 3으로도 나눠질 때
        {
            DP[i] = Min(Min(DP[i / 2] + 1, DP[i / 3] + 1), DP[i - 1] + 1);
        }
        else if (i % 3 == 0) // 3으로만 나눠질 때
        {
            DP[i] = Min(DP[i - 1] + 1, DP[i / 3] + 1);
        }
        else if (i % 2 == 0) // 2로만 나눠질 때
        {
            DP[i] = Min(DP[i - 1] + 1, DP[i / 2] + 1);
        }
        else // 3으로도 2로도 안나눠질때
        {
            DP[i] = DP[i - 1] + 1;
        }
    }

    std::cout << DP[nX];
}

int Min(int nA, int nB)
{
    if (nA > nB)
    {
        return nB;
    }
    return nA;
}