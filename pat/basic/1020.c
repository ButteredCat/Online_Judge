#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	double amount;
	double totalPrice;
	double price;
} Cake;

int
cmp (void const *a, void const *b)
{
	return (*(Cake *) a).price > (*(Cake *) b).price ? -1 : 1;
}

int
main (void)
{
	int n, d, i;

	double revenue, saled;

	Cake *p = NULL;

	scanf ("%d %d", &n, &d);
	if ((p = (Cake *) malloc (n * sizeof (Cake))) != NULL)
	{
		for (i = 0; i < n; ++i)
			scanf ("%lf", &p[i].amount);
		for (i = 0; i < n; ++i)
		{
			scanf ("%lf", &p[i].totalPrice);
			p[i].price = p[i].totalPrice / p[i].amount;
		}

		qsort (p, n, sizeof (Cake), cmp);

		revenue = saled = 0.0;
		/*
		   while (saled < d && i < n)
		   {
		   temp = saled + p[i].amount;
		   if (temp > d)
		   {
		   revenue += p[i].price * (d - saled);
		   saled = d;
		   }
		   else
		   {
		   revenue += p[i].totalPrice;
		   saled = temp;
		   ++i;
		   }
		   } */
		for (i = 0; i < n; ++i)
		{
			if (saled + p[i].amount > d)
			{
				revenue += (d - saled) * p[i].price;
				break;
			}
			else
			{
				saled += p[i].amount;
				revenue += p[i].totalPrice;
			}
		}
		printf ("%.2f\n", revenue);
		free (p);
	}
	else
		exit (1);
	return 0;
}
