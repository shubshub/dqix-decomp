#include <globaldefs.h>

struct Struct_ov025_021eb05c {
    char pad[0x582];
    unsigned char count;
    char pad2;
    unsigned short arr[8];
};

// USA: func_ov025_021eb05c
extern "C" ARM void func_ov025_021eb05c(struct Struct_ov025_021eb05c* obj, int val) {
    if (val < 0) {
        return;
    }
    if (obj->count < 8) {
        unsigned char c = obj->count;
        obj->count = c + 1;
        obj->arr[c] = val;
    }
}
