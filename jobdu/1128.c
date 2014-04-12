#include<stdio.h>

int
main ()
{
	int n, i, sum, age;

	while (scanf ("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 0; i < n; ++i)
		{
			scanf ("%d", &age);
			sum += age;
		}
		printf ("%.2f\n", (double) sum / (double) n);
	}
	return 0;
}
