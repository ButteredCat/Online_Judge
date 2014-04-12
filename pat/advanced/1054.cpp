#include<cstdio>
#include<map>

using namespace std;

int
main ()
{
	int m, n, color;

	while (scanf ("%d%d", &m, &n) != EOF)
	{
		map < int, int >set;

		m *= n;
		for (int i = 0; i < m; ++i)
		{
			scanf ("%d", &color);
			++set[color];
		}
		m /= 2;
		for (map < int, int >::iterator i = set.begin (); i != set.end ();
			 ++i)
			if (i->second > m)
				printf ("%d\n", i->first);
	}
	return 0;
}
