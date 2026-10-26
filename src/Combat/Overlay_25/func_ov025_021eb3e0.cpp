#include <globaldefs.h>

struct Struct_ov025_021e88d8 {
    int a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

extern "C" void func_ov025_021e8a20(struct Struct_ov025_021e88d8* obj);

// USA: func_ov025_021eb3e0
extern "C" ARM void* func_ov025_021eb3e0(void* obj) {
    struct Struct_ov025_021e88d8* rec = (struct Struct_ov025_021e88d8*)((char*)obj + 0x194 + 0x400);
    unsigned char i = 0;
    while (i < 4) {
        if (rec->e == 0) {
            func_ov025_021e8a20(rec);
            return rec;
        }
        i++;
        rec++;
    }
    return 0;
}
