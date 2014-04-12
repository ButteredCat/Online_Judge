#include<iostream>
#include<map>

using namespace std;

int
main ()
{
	string s;

	while (cin >> s)
	{
		map < string, int >m;

		for (string::size_type i = 0; i != s.size (); ++i)
			m[s.substr (i)];
		for (map < string, int >::iterator i = m.begin ();
			 i != m.end (); ++i)
			cout << i->first << endl;
	}
	return 0;
}
