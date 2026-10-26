#include <globaldefs.h>

struct Struct_0204bab4_3 {
    char pad[0x10];
};

struct Struct_0204bbb4 {
    char pad0[0x10];
    struct Struct_0204bab4_3* p10;
    char unknown_14_[0x1d - 0x14];
    unsigned char unknown_1d_;
};

extern "C" void func_0204bab4(struct Struct_0204bbb4*, struct Struct_0204bab4_3*, int, int, int, int, int, int, int);

// USA: func_0204bbb4
extern "C" ARM void func_0204bbb4(struct Struct_0204bbb4* obj, unsigned int idx, int a2, int a3,
                               short a4, short a5, short a6, short a7, unsigned short a8) {
    if (obj->unknown_1d_ > idx && obj->p10 != NULL) {
        func_0204bab4(obj, &obj->p10[idx], a2, a3, a4, a5, a6, a7, a8);
    }
}
