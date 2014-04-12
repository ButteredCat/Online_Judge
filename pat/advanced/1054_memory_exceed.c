#include<stdio.h>
#include<string.h>

#define MAX 16777216

int set[MAX];

int
main ()
{
	int m, n, i, color;

	while (scanf ("%d%d", &m, &n) != EOF)
	{
		memset (set, 0, sizeof (set));
		m *= n;
		for (i = 0; i < m; ++i)
		{
			scanf ("%d", &color);
			++set[color];
		}
		m /= 2;
		for (i = 0; i < MAX; ++i)
			if (set[i] > m)
				printf ("%d\n", i);
	}
	return 0;
}
