#include <iostream>
#include <vector>

int main()
{
    int nA{};
    int nB{};
    int nC{};
    int nEnter1{};
    int nEnter2{};
    int nEnter3{};
    int nExit1{};
    int nExit2{};
    int nExit3{};
    int nVecLen{};
    int nResult{};
    std::vector<int> vecTime{};

    std::cin >> nA;
    std::cin >> nB;
    std::cin >> nC;

    std::cin >> nEnter1;
    std::cin >> nExit1;

    std::cin >> nEnter2;
    std::cin >> nExit2;

    std::cin >> nEnter3;
    std::cin >> nExit3;

    nVecLen = nExit1;
    
    if(nVecLen < nExit2)
    {
        nVecLen = nExit2;
    }

    if(nVecLen < nExit3)
    {
        nVecLen = nExit3;
    }

    for(int i=0;i<nVecLen;i++)
    {
        vecTime.push_back(0);
    }

    for(int i=nEnter1;i<nExit1;i++)
    {
        vecTime[i]++;
    }

    for(int i=nEnter2;i<nExit2;i++)
    {
        vecTime[i]++;
    }

    for(int i=nEnter3;i<nExit3;i++)
    {
        vecTime[i]++;
    }

    for(int i=1;i<nVecLen;i++)
    {
        if(vecTime[i]==1)
        {
            nResult += nA;
        }
        else if(vecTime[i]==2)
        {
            nResult += nB * 2;
        }
        else if(vecTime[i]==3)
        {
            nResult += nC * 3;
        }
    }

    std::cout << nResult;
}