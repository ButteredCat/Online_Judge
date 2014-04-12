#include<stdio.h>

void MyStrcat(char dstStr[], char srcStr[])
{
	int ldst=0;
	int lsrc=0;
	char *p=dstStr;
	while(*p)
	{
		++p;
		++length;
	}
}

int main()
{
	char s1[200];
	char s2[200];
	while(scanf("%s %s", s1, s2) != EOF)
	{
		MyStrcat(s1, s2);
		printf("%s\n", s1);
	}
	return 0;
}
