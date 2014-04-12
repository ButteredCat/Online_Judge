#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

string::size_type findsub (const string & line, const string & sub)
{
	if ( line.size () >= sub.size ())
	{
		for (string::size_type i = 0; i <= line.size () - sub.size (); ++i)
		{
			string::size_type j, temp = i;
			for (j = 0; j != sub.size (); ++j)
			{
				if (tolower (line[i]) == tolower (sub[j]))
					++i;
				else
					break;
			}
			if (j == sub.size ())
				return temp;
			else
				i = temp;
		}
	}
	return string::npos;
}

int
main ()
{
	string sub, line;

	vector < string > svec;
	cin >> sub;
	while (getline (cin, line))
		svec.push_back (line);
	for (vector < string >::iterator i = svec.begin () + 1;
		 i != svec.end (); ++i)
	{
		string::size_type pos;
		while ((pos = findsub (*i, sub)) != string::npos)
			i->erase (pos, sub.size ());
		while ((pos = i->find (" ")) != string::npos)
			i->erase (pos, 1);
		cout << *i << endl;
	}
	return 0;
}
