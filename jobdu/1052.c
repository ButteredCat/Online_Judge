#include<stdio.h>
#include<stdlib.h>


int
main ()
{
	int i, x, n;

	int *p;

	while (scanf ("%d", &n) != EOF)
	{
		if ((p = (int *) malloc (n * sizeof (int))) != NULL)
		{
			for (i = 0; i < n; i++)
			{
				scanf ("%d ", p + i);
			}
			scanf ("%d", &x);

			for (i = 0; i < n; i++)
			{
				if (p[i] == x)
				{
					printf ("%d\n", i);
					break;
				}
			}
			if (i == n)
				printf ("%d\n", -1);
		}
		free (p);
	}
}
