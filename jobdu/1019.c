#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 101

char cstack[SIZE];

int ctop = -1;

double dstack[SIZE];

int dtop = -1;

static char
cpop ()
{
	/* to save time, do not check if it's empty */
	return cstack[ctop--];
}

static void
cpush (char n)
{
	/* do not check if it's full */
	cstack[++ctop] = n;
}

static double
dpop ()
{
	return istack[itop--];
}

static void
dpush (double n)
{
	istack[++itop] = n;
}


int
main ()
{
	char opnd;
	double optr;

	return 0;
}
