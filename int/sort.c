#include "../utils/sys.h"
#include "../utils/error.h"
#include "../utils/type.h"
#include "../utils/utils.h"

void selectSort(int array[], unsigned int n)
{
	assert(NULL != array);
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (array[i] > array[j]) SWAP(array[i], array[j]);
		}
	}
}

void insertSort(int array[], unsigned int n)
{
	assert(NULL != array);
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = array[i];
		for (j=i-1; j >= 0 && array[j] > tmp; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = tmp;
	}
}

void bubbleSort(int array[], unsigned int n)
{
	assert(NULL != array);
	int i, j;
	for (j = n; j > 0; j--)
	{
		for (i = 0; i+1 < j; i++)
		{
			if (array[i] > array[i+1]) SWAP(array[i], array[i+1]);
		}
	}
}

void shellSort(int array[], unsigned int n)
{
	assert(NULL != array);
	int step;
	for (step = n; step > 0; step >>= 1)
	{
		int i, j;
		for (i = step; i < n; i++)
		{	
			int tmp = array[i];
			for (j=i-step; j >= 0 && array[j] > tmp; j -= step)
			{
				array[j+step] = array[j];
			}
			array[j+step] = tmp;
		}
	}
}

static void _mergeSort(int array[], int head, int tail)
{
	/* end condition */
	if (head >= tail) return;

	/* divide */
	_mergeSort(array, head, (head+tail)/2);
	_mergeSort(array, (head+tail)/2 + 1, tail);

	/* merge */
	int left = head, right = (head+tail)/2 + 1;
	while (left < right && right <= tail)
	{
		if (array[left] >= array[right])
		{
			int k, tmp = array[right];
			for (k = right - 1; k >= left; k--)
			{
				array[k+1] = array[k];
			}
			array[k+1] = tmp;
			right++;
		}
		left++;
	}
}

void mergeSort(int array[], unsigned int n)
{
	assert(NULL != array);
	_mergeSort(array, 0, n-1);
}

static void _quickSort(int array[], int head, int tail)
{
	/* end condition */
	if (head >= tail) return;

	/* choose middle value */
	SWAP(array[head], array[(head+tail)/2]);

	unsigned int i = head + 1, j = tail;
	while (i <= j)
	{
		if (array[i] <= array[head])
		{
			i++;
			continue;
		}
		if (array[j] <= array[head])
		{
			SWAP(array[i], array[j]);
		}
		j--;
	}
	SWAP(array[head], array[i-1]);
	_quickSort(array, head, i-2);
	_quickSort(array, i, tail);
}

void quickSort(int array[], unsigned int n)
{
	assert(NULL != array);
	_quickSort(array, 0, n-1);
}

#define leftchild(i) ((i)*2+1)
#define rightchild(i) ((i)*2+2)

void heapSort(int array[], unsigned int n)
{
	assert(NULL != array);
	if (n < 2) return;

	/* max heap */
	int index;
	for (index = n/2-1; index >= 0; index--)
	{
		int child, father = index;
		while ((child = leftchild(father)) < n)
		{
			if (child + 1 < n && array[child+1] >= array[child]) child++;
			if (array[father] < array[child])
			{
				SWAP(array[father], array[child]);
				father = child;
			} else break;
		}
	}

	/* sort */
	int tail;
	for (tail = n-1; tail >= 0; tail--)
	{
		SWAP(array[tail], array[0]);
		int child, father = 0;
		while ((child = leftchild(father)) < tail)
		{
			if (child + 1 < tail && array[child+1] >= array[child]) child++;
			if (array[father] < array[child])
			{
				SWAP(array[father], array[child]);
				father = child;
			} else break;
		}
	}
}



