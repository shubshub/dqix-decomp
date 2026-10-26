#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void* func_020df828(void* dst);
extern "C" void func_ov023_021e20c0(void* p);
extern "C" void SpriteContext_Init(char* obj);
struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198* p);
extern "C" void func_ov023_021db0d4(void* obj, int flag);
extern "C" void func_ov023_021dce88(void* obj);

struct Struct_ov023_021ff9e0_3 {
#if defined(jpn)
    void* field14;
    void* field0;
    int field18;
    int unknown_c_;
    int fieldc;
    int field4;
    char pad18[4];
    void* field20;
    void* field24;
    void* field8;
    void* field28;

#else
    void* field0;   // 0x0
    int field4;     // 0x4
    void* field8;   // 0x8
    int fieldc;     // 0xc
    int field10;    // 0x10
    void* field14;  // 0x14
    int field18;    // 0x18
    unsigned char unknown_1c_[0x20 - 0x1c];
    void* field20;  // 0x20
    void* field24;  // 0x24
    void* field28;  // 0x28

#endif
};
extern struct Struct_ov023_021ff9e0_3 data_ov023_021ff9e0;
extern char data_ov023_021ffa0c;

struct Struct_ov023_021dc134 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char rest : 6;
};

// USA: func_ov023_021dc134
extern "C" ARM void func_ov023_021dc134(void* objRaw, short key, int flag) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x125, regionalOffset2=0x128, regionalOffset3=0x17c, regionalOffset4=0x62c, regionalOffset5=0x80, regionalOffset6=0x6ac, Enum_ov023_021dc134_1844=0x6b0, Enum_ov023_021dc134_1848=0x6b4, regionalOffset9=0x6d4, Enum_ov023_021dc134_1884=0x6d8, Enum_ov023_021dc134_1888=0x6dc, Enum_ov023_021dc134_1892=0x6e0, Enum_ov023_021dc134_1896=0x6e4, Enum_ov023_021dc134_1900=0x6e8, Enum_ov023_021dc134_1904=0x6ec, Enum_ov023_021dc134_1906=0x6ee, Enum_ov023_021dc134_1908=0x6f0, Enum_ov023_021dc134_1910=0x6f2, Enum_ov023_021dc134_1911=0x6f3, Enum_ov023_021dc134_1912=0x6f4, Enum_ov023_021dc134_1913=0x6f5, Enum_ov023_021dc134_1914=0x6f6, Enum_ov023_021dc134_1915=0x6f7, Enum_ov023_021dc134_1916=0x6f8, Enum_ov023_021dc134_1917=0x6f9, Enum_ov023_021dc134_1918=0x6fa, Enum_ov023_021dc134_1920=0x6fc, Enum_ov023_021dc134_1945=0x715, Enum_ov023_021dc134_1946=0x716, Enum_ov023_021dc134_1947=0x717};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x129, regionalOffset2=0x12c, regionalOffset3=0x180, regionalOffset4=0x630, regionalOffset5=0x100, regionalOffset6=0x730, Enum_ov023_021dc134_1844=0x734, Enum_ov023_021dc134_1848=0x738, regionalOffset9=0x758, Enum_ov023_021dc134_1884=0x75c, Enum_ov023_021dc134_1888=0x760, Enum_ov023_021dc134_1892=0x764, Enum_ov023_021dc134_1896=0x768, Enum_ov023_021dc134_1900=0x76c, Enum_ov023_021dc134_1904=0x770, Enum_ov023_021dc134_1906=0x772, Enum_ov023_021dc134_1908=0x774, Enum_ov023_021dc134_1910=0x776, Enum_ov023_021dc134_1911=0x777, Enum_ov023_021dc134_1912=0x778, Enum_ov023_021dc134_1913=0x779, Enum_ov023_021dc134_1914=0x77a, Enum_ov023_021dc134_1915=0x77b, Enum_ov023_021dc134_1916=0x77c, Enum_ov023_021dc134_1917=0x77d, Enum_ov023_021dc134_1918=0x77e, Enum_ov023_021dc134_1920=0x780, Enum_ov023_021dc134_1945=0x799, Enum_ov023_021dc134_1946=0x79a, Enum_ov023_021dc134_1947=0x79b};
#endif
    char* obj = (char*)objRaw;

    data_ov023_021ff9e0.field4 = 0;

    ((SafeAllocator*)(obj + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x28))->ResetAllocatorPointer();

    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x54));

    func_020df828(obj + 0x6c);
    func_020df828(obj + 0x7c);

    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x8c));
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0xa4));

    *(int*)(obj + 0xc4) = 0;
    *(int*)(obj + 0xc8) = 0;
    func_ov023_021e20c0(obj + 0xcc);

    *(unsigned char*)(obj + regionalOffset0) = 0;
    *(unsigned char*)(obj + regionalOffset1) = 0;
    SpriteContext_Init(obj + regionalOffset2);

    for (unsigned char i = 0; i < 30; i++) {
        Sprite_Init((struct Struct0205a198*)(obj + regionalOffset3 + i * 0x28));
    }

    memset(obj + regionalOffset4, 0, regionalOffset5);

    *(int*)(obj + regionalOffset6) = 0;
    *(int*)(obj + Enum_ov023_021dc134_1844) = -1;
    for (int i = 0; i < 7; i++) {
        *(int*)(obj + Enum_ov023_021dc134_1848 + i * 4) = -1;
    }

    *(int*)(obj + regionalOffset9) = 0;
    *(int*)(obj + Enum_ov023_021dc134_1884) = 0;

    *(short*)(obj + Enum_ov023_021dc134_1904) = key;
    *(short*)(obj + Enum_ov023_021dc134_1906) = key;
    *(short*)(obj + Enum_ov023_021dc134_1908) = 0;

    *(unsigned char*)(obj + Enum_ov023_021dc134_1910) = 0;
    *(unsigned char*)(obj + Enum_ov023_021dc134_1911) = 0;
    *(unsigned char*)(obj + Enum_ov023_021dc134_1912) = 0;
    *(signed char*)(obj + Enum_ov023_021dc134_1913) = -1;
    *(signed char*)(obj + Enum_ov023_021dc134_1914) = -1;
    *(signed char*)(obj + Enum_ov023_021dc134_1946) = -1;

    ((Struct_ov023_021dc134*)(obj + Enum_ov023_021dc134_1947))->bit0 = 0;
    ((Struct_ov023_021dc134*)(obj + Enum_ov023_021dc134_1947))->unknown_0_1_ = 0;

    *(signed char*)(obj + Enum_ov023_021dc134_1917) = -1;
    *(unsigned char*)(obj + Enum_ov023_021dc134_1918) = 1;
    *(int*)(obj + Enum_ov023_021dc134_1920) = -1;

    func_ov023_021dce88(obj);

    *(int*)(obj + Enum_ov023_021dc134_1888) = 0;
    *(int*)(obj + Enum_ov023_021dc134_1892) = 0;
    *(unsigned char*)(obj + Enum_ov023_021dc134_1945) = 1;
    *(int*)(obj + Enum_ov023_021dc134_1896) = 0;
    *(int*)(obj + Enum_ov023_021dc134_1900) = 0;

