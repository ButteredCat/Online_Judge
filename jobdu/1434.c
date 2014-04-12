#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int start;
	int end;
} Prog;

static int
cmp (const void *a, const void *b)
{
	return (*(Prog *) a).end - (*(Prog *) b).end;
}

int
main (void)
{
	int n, i, j, c;

	Prog *p;

	while (scanf ("%d", &n) != EOF && n != 0)
	{
		if ((p = (Prog *) malloc (n * sizeof (Prog))) != NULL)
		{
			for (i = 0; i < n; i++)
				scanf ("%d %d", &p[i].start, &p[i].end);

			qsort (p, n, sizeof (p[0]), cmp);

			c = 1;
			for (i = 1, j = 0; i < n; i++)
			{
				if (p[i].start >= p[j].end)
				{
					j = i;
					c++;
				}
			}
			printf ("%d\n", c);
			free (p);
		}
		else
			exit (1);
	}
	return 0;
}
