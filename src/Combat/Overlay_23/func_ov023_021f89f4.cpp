#include <globaldefs.h>

struct Struct_ov023_021f6ed8;
extern "C" ARM void func_ov023_021f6ed8(struct Struct_ov023_021f6ed8* obj);

struct Struct_ov023_021f89f4 { unsigned char lo : 4; unsigned char hi : 4; };
#if defined(jpn)
struct Struct_ov023_021f89f4_2 { unsigned char bit0 : 1; unsigned char unknown_0_1_ : 7; };
#else
struct Struct_ov023_021f89f4_2 { unsigned char bit0 : 1; unsigned char unknown_0_1_ : 6; unsigned char unknown_0_7_ : 1; };
#endif


// USA: func_ov023_021f89f4
extern "C" ARM int func_ov023_021f89f4(char* obj, int unused, int arg2, int arg3, int pA, int pB, int arg6, int arg7, int arg8, int arg9, int arg10) {
    func_ov023_021f6ed8((struct Struct_ov023_021f6ed8*)obj);
    *(short*)(obj + 0x4) = 8;
    *(short*)(obj + 0x6) = arg2;
    *(short*)(obj + 0x8) = arg3;
    *(short*)(obj + 0xa) = 0;
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x1c) = 2;

    struct Struct_ov023_021f89f4_2* var0 = (struct Struct_ov023_021f89f4_2*)(obj + 0x45);
    var0->unknown_0_1_ = 0;
    *(short*)(obj + 0x42) = 0;
#if defined(jpn)

#else
    var0->unknown_0_7_ = 0;
#endif

    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = -0x10000;
    *(int*)(obj + 0x28) = -0x3000;
    *(int*)(obj + 0x2c) = 0;
    *(short*)(obj + 0x30) = 0;
    *(short*)(obj + 0x32) = 0;
    *(short*)(obj + 0x34) = pA;
    *(short*)(obj + 0x36) = pB;
    *(short*)(obj + 0x38) = arg6;
    *(short*)(obj + 0x3a) = arg7;
    *(short*)(obj + 0x3c) = arg8;

    struct Struct_ov023_021f89f4* var1 = (struct Struct_ov023_021f89f4*)(obj + 0x44);
    var1->lo = (unsigned char)arg9;
    var1->hi = (unsigned char)arg10;

    var0->bit0 = 0;
    *(short*)(obj + 0x46) = 0;
    *(short*)(obj + 0x48) = 0;
    *(short*)(obj + 0x4a) = 0;
    *(short*)(obj + 0x4c) = 0;
    return 1;
}
