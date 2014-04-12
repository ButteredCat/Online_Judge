#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Person
{
  public:
	Person (const string & n, int a, int w)
	{
		name = n;
		age = a;
		worth = w;
	}
	bool operator < (const Person & b) const
	{
		if (worth != b.worth)
			return worth < b.worth;
		else if (age != b.age)
			return age > b.age;
		else
			return name.compare (b.name) > 0;
	}
	const char *getname ()
	{
		return name.c_str ();
	}
	int getage ()
	{
		return age;
	}
	int getworth ()
	{
		return worth;
	}
  private:
	string name;
	int age;

	int worth;
};

int
main ()
{
	int n, k;

	vector < Person > v;

	scanf ("%d%d", &n, &k);
	while (n--)
	{
		char name[9];

		int age, worth;

		scanf ("%s%d%d", name, &age, &worth);
		string n (name);

		Person one (n, age, worth);

		v.push_back (one);
	}
	sort (v.begin (), v.end ());
	for (int i = 1; i <= k; ++i)
	{
		int m, max, min;

		scanf ("%d%d%d", &m, &min, &max);
		int count = m;

		printf ("Case #%d:\n", i);
		for (vector < Person >::reverse_iterator it = v.rbegin ();
			 it != v.rend (); ++it)
		{
			if (it->getage () >= min && it->getage () <= max)
			{
				printf ("%s %d %d\n", it->getname (),
						it->getage (), it->getworth ());
				if (--count == 0)
					break;
			}
		}
		if (count == m)
			printf ("None\n");
	}
	return 0;
}
