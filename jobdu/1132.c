#include<stdio.h>

const int a[30] = {
	7, 14, 17, 21, 27,
	28, 35, 37, 42, 47,
	49, 56, 57, 63, 67,
	70, 71, 72, 73, 74,
	75, 76, 77, 78, 79,
	84, 87, 91, 97, 98
};

int
main ()
{
	int n, i, sum;
	int b[100] = { 0 };

	for (i = 0; i < 30; ++i)
		b[a[i]] = 1;

	while (scanf ("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 0; i <= n; ++i)
			if (!b[i])
				sum += i * i;
		printf ("%d\n", sum);
	}
	return 0;
}
