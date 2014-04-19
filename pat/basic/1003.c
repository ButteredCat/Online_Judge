#include<stdio.h>
#include<string.h>

#define NO 0
#define YES 1

char *answer[] = { "NO", "YES" };

int
countA (char const *begin, char const *end)
{
	int count = 0;

	while (begin <= end)
		if (*begin++ == 'A')
			++count;
	return count;
}

int
main (void)
{
	int n, a, b, c, is;

	char in[101], *firstP, *firstT;

	scanf ("%d", &n);
	while (n--)
	{
		scanf ("%s", in);
		is = NO;
		firstP = strpbrk (in, "P");
		firstT = strpbrk (in, "T");
		if (firstP != NULL && firstT != NULL && firstP < firstT)
		{
			a = countA (in, firstP);
			b = countA (firstP, firstT);
			c = countA (firstT, in + strlen (in));
			if ((a == firstP - in) && (b == firstT - firstP - 1)
				&& (c == in + strlen (in) - firstT - 1) && (c == a * b)
				&& (b != 0))
				is = YES;
		}
		printf ("%s\n", answer[is]);
	}
	return 0;
}
