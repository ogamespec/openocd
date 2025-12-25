#include <inttypes.h>

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#define HAVE_STRNLEN
#define HAVE_GETTIMEOFDAY