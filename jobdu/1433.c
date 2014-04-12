#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int j;
	int f;
	double price;
} Fatmouse;

static int
cmp (const void *a, const void *b)
{
	return (*(Fatmouse *) a).price > (*(Fatmouse *) b).price ? 1 : -1;
}

int
main (void)
{
	int m, n, i;

	double j;

	Fatmouse *p;

	while (scanf ("%d %d", &m, &n) != EOF && m != -1 && n != -1)
	{
		if ((p = (Fatmouse *) malloc (n * sizeof (Fatmouse))) != NULL)
		{
			for (i = 0; i < n; i++)
			{
				scanf ("%d %d", &p[i].j, &p[i].f);
				p[i].price = (double) p[i].f / (double) p[i].j;
			}
			qsort (p, n, sizeof (p[0]), cmp);

			for (i = 0, j = 0; i < n; i++)
			{
				if (m - p[i].f >= 0)
				{
					m -= p[i].f;
					j += p[i].j;
				}
				else
				{
					j += (double) m / p[i].price;
					break;
				}
			}
			printf ("%.3lf\n", j);
			free (p);
		}
		else
			exit (1);
	}
	return 0;
}
