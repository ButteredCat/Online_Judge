#include<stdio.h>

#define ISLEAP(Y) (Y%100!=0&&Y%4==0||Y%400==0?1:0)

typedef struct
{
	int year;
	int month;
	int day;
} Date;

int nolp[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int lp[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int
main ()
{
	Date n;

	int *p;

	int i, count;

	while (scanf ("%d %d %d", &n.year, &n.month, &n.day) != EOF)
	{
		p = ISLEAP (n.year) ? lp : nolp;
		count = 0;
		for (i = 1; i < n.month; i++)
			count += p[i];
		count += n.day;
		printf ("%d\n", count);
	}
	return 0;
}
