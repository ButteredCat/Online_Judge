#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode
{
	int n;
	struct BiNode *left;
	struct BiNode *right;
} Node;

Node *
create (void)
{
	Node *pt;

	pt = (Node *) malloc (sizeof (Node));
	pt->left = pt->right = NULL;

	return pt;
}

Node *
insert (Node * T, int x)
{
	if (T == NULL)
	{
		T = create ();
		T->n = x;
	}
	else if (x < T->n)
		T->left = insert (T->left, x);
	else if (x > T->n)
		T->right = insert (T->right, x);

	return T;
}

void
destory (Node * T)
{
	if (T->left != NULL)
		destory (T->left);
	if (T->right != NULL)
		destory (T->right);

	free (T);
}

void
preOrder (Node * T)
{
	printf ("%d ", T->n);
	if (T->left)
		preOrder (T->left);
	if (T->right)
		preOrder (T->right);
}

void
inOrder (Node * T)
{
	if (T->left)
		inOrder (T->left);
	printf ("%d ", T->n);
	if (T->right)
		inOrder (T->right);
}

void
postOrder (Node * T)
{
	if (T->left)
		postOrder (T->left);
	if (T->right)
		postOrder (T->right);
	printf ("%d ", T->n);
}


int
main ()
{
	int n, x, i;

	Node *T;

	while (scanf ("%d", &n) != EOF)
	{
		T = NULL;
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
		destory (T);
	}
	return 0;
}
