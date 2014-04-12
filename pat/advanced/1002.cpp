#include<iostream>
#include<sstream>
#include<map>

using namespace std;

const double EPSINON = 0.000001;

int
main ()
{
	string line1, line2;

	while (getline (cin, line1) && getline (cin, line2))
	{
		map < int, double >m;

		istringstream stream1 (line1), stream2 (line2);

		int k, exp;

		double coe;

		stream1 >> k;
		while (k--)
		{
			stream1 >> exp >> coe;
			m.insert (make_pair (exp, coe));
		}
		stream2 >> k;
		while (k--)
		{
			stream2 >> exp >> coe;
			if (m.count (exp) != 0)
			{
				m[exp] += coe;
				if ((m[exp] >= -EPSINON) && (m[exp] <= EPSINON))
					m.erase (exp);
			}
			else
				m.insert (make_pair (exp, coe));
		}
		cout << m.size ();
		cout.precision (1);
		for (map < int, double >::reverse_iterator i = m.rbegin ();
			 i != m.rend (); ++i)
			cout << " " << i->first << " " << fixed << i->second;
		cout << endl;
	}
	return 0;
}
