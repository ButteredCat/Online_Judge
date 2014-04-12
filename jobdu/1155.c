#include<stdio.h>

int
main ()
{
	int n, a, i;

	while (scanf ("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &a);
			if (a % 2)
				printf ("0 0\n");
			else
				printf ("%d %d\n", a % 4 ? a / 4 + 1 : a / 4, a / 2);
		}
	}
	return 0;
}
