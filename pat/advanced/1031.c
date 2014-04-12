#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
main ()
{
	char s[81];

	int n, n1, n2, i, beg, end;

	char *p = NULL;

	while (scanf ("%s", s) != EOF)
	{
		n = strlen (s);
		n1 = (n + 2 - (n + 2) % 3) / 3;
		n2 = n + 2 - 2 * n1;

		if ((p = (char *) calloc (n2 + 1, sizeof (char))) == NULL)
			exit (-1);
		beg = 0;
		end = n - 1;
		for (i = 0; i < n1 - 1; ++i)
		{
			memset (p, ' ', n2 * sizeof (char));
			p[0] = s[beg++];
			p[n2 - 1] = s[end--];
			printf ("%s\n", p);
		}
		i = 0;
		while (beg <= end)
			p[i++] = s[beg++];
		printf ("%s\n", p);

		free (p);
	}
	return 0;
}
