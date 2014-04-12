#include<stdio.h>
#include<stdlib.h>

void
triangle (int a[], int n)
{
	int *plast;

	int i;

	a[0] = a[n - 1] = 1;
	if (n > 2)
	{
		plast = (int *) malloc ((n - 1) * sizeof (int));
		triangle (plast, n - 1);
		for (i = 1; i < n - 1; i++)
			a[i] = plast[i] + plast[i - 1];
		free (plast);
	}
	for (i = 0; i < n - 1; i++)
		printf ("%d ", a[i]);
	printf ("%d\n", a[i]);
}


int
main ()
{
	int n;

	int *p;

	while (scanf ("%d", &n) != EOF)
	{
		p = (int *) malloc (n * sizeof (int));
		triangle (p, n);
		free (p);
	}
	return 0;
}
