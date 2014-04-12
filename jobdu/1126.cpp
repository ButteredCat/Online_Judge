#include<iostream>

using namespace std;

int
main ()
{
	int n;

	while (cin >> n)
	{
		for (int i = 0; i != n; ++i)
		{
			int jj, j, k;

			cin >> k;
			int *p = new int[k];

			int *pi = new int[k];

			for (j = 0; j != k; ++j)
				cin >> p[j];

			jj = j = 0;
			if (p[0] != p[1])
				pi[jj++] = 0;
			for (j = 1; j != k - 1; ++j)
			{
				if ((p[j] > p[j - 1] && p[j] > p[j + 1])
					|| (p[j] < p[j - 1] && p[j] < p[j + 1]))
					pi[jj++] = j;
			}
			if (p[k - 1] != p[k - 2])
				pi[jj++] = j;

			for (j = 0; j != jj; ++j)
			{
				if (j == 0)
					cout << pi[j];
				else
					cout << " " << pi[j];
			}
			cout << endl;
			delete[]p;
			delete[]pi;
		}
	}
	return 0;
}
