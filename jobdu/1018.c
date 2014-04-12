#include<stdio.h>
#include<stdlib.h>

int
main ()
{
	int i, n, x, c;

	int *p;

	while (scanf ("%d", &n) && (n != 0))
	{
		c = 0;
		if ((p = (int *) malloc (n * sizeof (int))) != NULL)
		{
			for (i = 0; i < n; i++)
				scanf ("%d ", p + i);
			scanf ("%d", &x);
			for (i = 0; i < n; i++)
				if (x == p[i])
					c++;
			printf ("%d\n", c);
			free (p);
		}
		else
			exit (1);
	}
	return 0;
}
