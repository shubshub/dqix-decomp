#include <globaldefs.h>

extern "C" void func_02048cf0(void* obj, int arg);

struct Struct_02049e88_2 {
    unsigned char pad[0x20];
    unsigned int flags;
};
struct Struct_02049e88 {
    unsigned char pad[0x13c];
    struct Struct_02049e88_2* sub;
};

// USA: func_02049e88
extern "C" ARM void func_02049e88(struct Struct_02049e88* obj) {
    if (obj->sub == NULL) return;
    obj->sub->flags &= ~0x3;
    obj->sub->flags |= 0x20;
    func_02048cf0(obj, 0);
}
