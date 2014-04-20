#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Student
{
private:
    int id;
    int de;
    int cai;
    int total;
    int grade;
public:
    Student (const int &i, const int &d, const int &c, const int &g)
    {
        id = i;
        de = d;
        cai = c;
        total = d + c;
        grade = g;
    }
    const int &getId() const
    {
        return id;
    }
    const int &getDe() const
    {
        return de;
    }
    const int &getCai() const
    {
        return cai;
    }
    bool operator < (const Student &b) const
    {
        if (this->grade != b.grade)
            return this->grade > b.grade;
        else if (this->total != b.total)
            return this->total < b.total;
        else if (this->de != b.de)
            return this->de < b.de;
        else
            return this->id > b.id;
    }
};

int main (void)
{
    int n, l, h;
    vector<Student> v;

    scanf ("%d %d %d", &n, &l, &h);

    while (n--)
    {
        int id, de, cai;
        scanf ("%d %d %d", &id, &de, &cai);

        if (de >= h && cai >= h)
            v.push_back ( Student (id, de, cai, 0)  );
        else if (de >= h && cai >= l)
            v.push_back (Student (id, de, cai, 1) );
        else if (de >= l && cai >= l )
            v.push_back (Student (id, de, cai, de >= cai ? 2 : 3) );
    }

    sort (v.begin(), v.end() );

    printf ("%d\n", v.size() );

    for (vector<Student>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
        printf ("%d %d %d\n", j->getId(), j->getDe(), j->getCai() );

    return 0;
}
