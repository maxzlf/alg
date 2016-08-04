#include "../utils/sys.h"
#include "../utils/error.h"
#include "../utils/type.h"
#include "../utils/utils.h"
#include "tree.h"

tnode *createTnode(int value)
{
	tnode *node = (tnode *)malloc(sizeof(tnode));
	node->value = value;
	node->pstLeft = NULL;
	node->pstRight = NULL;
	return node;
}

tnode *addTnode(tnode *tree, tnode *node)
{
	if (NULL == node) return tree;
	if (NULL == tree) return node;

	tnode *current = tree;
	tnode *father;
	while (NULL != current)
	{
		father = current;
		if (current->value >= node->value)
		{
			current = current->pstLeft;
		}
		else
		{
			current = current->pstRight;
		}
	}
	if (father->value >= node->value)
	{
		father->pstLeft = node;
	}
	else
	{
		father->pstRight = node;
	}

	return tree;
}

tnode *buildBinaryTree(unsigned int n)
{
	tnode *tree = NULL;
	int i;
	for (i = 0; i < n; i++)
	{
		tree = addTnode(tree, createTnode(rnd(0, n)));
	}
	return tree;
}

void deleteBinaryTree(tnode *tree)
{
	if (NULL == tree) return;
	deleteBinaryTree(tree->pstLeft);
	deleteBinaryTree(tree->pstRight);
	free(tree);
}

static void _printBranch(unsigned int layer)
{
	printf("%*s", layer, "");
	int i = layer;
	while (i-- > 0)
	{
		if (0 == i) printf("%s", "----");
		else		printf("%s", "    ");
	}
}

static void _printTree(tnode *tree, unsigned int layer)
{
	if (NULL == tree) return;
	_printBranch(layer);
	printf("%-4d\n", tree->value);
	_printTree(tree->pstLeft, layer+1);
	if (NULL == tree->pstLeft && NULL != tree->pstRight)
	{
		_printBranch(layer+1);
		printf("\n");
	}
	_printTree(tree->pstRight, layer+1);
}

/**
 * 先根遍历,直观打印
 */
void printTree(tnode *tree)
{
	_printTree(tree, 0);
}

/**
 * 先根遍历
 */
void printTreeF(tnode *tree)
{
	if (NULL == tree) return;
	printf("%-4d", tree->value);
	printTreeF(tree->pstLeft);
	printTreeF(tree->pstRight);
}

/**
 * 中根遍历
 */
void printTreeM(tnode *tree)
{
	if (NULL == tree) return;
	printTreeM(tree->pstLeft);
	printf("%-4d", tree->value);
	printTreeM(tree->pstRight);
}

/**
 * 后根遍历
 */
void printTreeL(tnode *tree)
{
	if (NULL == tree) return;
	printTreeL(tree->pstLeft);
	printTreeL(tree->pstRight);
	printf("%-4d", tree->value);
}





