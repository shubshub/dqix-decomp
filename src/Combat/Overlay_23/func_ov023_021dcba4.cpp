#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021db2e4(volatile int* p);
extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);

struct Struct_ov023_021dcba4 {
#if defined(jpn)
    char pad0[0xec];
#else
    char pad0[0x70];
#endif

    short unknown_70_;
    short unknown_72_;
    unsigned short unknown_74_;
    char unknown_76_[0x7c - 0x76];
    signed char f7c;
};

// USA: func_ov023_021dcba4
extern "C" ARM void func_ov023_021dcba4(void* obj, short arg1) {
#if defined(jpn)
 enum {regionalOffset0=0x6b0, regionalOffset1=0x6b4, regionalOffset2=0x6d0, regionalOffset3=0x6ec, regionalOffset4=0x6ee, regionalOffset5=0x6f0, regionalOffset6=0x6f2, Enum_ov023_021dcba4_1916=0x6f8, Enum_ov023_021dcba4_1792=0x600};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x738, regionalOffset2=0x754, regionalOffset3=0x770, regionalOffset4=0x772, regionalOffset5=0x774, regionalOffset6=0x776, Enum_ov023_021dcba4_1916=0x77c, Enum_ov023_021dcba4_1792=0x700};
#endif
    if (*((unsigned char*)obj + regionalOffset6) == 0) {
        ((struct Struct_ov023_021dcba4*)((char*)obj + Enum_ov023_021dcba4_1792))->unknown_72_ = arg1;
        return;
    }

    if ((((struct Struct_ov023_021dcba4*)((char*)obj + Enum_ov023_021dcba4_1792))->unknown_74_ & 4) == 0) {
        return;
    }

    func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset0));
    for (int i = 0; i < 7; i++) {
        func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset1 + i * 4));
    }

    *(short*)((char*)obj + regionalOffset3) = arg1;
    *(short*)((char*)obj + regionalOffset4) = *(short*)((char*)obj + regionalOffset3);
    *(int*)((char*)obj + regionalOffset2) = 0;
    *(unsigned short*)((char*)obj + regionalOffset5) |= 9;

    if (*(signed char*)((char*)obj + Enum_ov023_021dcba4_1916) == 1) {
        memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
    } else {
        memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
    }
}
