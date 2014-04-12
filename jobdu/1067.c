#include<stdio.h>

int
main ()
{
	int n, i;

	long long int result;

	while (scanf ("%d", &n) != EOF)
	{
		result = 1;
		for (i = 1; i <= n; i++)
			result *= i;
		printf ("%lld\n", result);
	}
	return 0;
}
