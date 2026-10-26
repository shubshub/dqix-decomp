#include <globaldefs.h>

struct Struct_ov031_0222c5d4_2 {
    unsigned char pad0[0x26];
    unsigned short field26;
    unsigned char field28;
    unsigned char pad1[0x2a - 0x29];
};

struct Struct_ov031_0222c5d4 {
    Struct_ov031_0222c5d4_2* elems;
    unsigned char unknown_4_[0x51 - 4];
    unsigned char unknown_51_;
};
struct Struct_ov031_02290c8c_12 {
    unsigned char pad[2];
    unsigned short field2;
    Struct_ov031_0222c5d4* field4;
};
extern Struct_ov031_02290c8c_12 data_ov031_02290c8c;

// USA: func_ov031_0222c5d4
extern "C" ARM void func_ov031_0222c5d4(int arg0, int arg1) {
    Struct_ov031_0222c5d4* inner = data_ov031_02290c8c.field4;
    if (arg0 >= inner->unknown_51_) return;

    unsigned char var1 = inner->elems[arg0].field28;
    void* p10 = *(void**)((char*)inner + 0x10 + arg1 * 4);
    unsigned short var3 = *(unsigned short*)((char*)inner + 0x42 + var1 * 2);
    unsigned short* var4 = (unsigned short*)((char*)p10 + 4);
    *var4 = (*var4 & ~0x3ff) | var3;

    Struct_ov031_0222c5d4* var5 = data_ov031_02290c8c.field4;
    void* var6 = *(void**)((char*)var5 + 0x24 + arg1 * 4);
    unsigned short var7 = var5->elems[arg0].field26;
    unsigned short var8 = *(unsigned short*)((char*)var5 + 0x48 + var7 * 2);
    unsigned short* var9 = (unsigned short*)((char*)var6 + 4);
    *var9 = (*var9 & ~0x3ff) | var8;
}
