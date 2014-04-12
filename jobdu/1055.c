#include<stdio.h>
#include<string.h>

int
main (void)
{
	char s[201];

	int i;

	while (scanf ("%s", s) != EOF)
	{
		for (i = strlen (s) - 1; i >= 0; i--)
			printf ("%c", s[i]);
		printf ("\n");
	}
	return 0;
}
