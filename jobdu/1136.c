#include<stdio.h>

int
main ()
{
	int n, x, y;

	while (scanf ("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf ("%d %d", &x, &y);
			if (y >= 0 && y == x)
				printf ("%d\n", 2 * x - x % 2);
			else if (y >= 0 && y == x - 2)
				printf ("%d\n", 2 * x - (x % 2 ? 3 : 2));
			else
				printf ("No Number\n");
		}
	}
	return 0;
}
