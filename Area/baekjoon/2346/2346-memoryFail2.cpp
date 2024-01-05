#include <iostream>
#include <deque>

std::deque<std::pair<int,int>> deqTmp{};

void RotateDequePlus(int nCount);
void RotateDequeMinus(int nCount);

int main()
{
    int nN{};
    std::deque<std::pair<int,int>> deqNum{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        deqNum.push_back(std::make_pair(i + 1, nTmp)); // 내가 몇번째 풍선인지, 내 안에 숫자 뭔지 덱에 추가
    }

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        nTmp = deqNum[0].second; // 터트릴 풍선 안의 값 미리 저장하기 / 무조건 맨 앞 풍선이 터트릴 풍선임! 지금 덱을 돌려서 찾고있으니까
        deqTmp = deqNum; // 돌릴 때 쓸 임시 덱에 원본 덱 복사해서 넣기
        std::cout << deqNum[0].first << '\n'; // 터트릴 풍선의 인덱스 출력
        deqTmp.pop_front(); // 풍선 터트리기
        if(nTmp > 0)
        {
            RotateDequePlus(nTmp);
            deqNum = deqTmp;
        }
        else
        {
            RotateDequeMinus(nTmp);
            deqNum = deqTmp;
        }
    }
}

void RotateDequePlus(int nCount)
{
    for(int i = 0; i < nCount-1; i++)
    {
        std::pair<int,int> pairTmp{};
        pairTmp = deqTmp.front();
        deqTmp.pop_front();
        deqTmp.push_back(pairTmp);
    }
}
void RotateDequeMinus(int nCount)
{
    int nTmp{};
    nTmp = std::abs(nCount);

    for(int i = 0; i < nTmp; i++)
    {
        std::pair<int,int> pairTmp{};
        pairTmp = deqTmp.back();
        deqTmp.pop_back();
        deqTmp.push_front(pairTmp);
    }
}