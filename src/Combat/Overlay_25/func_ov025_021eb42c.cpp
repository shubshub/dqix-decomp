#include <globaldefs.h>

struct Struct_ov025_021e88d8 {
    int a;
    short b;
    short c;
    unsigned char d;
    unsigned char e;
};

extern "C" void func_ov025_021e8a20(struct Struct_ov025_021e88d8* obj);
extern "C" int func_ov025_021eb188(void* arg0, struct Struct_ov025_021e88d8* obj);

// USA: func_ov025_021eb42c
extern "C" ARM int func_ov025_021eb42c(void* arg0, short b, short c) {
    struct Struct_ov025_021e88d8 local;
    func_ov025_021e8a20(&local);
    local.b = b;
    local.c = c;
    local.d = 0;
    return func_ov025_021eb188(arg0, &local);
}
