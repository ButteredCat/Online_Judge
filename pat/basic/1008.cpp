#include<iostream>

using namespace std;

void
reverse (int *p, int begin, int end)
{
    for (; begin < end; ++begin, --end)
    {
        int temp = p[end];
        p[end] = p[begin];
        p[begin] = temp;
    }
}

void
shiftRight (int *p, int n, int m)
{
    m = m % n;
    reverse (p, 0, n - m - 1);
    reverse (p, n - m, n - 1);
    reverse (p, 0, n - 1);
}

int
main ()
{
    int n, m;                   // length=n, shift right m

    while (cin >> n >> m)
    {
        int i, *p = new int[n];

        for (i = 0; i != n; ++i)
            cin >> p[i];

        shiftRight (p, n, m);

        for (i = 0; i != n - 1; ++i)
            cout << p[i] << " ";

        cout << p[i] << endl;

        delete[] p;
    }

    return 0;
}
