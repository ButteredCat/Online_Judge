#include<stdio.h>
#include<string.h>

typedef struct
{
	char c;
	int num;
} Bracket;

Bracket stack[101];

int top = -1;

void
push (Bracket * p)
{
	stack[++top] = *p;
}

Bracket
pop (void)
{
	return stack[top--];
}

int
main ()
{
	char str[101], mark[101];

	int length, i;

	Bracket b;

	while (scanf ("%s", str) != EOF)
	{
		length = strlen (str);
		memset (mark, ' ', sizeof (mark));
		mark[length] = '\0';

		for (i = 0; i < length; i++)
		{
			if (str[i] == '(')
			{
				b.c = '(';
				b.num = i;
				push (&b);
			}
			else if (str[i] == ')')
			{
				/* dangerous if the first char is '(', when you access stack[-1] */
				if (top > -1 && stack[top].c == '(')
					pop ();
				else
				{
					b.c = ')';
					b.num = i;
					push (&b);
				}
			}
		}
		while (top != -1)
		{
			b = pop ();
			mark[b.num] = b.c == '(' ? '$' : '?';
		}
		printf ("%s\n%s\n", str, mark);
	}

	return 0;
}
