#include <globaldefs.h>

struct Struct_0207fdcc_2;

struct Struct_0207fdcc {
    char unk[0xc5];
    unsigned char flags;
    char unk2[0x1a];
};

extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);

// USA: func_02080c20
extern "C" ARM void func_02080c20(struct Struct_0207fdcc_2* obj, int key) {
    struct Struct_0207fdcc* elem = func_02081da8(obj, key);
    if (elem != NULL) {
        elem->flags &= ~0x20;
    }
}
