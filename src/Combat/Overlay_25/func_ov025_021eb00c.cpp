#include <globaldefs.h>

extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov000_021639b4(void);

struct Struct_ov025_021e4450 {
    char pad[0xc];
    int fieldC;
    char pad2[0x1c4 - 0xc - 4];
    int flags;
};

// USA: func_ov025_021eb00c
extern "C" ARM void func_ov025_021eb00c(struct Struct_ov025_021e4450* obj) {
    if (obj->fieldC == 0) return;
    if (obj->flags & 0x4) return;
    func_ov000_02160130();
    func_ov000_021639b4();
    obj->flags |= 0x4;
}
