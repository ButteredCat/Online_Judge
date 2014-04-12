#include<stdio.h>
#include<string.h>

int
main ()
{
	int n, i;

	int x[3];

	while (scanf ("%d", &n) != EOF)
	{
		i = 2;
		memset (x, 0, sizeof (x));
		while (n)
		{
			x[i--] = n % 10;
			n /= 10;
		}
		while (x[0]--)
			printf ("B");
		while (x[1]--)
			printf ("S");
		i = 1;
		while (x[2]--)
			printf ("%d", i++);
		printf ("\n");
	}
	return 0;
}
