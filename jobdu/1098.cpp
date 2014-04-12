#include<iostream>
#include<map>

using namespace std;

int
main ()
{
	string line;

	while (cin >> line)
	{
		map < char, int >table;

		for (char c = 'A'; c <= 'Z'; ++c)
			table[c];
		for (string::iterator i = line.begin (); i != line.end (); ++i)
			if (*i >= 'A' && *i <= 'Z')
				++table[*i];
		for (map < char, int >::iterator i = table.begin ();
			 i != table.end (); ++i)
			cout << i->first << ":" << i->second << endl;

	}
	return 0;
}