#if defined(jpn)
    data_ov023_021ff9e0.field18 = 5;
    data_ov023_021ff9e0.unknown_c_ = 7;
#else
    data_ov023_021ff9e0.field18 = 5;
#endif

    data_ov023_021ff9e0.fieldc = 9;
#if defined(jpn)

#else
    data_ov023_021ff9e0.field10 = 0;
#endif


    *(signed char*)(obj + Enum_ov023_021dc134_1915) = (signed char)flag;
    *(unsigned char*)(obj + Enum_ov023_021dc134_1916) = 1;

    if (flag == 1) {
        *(unsigned char*)(obj + Enum_ov023_021dc134_1916) = 0;
        *(unsigned short*)(obj + Enum_ov023_021dc134_1908) |= 0x800;
    }

    *(short*)(obj + 0xc2) = 0;
    memset(obj + 0xbc, 0, 6);

    data_ov023_021ff9e0.field14 = obj + 0x54;
    data_ov023_021ff9e0.field24 = obj + 0x6c;
    data_ov023_021ff9e0.field0 = obj + 0x7c;
    data_ov023_021ff9e0.field8 = obj + 0x8c;
    data_ov023_021ff9e0.field28 = obj + 0xa4;
    data_ov023_021ff9e0.field20 = obj;

    *(unsigned short*)(obj + Enum_ov023_021dc134_1908) |= 8;

    func_ov023_021db0d4(&data_ov023_021ffa0c, 0);
}
