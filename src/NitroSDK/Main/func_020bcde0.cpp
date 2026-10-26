#include <globaldefs.h>
extern "C" void func_020d2680(unsigned int);

extern "C" void func_020d1f0c(void*, int, int, int);
extern "C" void func_020d24c4(int);
extern "C" int func_020d26ec(void);

struct Struct_020bcde0 {
    char pad0[0x24];
    int bit0 : 1;
    int unknown_24_1_ : 1;
    int unknown_24_2_ : 30;
    char pad28[0x40 - 0x28];
    int field40;
    void* field44;
};

// USA: func_020bcde0
extern "C" ARM void func_020bcde0(struct Struct_020bcde0* obj) {
    if (!obj->unknown_24_1_) return;
    func_020d1f0c(obj->field44, 0, 1 << obj->field40, 0);
    int x = func_020d26ec();
    func_020d24c4(1);
    func_020d2680((unsigned int)(x));
}
