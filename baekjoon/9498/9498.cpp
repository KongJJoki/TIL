#include <stdio.h>

int main()
{
	int nScore{};
	int nDivideScore{};
	char cScore{};

	cScore = 'F';

	scanf_s("%d", &nScore);
	while (nScore < 0 || nScore > 100)
	{
		scanf_s("%d", &nScore);
	}

	nDivideScore = nScore / 10;

	if (nDivideScore == 10 || nDivideScore == 9)
	{
		cScore = 'A';
	}
	else if (nDivideScore == 8)
	{
		cScore = 'B';
	}
	else if (nDivideScore == 7)
	{
		cScore = 'C';
	}
	else if (nDivideScore == 6)
	{
		cScore = 'D';
	}
	printf("%c", cScore);
}