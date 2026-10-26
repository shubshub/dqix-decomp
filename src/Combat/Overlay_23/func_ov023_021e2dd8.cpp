#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void ItemTable_Init(void* obj);
extern "C" void func_ov023_021e20c0(void* p);
extern "C" void func_020dc4d0(signed char* out, signed char* outCount);

// USA: func_ov023_021e2dd8
extern "C" ARM void func_ov023_021e2dd8(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x128, regionalOffset2=0x130, regionalOffset3=0x4e2, regionalOffset4=0x4e3, regionalOffset5=0x11c, regionalOffset6=0x120, Enum_ov023_021e2dd8_1256=0x4e4, Enum_ov023_021e2dd8_1260=0x4e8, regionalOffset9=0x4e0, Enum_ov023_021e2dd8_1584=0x568, Enum_ov023_021e2dd8_1588=0x56c, Enum_ov023_021e2dd8_1590=0x56e, Enum_ov023_021e2dd8_1592=0x570, Enum_ov023_021e2dd8_1596=0x574};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x12c, regionalOffset2=0x134, regionalOffset3=0x4e6, regionalOffset4=0x4e7, regionalOffset5=0x120, regionalOffset6=0x124, Enum_ov023_021e2dd8_1256=0x4e8, Enum_ov023_021e2dd8_1260=0x4ec, regionalOffset9=0x4e4, Enum_ov023_021e2dd8_1584=0x630, Enum_ov023_021e2dd8_1588=0x634, Enum_ov023_021e2dd8_1590=0x636, Enum_ov023_021e2dd8_1592=0x638, Enum_ov023_021e2dd8_1596=0x63c};
#endif
    void* p;
    GameState* battle;
    signed char buf[4];
    signed char outCount;
    int i;
    int j;

    p = GlobalFlags_GetInstance();
    FlagWord_SetBits((unsigned int*)p, 0xf);

    *(unsigned int*)(obj + 0x0) = 0;
    *(unsigned int*)(obj + 0x4) = 0;
    *(unsigned int*)(obj + 0xc) = 0;
    *(unsigned int*)(obj + 0x10) = 0;
    *(unsigned int*)(obj + 0x14) = 0;

    ((SafeAllocator*)(obj + 0x2c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x54))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x68))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x7c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x90))->ResetAllocatorPointer();

    ItemTable_Init(obj + 0xa4);

    *(unsigned short*)(obj + 0xbc) = 0;
    *(unsigned short*)(obj + 0xbe) = 0;
    *(unsigned int*)(obj + 0xc0) = 0;
    *(unsigned int*)(obj + 0xc4) = 0;
    *(unsigned int*)(obj + 0xc8) = 0;
    *(unsigned int*)(obj + 0xcc) = 0;
    *(unsigned int*)(obj + 0xd0) = 0;

    func_ov023_021e20c0(obj + 0xd4);

    *(unsigned int*)(obj + regionalOffset0) = 0;
    *(unsigned int*)(obj + regionalOffset1) = 0;
    *(unsigned int*)(obj + regionalOffset2) = 0;
    *(unsigned char*)(obj + regionalOffset3) = 0;
    *(unsigned char*)(obj + regionalOffset4) = 0;
    *(unsigned int*)(obj + regionalOffset5) = 0;
    *(unsigned int*)(obj + regionalOffset6) = 0;
    *(unsigned int*)(obj + Enum_ov023_021e2dd8_1256) = 0;

    battle = GameState::GetInstance();
    outCount = 0;
    for (i = 0; i < 4; i++) buf[i] = -1;
    func_020dc4d0(buf, &outCount);
    for (j = 0; j < 4; j++) {
        signed char v = buf[j];
        *(int*)((char*)obj + j * 4 + Enum_ov023_021e2dd8_1260) = v;
        func_0200ff1c(battle, v);
    }

    *(int*)(obj + Enum_ov023_021e2dd8_1256) = outCount;
    *(unsigned char*)(obj + regionalOffset9) = 1;
    *(unsigned int*)(obj + Enum_ov023_021e2dd8_1584) = 0;
    memset(obj + Enum_ov023_021e2dd8_1588, 0, 2);
    *(unsigned char*)(obj + Enum_ov023_021e2dd8_1590) = 0;
    *(unsigned int*)(obj + Enum_ov023_021e2dd8_1592) = 0;
    *(unsigned int*)(obj + Enum_ov023_021e2dd8_1596) = 0;
#if defined(jpn)

#else
    *(unsigned int*)(obj + 0x640) = 0;
    *(unsigned int*)(obj + 0x644) = 0;
#endif

}
