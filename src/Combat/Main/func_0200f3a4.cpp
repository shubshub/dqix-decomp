#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"
#include "Util/Random.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_020c99c8(void* out);
void InitBigManagerStruct0208660c(char* base);
struct PartyExtension;
extern "C" void func_02082828(PartyExtension* ext);
void ClearSubstructBytes_0200fb40(void* obj);
struct Pair0209a338;
void ClearFirstTwoWords0209a338(Pair0209a338* p);
struct S_02010124;
void InitFields02010124(S_02010124* obj);
void ResetState_020118fc(void* obj);
void* GlobalFlags_GetInstance();
struct S02046730;
void ClearField0x0_02046730(S02046730* p);
struct State0200fad4;
void ClearFlagsAndValue0200fad4(State0200fad4* s);

struct Struct_020f33b4 {
    unsigned char unknown_0_;
    float unknown_4_;
    float unknown_8_;
    float unknown_c_;
    float unknown_10_;
    float unknown_14_;
};
extern Struct_020f33b4 data_020f33b4;

struct Struct_0200f3a4_12 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_0200f3a4 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 10;
    unsigned int unknown_2_3_ : 11;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_0200f3a4_2 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 25;
};

struct Struct_0200f3a4_3 {
    unsigned short unknown_0_0_ : 14;
    unsigned short unknown_1_6_ : 1;
    unsigned short unknown_1_7_ : 1;
};

struct Struct_0200f3a4_4 {
    char unknown_0_[6];
    char unknown_6_[0xb];
    unsigned char unknown_11_;
    Struct_0200f3a4_3 unknown_12_;
    char unknown_14_[0x18];
};

struct Struct_0200f3a4_5 {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};

struct Struct_0200f3a4_6 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 3;
};

// USA: func_0200f3a4
// EUR: func_0200f3a4
#if defined(jpn)
#define J(x) ((x) < 0x6470 ? (x) - 0x260 : (x) < 0x64de ? (x) - 0x280 : (x) < 0x7f00 ? (x) - 0x240 : (x) - 0x2d4)
#define J_PARTY_STRIDE 0x8cc
#define J_MEMSET_649E 0x80
#else
#define J(x) (x)
#define J_PARTY_STRIDE 0x964
#define J_MEMSET_649E 0x40
#endif

