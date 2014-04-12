#include<stdio.h>

int
reverse (int n)
{
	int i, m = 0;

	for (i = 1000; i >= 1; i /= 10)
	{
		m += (n % 10) * i;
		n /= 10;
	}
	return m;
}

int
main ()
{
	int i = 1000;

	while (i++ < 1111)
		if (i * 9 == reverse (i))
			printf ("%d\n", i);
	return 0;
}
