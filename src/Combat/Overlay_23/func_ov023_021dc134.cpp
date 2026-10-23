#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40* p);
void* Zero16Bytes020df828(void* dst);
void ClearFields_021e20c0(void* p);
void SpriteContext_Init(char* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void InitFields_021db0d4(void* obj, int flag);
void ClearField784Array3_021dce88(void* obj);

struct Struct_ov023_021ff9e0_3 {
#if defined(jpn)
    void* unknown_14_;
    void* unknown_0_;
    int unknown_8_;
    int unknown_c_;
    int unknown1_c_;
    int unknown_4_;
    char unknown_18_[4];
    void* unknown_20_;
    void* unknown_24_;
    void* unknown1_8_;
    void* unknown_28_;

#else
    void* unknown_0_;   // 0x0
    int unknown_4_;     // 0x4
    void* unknown1_8_;   // 0x8
    int unknown1_c_;     // 0xc
    int unknown_10_;    // 0x10
    void* unknown_14_;  // 0x14
    int unknown1_18_;    // 0x18
    unsigned char unknown_1c_[0x20 - 0x1c];
    void* unknown_20_;  // 0x20
    void* unknown_24_;  // 0x24
    void* unknown_28_;  // 0x28

#endif
};
extern struct Struct_ov023_021ff9e0_3 data_ov023_021ff9e0;
extern char data_ov023_021ffa0c;

struct Struct_ov023_021dc134 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 6;
};

// USA: func_ov023_021dc134
extern "C" ARM void func_ov023_021dc134(void* arg0, short arg1, int arg2) {
#if defined(jpn)
 enum {Enum_ov023_021dc134_296=0x124, Enum_ov023_021dc134_297=0x125, Enum_ov023_021dc134_300=0x128, Enum_ov023_021dc134_384=0x17c, Enum_ov023_021dc134_1584=0x62c, Enum_ov023_021dc134_256=0x80, Enum_ov023_021dc134_1840=0x6ac, Enum_ov023_021dc134_1844=0x6b0, Enum_ov023_021dc134_1848=0x6b4, Enum_ov023_021dc134_1880=0x6d4, Enum_ov023_021dc134_1884=0x6d8, Enum_ov023_021dc134_1888=0x6dc, Enum_ov023_021dc134_1892=0x6e0, Enum_ov023_021dc134_1896=0x6e4, Enum_ov023_021dc134_1900=0x6e8, Enum_ov023_021dc134_1904=0x6ec, Enum_ov023_021dc134_1906=0x6ee, Enum_ov023_021dc134_1908=0x6f0, Enum_ov023_021dc134_1910=0x6f2, Enum_ov023_021dc134_1911=0x6f3, Enum_ov023_021dc134_1912=0x6f4, Enum_ov023_021dc134_1913=0x6f5, Enum_ov023_021dc134_1914=0x6f6, Enum_ov023_021dc134_1915=0x6f7, Enum_ov023_021dc134_1916=0x6f8, Enum_ov023_021dc134_1917=0x6f9, Enum_ov023_021dc134_1918=0x6fa, Enum_ov023_021dc134_1920=0x6fc, Enum_ov023_021dc134_1945=0x715, Enum_ov023_021dc134_1946=0x716, Enum_ov023_021dc134_1947=0x717};
#else
 enum {Enum_ov023_021dc134_296=0x128, Enum_ov023_021dc134_297=0x129, Enum_ov023_021dc134_300=0x12c, Enum_ov023_021dc134_384=0x180, Enum_ov023_021dc134_1584=0x630, Enum_ov023_021dc134_256=0x100, Enum_ov023_021dc134_1840=0x730, Enum_ov023_021dc134_1844=0x734, Enum_ov023_021dc134_1848=0x738, Enum_ov023_021dc134_1880=0x758, Enum_ov023_021dc134_1884=0x75c, Enum_ov023_021dc134_1888=0x760, Enum_ov023_021dc134_1892=0x764, Enum_ov023_021dc134_1896=0x768, Enum_ov023_021dc134_1900=0x76c, Enum_ov023_021dc134_1904=0x770, Enum_ov023_021dc134_1906=0x772, Enum_ov023_021dc134_1908=0x774, Enum_ov023_021dc134_1910=0x776, Enum_ov023_021dc134_1911=0x777, Enum_ov023_021dc134_1912=0x778, Enum_ov023_021dc134_1913=0x779, Enum_ov023_021dc134_1914=0x77a, Enum_ov023_021dc134_1915=0x77b, Enum_ov023_021dc134_1916=0x77c, Enum_ov023_021dc134_1917=0x77d, Enum_ov023_021dc134_1918=0x77e, Enum_ov023_021dc134_1920=0x780, Enum_ov023_021dc134_1945=0x799, Enum_ov023_021dc134_1946=0x79a, Enum_ov023_021dc134_1947=0x79b};
#endif
    char* var0 = (char*)arg0;

    data_ov023_021ff9e0.unknown_4_ = 0;

    ((SafeAllocator*)(var0 + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)(var0 + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)(var0 + 0x28))->ResetAllocatorPointer();

    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x54));

    func_020df828(var0 + 0x6c);
    func_020df828(var0 + 0x7c);

    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x8c));
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0xa4));

    *(int*)(var0 + 0xc4) = 0;
    *(int*)(var0 + 0xc8) = 0;
    func_ov023_021e20c0(var0 + 0xcc);

    *(unsigned char*)(obj + regionalOffset0) = 0;
    *(unsigned char*)(obj + regionalOffset1) = 0;
    SpriteContext_Init(obj + regionalOffset2);

    for (unsigned char i = 0; i < 30; i++) {
        Sprite_Init((struct Struct0205a198*)(obj + regionalOffset3 + i * 0x28));
    }

    memset(var0 + Enum_ov023_021dc134_1584, 0, Enum_ov023_021dc134_256);

    *(int*)(var0 + Enum_ov023_021dc134_1840) = 0;
    *(int*)(var0 + Enum_ov023_021dc134_1844) = -1;
    for (int var2 = 0; var2 < 7; var2++) {
        *(int*)(var0 + Enum_ov023_021dc134_1848 + var2 * 4) = -1;
    }

    *(int*)(var0 + Enum_ov023_021dc134_1880) = 0;
    *(int*)(var0 + Enum_ov023_021dc134_1884) = 0;

    *(short*)(var0 + Enum_ov023_021dc134_1904) = arg1;
    *(short*)(var0 + Enum_ov023_021dc134_1906) = arg1;
    *(short*)(var0 + Enum_ov023_021dc134_1908) = 0;

    *(unsigned char*)(var0 + Enum_ov023_021dc134_1910) = 0;
    *(unsigned char*)(var0 + Enum_ov023_021dc134_1911) = 0;
    *(unsigned char*)(var0 + Enum_ov023_021dc134_1912) = 0;
    *(signed char*)(var0 + Enum_ov023_021dc134_1913) = -1;
    *(signed char*)(var0 + Enum_ov023_021dc134_1914) = -1;
    *(signed char*)(var0 + Enum_ov023_021dc134_1946) = -1;

    ((Struct_ov023_021dc134*)(var0 + Enum_ov023_021dc134_1947))->unknown_0_0_ = 0;
    ((Struct_ov023_021dc134*)(var0 + Enum_ov023_021dc134_1947))->unknown_0_1_ = 0;

    *(signed char*)(var0 + Enum_ov023_021dc134_1917) = -1;
    *(unsigned char*)(var0 + Enum_ov023_021dc134_1918) = 1;
    *(int*)(var0 + Enum_ov023_021dc134_1920) = -1;

    func_ov023_021dce88(var0);

    *(int*)(var0 + Enum_ov023_021dc134_1888) = 0;
    *(int*)(var0 + Enum_ov023_021dc134_1892) = 0;
    *(unsigned char*)(var0 + Enum_ov023_021dc134_1945) = 1;
    *(int*)(var0 + Enum_ov023_021dc134_1896) = 0;
    *(int*)(var0 + Enum_ov023_021dc134_1900) = 0;

