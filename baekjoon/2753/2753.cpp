#include <stdio.h>

int main()
{
	int nYear{};
	bool bYoon{};
	bool bYear4{};
	bool bYear100{};
	bool bYear400{};

	bYoon = false;
	scanf_s("%d", &nYear);
	while (nYear < 1 || nYear >4000)
	{
		scanf_s("%d", &nYear);
	}

	if (nYear % 4 == 0)
	{
		bYear4 = true;
	}
	if (nYear % 100 == 0)
	{
		bYear100 = true;
	}
	if (nYear % 400 == 0)
	{
		bYear400 = true;
	}

	if (bYear400)
	{
		bYoon = true;
	}
	else if (bYear4 && !bYear100)
	{
		bYoon = true;
	}

	printf("%d", bYoon);
}