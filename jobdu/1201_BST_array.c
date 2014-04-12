#include<stdio.h>
#include<string.h>

typedef struct BiNode
{
	struct BiNode *lchild;
	struct BiNode *rchild;
	int c;
} Node;

Node Tree[110];

int loc;

Node *
create ()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

void
postOrder (Node * T)
{
	if (T->lchild != NULL)
		postOrder (T->lchild);
	if (T->rchild != NULL)
		postOrder (T->rchild);
	printf ("%d ", T->c);
}

void
inOrder (Node * T)
{

	if (T->lchild != NULL)
		inOrder (T->lchild);
	printf ("%d ", T->c);
	if (T->rchild != NULL)
		inOrder (T->rchild);
}

void
preOrder (Node * T)
{
	printf ("%d ", T->c);
	if (T->lchild != NULL)
		preOrder (T->lchild);
	if (T->rchild != NULL)
		preOrder (T->rchild);
}

Node *
insert (Node * T, int x)
{
	if (T == NULL)
	{
		T = create ();
		T->c = x;
	}
	else if (x < T->c)
		T->lchild = insert (T->lchild, x);
	else if (x > T->c)
		T->rchild = insert (T->rchild, x);

	return T;
}

int
main ()
{
	int n, x, i;

	while (scanf ("%d", &n) != EOF)
	{
		loc = 0;
		Node *T = NULL;

		for (i = 0; i < n; i++)
		{
			scanf ("%d", &x);
			T = insert (T, x);
		}
		preOrder (T);
		printf ("\n");
		inOrder (T);
		printf ("\n");
		postOrder (T);
		printf ("\n");
	}
	return 0;
}
