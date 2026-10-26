#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_020704fc(void*);
struct Struct_02070900_2;
struct Struct_02070900;
extern "C" void func_02070900(struct Struct_02070900_2*, struct Struct_02070900*, unsigned int);

struct Struct_ov001_0215b3ac { unsigned int r, g, b; };

// USA: func_ov001_0215b3ac
extern "C" ARM int func_ov001_0215b3ac(void* self) {
    Struct_ov001_0215b3ac var0;
    var0.r = func_ov017_021d60f4(self);
    var0.g = func_ov017_021d60f4((char*)self + 0x8);
    var0.b = func_ov017_021d60f4((char*)self + 0x10);
    unsigned int v = func_ov017_021d60f4((char*)self + 0x18);
    void* handle = func_020704fc((void*)v);
    if (handle != NULL) {
        func_02070900((struct Struct_02070900_2*)handle, (struct Struct_02070900*)&var0, v);
    }
    return 1;
}
