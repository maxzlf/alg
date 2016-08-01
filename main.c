#include "utils/sys.h"
#include "utils/utils.h"
#include "other/other.h"
#include "int/int.h"
#include "str/str.h"

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
		printf("%-4d", array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int array[10];
	fillarray(array, ARRAYLEN(array));
	print_array(array, ARRAYLEN(array));
	// selectSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	// bubbleSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	// insertSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	// mergeSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	// shellSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	// quickSort(array, ARRAYLEN(array));
	// print_array(array, ARRAYLEN(array));
	heapSort(array, ARRAYLEN(array));
	print_array(array, ARRAYLEN(array));
	return 0;
}