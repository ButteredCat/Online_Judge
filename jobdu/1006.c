#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int
main ()
{
	char s[1000];

	char *pz, *pj, *end;

	int oa, ob, oc;

	while (scanf ("%s", s) != EOF)
	{
		if ((pz = strchr (s, 'z')) == NULL
			|| (pj = strchr (s, 'j')) == NULL)
		{
			printf ("Wrong Answer\n");
			continue;
		}
		if (pz >= pj)
		{
			printf ("Wrong Answer\n");
			continue;
		}
		/* count 'o' */
		end = s + strlen (s) - 1;
		*pz = *pj = '\0';
		if ((oa = strspn (s, "o")) != (pz - s)
			|| (ob = strspn (pz + 1, "o")) != (pj - pz - 1)
			|| (oc = strspn (pj + 1, "o")) != (end - pj))
		{
			printf ("Wrong Answer\n");
			continue;
		}

		if (ob == 0 || ob * oa != oc)
		{
			printf ("Wrong Answer\n");
			continue;
		}
		printf ("Accepted\n");
	}
	return 0;
}
