#include<stdio.h>
#include<string.h>

int
main (void)
{
	char a[1001], q[1001];

	int b, r, length, i, j, temp;

	while (scanf ("%s %d", a, &b) != EOF)
	{
		memset (q, '\0', sizeof (q));
		length = strlen (a);
		i = j = r = 0;
		if (a[i] - '0' >= b)
		{
			temp = a[i] - '0';
			q[j++] = temp / b + '0';
			r = temp % b;
		}
		else
		{
			r = a[i] - '0';
			if (strlen (a) == 1)
				q[j] = '0';
		}
		for (i = 1; i < length; ++i)
		{
			temp = 10 * r + a[i] - '0';
			q[j++] = temp / b + '0';
			r = temp % b;
		}
		printf ("%s %d\n", q, r);
	}
	return 0;
}
