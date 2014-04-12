#include<stdio.h>

int
main ()
{
	int m, n, level, k, temp, start, end;

	while (scanf ("%d %d", &m, &n) != EOF && m | n)
	{
		level = k = 1;
		temp = m;
		while ((temp *= 2) <= n)
			level++;
		temp = level;
		while (--temp > 0)
			k *= 2;				/* k-1 elements on level-1 levels */
		//printf ("k=%d, n=%d, m=%d\n", k, n, m);
		start = m * k;
		end = m;
		temp = level;
		while (--temp > 0)
			end = end * 2 + 1;
		if (n < start)
			printf ("%d\n", k - 1);
		else if (n >= start && n <= end)
			printf ("%d\n", k + n - start);
		else
			printf ("%d\n", k + end - start);
	}
	return 0;
}
