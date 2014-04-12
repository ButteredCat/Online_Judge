#include<stdio.h>

#define USED 0
#define AVA  1

const int prime[32] = { 0,
	0, 1, 1, 0, 1,
	0, 1, 0, 0, 0,
	1, 0, 1, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 1, 0, 0,
	0, 0, 0, 1, 0,
	1
};

typedef struct{
	int n;			/* n numbers from 1 to n */
	int used[17];	/* used[n]==USED if n is used */
	int left;		/* left = n - used */
} POOL;

/*
int
ring (int pool[], int i, int n)
{
	int j;

	for (j = 2; (j <= n) && (pool[j] == 1) && left; j++)
	{
		if (prime[i + j] == 1)
		{
			pool[j] = 0;
			left--;
			printf ("%d ", j);
			ring (pool, j, n);
			pool[j] = 1;
			left++;
		}
	}

	return 0;
}
*/
int ring[17];

int ringGen(POOL p, int x)
{
	int i, count=0;
	if(p.left==0 && ring[n] != 0)
	{
		for(i=1; i<n; i++)
		{
			printf("%d ", ring[i]);
			ring[i]=0;
		}
		}
	for(i=1; i<=p.n; i++)
	{
		if(used[i]!=USED && prime[x+i]==1)
		{
			count++;
			p.used[i]=USED;
			ringGen(p, i);
		}
	}

	return 0;
}


int
main (void)
{
	int n, i;
	POOL p;
	while (scanf ("%d", &n) != EOF)
	{
		p.n=n;
		for (i = 2; i <= n; i++)
			p.used[i] = AVA;
		p.left=n-1;
		ringGen (p, x);
	}
	return 0;
}
