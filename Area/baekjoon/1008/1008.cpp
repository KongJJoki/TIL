#include <stdio.h>

int main()
{
	int nNumberA{};
	int nNumberB{};
	double dResult{};

	scanf("%d", &nNumberA);
	while (nNumberA <= 0)
	{
		scanf("%d", &nNumberA);
	}

	scanf("%d", &nNumberB);
	while (nNumberB >= 10)
	{
		scanf("%d", &nNumberB);
	}

	dResult = (double)nNumberA / (double)nNumberB;

	printf("%.10lf", dResult);
}