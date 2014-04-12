#include<stdio.h>
#include<math.h>

int
main ()
{
	int n, i, d, start;

	int tree[1001];

	while (scanf ("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf ("%d", tree + i);
		scanf ("%d", &d);
		start = pow (2, d - 1);
		if (start > n)
			printf ("EMPTY\n");
		else
		{
			for (i = start; i < start * 2 - 1 && i < n; i++)
				printf ("%d ", tree[i]);
			printf ("%d\n", tree[i]);
		}
	}
	return 0;
}
