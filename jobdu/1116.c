#include<stdio.h>

int
main ()
{
	int a, b, res;

	char op;

	while (scanf ("%d %c", &a, &op) != EOF)
	{
		if (op != '!')
		{
			scanf ("%d", &b);
			switch (op)
			{
			case '+':
				res = a + b;
				break;
			case '-':
				res = a - b;
				break;
			case '*':
				res = a * b;
				break;
			case '/':
			case '%':
				if (b)
					res = (op == '/') ? a / b : a % b;
				else
				{
					printf ("error\n");
					continue;
				}
				break;
			}
		}
		else
		{
			res = 1;
			if (a > 0)
				while (a)
					res *= a--;
		}
		printf ("%d\n", res);
	}
	return 0;
}
