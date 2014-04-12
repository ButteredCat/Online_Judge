#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int
main ()
{
	string s1, s2;

	while (getline (cin, s1) && getline (cin, s2))
	{
		vector < bool > subtrac (128, false);
		for (string::size_type i = 0; i != s2.size (); ++i)
			subtrac[s2[i]] = true;
		for (string::size_type i = 0; i != s1.size (); ++i)
			if (!subtrac[s1[i]])
				printf ("%c", s1[i]);
		printf ("\n");
	}
	return 0;
}
