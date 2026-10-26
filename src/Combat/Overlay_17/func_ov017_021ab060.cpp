#include <globaldefs.h>

extern "C" void func_02080b54(void* obj, int id);
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);

struct Struct_ov017_021aa59c_4 {
    char pad0[0x18];
    void* unknown_18_;
    char pad1[0x4c - 0x1c];
    short s4c;
};

// USA: func_ov017_021ab060
extern "C" ARM void func_ov017_021ab060(Struct_ov017_021aa59c_4* self) {
    int var0 = 2;
    if (self->s4c == 1) {
        var0 = 5;
    }
    void* p = self->unknown_18_;
    int i;
    func_02080b54(p, 1);
    for (i = 0; i < 3; i++) {
        func_02080b40(p, var0);
        var0 = (short)(var0 + 1);
    }
    func_020813ec(p, 1);
}
