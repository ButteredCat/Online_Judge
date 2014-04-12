#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int
main (void)
{
	int n, i, m, count, yes;

	char out[2][4] = { "no", "yes" };

	while (scanf ("%d", &n) != EOF)
	{
		if (n <= 1)
			yes = FALSE;
		else if (n == 2)
			yes = TRUE;
		else
		{
			m = sqrt (n);
			count = 0;
			for (i = 2; i <= m; i++)
				if (n % i == 0)
					count++;
			yes = count == 0 ? TRUE : FALSE;
		}
		printf ("%s\n", out[yes]);
	}
	return 0;
}
