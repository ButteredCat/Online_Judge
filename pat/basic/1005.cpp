#include<iostream>
#include<cstdlib>

using namespace std;

static int
cmp (const void *a, const void *b)
{
	return *(int *) b - *(int *) a;
}

int
main ()
{
	int k;

	while (cin >> k)
	{
		int *n = new int[k];

		int i;

		for (i = 0; i < k; ++i)
			cin >> n[i];
		for (i = 0; i < k; ++i)
		{
			int a = n[i];

			while ((a != 0) && (a != 1))
			{
				if (a % 2 == 0)
					a /= 2;
				else
					a = (3 * a + 1) / 2;
				for (int j = 0; j < k; ++j)
					if (n[j] == a)
						n[j] = 0;
			}
		}

		qsort (n, k, sizeof (int), cmp);

		i = 0;
		while (n[i] == 0)
			++i;
		if (i < k)
			cout << n[i];
		for (++i; i < k; ++i)
			if (n[i] != 0)
				cout << " " << n[i];
		cout << endl;
		delete[]n;
	}
	return 0;
}
