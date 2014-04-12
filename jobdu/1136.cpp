#include<iostream>

using namespace std;

int
main ()
{
	int n, x, y;

	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			if (y == x && y >= 0)
				cout << 2 * x - x % 2 << endl;
			else if (y == x - 2 && y >= 0)
				cout << 2 * x - (x % 2 ? 3 : 2) << endl;
			else
				cout << "No Number" << endl;
		}
	}
	return 0;
}
