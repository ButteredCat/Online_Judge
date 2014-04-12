#include<iostream>
#include<stack>

using namespace std;

int
main ()
{
	int n;

	while (cin >> n && n)
	{
		stack < int >stk;

		while (n--)
		{
			char op;

			cin >> op;
			switch (op)
			{
			case 'P':
				{
					int e;

					cin >> e;
					stk.push (e);
				}
				break;
			case 'O':
				if (!stk.empty ())
					stk.pop ();
				break;
			case 'A':
				stk.empty ()? cout << "E" << endl : cout << stk.top () <<
					endl;
			}
		}
		cout << endl;
	}
	return 0;
}
