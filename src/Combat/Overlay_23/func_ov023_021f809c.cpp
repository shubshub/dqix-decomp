#include <globaldefs.h>

extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" void func_ov023_021f7eb8(void* obj, void* param2, int zero, int arg3,
    int arg4, int arg5, int arg6, unsigned char arg7, int arg8, int arg9);

struct Struct_ov004_0215fdfc {
    char pad1[0xc8];
    short unknown_c8_;
    short unknown_ca_;
    short unknown_cc_;
    short unknown_ce_;
    char pad2[0x12];
    unsigned short unknown_e2_;
    char pad3;
    unsigned char unknown_e5_;
};

// USA: func_ov023_021f809c
extern "C" ARM void func_ov023_021f809c(struct Struct_ov004_0215fdfc* obj, void* param2) {
    if (WindowPane_IsOpen((unsigned char*)obj + 0x20)) {
        unsigned char var0 = obj->unknown_e5_;
        unsigned short e2 = obj->unknown_e2_;
        int var2 = (var0 & 4) ? 1 : 0;
        int var3 = (var0 & 0x10) ? 1 : 0;
        short ce = obj->unknown_ce_;
        unsigned char var5 = (unsigned char)e2;
        short c8 = obj->unknown_c8_;
        short var7 = obj->unknown_ca_;
        short cc = obj->unknown_cc_;
        func_ov023_021f7eb8(obj, param2, 0, cc, ce, c8, var7, var5, var2, var3);
    }
}
