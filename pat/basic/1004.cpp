#include<iostream>
#include<string>

using namespace std;

struct stu
{
    string name;
    string id;
    int mark;
};

int
main ()
{
    int n;

    while (cin >> n)
    {
        stu max, min, in;

        cin >> in.name >> in.id >> in.mark;
        max = min = in;
        while (--n)
        {
            cin >> in.name >> in.id >> in.mark;
            max = max.mark > in.mark ? max : in;
            min = min.mark < in.mark ? min : in;
        }
        cout << max.name << " " << max.id << endl
             << min.name << " " << min.id << endl;
    }
    return 0;
}
