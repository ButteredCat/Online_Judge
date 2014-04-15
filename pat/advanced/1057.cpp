#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int
main ()
{
    int n;

    scanf ("%d", &n);

    stack< int, vector<int> > stk;
    vector<int> v;
    while (n--)
    {
        char op[12];

        scanf ("%s", op);
        if (strcmp (op, "Pop") == 0)
        {
            if (!stk.empty ())
            {
                int e = stk.top ();

                stk.pop ();
                int k=0;
                while(v[k]!=e)
                    ++k;
                v.erase(v.begin()+k);
                printf ("%d\n", e);
            }
            else
                printf ("Invalid\n");
        }
        else if (strcmp (op, "Push") == 0)
        {
            int e;

            scanf ("%d", &e);
            stk.push (e);
            v.push_back(e);
        }
        else if (strcmp (op, "PeekMedian") == 0)
        {
            if (!stk.empty ())
            {
                stack < int >::size_type m = stk.size ();

                m = (m + m % 2) / 2 - 1;
                nth_element (v.begin (), v.begin () + m, v.end ());
                printf ("%d\n", *(v.begin () + m));
            }
            else
                printf ("Invalid\n");
        }
    }

    return 0;
}
