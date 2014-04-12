#include<stdio.h>
#include<string.h>

const char code[] =
	{ 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'
};

int
main ()
{
	char s[201] = { 0 };
	char buffer[201] = { 0 };
	int i, length;

	while (scanf ("%s", buffer) != EOF && strcmp (buffer, "ENDOFINPUT"))
	{
		memset (s, 0, sizeof (s));
		if (!strcmp (buffer, "START"))
		{
			while (scanf ("%s", buffer) != EOF && strcmp (buffer, "END"))
			{
				if (strlen (s))
					strcat (s, " ");
				strcat (s, buffer);
			}

			length = strlen (s);
			for (i = 0; i < length; i++)
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = code[s[i] - 'A'];
			}
			printf ("%s\n", s);
			continue;
		}
	}
	return 0;
}
