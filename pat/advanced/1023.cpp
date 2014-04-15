#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int
main ()
{
    string n;

    while (cin >> n)
    {
        int carry = 0;

        string dubl, orig = n;

        string::size_type size = n.size ();
        string::size_type i = size - 1;
        while (size--)
        {
            int prodct = (n[i] - '0') * 2 + carry;

            if (prodct > 9)
            {
                prodct %= 10;
                carry = 1;
            }
            else
                carry = 0;
            n[i] = prodct + '0';
            if ((i == 0) && (carry == 1))
                n = "1" + n;
            --i;
        }
        dubl = n;
        sort (orig.begin (), orig.end ());
        sort (dubl.begin (), dubl.end ());
        cout << (orig == dubl ? "Yes" : "No") << endl << n << endl;
    }
    return 0;
}
