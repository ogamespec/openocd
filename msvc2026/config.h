#define HAVE_INTTYPES_H
#define HAVE_STDBOOL_H

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#define HAVE_STRNLEN
#define HAVE_GETTIMEOFDAY
#define IS_WIN32 1
#define _TIMEVAL_DEFINED

#define VERSION "0.12"
#ifdef _DEBUG
#define RELSTR " Debug"
#else
#define RELSTR " Release"
#endif
#define GITVERSION "0.12"

#include <WinSock2.h>
#include <fcntl.h>

#define BINDIR "bin"
#define PKGDATADIR "pkgdata"

#define BUILD_CMSIS_DAP_USB 1
#define BUILD_CMSIS_DAP_HID 0
#define BUILD_CMSIS_DAP_TCP 1

#include "strings.h"