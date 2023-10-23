#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int nScoreNum{};
	float fTmpNewScoreTotal{};
	int nBigScore{};
	float fNewAve{};
	std::vector<float> vScore{};

	scanf_s("%d", &nScoreNum);
	while (nScoreNum < 0 || nScoreNum>1000)
	{
		scanf_s("%d", &nScoreNum);
	}

	for (int i = 0; i < nScoreNum; i++)
	{
		int nTmpScore{};
		scanf_s("%d", &nTmpScore);
		while (nTmpScore < 0 || nTmpScore>100)
		{
			scanf_s("%d", &nTmpScore);
		}
		vScore.push_back(nTmpScore);

		if (nTmpScore > nBigScore)
		{
			nBigScore = nTmpScore;
		}
	}

	for (int i = 0; i < nScoreNum; i++)
	{
		int nTmp{};
		nTmp = vScore[i];
		vScore[i] = (float)nTmp / (float)nBigScore * 100;
		fTmpNewScoreTotal += vScore[i];
	}
	fNewAve = fTmpNewScoreTotal / (float)nScoreNum;
	printf("%f", fNewAve);
}