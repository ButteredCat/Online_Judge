#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

int
main ()
{
	string a, b;

	int k;

	while (cin >> a >> b >> k && (a != "0" || b != "0"))
	{
		int r = min ((unsigned int) k, min (a.size (), b.size ()));

		if (a.compare (a.size () - r, r, b, b.size () - r, r) == 0)
			cout << "-1" << endl;
		else
			cout << atoi (a.c_str ()) + atoi (b.c_str ()) << endl;
	}
	return 0;
}
