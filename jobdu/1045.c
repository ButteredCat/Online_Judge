#include<stdio.h>

int
main ()
{
	int n;

	int x, y, z;

	int xx, yy, zz;

	while (scanf ("%d", &n) != EOF)
	{
		xx = n / 5;
		for (x = 0; x <= xx && x <= 100; x++)
		{
			yy = (n - 5 * x) / 3;
			for (y = 0; y <= yy && x + y <= 100; y++)
			{
				zz = (n - 5 * x - 3 * y) * 3;
				for (z = 0; z <= zz && x + y + z <= 100; z++)
				{
					if (x + y + z == 100)
						printf ("x=%d,y=%d,z=%d\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
