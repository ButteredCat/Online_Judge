#include<iostream>
#include<vector>

using namespace std;

int
main ()
{
	long long n, b;

	while (cin >> n >> b)
	{
		vector < long long >backward;

		if (n == 0)
			backward.push_back (0);
		else
			while (n)
			{
				backward.push_back (n % b);
				n /= b;
			}
		vector < long long >forward (backward.rbegin (), backward.rend ());

		cout << (forward == backward ? "Yes" : "No") << endl;
		vector < long long >::iterator i = forward.begin ();

		cout << *i;
		for (++i; i != forward.end (); ++i)
			cout << " " << *i;
		cout << endl;
	}
	return 0;
}
