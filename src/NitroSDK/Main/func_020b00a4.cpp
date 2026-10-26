#include <globaldefs.h>

extern "C" void func_020b0108(void*);

struct Hdr02b0288;
struct Struct_020afec4;
extern "C" struct Struct_020afec4* func_020b0288(struct Hdr02b0288*, unsigned int);

// USA: func_020b00a4
extern "C" ARM int func_020b00a4(void* file, void** out) {
    struct Struct_020afec4* var0 = func_020b0288((struct Hdr02b0288*)file, 0x4345424b);
    if (var0 == 0) {
        *out = 0;
        return 0;
    }
    func_020b0108((char*)var0 + 8);
    *out = (char*)var0 + 8;
    return 1;
}
