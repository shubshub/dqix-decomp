#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"
#include "std_library_functions.h"

struct Struct_02011930 {
    unsigned char b0;
    unsigned char b1;
    unsigned short s0;
};
extern "C" unsigned char func_02011930(void* obj, struct Struct_02011930* info, void* name1, void* name2);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern char* data_ov004_02171010;
extern "C" void* Zone3D_GetInstance(void);
struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};
extern "C" struct Elem020985ec* func_020985ec(struct Elem020985ec* arr, int val);

// USA: func_ov004_02164f48
extern "C" ARM int func_ov004_02164f48(void* a1) {
    char* battle = (char*)GameState::GetInstance();
    struct Struct_02011930 info;
    char var2[0xa];
    char var3[0xa];
    var2[0] = 0;
    var3[0] = 0;

    if (func_02011930(battle, &info, var2, var3) != 0) {
        func_ov011_021848a0(a1, 0x69);

        srand(GetMain16BitTimerCounter());

        char* arr = data_ov004_02171010;
#if defined(jpn)
        unsigned char cnt = *(unsigned char*)(arr + 0x1000 + 0x9f4);
#else
        unsigned char cnt = *(unsigned char*)(arr + 0x1000 + 0x8f4);
#endif
        TreasureMapMetadata* var6 = (TreasureMapMetadata*)(arr + cnt * 0x1c);

        if (info.b0 == 1) {
            var6->InitialiseAsNonLegacyMap(info.b1, info.s0);
        } else if (info.b0 == 2) {
            var6->InitialiseAsLegacyBossMap(info.b1, info.s0 & 0xff);
#if defined(jpn)
            unsigned short var7 = *(unsigned short*)(battle + 0x6100 + 0xfe);
#else
            unsigned short var7 = *(unsigned short*)(battle + 0x6400 + 0x7e);
#endif
            if (var7 != 0) var6->SeedOrMinTurns = var7;
        } else {
            var6->InitialiseAsNonLegacyMap(0, 0);
        }

        if (var2[0] != 0) {
            VectorizedInvertedMemcpy(var2, (char*)var6 + 1, 0xa);
        } else {
            var6->DiscoveredBy[0] = 0;
        }
        if (var3[0] != 0) {
            VectorizedInvertedMemcpy(var3, (char*)var6 + 0xb, 0xa);
        } else {
            var6->ClearedBy[0] = 0;
        }

#if defined(jpn)
        int var8 = *(int*)(battle + 0x6000 + 0x1f8);
#else
        int var8 = *(int*)(battle + 0x6000 + 0x478);
#endif
        if (var8 != -1) var6->Location = (unsigned char)var8;
#if defined(jpn)
        unsigned char var9 = *(unsigned char*)(battle + 0x6000 + 0x1fc);
#else
        unsigned char var9 = *(unsigned char*)(battle + 0x6000 + 0x47c);
#endif
        if (var9 != 0) var6->TreasureDiscoveryFlags = var9;

        unsigned char* arr2 = (unsigned char*)data_ov004_02171010;
#if defined(jpn)
        *(arr2 + 0x1000 + 0x9f4) = *(arr2 + 0x1000 + 0x9f4) + 1;
#else
        *(arr2 + 0x1000 + 0x8f4) = *(arr2 + 0x1000 + 0x8f4) + 1;
#endif

#if defined(jpn)
        int var11 = *(int*)(battle + 0x6000 + 0x1f4);
#else
        int var11 = *(int*)(battle + 0x6000 + 0x474);
#endif
        if (var11 >= 0) {
#if defined(jpn)
            struct Elem020985ec* base = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + 0x860);
#else
            struct Elem020985ec* base = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + 0x840);
#endif
            struct Elem020985ec* elem = func_020985ec(base, var11);
            if (elem) {
                ((unsigned char*)elem)[0xb] &= ~0x80;
            }
        }
#if defined(jpn)
        *(int*)(battle + 0x6000 + 0x1f4) = -1;
#else
        *(int*)(battle + 0x6000 + 0x474) = -1;
#endif
    } else {
        func_ov011_021848a0(a1, 0x69);
    }
    return 0;
}
