#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"
#include "Util/Random.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void OS_GetOwnerInfo(void* out);
extern "C" void Party_Init(char* base);
struct Struct_0200f3a4_7;
extern "C" void func_02082828(Struct_0200f3a4_7* ext);
extern "C" void func_0200fb40(void* obj);
struct Pair0209a338;
extern "C" void func_0209a338(Pair0209a338* p);
struct S_02010124;
extern "C" void GameState_ResetTiming(S_02010124* obj);
extern "C" void func_020118fc(void* obj);
extern "C" void* GlobalFlags_GetInstance();
struct S02046730;
extern "C" void FlagWord_Clear(S02046730* p);
struct State0200fad4;
extern "C" void func_0200fad4(State0200fad4* s);

struct DayCycleTimes {
    unsigned char initialized;
#if defined(jpn)
    float eveningStart;
    float dayLength;
#else
    float dayLength;
    float eveningStart;
#endif
    float dayStart;
    float morningStart;
    float nightStart;
};
extern DayCycleTimes data_020f33b4;

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
    unsigned int low7 : 7;
    unsigned int unknown_0_7_ : 25;
};

struct TimedKey {
    unsigned char key[6];
    char unknown6[0xb];
    unsigned char timer;
    unsigned short count : 14;
    unsigned short active : 1;
    unsigned short flag : 1;
    char unknown14[0x18];
};

struct Struct_0200f3a4_5 {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};

struct Struct_0200f3a4_6 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char rest : 3;
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

