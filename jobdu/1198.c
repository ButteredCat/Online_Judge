#include<stdio.h>
#include<string.h>

typedef struct
{
	int digi[300];
	int size; /*0 <= size < 300*/
} BigInt;

const short int mat[4][10] = {
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
	{0, 10, 20, 30, 40, 50, 60, 70, 80, 90},
	{0, 100, 200, 300, 400, 500, 600, 700, 800, 900},
	{0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000}
};

void
Set (BigInt * n, char const *s)
{
	int i, j, t;

	memset (n->digi, 0, sizeof (n->digi));
	n->size = 0;

	for (i = strlen (s) - 1, j = 0, t = 0; i >= 0; i--)
	{
		t += mat[j++][s[i] - '0'];
		if (j == 4 || i == 0)
		{
			n->digi[n->size++] = t;
			j = t = 0;
		}
	}
}

BigInt
Plus (BigInt const *m, BigInt const *n)
{
	BigInt k;

	int i, carry = 0, temp = 0;

	memset (k.digi, 0, sizeof (k.digi));

	k.size = (m->size > n->size) ? m->size : n->size;
	for (i = 0; i < k.size; i++)
	{
		temp = m->digi[i] + n->digi[i] + carry;
		carry = (temp >= 10000) ? 1 : 0;
		k.digi[i] = temp % 10000;
	}
	if (carry == 1)
		k.digi[++(k.size) - 1] = 1;

	return k;
}

void
Print (BigInt const *n)
{
	int i;

	for (i = n->size - 1; i >= 0; i--)
	{
		if (i == n->size - 1)
			printf ("%d", n->digi[i]);
		else
			printf ("%04d", n->digi[i]);
	}
}


int
main ()
{
	char str1[1001], str2[1001];

	BigInt a, b, c;

	while (scanf ("%s %s", str1, str2) != EOF)
	{
		Set (&a, str1);
		Set (&b, str2);
		c = Plus (&a, &b);
		Print (&c);
		printf ("\n");
	}
	return 0;
}
