#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_ov023_021db2e4(volatile int* p);

// USA: func_ov023_021dcdf4
extern "C" ARM void func_ov023_021dcdf4(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6b0, regionalOffset1=0x6b4, regionalOffset2=0x6d0, regionalOffset3=0x6ec, regionalOffset4=0x6ee, regionalOffset5=0x6f0, regionalOffset6=0x6f2, Enum_ov023_021dcdf4_1913=0x6f5};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x738, regionalOffset2=0x754, regionalOffset3=0x770, regionalOffset4=0x772, regionalOffset5=0x774, regionalOffset6=0x776, Enum_ov023_021dcdf4_1913=0x779};
#endif
    (int)BackgroundLoader::GetInstance();
    if (*((unsigned char*)obj + regionalOffset6)) {
        func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset0));
        for (int i = 0; i < 7; i++) {
            func_ov023_021db2e4((volatile int*)((char*)obj + regionalOffset1 + i * 4));
        }
        *(int*)((char*)obj + regionalOffset2) = 0;
        *(unsigned short*)((char*)obj + regionalOffset5) |= 1;
    }
    *(short*)((char*)obj + regionalOffset4) = -1;
    *(short*)((char*)obj + regionalOffset3) = -2;
    *(char*)((char*)obj + Enum_ov023_021dcdf4_1913) = -1;
    *(unsigned short*)((char*)obj + regionalOffset5) &= ~4;
    *(unsigned short*)((char*)obj + regionalOffset5) &= ~0x2000;
}
