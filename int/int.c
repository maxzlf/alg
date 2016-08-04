#include "../utils/sys.h"
#include "../utils/utils.h"

unsigned long gcd(unsigned long a, unsigned long b)
{
	if (0 == a) return a;
	if (0 == b) return b;

	unsigned int bigger = MAX(a, b);
	unsigned int smaller = MIN(a, b);
	unsigned int gcd;

	while (smaller > 0)
	{
		gcd = bigger % smaller;
		bigger = smaller;
		smaller = gcd;
	}
	return bigger;
}

static unsigned long factl(unsigned long m, unsigned long n)
{
	assert(m <= n);
	if (m == n) return m;
	return factl(m, (m+n)/2) * factl((m+n)/2 + 1, n);
}

unsigned long factlog(unsigned long n)
{
	if (0 == n || 1 == n) return n;
	return factl(1, n);
}

long mypow(long n, unsigned long p)
{
	if (0 == n) return 0;
	if (1 == n || 0 == p) return 1;
	
	long m = 1;
	while (p > 0)
	{
		if (ISODD(p)) m *= n;
		n *= n;
		p >>= 1;
	}
	return m;
}

/**
 * max sub sequence sum
 */
long msss(const int array[], unsigned int n)
{
	assert(NULL != array);
	long maxsum = 0;
	long sum = 0;

	int i;
	for (i = 0; i< n; i++)
	{
		sum += array[i];
		if (sum > maxsum) maxsum = sum;
		if (sum < 0) sum = 0;
	}
	return maxsum;
}

int binarySearch(const int array[], unsigned int n, int target)
{
	assert(NULL != array);

	int head = 0, tail = n -1;
	while (head <= tail)
	{
		int middle = (head + tail) / 2;
		if (target < array[middle])
		{
			tail = middle - 1;
		}
		else if (target > array[middle])
		{
			head = middle + 1;
		} else return middle;
	}
	return -1;
}


