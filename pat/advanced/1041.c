#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BET
{
	int count;
	int index;
} Bet;

Bet h[10001];

int
main ()
{
	int n, i, input, first, unique;

	while (scanf ("%d", &n) != EOF)
	{
		memset (h, 0, sizeof (h));
		for (i = 1; i <= n; ++i)
		{
			scanf ("%d", &input);
			h[input].index = i;
			++h[input].count;
		}
		first = n + 1;
		for (i = 0; i <= 10000; ++i)
		{
			if ((h[i].count == 1) && (h[i].index < first))
			{
				first = h[i].index;
				unique = i;
			}
		}
		if (first == n + 1)
			printf ("None\n");
		else
			printf ("%d\n", unique);
	}

	return 0;
}
