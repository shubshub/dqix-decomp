#include <globaldefs.h>

extern "C" bool func_020ae4c8();
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020ae4ec(int param0, int param1);

struct Obj0201b600;
struct Struct_0201b600 { unsigned short key; unsigned short flags; };
extern "C" struct Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);

// USA: func_020ae880
extern "C" ARM void func_020ae880(int mode) {
    struct Obj0201b600* obj = (struct Obj0201b600*)Zone3D_GetInstance();
    if (*(unsigned short*)obj != 0x232f) return;

    struct Struct_0201b600* var1 = func_0201b600(obj, 0, 5);
    struct Struct_0201b600* var2 = func_0201b600(obj, 0, 3);
    struct Struct_0201b600* var3 = func_0201b600(obj, 0, 0xf);
    struct Struct_0201b600* var4 = func_0201b600(obj, 0, 0x11);
    if (var1 == 0 || var2 == 0 || var3 == 0 || var4 == 0) return;

    if (!func_020ae4c8()) {
        if (mode == 0) {
            var2->flags &= ~0x4;
            var4->flags &= ~0x4;
            var3->flags |= 0x4;
            var1->flags |= 0x4;
        } else {
            var2->flags |= 0x4;
            var4->flags |= 0x4;
            var3->flags &= ~0x4;
            var1->flags &= ~0x4;
        }
    }
    func_020ae4ec(0xc, mode != 0 ? 1 : 0);
}
