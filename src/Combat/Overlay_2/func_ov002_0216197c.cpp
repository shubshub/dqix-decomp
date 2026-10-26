#include <globaldefs.h>

struct Struct_0205d81c;

extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

#pragma optimize_for_size off
// USA: func_ov002_0216197c
extern "C" ARM int func_ov002_0216197c(int key, struct Struct_0205d81c* obj) {
    unsigned char* e = (unsigned char*)func_0205d81c(obj, key);
    if (e != NULL) {
        return (e[0xc5] & 0x40) != 0;
    }
    return 0;
}
