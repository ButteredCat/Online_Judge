#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
main ()
{
	char a[5], b[5];

	int k;

	while (scanf ("%s %s %d", a, b, &k) != EOF && (*a != '0' || *b != '0'))
	{
		int la = strlen (a);

		int lb = strlen (b);

		int min = la > lb ? lb : la;

		k = k > min ? min : k;
		if (strcmp (a + la - k, b + lb - k) == 0)
			printf ("-1\n");
		else
			printf ("%d\n", atoi (a) + atoi (b));
	}
	return 0;
}
