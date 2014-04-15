#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

struct ID
{
    string name;
    string passwd;
    int replaced;
};


int
main ()
{
    int n;

    vector < pair < string, string > >v;
    v.push_back (make_pair ("1", "@"));
    v.push_back (make_pair ("0", "%"));
    v.push_back (make_pair ("l", "L"));
    v.push_back (make_pair ("O", "o"));

    while (cin >> n)
    {
        ID *p = new ID[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> p[i].name >> p[i].passwd;
            p[i].replaced = 0;
        }
        int replaced = 0;

        for (int i = 0; i < n; ++i)
        {
            string::size_type pos = 0;
            for (string::size_type j = 0; j < 4; ++j)
                while ((pos =
                            p[i].passwd.find (v[j].first)) != string::npos)
                {
                    p[i].passwd.replace (pos, 1, v[j].second);
                    ++p[i].replaced;
                }
            if (p[i].replaced > 0)
                ++replaced;
        }
        if (replaced != 0)
        {
            cout << replaced << endl;
            for (int i = 0; i < n; ++i)
                if (p[i].replaced > 0)
                    cout << p[i].name << " " << p[i].passwd << endl;
        }
        else
        {
            if (n == 1)
                cout << "There is " << n <<
                     " account and no account is modified" << endl;
            else
                cout << "There are " << n <<
                     " accounts and no account is modified" << endl;
        }
        delete[]p;
    }
    return 0;
}
