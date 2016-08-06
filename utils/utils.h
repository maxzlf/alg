#ifndef UTILS_H
#define UTILS_H

#define MAX(a,b) \
    ({                           \
    	__typeof__ (a) _a = (a);   \
      __typeof__ (b) _b = (b);   \
      _a > _b ? _a : _b;         \
    })

#define MIN(a,b) \
    ({ 							 \
    	__typeof__ (a) _a = (a);   \
      __typeof__ (b) _b = (b);   \
      _a < _b ? _a : _b;         \
    })

#define TMAX(a,b,c) \
    ({                           \
      __typeof__ (a) _a = (a);   \
      __typeof__ (b) _b = (b);   \
      __typeof__ (c) _c = (c);   \
      (_a < _b? (_b < _c? _c : _b) : (_a < _c? _c : _a)); \
    })

#define TMIN(a,b,c) \
    ({                           \
      __typeof__ (a) _a = (a);   \
      __typeof__ (b) _b = (b);   \
      __typeof__ (c) _c = (c);   \
      (_a < _b? (_a < _c? _a : _c) : (_b < _c? _b : _c)); \
    })

#define TMIDDLE(a,b,c) \
    ({                           \
      __typeof__ (a) _a = (a);   \
      __typeof__ (b) _b = (b);   \
      __typeof__ (c) _c = (c);   \
      (_a < _b? (_b < _c? _b : (_a < _c? _c : _a)) : (_a < _c? _a : (_c < _b? _b : _c))); \
    })

#define SWAP(a,b) \
    ({							 	\
    	__typeof__ (a) t = (a);		\
    	(a) = (b);					      \
    	(b) = t;					        \
    })

#define ISODD(n) ((n)&0x01)

#define ARRAYLEN(arrayName) (sizeof(arrayName) / sizeof((arrayName)[0]))

void init_rnd();
int rnd(int begin, int end);

typedef struct S_NODE
{
  int value;
  struct S_NODE *pstnext;
} snode;

#endif