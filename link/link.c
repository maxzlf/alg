#include "../utils/sys.h"
#include "../utils/error.h"
#include "../utils/type.h"
#include "../utils/utils.h"
#include "link.h"

snode *buildLink(unsigned int len)
{	
	snode *link = NULL;
	snode *current = NULL;
	int index = len;
	while (index-- > 0)
	{
		snode *node = (snode *)malloc(sizeof(snode));
		node->value = rnd(0, len);
		node->pstnext = NULL;

		if (NULL != current) current->pstnext = node;
		if (NULL == link) link = node;
		current = node;
	}
	return link;
}

void printLink(snode *link)
{
	while (NULL != link)
	{
		printf("%-4d", link->value);
		link = link->pstnext;
	}
	printf("\n");
}

void deleteLink(snode *link)
{
	snode *next;
	while (NULL != link)
	{
		next = link->pstnext;
		free(link);
		link = next;
	}
}

/**
 * 反转单链表
 */
snode *revsLink(snode *link)
{	
	snode *father = NULL;
	snode *current = link;
	snode *next;

	while (NULL != current)
	{
		next = current->pstnext;
		current->pstnext = father;
		father = current;
		current = next;
	}

	return father;
}

/**
 * 查找链表倒数第 k 个节点
 */
snode *knode(snode *link, unsigned int k)
{
	snode *right = link;
	int i = k;
	while (i-- > 0)
	{
		if (NULL == right) return NULL;
		right = right->pstnext;
	}
	snode *kth = link;
	while (NULL != right)
	{
		right = right->pstnext;
		kth = kth->pstnext;
	}
	return kth;
}
