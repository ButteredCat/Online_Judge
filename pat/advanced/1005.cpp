#include<iostream>
#include<sstream>

using namespace std;

const string table[] =
{
    "zero", "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine"
};

int
main ()
{
    string n;

    while (cin >> n)
    {
        int sum = 0;

        string::size_type i;
        for (i = 0; i != n.size (); ++i)
            sum += n[i] - '0';
        ostringstream oss;

        oss << sum;
        n = oss.str ();
        i = 0;
        cout << table[n[i++] - '0'];
        for (; i != n.size (); ++i)
            cout << " " << table[n[i] - '0'];
        cout << endl;
    }
    return 0;
}
