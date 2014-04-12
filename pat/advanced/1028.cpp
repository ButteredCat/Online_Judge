#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Rec
{
	string id;
	string name;
	int grade;
};

bool
id_cmp (const Rec & a, const Rec & b)
{
	if (a.id.compare (b.id) < 0)
		return true;
	else
		return false;
}

bool
name_cmp (const Rec & a, const Rec & b)
{
	if (a.name.compare (b.name) < 0)
		return true;
	else if (a.name.compare (b.name) == 0)
		return id_cmp (a, b);
	else
		return false;
}

bool
grade_cmp (const Rec & a, const Rec & b)
{
	if (a.grade == b.grade)
		return id_cmp (a, b);
	else
		return a.grade < b.grade;
}

int
main ()
{
	int n, c;

	bool (*cmp[])(const Rec & a, const Rec & b) =
	{
	id_cmp, name_cmp, grade_cmp};
	while (cin >> n >> c)
	{
		vector < Rec > v;
		while (n--)
		{
			Rec r;

			cin >> r.id >> r.name >> r.grade;
			v.push_back (r);
		}
		sort (v.begin (), v.end (), cmp[c - 1]);
		for (vector < Rec >::iterator i = v.begin (); i != v.end (); ++i)
			cout << i->id << " " << i->name << " " << i->grade << endl;
	}
	return 0;
}
