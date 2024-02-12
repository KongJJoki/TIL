#include <iostream>
#include <vector>

int gcd(int nA, int nB);
int Kying(int nM, int nN, int nX, int nY);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nT{};

    std::cin >> nT;

    for (int i = 0; i < nT; i++)
    {
        int nM{};
        int nN{};
        int nX{};
        int nY{};
        std::cin >> nM;
        std::cin >> nN;
        std::cin >> nX;
        std::cin >> nY;

        std::cout << Kying(nM, nN, nX, nY) << '\n';
    }
}

int gcd(int nA, int nB)
{
    while (nB != 0)
    {
        int nR = nA % nB;
        nA = nB;
        nB = nR;
    }

    return nA;
}

int Kying(int nM, int nN, int nX, int nY)
{
    bool isExist{};
    int nResult{};
    int nMax{};
    nMax = (nM * nN) / gcd(nM, nN); // 유클리드 호제법?으로 최대 공약수 구하기 마지막 해가 최대 공약수번째 해임

    nResult = nX; // 10 12 3 9 라고 치면 3에 맞추기 위해서 3번째 해, 13번째 해, 23번째 해... 확인

    while (nResult <= nMax) // 내가 확인하려는 해가 마지막 해 전까지만 확인
    {
        if (nResult % nN == nY) // 내가 확인하려는 해의 오른쪽 숫자가 원하는 nY가 맞는지 확인(n번째 해의 오른쪽 숫자 = n % nN 이기 때문)
        {
            isExist = true;
            break;
        }
        else if(nResult % nN == 0 && nN == nY) // 만약 오른쪽 숫자가 정확히 nN 이여 버리면 나눠도 0 이 되니까 나머지가 0이면 혹시 nN = nY인지 확인
        {
            isExist = true;
            break;
        }
        
        nResult += nM; // 3번째 해 아니였으면 13번째 해 확인하려고 + 하기
    }

    if (isExist)
    {
        return nResult;
    }
    else
    {
        return -1;
    }
}