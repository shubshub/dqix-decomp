#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011a74
extern "C" ARM void func_02011a74(char* obj, unsigned int index, const char* source) {
    if (source == NULL) return;
#if defined(jpn)
    char* destination = obj + 0x621e;
#else
    char* destination = obj + 0x649e;
#endif
    if (destination == NULL) return;
    if (index > 3) return;
#if defined(jpn)
    destination += index * 32;
#endif
    strcpy(destination, source);
}
