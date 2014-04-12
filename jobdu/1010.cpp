#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

inline char
convert (const string & a)
{
	const char c1 = *(a.c_str ());

	if (a.size () == 1)
		return c1;
	else
	{
		const char c3 = *(a.c_str () + 2);

		switch (c3)
		{
		case 'e':
			return '1';
		case 'o':
			return '2';
		case 'r':
			return c1 == 'z' ? '0' : '3';
		case 'u':
			return '4';
		case 'v':
			return c1 == 'f' ? '5' : '7';
		case 'x':
			return '6';
		case 'g':
			return '8';
		case 'n':
			return '9';
		default:
			return '0';
		}
	}
}

int
main ()
{
	string line, op;

	while (getline (cin, line))
	{
		stack < int >stk;

		istringstream stream (line);

		while (stream >> op)
		{
			const char o = convert (op);

			if (o == '+')
			{
				int w = 1;

				int n = 0;

				while (!stk.empty ())
				{
					n += stk.top () * w;
					stk.pop ();
					w *= 10;
				}
				stk.push (n);
				stk.push (-1);
			}
			else if (o == '=')
			{
				int w = 1;

				int n = 0;

				while (stk.top () != -1)
				{
					n += stk.top () * w;
					stk.pop ();
					w *= 10;
				}
				stk.pop ();
				stk.push (n);
			}
			else
				stk.push (o - '0');
		}
		int b = stk.top ();

		stk.pop ();
		int a = stk.top ();

		if (a | b)
			cout << a + b << endl;
		else
			break;
	}
	return 0;
}
