#include <globaldefs.h>

struct Struct_020b01a4;
extern "C" void func_020b01e0(struct Struct_020b01a4*);

struct Hdr02b0288;
struct Struct_020afec4;
extern "C" struct Struct_020afec4* func_020b0288(struct Hdr02b0288*, unsigned int);

// USA: func_020b01a4
extern "C" ARM int func_020b01a4(void* file, void** out) {
    struct Struct_020afec4* var0 = func_020b0288((struct Hdr02b0288*)file, 0x43484152);
    if (var0 == 0) {
        *out = 0;
        return 0;
    }
    func_020b01e0((struct Struct_020b01a4*)((char*)var0 + 8));
    *out = (char*)var0 + 8;
    return 1;
}
