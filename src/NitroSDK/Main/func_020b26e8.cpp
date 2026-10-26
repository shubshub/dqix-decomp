#include <globaldefs.h>

struct Struct_020b0fac_2 {
    void* field0;
    int (*unknown_4_)(const char** cursor);
};
struct Struct_020b26e8 {
    int field_0x0;
    Struct_020b0fac_2* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};
struct Struct_020b26e8_2 { signed char x, y; };
extern "C" int func_020b0fac(Struct_020b0fac_2*, int, const char*);
extern "C" void func_020b245c(Struct_020b26e8*, int, int, int, int, int, const char*, Struct_020b26e8_2);

// USA: func_020b26e8
extern "C" ARM void func_020b26e8(Struct_020b26e8* obj, int x, int y, int arg3, int available, int arg5, int flags, const char* text, Struct_020b26e8_2 direction) {
    if (flags & 0x100) {
        int var0 = func_020b0fac(obj->unknown_4_, obj->unknown_c_, text);
        int offset = available - var0;
        x += offset * -direction.y;
        y += offset * direction.x;
    } else if (flags & 0x80) {
        int var2 = func_020b0fac(obj->unknown_4_, obj->unknown_c_, text);
        int offset = (available + 1) / 2 - (var2 + 1) / 2;
        x += offset * -direction.y;
        y += offset * direction.x;
    }
    func_020b245c(obj, x, y, arg3, arg5, flags, text, direction);
}
