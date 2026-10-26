#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" void func_ov023_021dcae0(void* obj, int val);
extern "C" void func_ov023_021db2e4(volatile int* p);
struct Struct_ov023_021fdaa8 { int handler; int unknown_4_; };
extern Struct_ov023_021fdaa8 data_ov023_021fdaa8[];

// USA: func_ov023_021dfb4c
extern "C" ARM void func_ov023_021dfb4c(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6ee, regionalOffset1=0x6ec, regionalOffset2=0x6f0, regionalOffset3=0x6f7, regionalOffset4=0x717, regionalOffset5=0x6b0, regionalOffset6=0x6b4, Enum_ov023_021dfb4c_1876=0x6d0};
#else
 enum {regionalOffset0=0x772, regionalOffset1=0x770, regionalOffset2=0x774, regionalOffset3=0x77b, regionalOffset4=0x79b, regionalOffset5=0x734, regionalOffset6=0x738, Enum_ov023_021dfb4c_1876=0x754};
#endif
    short var0 = *(short*)((char*)obj + regionalOffset0);
    short field770 = *(short*)((char*)obj + regionalOffset1);
    if (field770 != var0) {
        func_ov023_021dcae0(obj, var0);
    }

    if ((*(unsigned short*)((char*)obj + regionalOffset2) & 1) == 0) {
        return;
    }

    if (*(signed char*)((char*)obj + regionalOffset3) == 1) {
        struct Struct_ov023_021dfb4c { unsigned char bit0 : 1; unsigned char unknown_0_1_ : 1; unsigned char rest : 6; };
        if (((Struct_ov023_021dfb4c*)((char*)obj + regionalOffset4))->unknown_0_1_ == 0) {
            func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset5));
            for (int i = 0; i < 7; i++) {
                func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset6 + i * 4));
            }
            *(unsigned short*)((char*)obj + regionalOffset2) |= 1;
            *(int*)((char*)obj + Enum_ov023_021dfb4c_1876) = 0;
            return;
        }
    }

    (int)BackgroundLoader::GetInstance();
    Struct_ov023_021fdaa8* table = data_ov023_021fdaa8;

    while (*(int*)((char*)obj + Enum_ov023_021dfb4c_1876) >= 0 &&
           table[*(int*)((char*)obj + Enum_ov023_021dfb4c_1876)].handler != 0) {
        int idx = *(int*)((char*)obj + Enum_ov023_021dfb4c_1876);
        Struct_ov023_021fdaa8* entry = &table[idx];
        int var6 = entry->unknown_4_;
        int var7 = *(int*)((char*)obj + Enum_ov023_021dfb4c_1876);

        char* arg = (char*)obj + (var6 >> 1);
        int (*fn)(void*);
        if (var6 & 1) {
            void* var10 = *(void**)arg;
            fn = *(int(**)(void*))((char*)var10 + entry->handler);
        } else {
            fn = (int(*)(void*))entry->handler;
        }

        int result = fn(arg);
        *(int*)((char*)obj + Enum_ov023_021dfb4c_1876) = result;
        if (result < 0) {
            *(unsigned short*)((char*)obj + regionalOffset2) &= ~1;
            func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset5));
            for (int i = 0; i < 7; i++) {
                func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset6 + i * 4));
            }
            return;
        }
        if (var7 == result) {
            return;
        }
    }
}
