#include <globaldefs.h>

struct Obj0209caa0 {
    unsigned char pad0[0xc8];
    unsigned char bit0 : 1;
    unsigned char flag2 : 1;
    unsigned char rest : 6;
    unsigned char pad1[4];
    unsigned char unknown_cd_;
};

extern "C" void func_0209c2e0(struct Obj0209caa0* obj, int a, int b);

// USA: func_0209caa0
extern "C" ARM void func_0209caa0(struct Obj0209caa0* obj, int enable) {
    if (obj->flag2 == enable) {
        return;
    }
    obj->flag2 = (enable != 0);
    func_0209c2e0(obj, obj->unknown_cd_, 0x1e);
}
