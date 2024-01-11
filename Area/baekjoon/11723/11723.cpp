#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nM{};
    bool arrNum[20] {};

    std::cin >> nM;

    for(int i = 0; i < nM; i++)
    {
        std::string strTmp{};
        std::cin >> strTmp;

        if(strTmp == "all")
        {
            for(int j = 0; j <20; j++)
            {
                arrNum[j] = true;
            }
        }
        else if(strTmp == "empty")
        {
            for(int j = 0; j <20; j++)
            {
                arrNum[j] = false;
            }
        }
        else if(strTmp == "add")
        {
            int nX{};
            std::cin >> nX;
            arrNum[nX-1] = true; // 해당 숫자의 인덱스에 가서 있다고 체크 -> bool 배열을 집합처럼 이용하기
        }
        else if(strTmp == "remove")
        {
            int nX{};
            std::cin >> nX;
            arrNum[nX-1] = false; // 해당 숫자의 인덱스에 가서 없앤다고 체크
        }
        else if(strTmp == "check")
        {
            int nX{};
            std::cin >> nX;
            if(arrNum[nX-1])
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else if(strTmp == "toggle")
        {
            int nX{};
            std::cin >> nX;
            if(arrNum[nX-1]) // 있으면
            {
                arrNum[nX-1] = false; // 제거
            }
            else // 없으면
            {
                arrNum[nX-1] = true; // 추가
            }
        }
    }
}