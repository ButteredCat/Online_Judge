#include<stdio.h>

int
main ()
{
	char str[4];

	int i;

	while (scanf ("%s", str) != EOF)
	{
		i = 3;
		while (i >= 0)
			printf ("%c", str[i--]);
		printf ("\n");
	}
	return 0;
}
