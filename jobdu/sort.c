#include<stdlib.h>
#include<stdio.h>


/* bubble sort */
int
sort (int p[], int n)
{
	int i = n, j;

	int temp;

	while (i > 0)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
		i--;
	}

	return 0;
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

			sort (p, n);

			for (i = 0; i < n; i++)
				printf ("%d ", p[i]);

			printf ("\n");
			free (p);
		}
		else
			exit (1);
	}

	return 0;
}
