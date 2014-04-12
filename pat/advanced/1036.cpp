#include<iostream>
#include<map>

using namespace std;

class student
{
  public:
	student (const string & a, const string & b)
	{
		name = a;
		id = b;
	}
	string getname ()
	{
		return name;
	}
	string getid ()
	{
		return id;
	}
  private:
	string name;
	string id;
};

int
main ()
{
	int n;

	while (cin >> n)
	{
		string name, gender, id;

		int grade;

		map < int, student > boy, girl;

		while (n--)
		{
			cin >> name >> gender >> id >> grade;
			student a (name, id);

			if (gender == "M")
				boy.insert (make_pair (grade, a));
			else
				girl.insert (make_pair (grade, a));
		}
		map < int, student >::reverse_iterator ih = girl.rbegin ();

		map < int, student >::iterator il = boy.begin ();

		if (girl.empty ())
			cout << "Absent" << endl;
		else
			cout << ih->second.getname () << " " << ih->second.
				getid () << endl;

		if (boy.empty ())
			cout << "Absent" << endl;
		else
			cout << il->second.getname () << " " << il->
				second.getid () << endl;

		if (girl.empty () || boy.empty ())
			cout << "NA" << endl;
		else
			cout << (ih->first - il->first) << endl;
	}
	return 0;
}
