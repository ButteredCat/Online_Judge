#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int
main (void)
{
    int n;

    while (cin >> n)
    {
        vector<int> iv (1, 2); // initialize, the first prime number is 2

        for (int i = 3; i <= n; i += 2)
        {
            int sqr = sqrt (i);
            bool isPrime = true;

            for (int j = 0; iv[j] <= sqr; ++j)
            {
                if (i % iv[j] == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                iv.push_back (i);
        }

        int pairs = 0;

        for (vector<int>::size_type i = 0; i != iv.size() ; ++i)
        {
            if (iv[i + 1] - iv[i] == 2)
                ++pairs;
        }

        cout << pairs << endl;
    }

    return 0;
}
