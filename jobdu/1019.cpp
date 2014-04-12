#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<cstdlib>
using
	std::cin;

using
	std::cout;

using
	std::string;

using
	std::istringstream;

using std::stack;

const int
pority[4][4] =
	{ {-1, -1, -1, -1}, {-1, -1, -1, -1}, {1, 1, -1, -1}, {1, 1, -1, -1} };

inline int
cmp (const string & a, const string & b)
{
	int
		x,
		y;

	switch (*(a.c_str ()))
	{
	case '+':
		x = 0;
		break;
	case '-':
		x = 1;
		break;
	case '*':
		x = 2;
		break;
	case '/':
		x = 3;
		break;
	default:
		break;
	}
	switch (*(b.c_str ()))
	{
	case '+':
		y = 0;
		break;
	case '-':
		y = 1;
		break;
	case '*':
		y = 2;
		break;
	case '/':
		y = 3;
		break;
	default:
		break;
	}
	return pority[x][y];
}

double
plus (const double &a, const double &b)
{
	return a + b;
}

double
minus (const double &a, const double &b)
{
	return a - b;
}

double
multi (const double &a, const double &b)
{
	return a * b;
}

double
div (const double &a, const double &b)
{
	return a / b;
}

int
main ()
{
	string line, op;

	double (*process[6]) (const double &, const double &) =
	{
	multi, plus, NULL, minus, NULL, div};
	while (getline (cin, line) && line != "0")
	{
		stack < double >
			opnd;

		stack < string > optr;
		istringstream
		stream (line);

		while (stream >> op)
		{
			if (op == "+" || op == "-" || op == "*" || op == "/")
			{
				if (!optr.empty ())
				{
					if (cmp (optr.top (), op) < 0)
					{
						while (cmp (optr.top (), op) < 0)
						{
							double
								pre = opnd.top ();

							opnd.pop ();
							double
								post = opnd.top ();

							opnd.pop ();
							opnd.
								push (process[*(op.c_str ()) - '*']
									  (pre, post));
						}
						optr.push (op);
					}
					else
						optr.push (op);
				}
				else
					optr.push (op);
			}
			else
				opnd.push (atoi (op.c_str ()));
			
			float sum=0;
			while(!optr.empty())
			{
				double pre=opnd.top();
				opnd.pop();
				double 
			}
		}
	}
	return 0;
}
