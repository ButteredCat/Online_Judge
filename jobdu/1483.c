#include<stdlib.h>
#include<stdio.h>

static int
find_max (const void *a, const void *b)
{
	return *(int *) a - *(int *) b;
}


static int
find_min (const void *a, const void *b)
{
	return *(int *) b - *(int *) a;
}

int
get (int p[], int n, int (*cmp) (const void *a, const void *b))
{
	int temp = p[0], i;

	for (i = 1; i < n; i++)
	{
		if (cmp (&temp, &p[i]) < 0)
			temp = p[i];
	}
	return temp;
}

int
main ()
{
	int n, i;

	int *p;

	while (scanf ("%d", &n) != EOF)
	{
		if ((p = (int *) malloc (n * sizeof (int))) != NULL)
		{
			for (i = 0; i < n; i++)
				scanf ("%d ", p + i);
			printf ("%d %d\n", get (p, n, find_max), get (p, n, find_min));
			free (p);
		}
		else
			exit (1);
	}
}
