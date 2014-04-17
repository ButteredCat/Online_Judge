#include<stdio.h>

int
partial (char *number, char d)
{
	int part, weight = 1;

	char *p = number;

	part = 0;
	while (*p != '\0')
	{
		if (*p++ == d)
		{
			part += (d - '0') * weight;
			weight *= 10;
		}
	}
	return part;
}

int
main (void)
{
	char a[10], b[10], da, db;

	while (scanf ("%s %c %s %c", a, &da, b, &db) != EOF)
		printf ("%d\n", partial (a, da) + partial (b, db));

	return 0;
}
