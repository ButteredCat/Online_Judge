#include<stdio.h>

int
main (void)
{
	int i, a[10];

	for (i = 0; i < 10; ++i)
		scanf ("%d", a + i);

	i = 1;
	/* find the first non-zero digi */
	while (i < 10 && a[i] == 0)
	{
		++i;
	}
	/* case 1: the first non-zero digi found */
	if (i < 10)
	{
		printf ("%d", i);
		--a[i];
		for (i = 0; i < 10; ++i)
		{
			while (a[i] != 0)
			{
				printf ("%d", i);
				--a[i];
			}
		}
	}
	/* case 2: no non-zero digi found */
	else
		printf ("0");

	printf ("\n");

	return 0;
}
