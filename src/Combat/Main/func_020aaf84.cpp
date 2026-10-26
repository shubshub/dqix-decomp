#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "std_library_functions.h"



struct Struct_020a94f8_2 {
    int unknown_0_;
    unsigned char resumed;
    unsigned char unknown_5_;
    unsigned char unknown_6_[2];
    char signature[8];
    float dayTimer;
};

struct Struct_02087574_2 {
    unsigned char data[0x14];
};

struct Struct_020a9eb8_12 {
    unsigned short unknown_0_;
    short count;
    Struct_02087574_2 entries[3];
};

struct Struct_020aaf84_7 {
    int unknown_0_;
    char unknown_4_[0x2ca8];
    char context[0x344];
    char unknown_2ff0_[0xa0];
    char unknown_3090_[0x330];
    unsigned char region[0x194];
    char unknown_3554_[0x4d0];
    char unknown_3a24_[0x3b4];
    char unknown_3dd8_[0xec];
    char unknown_3ec4_[0x1b40];
    char unknown_5a04_[0x404];
    char unknown_5e08_[0xad8];
    char unknown_68e0_[0x7c];
    char unknown_695c_[0x1c];
    char unknown_6978_[0x2c4];
    char unknown_6c3c_[0x110];
    Struct_020a9eb8_12 entries;
};

struct SaveScratch020aaf84 {
    char unknown_0_[0x28000];
    Struct_020aaf84_7 body;
};

struct Struct_020aaf84_2 {
    char unknown_0_[0x569c];
    char unknown_569c_[0x7c];
    char unknown_5718_[0x5cc8 - 0x5718];
    unsigned char error;
    char unknown_5cc9_[0x5e6c - 0x5cc9];
    char unknown_5e6c_[0x110];
    char unknown_5f7c_[0x71fc - 0x5f7c];
    char unknown_71fc_[0x2c4];
    char unknown_74c0_[0x44];
    char unknown_7504_[0xec];
    char unknown_75f0_[0x4d0];
    char unknown_7ac0_[0x3b4];
};

struct BattleEntries020aaf84 {
    char unknown_0_[0xf2c];
    Struct_02087574_2 entries[3];
};

struct Context020aaf84 {
    char unknown_0_[0x8c];
    unsigned char bits[1];
};

struct Struct_020aaf84_5 { char data[0xa0]; char unknown_a0_[0xd8]; char extra[0x330]; };
struct Struct_02011544;
struct FlagWord020466f4;

extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern const char data_020f1bf0[];
extern "C" int func_02075910(int, void*, unsigned int, int);
extern "C" int func_01ff85b8(void*, int);
extern "C" Context020aaf84* Scenario_GetInstance();
#if defined(jpn)
extern "C" int func_020a95a4(void*, void*);
#else
extern "C" int func_020a95a4(void*, void*, unsigned char*);
#endif
extern "C" int func_020a9a50(void*, void*, int);
extern "C" void func_020a9b2c(void*);
extern "C" void func_020a9c14(void*);
extern "C" void func_020a9e30(void*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" int func_020a94f8(Struct_020a94f8_2*, int);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void func_02011544(Struct_02011544*);
extern "C" Struct_020aaf84_5* func_02094d6c();
extern "C" void* func_020108d8(char*, int);
extern "C" void func_020a9af8(unsigned char*);
extern "C" void func_020a9ba4(void*);
extern "C" void func_020a9d78(void*);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_020865ec(char*);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);

// USA: func_020aaf84
#if defined(jpn)
struct Struct_020aaf84_6 {
    char unknown_0_[0x543c];
    char unknown_543c_[0x7c];
    char unknown_54b8_[0x5a68 - 0x54b8];
    unsigned char error;
    char unknown_5a69_[0x5c0c - 0x5a69];
    char unknown_5c0c_[0x110];
    char unknown_5d1c_[0x6fbc - 0x5d1c];
    char unknown_6fbc_[0x2c4];
    char unknown_7280_[0x44];
    char unknown_72c4_[0xec];
    char unknown_73b0_[0x4d0];
    char unknown_7880_[0x3b4];
};

