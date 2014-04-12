#include<iostream>

using namespace std;

int
main ()
{
	int n;

	while (cin >> n)
	{
		if (n == 5 || n == 6)
			cout << "Yes!" << endl;
		else if (n * n % 100 - n == 0)
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;
	}
	return 0;
}
