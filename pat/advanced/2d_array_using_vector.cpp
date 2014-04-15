// string subtraction
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int
main ()
{
    string s1, s2;

    while (getline (cin, s1) && getline (cin, s2))
    {
        vector < vector < int > > table (128);

        for (string::size_type i = 0; i != s1.size (); ++i)
            table[s1[i] - 0].push_back (i);
        for (string::size_type i = 0; i != s2.size (); ++i)
        {
            for (vector < int >::iterator iter = table[s2[i] - 0].begin ();
                    iter != table[s2[i] - 0].end (); ++iter)
                table[0].push_back (*iter);
            table[s2[i] - 0].clear ();
        }
        for (int i = 0; i != 128; ++i)
        {
            for (vector < int >::iterator iter = table[i].begin ();
                    iter != table[i].end (); ++iter)
                s1[*iter] = (char) i;
        }
        cout << s1 << endl;
    }
    return 0;
}
