#include<stdio.h>

int
main (void)
{
	int n, i;
	const char *p[] = { "false", "true" };
	long long a, b, c;

	while (scanf ("%d", &n) != EOF)
	{
		for (i = 1; i <= n; ++i)
		{
			scanf ("%lld %lld %lld", &a, &b, &c);
			printf ("Case #%d: %s\n", i, p[a + b > c ? 1 : 0]);
		}
	}
	return 0;
}