extern "C" ARM void func_0200f3a4(void* obj) {
    GameState* gs = (GameState*)obj;
    char* base = (char*)obj;
#if !defined(jpn)
    unsigned char buf[0x54];
    unsigned char v;

    OS_GetOwnerInfo(buf);
    v = buf[0];
    *(unsigned char*)(base + 5) = v;
#if defined(eur)
    if (v != 2 && v != 3 && v != 4 && v != 5) *(unsigned char*)(base + 5) = 1;
#else
    if (v != 2 && v != 5) *(unsigned char*)(base + 5) = 1;
#endif
#endif

    memset(gs->objects_, 0, sizeof(gs->objects_));

    Party_Init(base + J(0x2a04));

    gs->camera_ = 0;
    gs->protagonistObjectIndex_ = 0;
    for (int i = 0; i < 4; i++) {
        func_02082828((Struct_0200f3a4_7*)(base + 0x474 + i * J_PARTY_STRIDE));
    }

    VectorizedMemset(base + 0x3f8, 0, 0x70);
    *(unsigned char*)(base + 0x3fc) = 1;
    *(unsigned char*)(base + 0x400) = 1;
    *(unsigned char*)(base + 0x401) = 1;
    *(signed char*)(base + 0x403) = -1;
    *(int*)(base + 0x418) = -1;
    *(int*)(base + 0x41c) = -1;
    *(int*)(base + 0x420) = -1;
    *(int*)(base + 0x424) = -1;
    *(short*)(base + 0x416) = -1;
    *(unsigned char*)(base + 0x404) = 0;
    *(short*)(base + 0x464) = -1;
    *(int*)(base + J(0x5ca4)) = 0;
    *(int*)(base + J(0x5ca8)) = 0;

    gs->dayLength_ = data_020f33b4.dayLength;
    gs->daySpeed_ = 1.0f / 60.0f;
    gs->dayTimer_ = data_020f33b4.dayStart;
    gs->timeOfDay_ = TimeOfDay_Day;
    gs->dayTimerRunning_ = 1;
    gs->unknown_3e0_ = 0;
    memset(&gs->mainTimestamp_, 0, sizeof(gs->mainTimestamp_));
    memset(&gs->altTimestamp_, 0, sizeof(gs->altTimestamp_));

    *(int*)(base + J(0x5cb0)) = 1;
    *(int*)(base + J(0x5cb4)) = 1;
    *(int*)(base + J(0x5cb8)) = 1;
    *(int*)(base + J(0x5cbc)) = 1;
    *(unsigned char*)(base + J(0x5728)) = 0;
    *(unsigned char*)(base + J(0x5729)) = 0;
    memset(base + J(0x5cc0), 0, 8);

    gs->characterCreated_ = 0;
    *(unsigned char*)(base + J(0x5cda)) = 8;
    memset(base + J(0x5cdc), 0, 0x190);

    {
        unsigned long long var5 = GetCurrentTimestamp();
        srand(var5 & 0xffffffff);
        SeedRandom64(GetBTRandom(), var5);
    }

    *(int*)(base + J(0x7f5c)) = 0;
    *(int*)(base + J(0x7f60)) = 0;
    *(int*)(base + J(0x7f64)) = 0;
    *(int*)(base + J(0x7f68)) = 0;
    func_0200fb40(base);

    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_0_0_ = 0x7d0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_1_4_ = 1;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_2_0_ = 1;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_4_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_2_5_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_3_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_1_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_2_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_5_ = 0;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_6_ = 1;
    ((Struct_0200f3a4_12*)(base + J(0x569c)))->unknown_3_7_ = 0;
    ((Struct_0200f3a4*)(base + J(0x56a0)))->unknown_0_0_ = 0x1ff;
    ((Struct_0200f3a4*)(base + J(0x56a0)))->unknown_3_6_ = 0;
    ((Struct_0200f3a4*)(base + J(0x56a0)))->unknown_1_1_ = 300;
    ((Struct_0200f3a4*)(base + J(0x56a0)))->unknown_2_3_ = 706;
    *(unsigned char*)(base + J(0x56a4)) = 0;

    func_0209a338((Pair0209a338*)(base + J(0x572c)));
    memset(base + J(0x5734), 0, 0x570);

    *(short*)(base + J(0x5e6c)) = 0;
    for (int i = 0; i < 6; i++) {
        *(short*)(base + i * 0x28 + J(0x5e70)) = -1;
        {
            Struct_0200f3a4_2* w = (Struct_0200f3a4_2*)(base + J(0x5e74) + i * 0x28);
            w->low7 = 0;
            w->unknown_0_7_ = 0;
        }
        memset(base + J(0x5e78) + i * 0x28, 0, 0xc);
        memset(base + J(0x5e84) + i * 0x28, 0, 0x12);
    }

    memset(base + J(0x5f60), 0, 4);

    *(short*)(base + J(0x5f64)) = -1;
    *(short*)(base + J(0x5f66)) = 0;
    *(short*)(base + J(0x5f68)) = 0;
    memset(base + J(0x5f6c), 0, 4);

    memset(base + J(0x5f70), 0, 4);
    memset(base + J(0x5f74), 0, 4);

    {
        Struct_0200f3a4_5* f = (Struct_0200f3a4_5*)(base + J(0x5f78));
        f->unknown_0_0_ = 0;
        f->unknown_1_5_ = 0;
    }
    *(int*)(base + J(0x5f7c)) = 0;

    memset(base + J(0x5f80), 0, 0x200);
    memset(base + J(0x6180), 0, 0x200);
    memset(base + J(0x6380), 0, 0x54);
    memset(base + J(0x5718), 0, 4);

    *(unsigned char*)(base + J(0x571c)) = 1;

    memset(base + J(0x571d), 0, 4);

    *(unsigned char*)(base + J(0x5721)) = 1;

    *(unsigned int*)(base + J(0x5ccc)) &= ~1u;
    *(unsigned int*)(base + J(0x5ccc)) |= 2u;

    GameState_ResetTiming((S_02010124*)base);

    *(unsigned char*)(base + J(0x63d6)) = 0;
    *(short*)(base + J(0x63d8)) = 0;
    *(short*)(base + J(0x63da)) = 0;
    *(int*)(base + J(0x63e0)) = 0;
    *(unsigned char*)(base + J(0x63e4)) = 0;
    *(unsigned char*)(base + J(0x63e5)) = 0;
    *(unsigned char*)(base + J(0x63e6)) = 1;
    *(unsigned char*)(base + J(0x63e7)) = 0;
    *(unsigned char*)(base + J(0x63e8)) = 0;
    *(unsigned char*)(base + J(0x63ed)) = 0;
    func_020118fc(base);

    *(unsigned char*)(base + J(0x6480)) = 0;
    VectorizedMemset(base + J(0x649e), 0, J_MEMSET_649E);

    *(unsigned char*)(base + J(0x64de)) = 0;
    *(int*)(base + J(0x6474)) = -1;
    *(unsigned char*)(base + J(0x63dc)) = 0;
    *(short*)(base + J(0x71dc)) = 0;
#if !defined(jpn)
    gs->unknown_7f58_ = 0;
#endif
    *(short*)(base + J(0x71de)) = -1;
    *(short*)(base + J(0x71e0)) = -1;
    *(int*)(base + J(0x5724)) = 0;

    if (*(int*)(base + J(0x7f6c)) < 1) {
        *(int*)(base + J(0x7f6c)) = 0;
        *(unsigned char*)(base + J(0x7f72)) = 0;
        *(unsigned char*)(base + J(0x7f73)) = 0;
    }
    *(unsigned char*)(base + J(0x7f70)) = 0;
    *(unsigned char*)(base + J(0x63d5)) = 1;
    if (data_020f33b4.initialized == 0) {
        *(unsigned char*)(base + J(0x7f71)) = 0;
        data_020f33b4.initialized = 1;
    }

    *(int*)(base + J(0x71f8)) = 0;
    *(unsigned char*)(base + J(0x71fc)) = 0;

    for (int i = 0; i < 16; i++) {
        VectorizedMemset(((TimedKey*)(base + J(0x7200) + i * 0x2c))->key, 0, 6);
        memset(((TimedKey*)(base + J(0x7200) + i * 0x2c))->unknown6, 0, 0xb);
        ((TimedKey*)(base + J(0x7200) + i * 0x2c))->count = 0;
        *(unsigned char*)(base + i * 0x2c + J(0x7211)) = 0;
        ((TimedKey*)(base + J(0x7200) + i * 0x2c))->active = 0;
        VectorizedMemset(((TimedKey*)(base + J(0x7200) + i * 0x2c))->unknown14, 0, 0x18);
    }

    memset(base + J(0x74de), 0, 0x20);
    memset(base + J(0x74fe), 0, 6);
    memset(base + J(0x71e4), 0, 0xc);

    *(int*)(base + J(0x71f0)) = 0;
    *(int*)(base + J(0x71f4)) = 0;

    FlagWord_Clear((S02046730*)GlobalFlags_GetInstance());

    memset(base + J(0x7504), 0, 0xec);
    memset(base + J(0x75f0), 0, 0x4d0);
    memset(base + J(0x7ac0), 0, 0x3b4);

    *(unsigned char*)(base + J(0x7e7e)) = 0xff;
    *(short*)(base + J(0x7e78)) = 0;
    *(short*)(base + J(0x7e7a)) = 0;
    *(short*)(base + J(0x7e7c)) = 0;
    *(int*)(base + J(0x7e74)) = 0x452;
    *(unsigned char*)(base + J(0x5cac)) = 0;
    gs->currentNumTicks_ = 0;

    for (int i = 0; i < 3; i++) {
        func_0200fad4((State0200fad4*)(base + J(0x7f8c) + i * 0xc));
        VectorizedMemset(base + J(0x74c0) + i * 0xa, 0, 6);
        *(signed char*)(base + i * 0xa + J(0x74c6)) = -1;
        *(unsigned char*)(base + i * 0xa + J(0x74c7)) = 0;
        *(unsigned char*)(base + i * 0xa + J(0x74c8)) = 0;
        *(signed char*)(base + i * 0xa + J(0x74c9)) = -1;
    }

    memset(base + J(0x7fb0), 0, 0x40);

    {
        Struct_0200f3a4_6* f = (Struct_0200f3a4_6*)(base + J(0x7ff0));
        f->bit0 = 0;
        f->unknown_0_1_ = 0;
        f->bit2 = 0;
        f->unknown_0_3_ = 0;
        f->unknown_0_4_ = 0;
    }
    *(unsigned char*)(base + J(0x7ff1)) = 0;
    *(unsigned char*)(base + J(0x7ff2)) = 0;
}
