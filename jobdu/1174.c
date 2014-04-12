#include<stdlib.h>
#include<stdio.h>

static int
cmp (const void *a, const void *b)
{
	return *(int *) a - *(int *) b;
}

int
main ()
{
	int i, j, n, k;

	int *p;

	while (scanf ("%d", &n) != EOF)
	{
		if ((p = (int *) malloc (n * sizeof (int))) != NULL)
		{
			for (i = 0; i < n; i++)
				scanf ("%d ", p + i);
			scanf ("%d", &j);

			qsort (p, n, sizeof (int), cmp);

			i = 0;
			k = 1;
			while (k < j)
			{
				if (p[i] != p[i + 1])
					k++;
				i++;
			}
			printf ("%d\n", p[i]);
			free (p);
		}
		else
			exit (1);
	}
	return 0;
}
