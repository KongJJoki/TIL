#include <iostream>
#include <vector>

int main()
{
    int nN{};
    int nCursor{};
    int nPrevNum{};
    std::vector<int> vecBallon{};

    nCursor = 1;

    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecBallon.push_back(nTmp);
    }

    for(int i = 0; i < nN; i++)
    {
        int nNextNum{};
        nNextNum = vecBallon[nCursor-1];

        while(nNextNum == 0)
        {
            if(nPrevNum > 0)
            {
                nCursor++;
                while(nCursor > nN)
                {
                    nCursor -= nN;
                }
                nNextNum = vecBallon[nCursor-1];
            }
            else
            {
                nCursor--;
                while(nCursor < 1)
                {
                    nCursor += nN;
                }
                nNextNum = vecBallon[nCursor-1];
            }
            //std::cout << "현재 번호" << nCursor << ' ';
        }
        
        std::cout << nCursor << '\n'; // 이번에 터트릴 풍선 번호 출력

        vecBallon[nCursor-1] = 0;

        nPrevNum = nNextNum;

        nCursor += nNextNum;
        while(nCursor > nN)
        {
            nCursor -= nN;
        }
        //std::cout << "현재 커서 " << nCursor << '\n';
    }
}