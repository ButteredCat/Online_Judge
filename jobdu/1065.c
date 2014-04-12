#include<stdio.h>

int
main ()
{
	int h, i, j;

	while (scanf ("%d", &h) != EOF)
	{
		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= (3 * h - 2); j++)
			{
				if (j <= 2 * (h - i))
					printf (" ");
				else
					printf ("*");
			}
			printf ("\n");
		}
	}
	return 0;
}