extern "C" ARM int func_020aaf84(int* output, int unused, int alternate, int arg3) {
    GameState* state;
    Struct_020a94f8_2 header;
    int var2;
    Struct_020aaf84_6* var3;
    Context020aaf84* context;
    LightingManager* lighting;
    Struct_020aaf84_5* globals;
    int id;
    int j;
    int i;
    BattleEntries020aaf84* battle;
    Struct_020a9eb8_12* entries;
    Struct_020aaf84_7* body;
    state = GameState::GetInstance();
    var3 = (Struct_020aaf84_6*)state;
    var3->error = 0;
    var2 = 1;
    if (!func_020a94f8(&header, alternate != 0)) var2 = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    if (alternate) id = 0x8084;
    else id = 0x84;
    body = &((SaveScratch020aaf84*)g_fileLoadBuffer)->body;
    if (!func_02075910(id, body, 0x6f60, 0)) var2 = 0;
    if (!strcmp(header.signature, data_020f1bf0) && var2) {
        if (func_01ff85b8(body->unknown_4_, 0x6f5c) != body->unknown_0_) {
            var3->error = alternate ? 3 : 2;
            var2 = 0;
        }
    }
    if (arg3) {
        BackgroundLoader::RemoveLockGlobal();
        return var2;
    }
    if (!var2) {
        func_02011544((Struct_02011544*)state);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    context = Scenario_GetInstance();
    globals = func_02094d6c();
    func_020a95a4(body->unknown_4_, func_020108d8((char*)state, 0));
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->unknown_2ff0_, 0xa0);
    memcpy(func_02094d6c()->extra, body->unknown_3090_, 0x330);
    func_020a9af8(body->region);
    memcpy(var3->unknown_73b0_, body->unknown_3554_, 0x4d0);
    memcpy(var3->unknown_7880_, body->unknown_3a24_, 0x3b4);
    memcpy(var3->unknown_72c4_, body->unknown_3dd8_, 0xec);
    func_020a9b2c(body->unknown_3ec4_);
    func_020a9ba4(body->unknown_5a04_);
    func_020a9c14(body->unknown_5e08_);
    memcpy(((Struct_020aaf84_6*)GameState::GetInstance())->unknown_543c_, body->unknown_68e0_, 0x7c);
    if (alternate) {
        func_020a9d78(body->unknown_695c_);
        func_020a9e30(&body->entries);
    } else {
        entries = &body->entries;
        battle = (BattleEntries020aaf84*)GameState_GetParty(GameState::GetInstance());
        for (i = 0; i < 3; i++) {
            func_020865ec((char*)&battle->entries[i]);
        }
        if (entries->unknown_0_ && entries->count) {
            for (j = 0; j < entries->count; j++) {
                memcpy(&battle->entries[j], &entries->entries[j], sizeof(Struct_02087574_2));
            }
        }
    }
    memcpy(((Struct_020aaf84_6*)GameState::GetInstance())->unknown_6fbc_, body->unknown_6978_, 0x2c4);
    memcpy(((Struct_020aaf84_6*)GameState::GetInstance())->unknown_5c0c_, body->unknown_6c3c_, 0x110);
    lighting = LightingManager::GetInstance();
    state->SetDayTimer(header.dayTimer);
    lighting->dayNightTimer_ = header.dayTimer;
    lighting->timeOfDayIndex_ = state->GetTimeOfDay();
    lighting->SetZone(Zone3D_GetInstance());
    lighting->RecomputeAdvancedLighting();
    Scenario_SetFlag(context, context->bits, 3, 0);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
#else
extern "C" ARM int func_020aaf84(int* output, int unused, int alternate, int arg3) {
    GameState* state;
    Struct_020a94f8_2 header;
    int var15;
    Struct_020aaf84_2* var16;
    unsigned int* flags;
    unsigned char status;
    LightingManager* lighting;
    Struct_020aaf84_5* globals;
    int id;
    int j;
    int i;
    BattleEntries020aaf84* battle;
    Struct_020a9eb8_12* entries;
    Context020aaf84* context;
    Struct_020aaf84_7* body;
    state = GameState::GetInstance();
    var16 = (Struct_020aaf84_2*)state;
    var16->error = 0;
    var15 = 1;
    if (!func_020a94f8(&header, alternate != 0)) var15 = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    flags = (unsigned int*)GlobalFlags_GetInstance();
    FlagWord_SetBits(flags, 0x2000000);
    if (alternate) id = 0x8084;
    else id = 0x84;
    body = &((SaveScratch020aaf84*)g_fileLoadBuffer)->body;
    if (!func_02075910(id, body, 0x6f60, 0)) var15 = 0;
    if (!strcmp(header.signature, data_020f1bf0) && var15) {
        if (func_01ff85b8(body->unknown_4_, 0x6f5c) != body->unknown_0_) {
            var16->error = alternate ? 3 : 2;
            var15 = 0;
        }
    }
    if (arg3) {
        FlagWord_ClearBits((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return var15;
    }
    if (!var15) {
        func_02011544((Struct_02011544*)state);
        FlagWord_ClearBits((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    context = Scenario_GetInstance();
    globals = func_02094d6c();
    status = 0;
    func_020a95a4(body->unknown_4_, func_020108d8((char*)state, 0), &status);
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->unknown_2ff0_, 0xa0);
    memcpy(func_02094d6c()->extra, body->unknown_3090_, 0x330);
    func_020a9af8(body->region);
    memcpy(var16->unknown_75f0_, body->unknown_3554_, 0x4d0);
    memcpy(var16->unknown_7ac0_, body->unknown_3a24_, 0x3b4);
    memcpy(var16->unknown_7504_, body->unknown_3dd8_, 0xec);
    func_020a9b2c(body->unknown_3ec4_);
    func_020a9ba4(body->unknown_5a04_);
    func_020a9c14(body->unknown_5e08_);
    memcpy(((Struct_020aaf84_2*)GameState::GetInstance())->unknown_569c_, body->unknown_68e0_, 0x7c);
    if (alternate) {
        func_020a9d78(body->unknown_695c_);
        func_020a9e30(&body->entries);
    } else if (status) {
        entries = &body->entries;
        battle = (BattleEntries020aaf84*)GameState_GetParty(GameState::GetInstance());
        for (i = 0; i < 3; i++) {
            func_020865ec((char*)&battle->entries[i]);
        }
        if (entries->unknown_0_ && entries->count) {
            for (j = 0; j < entries->count; j++) {
                memcpy(&battle->entries[j], &entries->entries[j], sizeof(Struct_02087574_2));
            }
        }
    }
    memcpy(((Struct_020aaf84_2*)GameState::GetInstance())->unknown_71fc_, body->unknown_6978_, 0x2c4);
    memcpy(((Struct_020aaf84_2*)GameState::GetInstance())->unknown_5e6c_, body->unknown_6c3c_, 0x110);
    lighting = LightingManager::GetInstance();
    state->SetDayTimer(header.dayTimer);
    lighting->dayNightTimer_ = header.dayTimer;
    lighting->timeOfDayIndex_ = state->GetTimeOfDay();
    lighting->SetZone(Zone3D_GetInstance());
    lighting->RecomputeAdvancedLighting();
    Scenario_SetFlag(context, context->bits, 3, 0);
    FlagWord_ClearBits((FlagWord020466f4*)flags, 0x2000000);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
#endif
