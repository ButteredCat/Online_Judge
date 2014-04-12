#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[100];
	unsigned char age;
	unsigned char score;
} item;

item p[1000];

/* bubble sort */
int
sort (int n)
{
	int i = n, j;

	item temp;

	while (i > 0)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (p[j].score > p[j + 1].score)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
			else if (p[j].score == p[j + 1].score)
			{
				if (strcmp (p[j].name, p[j + 1].name) > 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
				else if (strcmp (p[j].name, p[j + 1].name) == 0)
				{
					if (p[j].age > p[j + 1].age)
					{
						temp = p[j];
						p[j] = p[j + 1];
						p[j + 1] = temp;
					}
				}
			}
		}
		i--;
	}

	return 0;
}


int
main ()
{
	int n, i;

	while (scanf ("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf ("%s %d %d", p[i].name, &p[i].age, &p[i].score);
		}

		sort (n);
		for (i = 0; i < n; i++)
		{
			printf ("%s %d %d\n", p[i].name, p[i].age, p[i].score);
		}
	}

	return 0;
}
