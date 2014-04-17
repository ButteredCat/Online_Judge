#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int
main (void)
{
	char s[4][61];

	int day, hour, minute;

	size_t i, length;

	day = hour = minute = 0;
	for (i = 0; i < 4; ++i)
		scanf ("%s", s[i]);

	length = strlen (s[0]) > strlen (s[1]) ? strlen (s[1]) : strlen (s[0]);
	for (i = 0; i < length; ++i)
	{
		if (s[0][i] == s[1][i] && s[0][i] >= 'A' && s[0][i] <= 'G')
		{
			day = s[0][i] - 'A';
			break;
		}
	}
	for (++i; i < length; ++i)
	{
		if (s[0][i] == s[1][i]
			&& (isdigit (s[0][i]) || (s[0][i] >= 'A' && s[0][i] <= 'N')))
		{
			hour = isdigit (s[0][i]) ? s[0][i] - '0' : s[0][i] - 'A' + 10;
			break;
		}
	}
	length = strlen (s[2]) > strlen (s[3]) ? strlen (s[3]) : strlen (s[2]);
	for (i = 0; i < length; ++i)
	{
		if (s[2][i] == s[3][i] && (islower (s[2][i]) || isupper (s[2][i])))
			minute = i;
	}

	printf ("%s %.2d:%.2d\n", week[day], hour, minute);
	return 0;
}
