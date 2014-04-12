#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TREE_TYPE int

typedef struct TREE_NODE
{
	TREE_TYPE value;			/* tree type */
	struct TREE_NODE *left;
	struct TREE_NODE *right;
} TreeNode, *Tree;


void
insert (Tree * link, TREE_TYPE value)
{
	Tree current;

	while ((current = *link) != NULL)
	{
		if (value < current->value)
			link = &current->left;
		else
		{
			assert (value != current->value);
			link = &current->right;
		}
	}
	current = (TreeNode *) malloc (sizeof (TreeNode));
	assert (current != NULL);
	current->value = value;
	current->left = current->right = NULL;
	*link = current;
}

TREE_TYPE *
find (Tree * link, TREE_TYPE value)
{
	Tree current = *link;

	while (current != NULL && current->value != value)
	{
		if (value < current->value)
			current = current->left;
		else
			current = current->right;
	}
	if (current != NULL)
		return &current->value;
	else
		return NULL;
}

static void
pre_order_traverse(Tree current, 

int
main ()
{
	return 0;
}
