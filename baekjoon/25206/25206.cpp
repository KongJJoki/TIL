#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

int main()
{
    float fScoreTotal{};
    float fGradeScoreTotal{};
    float fResult{};

    std::map<std::string, float> mapGrade{};
    mapGrade = { {"A+",4.5f},{"A0",4.0f}, {"B+",3.5f}, {"B0",3.0f},
        {"C+",2.5f}, {"C0",2.0f},{"D+",1.5f},{"D0",1.0f},{"F",0.0f} };

    for (int i = 0; i < 20; i++)
    {
        std::string strSubject{};
        float fTmpScore{};
        std::string strTmpGrade{};

        std::cin >> strSubject >> fTmpScore >> strTmpGrade;

        if (strTmpGrade != "P")
        {
            fScoreTotal += fTmpScore;
            fGradeScoreTotal += fTmpScore * mapGrade[strTmpGrade];
        }
    }

    fResult = fGradeScoreTotal / fScoreTotal;

    std::cout << fResult;
}