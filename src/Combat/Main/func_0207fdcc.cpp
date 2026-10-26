#include <globaldefs.h>
extern "C" void func_0204c804(void*);

struct Struct_0207fdcc;

struct Struct_0207fdcc_2 {
#if defined(jpn)
    char pad0[0x24];
#else
    char pad0[0x30];
#endif
    struct Struct_0207fdcc* elems;
};

extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);

// USA: func_0207fdcc
extern "C" ARM void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key) {
    struct Struct_0207fdcc* e;
    if (obj->elems == NULL) return;
    e = func_02081da8(obj, key);
    if (e == NULL) return;
    func_0204c804((void*)(e));
}
