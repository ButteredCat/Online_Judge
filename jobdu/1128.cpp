#include<iostream>

using namespace std;

int
main ()
{
	int n;

	while (cin >> n)
	{
		int sum = 0, age;

		for (int i = 0; i != n; ++i)
		{
			cin >> age;
			sum += age;
		}
		cout.precision (2);
		cout << fixed << (double) sum / (double) n << endl;
	}
	return 0;
}
