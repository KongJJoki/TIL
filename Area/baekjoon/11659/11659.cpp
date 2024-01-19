#include <iostream>

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int arrSum[100000]{};

    int nN{};
    int nM{};

    std::cin >> nN;
    std::cin >> nM;

    std::cin >> arrSum[0]; // 첫 값은 무조건 인덱스 0에 자기 자신값

    for(int i = 1; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        arrSum[i] = arrSum[i-1] + nTmp; // 누적합 배열로 만들기 인덱스 1에는 0 + 자기 값 , 2에는 0 + 1 + 자기값이니까 바로 앞의 인덱스 1 값 + 자기 값
    }

    for(int i = 0; i < nM; i++)
    {
        int nI{};
        int nJ{};
        std::cin >> nI;
        std::cin >> nJ;
        
        if(nI == 1)
        {
            std::cout << arrSum[nJ - 1] << '\n';
        }
        else
        {
            std::cout << arrSum[nJ - 1] - arrSum[nI - 2] << '\n';
        }
    }

}