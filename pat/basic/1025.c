#include<stdio.h>


typedef struct
{
	int data;
	int next;
	int prior;
} Node;

Node list[100000];

int head;

void
swap (int *pa, int *pb)
{
	int t = *pa;

	*pa = *pb;
	*pb = t;
}

void
reverse (int n, int k)
{
	int i, m, last_tail, addr = head;

	m = n - n % k;
	last_tail = head;
	for (i = 0; i < m; ++i)
	{
		swap (&list[addr].next, &list[addr].prior);
		printf ("addr=%d\n", addr);
		if (i % k == k - 1)
		{
			if (i == k - 1)
				head = addr;
			else
				list[last_tail].next = addr;
		}
		if (i % k == 0)
		{
			last_tail = addr;
		}
		addr = list[addr].prior;
	}
	printf ("addr=%d\n", addr);
	list[last_tail].next = addr;
}

int
main (void)
{
	int addr, data, next, n, k, i;

	scanf ("%d %d %d", &head, &n, &k);
	list[head].prior = -1;
	for (i = 0; i < n; ++i)
	{
		scanf ("%d %d %d", &addr, &data, &next);
		list[addr].data = data;
		list[addr].next = next;
		if (next != -1)
			list[next].prior = addr;
	}

	reverse (n, k);

	addr = head;
	while (addr != -1)
	{
		printf ("%.5d %d ", addr, list[addr].data);
		if (list[addr].next == -1)
			printf ("%d\n", list[addr].next);
		else
			printf ("%.5d\n", list[addr].next);
		addr = list[addr].next;
	}
	return 0;
}
