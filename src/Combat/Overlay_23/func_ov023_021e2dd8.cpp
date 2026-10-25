#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void ItemTable_Init(void* obj);
void ClearFields_021e20c0(void* p);
void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount);

// USA: func_ov023_021e2dd8
extern "C" ARM void func_ov023_021e2dd8(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021e2dd8_296=0x124, Enum_ov023_021e2dd8_300=0x128, Enum_ov023_021e2dd8_308=0x130, Enum_ov023_021e2dd8_1254=0x4e2, Enum_ov023_021e2dd8_1255=0x4e3, Enum_ov023_021e2dd8_288=0x11c, Enum_ov023_021e2dd8_292=0x120, Enum_ov023_021e2dd8_1256=0x4e4, Enum_ov023_021e2dd8_1260=0x4e8, Enum_ov023_021e2dd8_1252=0x4e0, Enum_ov023_021e2dd8_1584=0x568, Enum_ov023_021e2dd8_1588=0x56c, Enum_ov023_021e2dd8_1590=0x56e, Enum_ov023_021e2dd8_1592=0x570, Enum_ov023_021e2dd8_1596=0x574};
#else
 enum {Enum_ov023_021e2dd8_296=0x128, Enum_ov023_021e2dd8_300=0x12c, Enum_ov023_021e2dd8_308=0x134, Enum_ov023_021e2dd8_1254=0x4e6, Enum_ov023_021e2dd8_1255=0x4e7, Enum_ov023_021e2dd8_288=0x120, Enum_ov023_021e2dd8_292=0x124, Enum_ov023_021e2dd8_1256=0x4e8, Enum_ov023_021e2dd8_1260=0x4ec, Enum_ov023_021e2dd8_1252=0x4e4, Enum_ov023_021e2dd8_1584=0x630, Enum_ov023_021e2dd8_1588=0x634, Enum_ov023_021e2dd8_1590=0x636, Enum_ov023_021e2dd8_1592=0x638, Enum_ov023_021e2dd8_1596=0x63c};
#endif
    void* var0;
    GameState* var1;
    signed char var2[4];
    signed char var3;
    int var4;
    int var5;

    p = GlobalFlags_GetInstance();
    FlagWord_SetBits((unsigned int*)p, 0xf);

    *(unsigned int*)(arg0 + 0x0) = 0;
    *(unsigned int*)(arg0 + 0x4) = 0;
    *(unsigned int*)(arg0 + 0xc) = 0;
    *(unsigned int*)(arg0 + 0x10) = 0;
    *(unsigned int*)(arg0 + 0x14) = 0;

    ((SafeAllocator*)(arg0 + 0x2c))->ResetAllocatorPointer();
    ((SafeAllocator*)(arg0 + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(arg0 + 0x54))->ResetAllocatorPointer();
    ((SafeAllocator*)(arg0 + 0x68))->ResetAllocatorPointer();
    ((SafeAllocator*)(arg0 + 0x7c))->ResetAllocatorPointer();
    ((SafeAllocator*)(arg0 + 0x90))->ResetAllocatorPointer();

    ItemTable_Init(obj + 0xa4);

    *(unsigned short*)(arg0 + 0xbc) = 0;
    *(unsigned short*)(arg0 + 0xbe) = 0;
    *(unsigned int*)(arg0 + 0xc0) = 0;
    *(unsigned int*)(arg0 + 0xc4) = 0;
    *(unsigned int*)(arg0 + 0xc8) = 0;
    *(unsigned int*)(arg0 + 0xcc) = 0;
    *(unsigned int*)(arg0 + 0xd0) = 0;

    func_ov023_021e20c0(arg0 + 0xd4);

    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_296) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_300) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_308) = 0;
    *(unsigned char*)(arg0 + Enum_ov023_021e2dd8_1254) = 0;
    *(unsigned char*)(arg0 + Enum_ov023_021e2dd8_1255) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_288) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_292) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_1256) = 0;

    var1 = GameState::GetInstance();
    var3 = 0;
    for (var4 = 0; var4 < 4; var4++) var2[var4] = -1;
    func_020dc4d0(var2, &var3);
    for (var5 = 0; var5 < 4; var5++) {
        signed char var6 = var2[var5];
        *(int*)((char*)arg0 + var5 * 4 + Enum_ov023_021e2dd8_1260) = var6;
        func_0200ff1c(var1, var6);
    }

    *(int*)(arg0 + Enum_ov023_021e2dd8_1256) = var3;
    *(unsigned char*)(arg0 + Enum_ov023_021e2dd8_1252) = 1;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_1584) = 0;
    memset(arg0 + Enum_ov023_021e2dd8_1588, 0, 2);
    *(unsigned char*)(arg0 + Enum_ov023_021e2dd8_1590) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_1592) = 0;
    *(unsigned int*)(arg0 + Enum_ov023_021e2dd8_1596) = 0;
#if defined(jpn)

#else
    *(unsigned int*)(arg0 + 0x640) = 0;
    *(unsigned int*)(arg0 + 0x644) = 0;
#endif

}
