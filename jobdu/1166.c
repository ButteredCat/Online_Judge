#include<stdio.h>

int
main ()
{
	int n, i;

	double x, res;

	while (scanf ("%lf %d", &x, &n) != EOF)
	{
		res = x;
		for (i = 0; i < n; ++i)
			res = res * 2 / 3 + x / (3 * res * res);
		printf ("%.6lf\n", res);
	}
	return 0;
}
