#include<stdio.h>
#include<string.h>

int
find (char const *s, char x)
{
	int count = 0;

	for (int i = 0; i < strlen (s); i++)
		if (s[i] == x)
			count++;

	return count;
}

int
main ()
{
	char s[100];

	while (scanf ("%s", s) != EOF && s[0] != 'E')
	{
		int z = find (s, 'Z');

		int o = find (s, 'O');

		int j = find (s, 'J');

		for (; z >= 0 || o >= 0 || j >= 0; z--, o--, j--)
		{
			if (z > 0)
				printf ("Z");

			if (o > 0)
				printf ("O");

			if (j > 0)
				printf ("J");
		}
		printf ("\n");
	}
	return 0;
}
