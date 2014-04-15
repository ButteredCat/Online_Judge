#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Person
{
public:
    Person (const string & n, int a, int w)
    {
        name = n;
        age = a;
        worth = w;
    }
    bool operator < (const Person & b) const
    {
        if (worth != b.worth)
            return worth < b.worth;
        else if (age != b.age)
            return age > b.age;
        else
            return name.compare (b.name) > 0;
    }
    const char *getname ()
    {
        return name.c_str ();
    }
    int getage ()
    {
        return age;
    }
    int getworth ()
    {
        return worth;
    }
private:
    string name;
    int age;

    int worth;
};

int
main ()
{
    int n, k;

    vector < vector< Person > > v(201);

    scanf ("%d%d", &n, &k);
    while (n--)
    {
        char name[9];

        int age, worth;

        scanf ("%s%d%d", name, &age, &worth);
        string n (name);

        Person one (n, age, worth);

        v.push_back (one);
    }
    for (int i = 1; i <= k; ++i)
    {
        int m, max, min;

        scanf ("%d%d%d", &m, &min, &max);
        printf ("Case #%d:\n", i);
    }
    return 0;
}
