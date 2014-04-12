#include<iostream>
#include<stack>

using namespace std;

int
main ()
{
	long long int a, b;

	int m;

	while (cin >> m && m && cin >> a >> b)
	{
		if (a | b)
		{
			long long int res = a + b;

			stack < int >stk;

			while (res)
			{
				stk.push (res % m);
				res /= m;
			}
			while (!stk.empty ())
			{
				cout << stk.top ();
				stk.pop ();
			}
			cout << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
