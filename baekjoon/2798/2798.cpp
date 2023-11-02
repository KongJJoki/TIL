#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nCount{};
    int nTargetNum{};
    int nThreeTotal{};
    int nResult{};
    std::vector<int> vecNumber{};

    std::cin >> nCount;
    std::cin >> nTargetNum;

    for (int i = 0; i < nCount; i++)
    {
        int nTmp{};
        std::cin >> nTmp;
        vecNumber.push_back(nTmp);
    }

    std::sort(vecNumber.begin(), vecNumber.end());

    for (int i = 0; i < nCount - 2; i++)
    {
		for (int j = i + 1; j < nCount - 1; j++)
        {
			for (int k = j + 1; k < nCount; k++)
            {
                int nTmpTotal{};
                nTmpTotal = vecNumber[i] + vecNumber[j] + vecNumber[k];

                if (nTmpTotal == nTargetNum)
                {
                    nThreeTotal = nTmpTotal;
                }
                else if (nTmpTotal > nThreeTotal && nTmpTotal < nTargetNum)
                {
                    nThreeTotal = nTmpTotal;
                }
            }
        }
    }

    std::cout << nThreeTotal;
}