#include<iostream>
#include<string>
#include<map>

using namespace std;

int
main ()
{
	int n;

	while (cin >> n)
	{
		string s;

		multimap < string::size_type, string > m;
		cin.ignore ();
		while (n-- && getline (cin, s) && s != "stop")
			m.insert (make_pair (s.size (), s));
		for (multimap < string::size_type, string >::iterator i =
			 m.begin (); i != m.end (); ++i)
			cout << i->second << endl;
	}
	return 0;
}
