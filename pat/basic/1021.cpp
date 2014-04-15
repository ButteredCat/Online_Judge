#include<string>
#include<iostream>

using namespace std;

int
main (void)
{
    string s;

    while (cin >> s)
    {
        int m[10] = { 0 };
        for (int i = 0; i < (int) s.size (); ++i)
            ++m[s[i] - '0'];
        for (int i = 0; i < 10; ++i)
            if (m[i] != 0)
                cout << i << ":" << m[i] << endl;
    }

    return 0;
}
