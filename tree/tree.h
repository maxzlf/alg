#ifndef TREE_H
#define TREE_H

typedef struct T_NODE
{
	int value;
	struct T_NODE *pstLeft;
	struct T_NODE *pstRight;
} tnode;

tnode *createTnode(int value);
tnode *addTnode(tnode *tree, tnode *node);
tnode *buildBinaryTree(unsigned int n);
void deleteBinaryTree(tnode *tree);
void printTreeF(tnode *tree);
void printTreeM(tnode *tree);
void printTreeL(tnode *tree);
void printTree(tnode *tree);

#endif