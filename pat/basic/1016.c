#include<stdio.h>

int
main (void)
{
	char a[10], b[10], da, db, *p;

	int pa, pb, weight;

	while (scanf ("%s %c %s %c", a, &da, b, &db) != EOF)
	{
		p = a;
		pa = 0;
		weight = 1;
		while (*p != '\0')
		{
			if (*p++ == da)
			{
				pa += (da - '0') * weight;
				weight *= 10;
			}
		}
		p = b;
		pb = 0;
		weight = 1;
		while (*p != '\0')
		{
			if (*p++ == db)
			{
				pa += (db - '0') * weight;
				weight *= 10;
			}
		}
		printf ("%d\n", pa + pb);
	}
	return 0;
}
