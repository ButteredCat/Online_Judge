#include<iostream>
#include<sstream>

using namespace std;

int
main ()
{
    string line;

    while (getline (cin, line))
    {
        int c, x;

        bool isFirst = true;

        istringstream stream (line);

        stream >> c >> x;
        if (x != 0)
        {
            cout << c * x << " " << x - 1;
            isFirst = false;
        }

        while (stream >> c >> x)
        {
            if (x != 0)
            {
                if (isFirst)
                {
                    cout << c * x << " " << x - 1;
                    isFirst = false;
                }
                else
                    cout << " " << c * x << " " << x - 1;
            }
        }
        cout << endl;
    }
    return 0;
}
