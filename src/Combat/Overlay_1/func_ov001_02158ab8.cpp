#include <globaldefs.h>

struct Struct_ov001_02158ab8 {
    char pad0[0x8];
    void* a;   // 0x8
    void* pad1; // 0xc
    void* b;   // 0x10
    void* pad2; // 0x14
    void* c;   // 0x18
    void* pad3; // 0x1c
    void* d;   // 0x20
};

// USA: func_ov001_02158ab8
extern "C" ARM int func_ov001_02158ab8(struct Struct_ov001_02158ab8* obj) {
    return obj->a == NULL && obj->b == NULL && obj->c == NULL && obj->d == NULL;
}
