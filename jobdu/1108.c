#include<stdio.h>

int stack[10001];

int top = -1;

void
push (int n)
{
	stack[++top] = n;
}

int
pop ()
{
	return stack[top--];
}

int
main ()
{
	char c;

	int i, n;

	while (scanf ("%d", &n) != EOF && n)
	{
		top = -1;
		for (i = 0; i < n; i++)
		{
			scanf ("%c", &c);
			switch (c)
			{
			case 'P':
				scanf (" %d", &n);
				push (n);
				break;
			case 'O':
				if (top > -1)
					pop ();
				break;
			case 'A':
				if (top > -1)
					printf ("%d\n", stack[top]);
				else
					printf ("E\n");
				break;
			default:
				break;
			}

		}
		printf ("\n");
	}
	return 0;
}
