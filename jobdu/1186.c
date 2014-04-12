#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0

int nolp[] =
	{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
int lp[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

int
isleap (int yr)
{
	if (yr % 4 == 0)
	{
		if (yr % 100 == 0)
		{
			if (yr % 400 == 0)
				return TRUE;
			else
				return FALSE;
		}
		else
			return TRUE;
	}
	else
		return FALSE;
}

int
main ()
{
	int year, day, month, date;

	int *p;

	while (scanf ("%d %d", &year, &day) != EOF)
	{
		p = isleap (year) ? lp : nolp;
		for (int i = 0; i <= 12; i++)
		{
			if (day <= p[i])
			{
				month = i;
				date = day - p[i - 1];
				break;
			}
		}

		printf ("%.4d-%.2d-%.2d\n", year, month, date);
	}

	return 0;
}
