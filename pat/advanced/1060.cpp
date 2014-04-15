#include<iostream>
#include<sstream>

using namespace std;

string
convert (string a, int d)
{
    int pow;

    // 0 <= a < 1
    if (a.find ("0.") == 0)
    {
        string::size_type start = a.find_first_not_of ("0", 2);
        // a == 0.000...
        if (start == string::npos)
        {
            string s2 = "0.";

            while (d--)
                s2 += "0";
            return s2 + "*10^0";
        }
        pow = a.find (".") - start + 1;
        ostringstream oss;

        oss << pow;
        string s1 = oss.str ();

        string s2;

        if (start + d >= a.size ())
        {
            s2.assign (a.begin () + start, a.end ());
            int k = start + d - a.size ();

            while (k--)
                s2 += "0";
        }
        else
            s2.assign (a.begin () + start, a.begin () + start + d);
        return "0." + s2 + "*10^" + s1;
    }
    // a == 0
    else if (a == "0")
    {
        string s2 = "0.";

        while (d--)
            s2 += "0";
        return s2 + "*10^0";
    }
    // a >= 1
    else
    {
        string::size_type start = a.find_first_not_of ("0");
        string::size_type dot = a.find (".");
        string s1, s2;

        ostringstream oss;

        if (dot != string::npos)
        {
            pow = dot - start;
            a.erase (a.begin () + dot);
        }
        else
            pow = a.size ();
        oss << pow;
        s1 = oss.str ();
        if (a.size () < d)
        {
            s2.assign (a.begin (), a.end ());
            int k = d - a.size ();

            while (k--)
                s2 += "0";
        }
        else
        {
            s2.assign (a.begin (), a.begin () + d);
        }
        return "0." + s2 + "*10^" + s1;
    }
}

int
main ()
{
    string a, b;

    int n;

    while (cin >> n >> a >> b)
    {
        a = convert (a, n);
        b = convert (b, n);
        if (a == b)
            cout << "YES " << a << endl;
        else
            cout << "NO " << a << " " << b << endl;
    }
    return 0;
}
