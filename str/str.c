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

char *revsStr(char *const str)
{
	assert(NULL != str);
	int len = strlen(str);

	int left, right;
	for (left = 0, right = len - 1; left < right; left++, right--)
	{
		SWAP(str[left], str[right]);
	}
	return str;
}

/**
 * 把一个字符串的大写字母移到字符串末尾，且字符相对顺序不变
 */
char *uperend(char *str)
{
	assert(NULL != str);
	int right = strlen(str);
	int index;

	for (index = right - 1; index >= 0; index--)
	{
		if (isupper(str[index]))
		{
			int i;
			char tmp = str[index];
			for (i = index; i < right - 1; i++)
			{
				str[i] = str[i+1];
			}
			str[i] = tmp;
			right--;
		}
	}
	return str;
}	


