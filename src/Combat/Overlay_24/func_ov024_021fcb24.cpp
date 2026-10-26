#include <globaldefs.h>

struct Struct_ov024_021fcb24 { char unk[0x70]; unsigned char flag; };

extern "C" int func_ov024_021fe698(void* obj, int idx);
extern "C" void func_ov024_021fd954(void* obj, int mode);

// USA: func_ov024_021fcb24
extern "C" ARM void func_ov024_021fcb24(struct Struct_ov024_021fcb24* obj) {
    if (obj->flag) {
        if (func_ov024_021fe698(obj, 11)) {
            func_ov024_021fd954(obj, 15);
        }
    }
}
