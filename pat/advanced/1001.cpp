#include<iostream>
#include<sstream>

using namespace std;

int
main ()
{
    int a, b;

    while (cin >> a >> b)
    {
        a = a + b;
        if (a < 0)
        {
            cout << "-";
            a = 0 - a;
        }
        ostringstream oss;

        oss << a;
        string sum = oss.str ();

        string::size_type i = 0;
        cout << sum.substr (0, sum.size () % 3);
        for (i += sum.size () % 3; i < sum.size (); i += 3)
        {
            if (i == 0)
                cout << sum.substr (i, 3);
            else
                cout << "," << sum.substr (i, 3);
        }
        cout << endl;
    }
    return 0;
}
