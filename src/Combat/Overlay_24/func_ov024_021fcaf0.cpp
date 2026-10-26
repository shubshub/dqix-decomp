#include <globaldefs.h>

struct Struct_ov024_021fcaf0 { char unk[0x6f]; unsigned char flag; };

extern "C" int func_ov024_021fe698(void* obj, int idx);
extern "C" void func_ov024_021fd954(void* obj, int mode);

// USA: func_ov024_021fcaf0
extern "C" ARM void func_ov024_021fcaf0(struct Struct_ov024_021fcaf0* obj) {
    if (obj->flag) {
        if (func_ov024_021fe698(obj, 11)) {
            func_ov024_021fd954(obj, 14);
        }
    }
}
