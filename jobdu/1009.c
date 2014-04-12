#include<stdio.h>
#include<string.h>

int
left (int current)
{
	return current * 2;
}

int
right (int current)
{
	return current * 2 + 1;
}

void
insert (char *tree, char c)
{
	int current = 1;

	while (tree[current] != 'x')
	{
		if (c < tree[current])
			current = left (current);
		if (c > tree[current])
			current = right (current);
	}
	tree[current] = c;
}

int
main ()
{
	int n, length, i, j;

	char tree1[1025] = {[1024] = '\0' };

	char tree2[1025] = {[1024] = '\0' };

	char s[21];

	while (scanf ("%d", &n) != EOF && n)
	{
		scanf ("%s", s);
		length = strlen (s);
		memset (tree1, 'x', sizeof (tree1) - 1);
		for (i = 0; i < length; i++)
			insert (tree1, s[i]);
		for (i = 0; i < n; i++)
		{
			scanf ("%s", s);
			length = strlen (s);
			memset (tree2, 'x', sizeof (tree2) - 1);
			for (j = 0; j < length; j++)
				insert (tree2, s[j]);

			printf ("%s\n", strcmp (tree1, tree2) ? "No" : "Yes");
		}
	}
	return 0;
}
