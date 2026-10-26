#include <globaldefs.h>

extern "C" bool func_020ae4c8();
extern "C" void* Zone3D_GetInstance(void);

struct Obj0201b600;
struct Struct_0201b600 { unsigned short key; unsigned short flags; };
extern "C" struct Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);

// USA: func_020ae694
extern "C" ARM void func_020ae694(int mode, int key1, unsigned short key2) {
    struct Struct_0201b600* elem;
    if (key2 == 0) return;
    if (func_020ae4c8()) return;
    elem = func_0201b600((struct Obj0201b600*)Zone3D_GetInstance(), key1, key2);
    if (elem == 0) return;
    if (mode == 0) {
        elem->flags |= 0x4;
    } else {
        elem->flags &= ~0x4;
    }
}
