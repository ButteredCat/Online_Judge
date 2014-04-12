#include<stdio.h>

int
main ()
{
	int n, counter;

	while (scanf ("%d", &n) != EOF)
	{
		counter = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = (3 * n + 1) / 2;
			++counter;
		}
		printf ("%d\n", counter);
	}
	return 0;
}
