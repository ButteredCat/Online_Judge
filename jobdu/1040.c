#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int prime[10001] = { 0, 2 };

int
main ()
{
	int i = 2;

	int n = 1;

	int j, sqr, is;

	while (n += 2, i <= 10000)
	{
		sqr = sqrt (n);
		is = TRUE;
		for (j = 1; prime[j] <= sqr && j < i; j++)
			if (n % prime[j] == 0)
			{
				is = FALSE;
				break;
			}
		if (is == TRUE)
			prime[i++] = n;
	}
	while (scanf ("%d", &n) != EOF)
		printf ("%d\n", prime[n]);
	return 0;
}
