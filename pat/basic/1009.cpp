#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int
main ()
{
	string line, word;

	while (getline (cin, line))
	{
		vector < string > v;
		istringstream stream (line);

		while (stream >> word)
			v.push_back (word);
		vector < string >::reverse_iterator i = v.rbegin ();
		cout << *i++;
		for (; i != v.rend (); ++i)
			cout << " " << *i;
		cout << endl;
	}
	return 0;
}
