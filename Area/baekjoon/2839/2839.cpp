#include <iostream>

int main()
{
    int nN{};
    int nResult{};

    std::cin >> nN;

    while (nN >= 0)
    {
        if (nN % 5 == 0) // 5로 나누어 떨어지면? 그냥 5kg 주머니로만 들고가기
        {
            nResult += nN / 5;
            nN = 0;
            break;
        }
        else // 5로 안나누어 떨어지면 3씩 빼보기
        {
            nN -= 3;
            nResult++; // 3씩 뺏을때마다 3kg 주머니 하나씩 추가
        }
    }

    if (nN == 0)
    {
        std::cout << nResult;
    }
    else
    {
        std::cout << -1;
    }
}