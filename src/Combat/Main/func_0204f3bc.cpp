#include <globaldefs.h>

extern "C" void func_0204cc68(void* obj, int a, int b, int idx, short c, short d);

struct Struct_0204f3bc {
    char pad[0xa8];
    short unknown_a8_;
    short unknown_aa_;
};

// USA: func_0204f3bc
extern "C" ARM void func_0204f3bc(struct Struct_0204f3bc* obj, int idx) {
    if (idx < 0) return;
    short var0 = obj->unknown_aa_;
    short a8 = obj->unknown_a8_;
    short var2 = a8 << 3;
    short var3 = var0 << 3;
    if (idx >= var3) return;
    short c = (short)(var2 - 1);
    short d = (short)(idx + 1);
    func_0204cc68(obj, 0xf, 1, idx, c, d);
}
