#include <globaldefs.h>

struct S_b20c { int field0; int field4; unsigned char field8; };
struct Struct_0204df9c { int a; short b; short c; short d; short e; };

struct Struct_0204df9c_2 {
    char pad0[8];
    int field8;
    char pad1[0xa8 - 0xc];
    short unknown_a8_;
    short unknown_aa_;
};

extern "C" void GlyphDestination_Clear(struct S_b20c* obj);
extern "C" void GlyphDestination_SetPixels(void* obj, int value);
extern "C" void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
extern "C" void GlyphDestination_DrawCharacter(void* obj, short v1, int v2, int v3, unsigned char v4, unsigned char v5);

// USA: func_0204df9c
extern "C" ARM void func_0204df9c(Struct_0204df9c_2* obj, short v1, int v2, int v3, unsigned char stackArg1, unsigned char stackArg2) {
    if (v1 == 0) return;
    Struct_0204df9c buf;
    buf.a = 0;
    buf.b = 0;
    buf.c = 0;
    buf.d = 0;
    buf.e = 0;
    buf.d = obj->unknown_a8_ << 3;
    buf.e = obj->unknown_aa_ << 3;
    S_b20c localObj;
    GlyphDestination_Clear(&localObj);
    GlyphDestination_SetPixels(&localObj, obj->field8);
    GlyphDestination_SetRects(&localObj, (int)&buf, 1);
    GlyphDestination_DrawCharacter(&localObj, v1, v2, v3, stackArg1, stackArg2);
}
