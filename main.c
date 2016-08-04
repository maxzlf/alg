#include "utils/sys.h"
#include "utils/utils.h"
#include "other/other.h"
#include "int/int.h"
#include "str/str.h"
#include "link/link.h"
#include "tree/tree.h"

void fillarray(int array[], unsigned int n)
{
	init_rnd();
	int i;
	for (i = 0; i < n; i++)
	{
		array[i] = rnd(0-n/2, n/2+1);
	}
}

void print_array(const int array[], unsigned int n)
{	
	assert(NULL != array);

	int i;
	for (i = 0; i < n; i++)
	{
		printf("%-5d", array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	init_rnd();
	// int array[256];
	// unsigned int arrlen = ARRAYLEN(array);
	// fillarray(array, arrlen);
	// print_array(array, arrlen);
	// selectSort(array, arrlen);
	// print_array(array, arrlen);
	// bubbleSort(array, arrlen);
	// print_array(array, arrlen);
	// insertSort(array, arrlen);
	// print_array(array, arrlen);
	// mergeSort(array, arrlen);
	// print_array(array, arrlen);
	// shellSort(array, arrlen);
	// print_array(array, arrlen);
	// quickSort(array, arrlen);
	// print_array(array, arrlen);
	// heapSort(array, arrlen);
	// print_array(array, arrlen);
	if (argc != 2) return 0;
	tnode *tree = buildBinaryTree(atoi(argv[1]));
	printTree(tree);
	deleteBinaryTree(tree);
	return 0;
}

