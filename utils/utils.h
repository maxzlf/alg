#ifndef UTILS_H
#define UTILS_H

#define MAX(a,b) \
    ({                           \
    	__typeof__ (a) _a = (a); \
       	__typeof__ (b) _b = (b); \
      	_a > _b ? _a : _b;       \
    })

#define MIN(a,b) \
    ({ 							 \
    	__typeof__ (a) _a = (a); \
       	__typeof__ (b) _b = (b); \
      	_a < _b ? _a : _b;       \
    })

#define SWAP(a,b) \
    ({							 	\
    	__typeof__ (a) t = (a);		\
    	(a) = (b);					\
    	(b) = t;					\
    })

#define ISODD(n) ((n)&0x01)

#define ARRAYLEN(arrayName) (sizeof(arrayName) / sizeof((arrayName)[0]))

void init_rnd();
int rnd(int begin, int end);

#endif