extern "C" ARM void func_0200f3a4(void* arg0) {
    GameState* var0 = (GameState*)arg0;
    char* var1 = (char*)arg0;
#if !defined(jpn)
    unsigned char var2[0x54];
    unsigned char var3;

    func_020c99c8(var2);
    var3 = var2[0];
    *(unsigned char*)(var1 + 5) = var3;
#if defined(eur)
    if (var3 != 2 && var3 != 3 && var3 != 4 && var3 != 5) *(unsigned char*)(var1 + 5) = 1;
#else
    if (var3 != 2 && var3 != 5) *(unsigned char*)(var1 + 5) = 1;
#endif
#endif

    memset(var0->objects_, 0, sizeof(var0->objects_));

    func_0208660c(var1 + J(0x2a04));

    gs->camera_ = 0;
    gs->protagonistObjectIndex_ = 0;
    for (int i = 0; i < 4; i++) {
        func_02082828((PartyExtension*)(base + 0x474 + i * J_PARTY_STRIDE));
    }

    VectorizedMemset(var1 + 0x3f8, 0, 0x70);
    *(unsigned char*)(var1 + 0x3fc) = 1;
    *(unsigned char*)(var1 + 0x400) = 1;
    *(unsigned char*)(var1 + 0x401) = 1;
    *(signed char*)(var1 + 0x403) = -1;
    *(int*)(var1 + 0x418) = -1;
    *(int*)(var1 + 0x41c) = -1;
    *(int*)(var1 + 0x420) = -1;
    *(int*)(var1 + 0x424) = -1;
    *(short*)(var1 + 0x416) = -1;
    *(unsigned char*)(var1 + 0x404) = 0;
    *(short*)(var1 + 0x464) = -1;
    *(int*)(var1 + J(0x5ca4)) = 0;
    *(int*)(var1 + J(0x5ca8)) = 0;

#if defined(jpn)
    var0->dayLength_ = data_020f33b4.unknown_8_;
#else
    var0->dayLength_ = data_020f33b4.unknown_4_;
#endif
    var0->daySpeed_ = 1.0f / 60.0f;
    var0->dayTimer_ = data_020f33b4.unknown_c_;
    var0->timeOfDay_ = TimeOfDay_Day;
    var0->dayTimerRunning_ = 1;
    var0->unknown_3e0_ = 0;
    memset(&var0->mainTimestamp_, 0, sizeof(var0->mainTimestamp_));
    memset(&var0->altTimestamp_, 0, sizeof(var0->altTimestamp_));

    *(int*)(var1 + J(0x5cb0)) = 1;
    *(int*)(var1 + J(0x5cb4)) = 1;
    *(int*)(var1 + J(0x5cb8)) = 1;
    *(int*)(var1 + J(0x5cbc)) = 1;
    *(unsigned char*)(var1 + J(0x5728)) = 0;
    *(unsigned char*)(var1 + J(0x5729)) = 0;
    memset(var1 + J(0x5cc0), 0, 8);

    *(unsigned char*)(var1 + J(0x63d4)) = 0;
    *(unsigned char*)(var1 + J(0x5cda)) = 8;
    memset(var1 + J(0x5cdc), 0, 0x190);

    {
        unsigned long long var5 = GetCurrentTimestamp();
        srand(var5 & 0xffffffff);
        SeedRandom64(GetBTRandom(), var5);
    }

    *(int*)(var1 + J(0x7f5c)) = 0;
    *(int*)(var1 + J(0x7f60)) = 0;
    *(int*)(var1 + J(0x7f64)) = 0;
    *(int*)(var1 + J(0x7f68)) = 0;
    func_0200fb40(var1);

    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_0_0_ = 0x7d0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_1_4_ = 1;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_2_0_ = 1;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_4_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_2_5_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_3_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_1_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_2_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_5_ = 0;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_6_ = 1;
    ((Struct_0200f3a4_12*)(var1 + J(0x569c)))->unknown_3_7_ = 0;
    ((Struct_0200f3a4*)(var1 + J(0x56a0)))->unknown_0_0_ = 0x1ff;
    ((Struct_0200f3a4*)(var1 + J(0x56a0)))->unknown_3_6_ = 0;
    ((Struct_0200f3a4*)(var1 + J(0x56a0)))->unknown_1_1_ = 300;
    ((Struct_0200f3a4*)(var1 + J(0x56a0)))->unknown_2_3_ = 706;
    *(unsigned char*)(var1 + J(0x56a4)) = 0;

    func_0209a338((Struct_0200f3a4_8*)(var1 + J(0x572c)));
    memset(var1 + J(0x5734), 0, 0x570);

    *(short*)(var1 + J(0x5e6c)) = 0;
    for (int var6 = 0; var6 < 6; var6++) {
        *(short*)(var1 + var6 * 0x28 + J(0x5e70)) = -1;
        {
            Struct_0200f3a4_2* var7 = (Struct_0200f3a4_2*)(var1 + J(0x5e74) + var6 * 0x28);
            var7->unknown_0_0_ = 0;
            var7->unknown_0_7_ = 0;
        }
        memset(var1 + J(0x5e78) + var6 * 0x28, 0, 0xc);
        memset(var1 + J(0x5e84) + var6 * 0x28, 0, 0x12);
    }

    memset(var1 + J(0x5f60), 0, 4);

    *(short*)(var1 + J(0x5f64)) = -1;
    *(short*)(var1 + J(0x5f66)) = 0;
    *(short*)(var1 + J(0x5f68)) = 0;
    memset(var1 + J(0x5f6c), 0, 4);

    memset(var1 + J(0x5f70), 0, 4);
    memset(var1 + J(0x5f74), 0, 4);

    {
        Struct_0200f3a4_5* var8 = (Struct_0200f3a4_5*)(var1 + J(0x5f78));
        var8->unknown_0_0_ = 0;
        var8->unknown_1_5_ = 0;
    }
    *(int*)(var1 + J(0x5f7c)) = 0;

    memset(var1 + J(0x5f80), 0, 0x200);
    memset(var1 + J(0x6180), 0, 0x200);
    memset(var1 + J(0x6380), 0, 0x54);
    memset(var1 + J(0x5718), 0, 4);

    *(unsigned char*)(var1 + J(0x571c)) = 1;

    memset(var1 + J(0x571d), 0, 4);

    *(unsigned char*)(var1 + J(0x5721)) = 1;

    *(unsigned int*)(var1 + J(0x5ccc)) &= ~1u;
    *(unsigned int*)(var1 + J(0x5ccc)) |= 2u;

    func_02010124((Struct_0200f3a4_9*)var1);

    *(unsigned char*)(var1 + J(0x63d6)) = 0;
    *(short*)(var1 + J(0x63d8)) = 0;
    *(short*)(var1 + J(0x63da)) = 0;
    *(int*)(var1 + J(0x63e0)) = 0;
    *(unsigned char*)(var1 + J(0x63e4)) = 0;
    *(unsigned char*)(var1 + J(0x63e5)) = 0;
    *(unsigned char*)(var1 + J(0x63e6)) = 1;
    *(unsigned char*)(var1 + J(0x63e7)) = 0;
    *(unsigned char*)(var1 + J(0x63e8)) = 0;
    *(unsigned char*)(var1 + J(0x63ed)) = 0;
    func_020118fc(var1);

    *(unsigned char*)(var1 + J(0x6480)) = 0;
    VectorizedMemset(var1 + J(0x649e), 0, J_MEMSET_649E);

    *(unsigned char*)(var1 + J(0x64de)) = 0;
    *(int*)(var1 + J(0x6474)) = -1;
    *(unsigned char*)(var1 + J(0x63dc)) = 0;
    *(short*)(var1 + J(0x71dc)) = 0;
#if !defined(jpn)
    var0->unknown_7f58_ = 0;
#endif
    *(short*)(var1 + J(0x71de)) = -1;
    *(short*)(var1 + J(0x71e0)) = -1;
    *(int*)(var1 + J(0x5724)) = 0;

    if (*(int*)(var1 + J(0x7f6c)) < 1) {
        *(int*)(var1 + J(0x7f6c)) = 0;
        *(unsigned char*)(var1 + J(0x7f72)) = 0;
        *(unsigned char*)(var1 + J(0x7f73)) = 0;
    }
    *(unsigned char*)(var1 + J(0x7f70)) = 0;
    *(unsigned char*)(var1 + J(0x63d5)) = 1;
    if (data_020f33b4.unknown_0_ == 0) {
        *(unsigned char*)(var1 + J(0x7f71)) = 0;
        data_020f33b4.unknown_0_ = 1;
    }

    *(int*)(var1 + J(0x71f8)) = 0;
    *(unsigned char*)(var1 + J(0x71fc)) = 0;

    for (int var9 = 0; var9 < 16; var9++) {
        VectorizedMemset(((Struct_0200f3a4_4*)(var1 + J(0x7200) + var9 * 0x2c))->unknown_0_, 0, 6);
        memset(((Struct_0200f3a4_4*)(var1 + J(0x7200) + var9 * 0x2c))->unknown_6_, 0, 0xb);
        ((Struct_0200f3a4_4*)(var1 + J(0x7200) + var9 * 0x2c))->unknown_12_.unknown_0_0_ = 0;
        *(unsigned char*)(var1 + var9 * 0x2c + J(0x7211)) = 0;
        ((Struct_0200f3a4_4*)(var1 + J(0x7200) + var9 * 0x2c))->unknown_12_.unknown_1_6_ = 0;
        VectorizedMemset(((Struct_0200f3a4_4*)(var1 + J(0x7200) + var9 * 0x2c))->unknown_14_, 0, 0x18);
    }

    memset(var1 + J(0x74de), 0, 0x20);
    memset(var1 + J(0x74fe), 0, 6);
    memset(var1 + J(0x71e4), 0, 0xc);

    *(int*)(var1 + J(0x71f0)) = 0;
    *(int*)(var1 + J(0x71f4)) = 0;

    ClearField0x0_02046730((S02046730*)GlobalFlags_GetInstance());

    memset(var1 + J(0x7504), 0, 0xec);
    memset(var1 + J(0x75f0), 0, 0x4d0);
    memset(var1 + J(0x7ac0), 0, 0x3b4);

    *(unsigned char*)(var1 + J(0x7e7e)) = 0xff;
    *(short*)(var1 + J(0x7e78)) = 0;
    *(short*)(var1 + J(0x7e7a)) = 0;
    *(short*)(var1 + J(0x7e7c)) = 0;
    *(int*)(var1 + J(0x7e74)) = 0x452;
    *(unsigned char*)(var1 + J(0x5cac)) = 0;
    var0->currentNumTicks_ = 0;

    for (int var10 = 0; var10 < 3; var10++) {
        func_0200fad4((Struct_0200f3a4_11*)(var1 + J(0x7f8c) + var10 * 0xc));
        VectorizedMemset(var1 + J(0x74c0) + var10 * 0xa, 0, 6);
        *(signed char*)(var1 + var10 * 0xa + J(0x74c6)) = -1;
        *(unsigned char*)(var1 + var10 * 0xa + J(0x74c7)) = 0;
        *(unsigned char*)(var1 + var10 * 0xa + J(0x74c8)) = 0;
        *(signed char*)(var1 + var10 * 0xa + J(0x74c9)) = -1;
    }

    memset(var1 + J(0x7fb0), 0, 0x40);

    {
        Struct_0200f3a4_6* var11 = (Struct_0200f3a4_6*)(var1 + J(0x7ff0));
        var11->unknown_0_0_ = 0;
        var11->unknown_0_1_ = 0;
        var11->unknown_0_2_ = 0;
        var11->unknown_0_3_ = 0;
        var11->unknown_0_4_ = 0;
    }
    *(unsigned char*)(var1 + J(0x7ff1)) = 0;
    *(unsigned char*)(var1 + J(0x7ff2)) = 0;
}
