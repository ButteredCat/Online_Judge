#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int
main ()
{
	string line, word;

	while (getline (cin, line))
	{
		line.erase (line.find ("."));
		istringstream stream (line);

		stream >> word;
		cout << word.size ();

		while (stream >> word)
		{
			cout << " " << word.size ();
		}
		cout << endl;
	}
	return 0;
}
