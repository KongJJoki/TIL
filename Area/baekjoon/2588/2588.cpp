#include <stdio.h>

int main()
{
	int nNumber1{};
	int nNumber2{};
	int nNumber3{};
	int nNumber4{};
	int nNumber5{};
	int nNumber6{};

	int nNum2One{};
	int nNum2Ten{};
	int nNum2Hun{};

	scanf_s("%d", &nNumber1);
	scanf_s("%d", &nNumber2);

	nNum2One = nNumber2 % 10;
	nNum2Ten = ((nNumber2 % 100) - nNum2One) / 10;
	nNum2Hun = nNumber2 / 100;

	nNumber3 = nNum2One * nNumber1;
	nNumber4 = nNum2Ten * nNumber1;
	nNumber5 = nNum2Hun * nNumber1;
	nNumber6 = nNumber3 + (nNumber4 * 10) + (nNumber5 * 100);

	printf("%d\n%d\n%d\n%d", nNumber3, nNumber4, nNumber5, nNumber6);
}