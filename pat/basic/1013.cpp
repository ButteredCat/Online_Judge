#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int
main (void)
{
    int m, n;

    while (cin >> m >> n)
    {
        vector<int> iv;

        iv.push_back (2);
        for (vector<int>::size_type i = 3; (int) iv.size () < n; i += 2)
        {
            int sqr = (int) sqrt (i);

            bool isPrime = true;

            for (vector<int>::size_type j = 0;
                    j < iv.size () && iv[j] <= sqr; ++j)
                if (i % iv[j] == 0)
                {
                    isPrime = false;
                    break;
                }
            if (isPrime)
                iv.push_back (i);
        }

        const string s = "         \n";

        int i, j;

        for (i = m - 1, j = 0; i < n - 1; ++i)
            cout << iv[i] << s[j++ % 10];

        cout << iv[i] << endl;
    }
    return 0;
}
