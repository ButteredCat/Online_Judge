#include<iostream>
#include<string>

using namespace std;

int
main ()
{
	string s;

	char c;

	while (cin >> s >> c)
	{
		string::size_type pos;
		while ((pos = s.find (c)) != string::npos)
			s.erase (s.begin () + pos);
		cout << s << endl;
	}
	return 0;
}
