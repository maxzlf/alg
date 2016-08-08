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

void _args()
{
	LOG_WARN("opps, something wrong.");
}

int main(int argc, char *argv[])
{
	init_rnd();
	int n = 100;
	while (n-- > 0)
	{
		printf("%-4ld", random());
	}
    return 0;
}
