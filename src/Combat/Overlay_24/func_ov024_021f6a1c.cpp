#include <globaldefs.h>

struct Struct_ov024_021f6a1c { char pad[0xc0]; int count; };

extern "C" void func_ov024_021f6a4c(void* dst, void* src);

// USA: func_ov024_021f6a1c
extern "C" ARM void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src) {
    if (obj->count < 0x10) {
        func_ov024_021f6a4c((char*)obj + obj->count * 0xc, src);
        obj->count = obj->count + 1;
    }
}
