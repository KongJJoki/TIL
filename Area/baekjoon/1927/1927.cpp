#include <iostream>

int nHeapLength{};
int arrHeap[100001]{};

void HeapPush(int nNum)
{
    int nParentIndex{};
    int nMyIndex{};
    arrHeap[nHeapLength + 1] = nNum; // 힙의 맨 마지막에 일단 변수 넣기 -> 인덱스 0번 안쓰고 1번부터 사용함 0번부터 쓰면 /2로 부모노드 비교가 불가능하기 때문에 편의를 위해서
    nHeapLength++;                   // 힙에 요소 추가했으니까 길이 변수에 +1 하기
    nMyIndex = nHeapLength;          // 내 인덱스는 방금 추가한 자리
    nParentIndex = nMyIndex / 2;     // 부모노드의 인덱스는 무조건 나 / 2 -> 완전이진트리이기 때문

    while (nMyIndex > 1 && arrHeap[nMyIndex] < arrHeap[nParentIndex]) // 부모노드가 루트노드일때까지 비교
    {
        std::swap(arrHeap[nMyIndex], arrHeap[nParentIndex]);
        nMyIndex = nParentIndex;     // 자리 바꿨으니까 현재 내 위치를 아까 부모노드의 위치로 바꿔주고
        nParentIndex = nMyIndex / 2; // 새로운 내 부모노드는 내 인덱스 / 2 해주기
    }
}

void HeapPop()
{
    if (nHeapLength == 0)
    {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << arrHeap[1] << '\n';

    arrHeap[1] = arrHeap[nHeapLength]; // 맨 위의 값을 팝할거니까 출력한 뒤에 맨 아래 값으로 바꿔버리기
    nHeapLength--;                     // 팝했으니까 길이 -1

    int nMyIndex{};
    int nChildIndex{};
    nMyIndex = 1;
    nChildIndex = 2;

    while (nChildIndex <= nHeapLength)
    {
        if ((nChildIndex + 1) <= nHeapLength && arrHeap[nChildIndex] > arrHeap[nChildIndex + 1]) // 오른쪽 자식이랑 왼쪽 자식 비교해서 더 작은걸 선택하기
        {
            nChildIndex++;
        }

        if(arrHeap[nMyIndex] > arrHeap[nChildIndex])
        {
            std::swap(arrHeap[nMyIndex], arrHeap[nChildIndex]);
            nMyIndex = nChildIndex;
            nChildIndex = nMyIndex * 2;
        }
        else
        {
            break;
        }
    }

    // int nMyIndex{};
    // int nLeftChildIndex{};
    // int nRightChildIndex{};

    // nMyIndex = 1;
    // nLeftChildIndex = 2;
    // nRightChildIndex = 3;

    // while(nLeftChildIndex <= nHeapLength)
    // {
    //     int nNext{};
    //     if(nRightChildIndex <= nHeapLength && arrHeap[nLeftChildIndex] > arrHeap[nRightChildIndex]) // 오른쪽 자식이 왼쪽보다 작은경우
    //     {
    //         nNext = nRightChildIndex;
    //     }
    //     else
    //     {
    //         nNext = nLeftChildIndex;
    //     }

    //     if(arrHeap[nMyIndex] > arrHeap[nNext]) // 내가 내 자식보다 큰 경우
    //     {
    //         std::swap(arrHeap[nMyIndex], arrHeap[nNext]);
    //         nMyIndex = nNext;
    //         nLeftChildIndex = nMyIndex * 2;
    //         nRightChildIndex = nLeftChildIndex + 1;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
}

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int nN{};
    std::cin >> nN;

    for (int i = 0; i < nN; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        if (nTmp == 0)
        {
            HeapPop();
        }
        else
        {
            HeapPush(nTmp);
        }
    }
}
