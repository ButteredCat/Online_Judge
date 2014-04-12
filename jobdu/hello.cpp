#include<iostream>

using namespace std;

int
main ()
{
	int a[3] = { 0, 1, 2 };
	int *p = a + 4;

	cout << "hello, world!" << endl << *p << endl;

	return 0;
}
