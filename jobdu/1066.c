#include<stdio.h>
#include<string.h>

int
main ()
{
	char s[21];

	char t[128];

	int i, j, k, len;

	while (scanf ("%s", s) != EOF)
	{
		memset (t, 0, sizeof (t));
		len = strlen (s);
		for (i = 0; i < len; ++i)
			++t[s[i] - 0];
		k = 0;
		for (i = 0; i < 128; ++i)
			for (j = 0; j < t[i - 0]; ++j)
				s[k++] = (char) i;
		printf ("%s\n", s);
	}
	return 0;
}
