#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<cstdlib>

const int pority[5][5] = {
	{1, 1, -1, -1, 1},
	{1, 1, -1, -1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{-1, -1, -1, -1, 0}
};

inline double
plus (double a, double b)
{
	return a + b;
}

inline double
minus (double a, double b)
{
	return a - b;
}

inline double
multi (double a, double b)
{
	return a * b;
}

inline double
div (double a, double b)
{
	return a / b;
}

int
main ()
{
	std::string line, op;
	double (*pf[4]) (double, double) =
	{
	plus, minus, multi, div};
	while (getline (std::cin, line) && line != "0")
	{
		std::istringstream stream (line + " #");
		std::stack < double >opnd;

		std::stack < int >optr;

		optr.push (4);
		while (stream >> op)
		{
			if (op == "+" || op == "-" || op == "*" || op == "/"
				|| op == "#")
			{
				int o;

				switch (*(op.c_str ()))
				{
				case '+':
					o = 0;
					break;
				case '-':
					o = 1;
					break;
				case '*':
					o = 2;
					break;
				case '/':
					o = 3;
					break;
				default:
					o = 4;
					break;
				}
				switch (pority[optr.top ()][o])
				{
				case 1:
					while (pority[optr.top ()][o] > 0)
					{
						double post = opnd.top ();

						opnd.pop ();
						double pre = opnd.top ();

						opnd.pop ();
						opnd.push (pf[optr.top ()](pre, post));
						optr.pop ();
					}
					optr.push (o);
					break;
				case -1:
					optr.push (o);
					break;
				default:
					break;
				}
			}
			else
				opnd.push (atoi (op.c_str ()));
		}
		std::cout.precision (2);
		std::cout << std::fixed << opnd.top () << std::endl;
	}
	return 0;
}
