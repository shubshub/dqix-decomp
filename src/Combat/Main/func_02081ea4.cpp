#include <globaldefs.h>

struct Struct_0207fdcc_2;

struct Struct_0207fdcc {
    char unk[0xc5];
    unsigned char flags;
    char unk2[0x1a];
};

extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020813ec(struct Struct_0207fdcc_2* obj, int key);

// USA: func_02081ea4
extern "C" ARM void func_02081ea4(struct Struct_0207fdcc_2* obj, int key, int enable) {
    struct Struct_0207fdcc* elem = func_02081da8(obj, key);
    if (elem != NULL) {
        if (enable != 0) {
            elem->flags |= 0x40;
        } else {
            elem->flags &= ~0x40;
        }
        func_020813ec(obj, key);
    }
}
