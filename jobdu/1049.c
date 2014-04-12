#include<stdio.h>
#include<string.h>

int
main ()
{
	char s[100];

	char c;

	while (scanf ("%s%c", s, &c) != EOF)
	{
		char t[100] = { 0 };
		int n = strlen (s);

		int i, j;

		for (i = j = 0; i < n; ++i)
			if (s[i] != c)
				t[j++] = s[i];
		printf ("%s\n", t);
	}
	return 0;
}
