#include <globaldefs.h>

extern "C" bool func_020ae4c8();
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020ae4ec(int param0, int param1);

struct Obj0201b600;
struct Struct_0201b600 { unsigned short key; unsigned short flags; };
extern "C" struct Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);

// USA: func_020ae7d4
extern "C" ARM void func_020ae7d4(int mode) {
    struct Obj0201b600* obj = (struct Obj0201b600*)Zone3D_GetInstance();
    if (*(unsigned short*)obj != 0x1bbd) return;

    struct Struct_0201b600* var1 = func_0201b600(obj, 0, 0xd);
    struct Struct_0201b600* elem2 = func_0201b600(obj, 0, 0xf);
    if (var1 == 0 || elem2 == 0) return;

    if (!func_020ae4c8()) {
        if (mode == 0) {
            var1->flags &= ~0x4;
            elem2->flags |= 0x4;
        } else {
            var1->flags |= 0x4;
            elem2->flags &= ~0x4;
        }
    }
    func_020ae4ec(9, mode != 0 ? 1 : 0);
}
