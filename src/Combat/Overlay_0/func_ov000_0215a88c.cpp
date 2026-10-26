#include <globaldefs.h>

extern "C" void* func_ov000_0215e9b8(void* p);

struct Struct_ov000_0215a88c_3;
struct Struct_ov000_0215a88c;
extern "C" void func_ov000_0215fe00(struct Struct_ov000_0215a88c_3* obj, struct Struct_ov000_0215a88c* arg1);

struct Struct_ov000_0215a88c_2 { short a; int b; };

// USA: func_ov000_0215a88c
extern "C" ARM void func_ov000_0215a88c(void* objRaw, void* arg1, int c) {
    void* var0 = func_ov000_0215e9b8(objRaw);
    struct Struct_ov000_0215a88c_2* entry = (struct Struct_ov000_0215a88c_2*)var0;
    if (entry == 0) {
        return;
    }
    entry->a = 0;
    entry->b = 0;
    entry->a = (short)c;
    func_ov000_0215fe00((struct Struct_ov000_0215a88c_3*)arg1, (struct Struct_ov000_0215a88c*)var0);
    unsigned char* obj = (unsigned char*)objRaw;
    obj[0x8000 + 0xe03] = obj[0x8000 + 0xe03] + 1;
}
