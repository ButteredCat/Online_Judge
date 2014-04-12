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
	int i, n;

	int *p;

	while (scanf ("%d", &n) != EOF)
	{
		if ((p = (int *) malloc (n * sizeof (int))) != NULL)
		{
			for (i = 0; i < n; i++)
				scanf ("%d ", p + i);
			if (n == 1)
			{
				printf ("%d\n%d\n", p[0], -1);
			}
			else
			{
				qsort (p, n, sizeof (int), cmp);

				printf ("%d\n", p[n - 1]);

				for (i = 0; i < n - 2; i++)
					printf ("%d ", p[i]);
				printf ("%d\n", p[i]);
			}
		}
		/* free! memory leaks otherwise */
		free (p);
	}
	/* do not free here, or you may free an un-malloced memory */
	return 0;
}
