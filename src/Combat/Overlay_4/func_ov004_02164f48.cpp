#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"
#include "std_library_functions.h"

struct Struct_02011930 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
};
extern "C" unsigned char func_02011930(void* arg0, struct Struct_02011930* arg1, void* arg2, void* arg3);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern char* data_ov004_02171010;
extern "C" void* Zone3D_GetInstance(void);
struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};
extern "C" struct Struct_020985ec* func_020985ec(struct Struct_020985ec* arg0, int arg1);

// USA: func_ov004_02164f48
extern "C" ARM int func_ov004_02164f48(void* arg0) {
    char* var0 = (char*)GameState::GetInstance();
    struct Struct_02011930 var1;
    char var2[0xa];
    char var3[0xa];
    var2[0] = 0;
    var3[0] = 0;

    if (func_02011930(var0, &var1, var2, var3) != 0) {
        func_ov011_021848a0(arg0, 0x69);

        srand(GetMain16BitTimerCounter());

        char* var4 = data_ov004_02171010;
#if defined(jpn)
        unsigned char var5 = *(unsigned char*)(var4 + 0x1000 + 0x9f4);
#else
        unsigned char var5 = *(unsigned char*)(var4 + 0x1000 + 0x8f4);
#endif
        TreasureMapMetadata* var6 = (TreasureMapMetadata*)(var4 + var5 * 0x1c);

        if (var1.unknown_0_ == 1) {
            var6->InitialiseAsNonLegacyMap(var1.unknown_1_, var1.unknown_2_);
        } else if (var1.unknown_0_ == 2) {
            var6->InitialiseAsLegacyBossMap(var1.unknown_1_, var1.unknown_2_ & 0xff);
#if defined(jpn)
            unsigned short var7 = *(unsigned short*)(var0 + 0x6100 + 0xfe);
#else
            unsigned short var7 = *(unsigned short*)(var0 + 0x6400 + 0x7e);
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
        int var8 = *(int*)(var0 + 0x6000 + 0x1f8);
#else
        int var8 = *(int*)(var0 + 0x6000 + 0x478);
#endif
        if (var8 != -1) var6->Location = (unsigned char)var8;
#if defined(jpn)
        unsigned char var9 = *(unsigned char*)(var0 + 0x6000 + 0x1fc);
#else
        unsigned char var9 = *(unsigned char*)(var0 + 0x6000 + 0x47c);
#endif
        if (var9 != 0) var6->TreasureDiscoveryFlags = var9;

        unsigned char* var10 = (unsigned char*)data_ov004_02171010;
#if defined(jpn)
        *(var10 + 0x1000 + 0x9f4) = *(var10 + 0x1000 + 0x9f4) + 1;
#else
        *(var10 + 0x1000 + 0x8f4) = *(var10 + 0x1000 + 0x8f4) + 1;
#endif

#if defined(jpn)
        int var11 = *(int*)(var0 + 0x6000 + 0x1f4);
#else
        int var11 = *(int*)(var0 + 0x6000 + 0x474);
#endif
        if (var11 >= 0) {
#if defined(jpn)
            struct Elem020985ec* base = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + 0x860);
#else
            struct Elem020985ec* base = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + 0x840);
#endif
            struct Struct_020985ec* var13 = func_020985ec(var12, var11);
            if (var13) {
                ((unsigned char*)var13)[0xb] &= ~0x80;
            }
        }
#if defined(jpn)
        *(int*)(var0 + 0x6000 + 0x1f4) = -1;
#else
        *(int*)(var0 + 0x6000 + 0x474) = -1;
#endif
    } else {
        func_ov011_021848a0(arg0, 0x69);
    }
    return 0;
}
