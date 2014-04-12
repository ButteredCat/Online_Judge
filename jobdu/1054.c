#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static int
cmp (const void *a, const void *b)
{
	return *(char *) a - *(char *) b;
}


int
main ()
{
	char str[201];

	while (scanf ("%s", str) != EOF)
	{
		qsort (str, strlen (str), sizeof (char), cmp);

		printf ("%s\n", str);
	}
	return 0;
}
