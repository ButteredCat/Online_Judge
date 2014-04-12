#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode{
	char c;
	struct BiNode *left;
	struct BiNode *right;
} Node;

Node * create()
{
	Node *T= (Node *) malloc (sizeof(Node));
	if(!T)
		T->left = T->right = NULL;
	return T;
}

int main()
{
	char s1[27]={0};
	char s2[27]={0};

	while(scanf("%s", s1) != EOF)
	{
		scanf("%s", s2);

	}
}
