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
char *uper2end(char *str)
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


unsigned int lcs(const char *strm, const char *strn)
{
	if (NULL == strm || NULL == strn) return 0;

	int m = strlen(strm) + 1;
	int n = strlen(strn) + 1;
	int size = m * n * sizeof(int);
	int *mn = (int *)malloc(size);
	memset(mn, '\0', size);

	int i, j;
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			int max = TMAX(mn[(i-1)*n + j-1], mn[i*n + j-1], mn[(i-1)*n + j]);
			if (strm[i-1] == strn[j-1])
			{
				mn[i*n + j] = mn[(i-1)*n + j-1] + 1;
			}
			else
			{
				mn[i*n + j] = max;
			}
		}
	}

	printf("lcs table\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%-4d", mn[i*n + j]);
		}
		printf("\n");
	}

	int result = mn[(m-1)*n + n-1];
	free(mn);
	return result;
}

void kmp(const char* strm, const char* strn)
{
	if (NULL == strm || NULL == strn) return;

	int mlen = strlen(strm);
	int nlen = strlen(strn);

	int *pi = (int *)malloc(nlen * sizeof(int));
	int k = 0, i;
	for (i = 1; i < nlen; i++)
	{
		while (k > 0 && strn[i] != strn[k]) k = pi[k-1];
		if (strn[i] == strn[k]) k++;
		pi[i] = k;
	}

	int j;
	k = 0;
	for (j = 0; j < mlen; j++)
	{
		while (k > 0 && strm[j] != strn[k]) k = pi[k-1];
		if (strm[j] == strn[k]) k++;
		if (k >= nlen)
		{
			printf("[%d-%d]\n", j-k+1, j);
			k = pi[k-1];
		}
	}

	free(pi);
}
