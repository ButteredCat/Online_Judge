#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>

using namespace std;

const string R = "0123456789";

string
radixDrev (int n, int d)
{
	vector < char >v;

	if (n == 0)
		v.push_back (R[0]);
	else
		while (n)
		{
			v.push_back (R[n % d]);
			n /= d;
		}
	string s (v.begin (), v.end ());

	return s;
}

int
toDecimal (const string & s, int d)
{
	int n = 0;

	int radix = 1;

	int i = s.size ();

	while (i--)
	{
		n += (s[i] - '0') * radix;
		radix *= d;
	}
	return n;
}

bool
isPrime (int n)
{
	if (n == 1 || n == 0)
		return false;
	else if (n > 2)
	{
		int i = 2;

		int sqr = sqrt (n);

		for (; i <= sqr; ++i)
			if (n % i == 0)
				return false;
	}
	return true;
}

int
main ()
{
	int n, d;

	while (cin >> n && (n > 0) && cin >> d)
	{
		if (!isPrime (n))
		{
			cout << "No" << endl;
			continue;
		}
		else
			cout << (isPrime (toDecimal (radixDrev (n, d), d)) ? "Yes" :
					 "No") << endl;
	}
	return 0;
}
