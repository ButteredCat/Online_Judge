#include<iostream>
#include<vector>
#include<string>

using namespace std;

const string radix = "0123456789ABC";

string
convert (int n)
{
    vector < char >v;

    if (n < 13)
    {
        v.push_back (radix[n]);
        v.push_back ('0');
    }
    else
        while (n)
        {
            v.push_back (radix[n % 13]);
            n /= 13;
        }
    string s (v.rbegin (), v.rend ());

    return s;
}

int
main ()
{
    int r, g, b;

    while (cin >> r >> g >> b)
        cout << "#" << convert (r) << convert (g) << convert (b) << endl;
    return 0;
}
