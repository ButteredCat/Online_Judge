#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int
main ()
{
	string line, word, a, b;

	while (getline (cin, line) && cin >> a >> b)
	{
		istringstream stream (line);

		stream >> word;
		cout << (!word.compare (a) ? b : word);
		while (stream >> word)
			cout << " " << (!word.compare (a) ? b : word);
		cout << endl;
		cin.ignore ();
	}
	return 0;
}
