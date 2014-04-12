#include<stdio.h>
#include<stdlib.h>

static int
cmp (const void *a, const void *b)
{
	return *(int *) a - *(int *) b;
}

int
main ()
{
	int n, i;

	int *p;

	while (scanf ("%d", &n) != EOF && n)
	{
		if ((p = (int *) malloc (n * sizeof (int))) == NULL)
			return -1;
		for (i = 0; i < n; i++)
			scanf ("%d", p + i);
		qsort (p, n, sizeof (int), cmp);

		printf ("%d\n",
				n % 2 ? p[(n - 1) / 2] : (p[n / 2] + p[n / 2 - 1]) / 2);

		free (p);
	}
	return 0;
}
