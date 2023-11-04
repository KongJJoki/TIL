#include <iostream>
#include <vector>

int main()
{
    int nInputN{};
    int nCursor{};
    int nRemainNumberStart{};
    int nVecTmpLength{};
    std::vector<int> vecInput{};
    std::vector<int> vecTmp{};
    std::vector<char> vecResult{};

    std::cin >> nInputN;

    for (int i = 0; i < nInputN; i++) // 만들어야하는 수열 입력받기
    {
        int nTmp{};
        std::cin >> nTmp;
        vecInput.push_back(nTmp);
    }

    for (int i = 0; i < vecInput[0]; i++) //input수열의 첫번째 값 가져와서 거기까지 + 하기
    {
        vecTmp.push_back(i + 1);
        vecResult.push_back('+');
        nVecTmpLength++;
    }
    nRemainNumberStart = vecInput[0] + 1; // 첫번째 수까지 + 했으니까 이제 1~n 중 어디부터 숫자 남아있는지 표시
    vecTmp.pop_back(); // 입력수열 첫번째 수 뽑기
    nVecTmpLength--;
    vecResult.push_back('-'); // 뽑았으니까 - 로 표시

    nCursor = 1; // 첫번째 수는 고정이라 앞에서 했으니까 2번째 부터 시작

    while (nCursor <= nInputN - 1) // input수열의 인덱스 1부터 끝까지
    {
        if (vecInput[nCursor] < vecInput[nCursor - 1]) // 이번에 뽑아야할 숫자가 바로 전에 뽑은 숫자보다 작을 때 -> 수열에 이미 들어가 있으니까 찾아서 - 해야함
        {
            int nTmp{};
            nTmp = nVecTmpLength - 1;
            while (vecInput[nCursor] != vecTmp[nTmp]) // Tmp벡터의 맨 끝에서부터 내가 원하는 숫자까지 -- 하면서 찾기
            {
                vecTmp.pop_back();
                vecResult.push_back('-');
                nTmp--;
            }
        }
    }

    for (int i = 0; i < nInputN; i++)
    {
        std::cout << vecResult[i] << '\n';
    }
}