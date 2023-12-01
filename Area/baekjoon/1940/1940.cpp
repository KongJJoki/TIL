#include <iostream>
#include <vector>

int main()
{
    int nCountN{};
    int nOnlyM{};
    int nResult{};
    int nVecLength{};
    std::vector<int> vecCloth{};

    std::cin >> nCountN;

    std::cin >> nOnlyM;

    for(int i =0;i<nCountN;i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecCloth.push_back(nTmp);
    }

    nVecLength=nCountN;

    while(nVecLength>1)
    {
        bool bFind{};
        bFind=false;
        int nTmp1{};
        nTmp1=vecCloth[0];
        for(int i=1;i<nVecLength;i++)
        {
            if(nTmp1+vecCloth[i]==nOnlyM)
            {
                nResult++;
                vecCloth.erase(vecCloth.begin());
                vecCloth.erase(vecCloth.begin()+i-1);
                nVecLength-=2;
                bFind=true;
                break;
            }
        }
        if(!bFind)
        {
            vecCloth.erase(vecCloth.begin());
            nVecLength--;
        }
    }

    std::cout << nResult;
}