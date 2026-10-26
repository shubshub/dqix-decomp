#include <globaldefs.h>

extern "C" int func_02068200(signed char* s);
extern "C" int sprintf(int value, void* slot);

struct Struct_020691f8 { unsigned char data[0x40]; };

// USA: func_020691f8
extern "C" ARM void func_020691f8(signed char* s, int* accum, char* base) {
    int idx = func_02068200(s) - 1;
    struct Struct_020691f8* slot = (struct Struct_020691f8*)(base + 0x4ac) + idx;
    if (slot != NULL) {
        *accum += sprintf(*accum, slot);
    }
}
