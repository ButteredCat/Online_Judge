#include<stdio.h>
#include<stdlib.h>

const float point[] = { 1.0, 1.0, 1.0, 1.0,
	1.5, 1.5, 1.5, 1.5,
	2.0, 2.0, 2.0, 2.0,
	2.3, 2.3, 2.3,
	2.7, 2.7, 2.7,
	3.0, 3.0, 3.0, 3.0,
	3.3, 3.3, 3.3,
	3.7, 3.7, 3.7, 3.7, 3.7
};

float
toGrade (int n)
{
	n -= 60;
	if (n < 0)
		return 0.0;
	else if (n >= 30)
		return 4.0;
	else
		return point[n];
}

int
main ()
{
	int n, i, mark;

	float sum_gpa, sum_credit;

	float grade[9];

	int credit[9];

	while (scanf ("%d", &n) != EOF)
	{
		for (i = 0; i < n; ++i)
			scanf ("%d", credit + i);
		for (i = 0; i < n; ++i)
		{
			scanf ("%d", &mark);
			grade[i] = toGrade (mark);
		}
		sum_gpa = sum_credit = 0.0;
		for (i = 0; i < n; ++i)
		{
			sum_gpa += grade[i] * credit[i];
			sum_credit += credit[i];
		}
		printf ("%.2f\n", sum_gpa / sum_credit);
	}
	return 0;
}
