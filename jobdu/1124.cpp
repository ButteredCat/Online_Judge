#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int
main ()
{
	string s;

	while ((cin >> s) && (s != "0"))
	{
		while (s.size () > 1)
		{
			int n = 0;

			for (string::size_type i = 0; i != s.size (); ++i)
				n += s[i] - '0';
			ostringstream oss;

			oss << n;
			s = oss.str ();
		}
		cout << s << endl;
	}
	return 0;
}
