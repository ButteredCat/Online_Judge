#include<stdio.h>

struct RING
{
	int elem[17];
	int total;
} R;



int next( int k)
{
	return (k==R.total) ? 1 : k+1;
}

int ringGen(int k)
{
	if(k==1)
		for(i=1; i<=R.total; ++i)
			printf("%d ", R.elem[i]);
	else if(isPrime(R.elem[k] + R.elem[next(k)]))
			ringGen(next(k));
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(i=0; i<n; ++i)
			R.elem[i]=i+1;
		R.total=n;
		ringGen(2);		
	}
	return 0;
}
