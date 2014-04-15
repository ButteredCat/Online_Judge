#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Type
{
public:
    int count;	// forget about the encapsulation now!
    int toPrint; // to print on screen, the meaning varies
    Type ():count (0), toPrint (0)
    {
    }
};

int
main (void)
{
    int n;

    while (cin >> n)
    {
        int m;

        Type t[5];

        for (int i = 0; i < n; ++i)
        {
            cin >> m;
            switch (m % 5)
            {
            case 0:
                if (m % 2 == 0)
                {
                    ++t[0].count;
                    t[0].toPrint += m;
                }
                break;
            case 1:
                ++t[1].count;
                t[1].toPrint += t[1].count % 2 ? m : -m;
                break;
            case 2:
                t[2].toPrint = ++t[2].count;
                break;
            case 3:
                ++t[3].count;
                t[3].toPrint += m;
                break;
            default:
                ++t[4].count;
                if (m > t[4].toPrint)
                    t[4].toPrint = m;
                break;
            }

        }
        if (t[0].count != 0)
            cout << t[0].toPrint;
        else
            cout << "N";
        for (int i = 1; i < 5; ++i)
        {
            if (t[i].count == 0)
                cout << " N";
            else
            {
                if (i == 3)
                    cout << " " << fixed << setprecision (1) << (double)
                         t[i].toPrint / t[i].count;
                else
                    cout << " " << t[i].toPrint;
            }
        }
        cout << endl;

    }
    return 0;
}
