#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Stu
{
	string id;
	string in;
	string out;
};

bool
inCmp (Stu a, Stu b)
{
	if (a.in.compare (b.in) < 0)
		return true;
	else
		return false;
}

bool
outCmp (Stu a, Stu b)
{
	if (a.out.compare (b.out) < 0)
		return true;
	else
		return false;
}

int
main ()
{
	int m;

	while (cin >> m)
	{
		vector < Stu > v;
		while (m--)
		{
			Stu s;

			cin >> s.id >> s.in >> s.out;
			v.push_back (s);
		}
		cout << min_element (v.begin (), v.end (), inCmp)->id << " "
			<< max_element (v.begin (), v.end (), outCmp)->id << endl;
	}
	return 0;
}
