#if defined(jpn)
enum {regionalOffset0=0x600, regionalOffset1=0xf0, regionalOffset2=0x717, regionalOffset3=0x204, regionalOffset4=0x128};
#else
enum {regionalOffset0=0x700, regionalOffset1=0x74, regionalOffset2=0x79b, regionalOffset3=0x208, regionalOffset4=0x12c};
#endif
#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* a, void* b, void* c, int d);

struct Struct_ov023_021dd404 {
    unsigned char bit0:1;
    unsigned char unknown_0_1_:1;
    unsigned char rest:6;
};

struct Struct_ov023_021dd404_2 {
    char pad0[regionalOffset1];
    unsigned short unknown_74_;
    char pad1[0x7b - 0x76];
    signed char unknown_7b_;
    char pad2[0x7d - 0x7c];
    signed char unknown_7d_;
};

// USA: func_ov023_021dd404
extern "C" ARM void func_ov023_021dd404(char* obj) {
    if (((Struct_ov023_021dd404_2*)(obj + regionalOffset0))->unknown_7b_ == 1) {
        if (!((Struct_ov023_021dd404*)(obj + regionalOffset2))->unknown_0_1_) return;
        Struct_ov023_021dd404_2* s = (Struct_ov023_021dd404_2*)(obj + regionalOffset0);
        if (!(s->unknown_74_ & 0x2000)) return;
    }
    signed char mode = ((Struct_ov023_021dd404_2*)(obj + regionalOffset0))->unknown_7d_;
    if (mode == 1) {
        Struct_ov023_021dd404_2* s2 = (Struct_ov023_021dd404_2*)(obj + regionalOffset0);
        if (!(s2->unknown_74_ & 0x800)) return;
        char* g = obj + regionalOffset3;
        *(unsigned char*)(g + 0x426) = 1;
        *(unsigned int*)(g + 0x414) = 0x10000;
        *(unsigned int*)(g + 0x418) = 0x68000;
        *(unsigned char*)(g + 0x422) = 0x58;
        SpriteContext_DrawSprite(obj + regionalOffset4, g + 0x400, g, 0x58);
        return;
    }
    if (mode == 2) {
        Struct_ov023_021dd404_2* s2 = (Struct_ov023_021dd404_2*)(obj + regionalOffset0);
        if (!(s2->unknown_74_ & 0x800)) return;
        char* g = obj + regionalOffset3;
        *(unsigned char*)(g + 0x426) = 2;
        *(unsigned int*)(g + 0x414) = 0x10000;
        *(unsigned int*)(g + 0x418) = 0x68000;
        *(unsigned char*)(g + 0x422) = 0x58;
        SpriteContext_DrawSprite(obj + regionalOffset4, g + 0x400, g, 0x58);
        return;
    }
}
