#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209ce14 {
    unsigned char pad[0x98];
    int count;
    unsigned char buffer[0x400];
};

// USA: func_0209e4a0
extern "C" ARM void func_0209e4a0(struct Struct_0209ce14* obj) {
    obj->count = 0;
    memset(obj->buffer, 0, 0x400);
}
