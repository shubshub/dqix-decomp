#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02003c3c {
    char* base;
    unsigned int capacity;
    unsigned int count;
};

// USA: func_02003c3c
extern "C" ARM int func_02003c3c(struct Struct_02003c3c* obj, void* src, unsigned int len) {
    if (obj->count + len > obj->capacity) {
        len = obj->capacity - obj->count;
    }
    memcpy(obj->base + obj->count, src, len);
    obj->count += len;
    return 1;
}
