#include<stdio.h>

int
main ()
{
	int max, input;

	int n = 0;

	while (++n, scanf ("%d", &input) != EOF)
	{
		if (n == 1)
			max = input;
		else
		{
			max = max > input ? max : input;
			if (n == 10)
			{
				n = 0;
				printf ("max=%d\n", max);
			}
		}
	}
	return 0;
}
