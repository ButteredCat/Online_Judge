#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>

using namespace std;

inline int
sum (int n)
{
	ostringstream oss;

	oss << n;
	string s = oss.str ();

	int su = 0;

	for (string::size_type i = 0; i != s.size (); ++i)
		su += s[i] - '0';
	return su;
}

int
main ()
{
	int n;

	while (cin >> n && n)
		cout << sum (n) << " " << sum (n * n) << endl;
	return 0;
}
