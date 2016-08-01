#include "../utils/sys.h"
#include "../utils/error.h"
#include "../utils/type.h"
#include "../utils/utils.h"

static void _allorder(char * const array, char *tmp)
{
	assert(NULL != array);

	if (NULL == tmp) tmp = array;
	unsigned int n = strlen(tmp);
	if (0 == n) printf("%s\n", array);

	int i;
	for (i = 0; i < n; i++)
	{			
		int j;
		bool skip = false;
		for (j = i-1; j >= 0; j--)
		{
			if (tmp[j] == tmp[i]) skip = true;
		}
		if (skip) continue;
		SWAP(tmp[0], tmp[i]);
		_allorder(array, tmp+1);
		SWAP(tmp[0], tmp[i]);
	}
}

void allorder(char *array)
{
	_allorder(array, NULL);
}