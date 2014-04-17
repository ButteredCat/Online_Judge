#include<stdio.h>

#define KAPREKAR 6174

int
non_decreasing (int n)
{
	int i, weight, result = 0;
	int digi[10] = { 0 };
	for (i = 0; i < 4; ++i)
	{
		++digi[n % 10];
		n /= 10;
	}
	weight = 1;
	for (i = 9; i >= 0; --i)
	{
		if (digi[i] != 0)
		{
			result += i * weight;
			--digi[i++];
			weight *= 10;
		}
	}
	return result;
}

int
non_increasing (int n)
{
	int i, weight, result = 0;
	int digi[10] = { 0 };
	for (i = 0; i < 4; ++i)
	{
		++digi[n % 10];
		n /= 10;
	}
	weight = 1;
	for (i = 0; i < 10; ++i)
	{
		if (digi[i] != 0)
		{
			result += i * weight;
			--digi[i--];
			weight *= 10;
		}
	}
	return result;
}

int
main (void)
{
	int n, a, b;

	while (scanf ("%d", &n) != EOF)
	{
		do
		{
			a = non_increasing (n);
			b = non_decreasing (n);
			printf ("%.4d - %.4d = %.4d\n", a, b, n = a - b);
		}
		while (n != KAPREKAR && n != 0);
	}
	return 0;
}
