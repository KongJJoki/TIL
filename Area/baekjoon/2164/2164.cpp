#include <iostream>
#include <deque>

int main()
{
    int nN{};
    int nCardCount{};
    std::deque<int> deqCard{};

    std::cin >> nN;
    nCardCount=nN;

    for(int i=0;i<nN;i++)
    {
        deqCard.push_back(i+1);
    }

    while(nCardCount>1)
    {
        int nTmpCard{};

        deqCard.pop_front();    //맨 위에거 버리기
        nCardCount--;           //버렸으니까 카드 갯수 하나 줄이기
        nTmpCard=deqCard[0];    //맨 앞에 카드 저장
        deqCard.pop_front();     //그 다음 맨 위 카드를 잠깐 다른데 저장하고 버리고 나서 맨 뒤에 추가하기
        deqCard.push_back(nTmpCard);
    }

    std::cout << deqCard[0];
}