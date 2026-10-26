#include <globaldefs.h>

extern "C" int func_ov000_02170c7c(int);

struct Struct_ov000_0217f5e4 { char pad[0x25]; signed char field25; char pad2[0x28 - 0x26]; };
struct Struct_ov000_02173954 { char pad[0x170]; struct Struct_ov000_0217f5e4* unknown_170_; };

// USA: func_ov000_0217f5e4
extern "C" ARM void func_ov000_0217f5e4(struct Struct_ov000_02173954* obj, int key) {
    if (key == 0) return;
    signed char v = (signed char)func_ov000_02170c7c(key);
    for (int i = 7; i < 0x11; i++) {
        obj->unknown_170_[i].field25 = v;
    }
}