#if defined(jpn)
    data_ov023_021ff9e0.unknown_8_ = 5;
    data_ov023_021ff9e0.unknown_c_ = 7;
#else
    data_ov023_021ff9e0.unknown1_18_ = 5;
#endif

    data_ov023_021ff9e0.unknown1_c_ = 9;
#if defined(jpn)

#else
    data_ov023_021ff9e0.unknown_10_ = 0;
#endif


    *(signed char*)(var0 + Enum_ov023_021dc134_1915) = (signed char)arg2;
    *(unsigned char*)(var0 + Enum_ov023_021dc134_1916) = 1;

    if (arg2 == 1) {
        *(unsigned char*)(var0 + Enum_ov023_021dc134_1916) = 0;
        *(unsigned short*)(var0 + Enum_ov023_021dc134_1908) |= 0x800;
    }

    *(short*)(var0 + 0xc2) = 0;
    memset(var0 + 0xbc, 0, 6);

    data_ov023_021ff9e0.unknown_14_ = var0 + 0x54;
    data_ov023_021ff9e0.unknown_24_ = var0 + 0x6c;
    data_ov023_021ff9e0.unknown_0_ = var0 + 0x7c;
    data_ov023_021ff9e0.unknown1_8_ = var0 + 0x8c;
    data_ov023_021ff9e0.unknown_28_ = var0 + 0xa4;
    data_ov023_021ff9e0.unknown_20_ = var0;

    *(unsigned short*)(var0 + Enum_ov023_021dc134_1908) |= 8;

    func_ov023_021db0d4(&data_ov023_021ffa0c, 0);
}
