#include "../utils/error.h"
#include "../utils/type.h"
#include "../utils/sys.h"

void hannoyi(unsigned int layer, const char *a, const char *b , const char *c)
{
	assert(a != NULL && b != NULL && c != NULL);
	if (0 == layer) return;

	if (1 == layer)
	{
		printf("%s --> %s\n", a, c);
		return;
	}

	layer--;
	hannoyi(layer, a, c, b);
	printf("%s --> %s\n", a, c);
	hannoyi(layer, b, a, c);
}
