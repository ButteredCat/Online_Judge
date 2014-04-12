#include<stdio.h>

int
main (void)
{
	const int a[] = {
		[2] = 0,
		[3] = 1,
		[1] = 2,
		[0] = 3,
	};
	int i = 0;

	while (i < 4)
		printf ("%d\n", a[i++]);
	return 0;
}
