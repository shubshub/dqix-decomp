#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02049410 {
    char pad[0x13c];
    char* buf;
};

// USA: func_02049410
extern "C" ARM void func_02049410(struct Struct_02049410* obj, void* src, int n) {
    if (obj->buf == NULL) return;
    if ((unsigned int)n >= 0x10) return;
    memcpy(obj->buf + 0x24, src, n);
    obj->buf[0x34] = (char)n;
}
