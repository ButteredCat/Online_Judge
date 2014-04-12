#include<stdio.h>
#include<string.h>

int Hash[1000001];

const int OFFSET = 500000;

int
main ()
{
	int m, n, i, j, input;

	while (scanf ("%d %d", &n, &m) != EOF)
	{
		memset (Hash, 0, sizeof (Hash));	/* Do not init 'int' arraries if not 0 */
		for (i = 0; i < n; i++)
		{
			scanf ("%d ", &input);
			Hash[input + OFFSET]++;
		}
		for (i = 1000000, j = 0; i >= 0 && j < m; i--)
		{
			if (Hash[i] != 0)
			{
				printf ("%d", i - OFFSET);
				if (++j < m)
					printf (" ");
				else
					printf ("\n");
			}
		}
	}
	return 0;
}
