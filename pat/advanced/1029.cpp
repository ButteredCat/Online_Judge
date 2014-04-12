#include<iostream>
#include<sstream>

using namespace std;

int
main ()
{
	string line1, line2;

	while (getline (cin, line1) && getline (cin, line2))
	{
		istringstream s1 (line1), s2 (line2);

		int n1, n2, n, i, j, k;

		s1 >> n1;
		int *p1 = new int[n1];

		for (i = 0; i < n1; ++i)
			s1 >> p1[i];
		s2 >> n2;
		int *p2 = new int[n2];

		for (i = 0; i < n2; ++i)
			s2 >> p2[i];
		n = n1 + n2;
		int *p = new int[n];

		i = j = k = 0;
		while (k < n)
		{
			if (p1[i] < p2[j])
				p[k++] = p1[i++];
			else
				p[k++] = p2[j++];
		}
		cout << p[n / 2 - (n % 2 ? 0 : 1)] << endl;
		delete[]p1;
		delete[]p2;
		delete[]p;
	}
	return 0;
}
