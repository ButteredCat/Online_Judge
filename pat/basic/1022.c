#include<stdio.h>
#include<string.h>

#define LENGTH 32

char out[LENGTH];

char *
convert (long long a, int d)
{
	int i = 1;

	do
	{
		out[i++] = (a % d) + '0';
	}
	while ((a /= d) != 0);
	return out + i - 1;
}

int
main (void)
{
	long long a, b;

	int d;

	char *p;

	while (scanf ("%lld %lld %d", &a, &b, &d) != EOF)
	{
		memset (out, '\0', LENGTH);
		p = convert (a + b, d);
		while (*p != '\0')
			printf ("%c", *p--);
		printf ("\n");
	}
	return 0;
}
