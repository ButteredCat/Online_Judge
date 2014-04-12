#include<iostream>
#include<vector>

using namespace std;

const float point[] = { 1.0, 1.0, 1.0, 1.0,
	1.5, 1.5, 1.5, 1.5,
	2.0, 2.0, 2.0, 2.0,
	2.3, 2.3, 2.3,
	2.7, 2.7, 2.7,
	3.0, 3.0, 3.0, 3.0,
	3.3, 3.3, 3.3,
	3.7, 3.7, 3.7, 3.7, 3.7
};

class Course
{
  public:
	Course ():grade (0.0), credit (0.0)
	{
	}
	Course (int n, float c)
	{
		grade = toGrade (n);
		credit = c;
	}
	void setGrade (int n)
	{
		grade = toGrade (n);
	}
	void setCredit (float c)
	{
		credit = c;
	}
	float getGrade ()
	{
		return grade;
	}
	float getCredit ()
	{
		return credit;
	}
  private:
	float grade;

	float credit;

	float toGrade (int n)
	{
		n -= 60;
		if (n < 0)
			return 0.0;
		else if (n >= 30)
			return 4.0;
		else
			return point[n];
	}
};


int
main ()
{
	int n;

	while (cin >> n)
	{
		vector < Course > cos;
		vector < Course >::iterator icos;
		float credit;

		for (int i = 0; i < n; ++i)
		{
			cin >> credit;
			Course input (0, credit);

			cos.push_back (input);
		}
		for (icos = cos.begin (); icos != cos.end (); ++icos)
		{
			int mark;

			cin >> mark;
			icos->setGrade (mark);

		}

		float sum_gpa = 0;

		float sum_credit = 0;

		for (icos = cos.begin (); icos != cos.end (); ++icos)
		{
			sum_gpa += icos->getGrade () * icos->getCredit ();
			sum_credit += icos->getCredit ();
		}
		cout.precision (2);
		cout << fixed << sum_gpa / sum_credit << endl;
	}
	return 0;

}
