#include <iostream>
#include <deque>

int main()
{
    int nN{};
    std::deque<std::pair<int,int>> deqNum{};

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;

        deqNum.push_back(std::make_pair(i+1,nTmp)); // 덱에 페어로 풍선번호, 숫자 넣기
    }
    
    for(int i = 0; i < nN; i++)
    {
        int nNum{};
        nNum = deqNum.front().second;
        std::cout << deqNum.front().first << '\n'; // 터트릴 풍선 번호 출력
        deqNum.pop_front(); // 맨 앞 풍선 터트리기

        if(nNum > 0) // 숫자가 양수일 때 -> 맨 앞 빼서 뒤로 넣기
        {
            for(int j = 0; j < nNum - 1; j++) // 양수일 때는 맨 앞 풍선을 터트리는게 한칸 가는거랑 똑같이 작용해서 한번 덜 돌려야함!!
            {
                deqNum.push_back(deqNum.front());
                deqNum.pop_front();
            }
        }
        else // 숫자가 음수일 때 -> 맨 뒤 빼서 앞에 넣기
        {
            for(int j = 0; j < (-1)*nNum; j++)
            {
                deqNum.push_front(deqNum.back());
                deqNum.pop_back();
            }
        }
    }
}