#include "sys.h"

void init_rnd()
{
	srandom(time(NULL));
}

int rnd(int begin, int end)
{
	assert(end > begin);
	return random() % (end-begin) + begin;
}