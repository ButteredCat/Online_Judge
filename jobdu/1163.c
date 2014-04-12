#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

static int
isPrime (int n)
{
	int i;

	if (n == 2)
		return TRUE;
	for (i = 2; i <= sqrt (n); i++)
	{
		if (n % i == 0)
			return FALSE;
	}
	return TRUE;
}

int
main ()
{
	int n, i, k, count;

	while (scanf ("%d", &n) != EOF)
	{
		k = (n % 10 == 0 || n % 10 == 1) ? n / 10 - 1 : n / 10;
		count = 0;
		for (i = 1; i <= k; i++)
		{
			if (isPrime (10 * i + 1) == TRUE)
			{
				count++;
				if (count == 1)
					printf ("%d", 10 * i + 1);
				else
					printf (" %d", 10 * i + 1);
			}
		}
		if (count == 0)
			printf ("%d", -1);
		printf ("\n");
	}
	return 0;
}
