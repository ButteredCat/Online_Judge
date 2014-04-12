#include<iostream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

int
main ()
{
	string line;

	map < string, string > m2f, f2m;
	while (getline (cin, line) && line != "@END@")
	{
		string magic (line.begin () + 1, line.begin () + line.find ("]"));

		string function = line.substr (line.find ("]") + 2);

		m2f.insert (make_pair (magic, function));
		f2m.insert (make_pair (function, magic));
	}
	int n;

	cin >> n;
	cin.ignore ();
	while (n-- && getline (cin, line))
	{
		if (line[0] == '[')
		{
			string magic (line.begin () + 1, line.end () - 1);

			if (m2f.count (magic))
			{
				cout << m2f[magic] << endl;
				continue;
			}
		}
		else if (f2m.count (line))
		{
			cout << f2m[line] << endl;
			continue;
		}
		cout << "what?" << endl;
	}
	return 0;
}
