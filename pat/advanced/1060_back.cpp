#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>

using namespace std;

string
convert (double a, int precision)
{
    stringstream ss, sss, ssss;

    ss << scientific << a;
    string sa = ss.str ();

    sa.erase (sa.begin () + sa.find ("."));
    sa = "0." + sa;
    string s1 (sa.begin (), sa.begin () + 2 + precision);

    string s2 (sa.begin () + sa.find ("e") + 1, sa.end ());

    sss << s2;
    int pow;

    sss >> pow;
    if (pow != 0)
        ++pow;
    ssss << pow;
    s2 = ssss.str ();
    return s1 + "*10^" + s2;
}

int
main ()
{
    int n;

    double a, b;

    while (cin >> n >> a >> b)
    {
        string aa = convert (a, n);

        string bb = convert (b, n);

        if (aa == bb)
            cout << "YES " << aa << endl;
        else
            cout << "NO " << aa << " " << bb << endl;
    }
    return 0;
}
