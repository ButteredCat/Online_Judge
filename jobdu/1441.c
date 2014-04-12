#include<stdio.h>

int
main (void)
{
	int a, b, i, temp;

	while ((scanf ("%d %d", &a, &b) != EOF) && (a | b))
	{
		temp = 1;
		for (i = 1; i <= b; i++)
		{
			temp = ((a % 1000) * temp) % 1000;
		}
		printf ("%d\n", temp);
	}
	return 0;
}
