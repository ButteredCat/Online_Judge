#include<stdio.h>

long long int
hanoi (int n)
{
	return n == 1 ? 2 : 3 * hanoi (n - 1) + 2;
}

int
main (void)
{
	int n;

	while (scanf ("%d", &n) != EOF)
		printf ("%lld\n", hanoi (n));

	return 0;
}
