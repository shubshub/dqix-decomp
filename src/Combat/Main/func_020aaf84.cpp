#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "std_library_functions.h"



struct Struct_020a94f8_2 {
    int unknown_0_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_[2];
    char unknown_8_[8];
    float unknown_10_;
};

struct Struct_02087574_2 {
    unsigned char unknown_0_[0x14];
};

struct Struct_020a9eb8_12 {
    unsigned short unknown_0_;
    short unknown_2_;
    Struct_02087574_2 unknown_4_[3];
};

struct Struct_020aaf84_7 {
    int unknown_0_;
    char unknown_4_[0x2ca8];
    char unknown_2cac_[0x344];
    char unknown_2ff0_[0xa0];
    char unknown_3090_[0x330];
    unsigned char unknown_33c0_[0x194];
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
    Struct_020a9eb8_12 unknown_6d4c_;
};

struct Struct_020aaf84 {
    char unknown_0_[0x28000];
    Struct_020aaf84_7 unknown_28000_;
};

struct Struct_020aaf84_2 {
    char unknown_0_[0x569c];
    char unknown_569c_[0x7c];
    char unknown_5718_[0x5cc8 - 0x5718];
    unsigned char unknown_5cc8_;
    char unknown_5cc9_[0x5e6c - 0x5cc9];
    char unknown_5e6c_[0x110];
    char unknown_5f7c_[0x71fc - 0x5f7c];
    char unknown_71fc_[0x2c4];
    char unknown_74c0_[0x44];
    char unknown_7504_[0xec];
    char unknown_75f0_[0x4d0];
    char unknown_7ac0_[0x3b4];
};

struct Struct_020aaf84_3 {
    char unknown_0_[0xf2c];
    Struct_02087574_2 unknown_f2c_[3];
};

struct Struct_020aaf84_4 {
    char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};

struct Struct_020aaf84_5 { char unknown_0_[0xa0]; char unknown_a0_[0xd8]; char unknown_178_[0x330]; };
struct Struct_02011544;
struct Struct_02038598_4;

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
int VerifyBuffer020a94f8(Buf020a94f8*, int);
void* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
void SetFlag0x5cccBit0_02011544(StateBits5ccc_11544*);
Globals020aaf84* GetGlobal02109418_02094d6c();
void* GetSlotEntry020108d8(char*, int);
void LoadBattleRegion0x5cdc_020a9af8(unsigned char*);
void CopyBlobIntoBattleStruct020a9ba4(void*);
void CopyBlobIntoBattleStruct020a9d78(void*);
void* GameState_GetParty(GameState*);
void ClearRegion020865ec(char*);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);

// USA: func_020aaf84
#if defined(jpn)
struct Struct_020aaf84_6 {
    char unknown_0_[0x543c];
    char unknown_543c_[0x7c];
    char unknown_54b8_[0x5a68 - 0x54b8];
    unsigned char unknown_5a68_;
    char unknown_5a69_[0x5c0c - 0x5a69];
    char unknown_5c0c_[0x110];
    char unknown_5d1c_[0x6fbc - 0x5d1c];
    char unknown_6fbc_[0x2c4];
    char unknown_7280_[0x44];
    char unknown_72c4_[0xec];
    char unknown_73b0_[0x4d0];
    char unknown_7880_[0x3b4];
};

extern "C" ARM int func_020aaf84(int* arg0, int arg1, int arg2, int arg3) {
    GameState* var0;
    Struct_020a94f8_2 var1;
    int var2;
    Struct_020aaf84_6* var3;
    Struct_020aaf84_4* var4;
    LightingManager* var5;
    Struct_020aaf84_5* var6;
    int var7;
    int var8;
    int var9;
    Struct_020aaf84_3* var10;
    Struct_020a9eb8_12* var11;
    Struct_020aaf84_7* var12;
    var0 = GameState::GetInstance();
    var3 = (Struct_020aaf84_6*)var0;
    var3->unknown_5a68_ = 0;
    var2 = 1;
    if (!func_020a94f8(&var1, arg2 != 0)) var2 = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    if (alternate) id = 0x8084;
    else id = 0x84;
    body = &((SaveScratch020aaf84*)g_fileLoadBuffer)->body;
    if (!func_02075910(id, body, 0x6f60, 0)) valid = 0;
    if (!strcmp(header.signature, data_020f1bf0) && valid) {
        if (func_01ff85b8(body->actorData, 0x6f5c) != body->checksum) {
            saveState->error = alternate ? 3 : 2;
            valid = 0;
        }
    }
    if (arg3) {
        BackgroundLoader::RemoveLockGlobal();
        return var2;
    }
    if (!var2) {
        func_02011544((Struct_02011544*)var0);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    context = Scenario_GetInstance();
    globals = GetGlobal02109418_02094d6c();
    func_020a95a4(body->actorData, GetSlotEntry020108d8((char*)state, 0));
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->globalData, 0xa0);
    memcpy(GetGlobal02109418_02094d6c()->extra, body->globalExtra, 0x330);
    LoadBattleRegion0x5cdc_020a9af8(body->region);
    memcpy(saveState->state75f0, body->state75f0, 0x4d0);
    memcpy(saveState->state7ac0, body->state7ac0, 0x3b4);
    memcpy(saveState->state7504, body->state7504, 0xec);
    func_020a9b2c(body->load3ec4);
    CopyBlobIntoBattleStruct020a9ba4(body->battle5a04);
    func_020a9c14(body->battle5e08);
    memcpy(((SaveStateJ020aaf84*)GameState::GetInstance())->state569c, body->state569c, 0x7c);
    if (alternate) {
        CopyBlobIntoBattleStruct020a9d78(body->extra695c);
        func_020a9e30(&body->entries);
    } else {
        entries = &body->entries;
        battle = (BattleEntries020aaf84*)GameState_GetParty(GameState::GetInstance());
        for (i = 0; i < 3; i++) {
            ClearRegion020865ec((char*)&battle->entries[i]);
        }
        if (var11->unknown_0_ && var11->unknown_2_) {
            for (var8 = 0; var8 < var11->unknown_2_; var8++) {
                memcpy(&var10->unknown_f2c_[var8], &var11->unknown_4_[var8], sizeof(Struct_02087574_2));
            }
        }
    }
    memcpy(((SaveStateJ020aaf84*)GameState::GetInstance())->state71fc, body->state71fc, 0x2c4);
    memcpy(((SaveStateJ020aaf84*)GameState::GetInstance())->state5e6c, body->state5e6c, 0x110);
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
extern "C" ARM int func_020aaf84(int* arg0, int arg1, int arg2, int arg3) {
    GameState* var13;
    Struct_020a94f8_2 var14;
    int var15;
    Struct_020aaf84_2* var16;
    unsigned int* var17;
    unsigned char var18;
    LightingManager* var19;
    Struct_020aaf84_5* var20;
    int var21;
    int var22;
    int var23;
    Struct_020aaf84_3* var24;
    Struct_020a9eb8_12* var25;
    Struct_020aaf84_4* var26;
    Struct_020aaf84_7* var27;
    var13 = GameState::GetInstance();
    var16 = (Struct_020aaf84_2*)var13;
    var16->unknown_5cc8_ = 0;
    var15 = 1;
    if (!func_020a94f8(&var14, arg2 != 0)) var15 = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    flags = (unsigned int*)GlobalFlags_GetInstance();
    FlagWord_SetBits(flags, 0x2000000);
    if (alternate) id = 0x8084;
    else id = 0x84;
    body = &((SaveScratch020aaf84*)g_fileLoadBuffer)->body;
    if (!func_02075910(id, body, 0x6f60, 0)) valid = 0;
    if (!strcmp(header.signature, data_020f1bf0) && valid) {
        if (func_01ff85b8(body->actorData, 0x6f5c) != body->checksum) {
            saveState->error = alternate ? 3 : 2;
            valid = 0;
        }
    }
    if (quiet) {
        FlagWord_ClearBits((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return var15;
    }
    if (!valid) {
        SetFlag0x5cccBit0_02011544((StateBits5ccc_11544*)state);
        FlagWord_ClearBits((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    context = Scenario_GetInstance();
    globals = GetGlobal02109418_02094d6c();
    status = 0;
    func_020a95a4(body->actorData, GetSlotEntry020108d8((char*)state, 0), &status);
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->globalData, 0xa0);
    memcpy(GetGlobal02109418_02094d6c()->extra, body->globalExtra, 0x330);
    LoadBattleRegion0x5cdc_020a9af8(body->region);
    memcpy(saveState->state75f0, body->state75f0, 0x4d0);
    memcpy(saveState->state7ac0, body->state7ac0, 0x3b4);
    memcpy(saveState->state7504, body->state7504, 0xec);
    func_020a9b2c(body->load3ec4);
    CopyBlobIntoBattleStruct020a9ba4(body->battle5a04);
    func_020a9c14(body->battle5e08);
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state569c, body->state569c, 0x7c);
    if (alternate) {
        CopyBlobIntoBattleStruct020a9d78(body->extra695c);
        func_020a9e30(&body->entries);
    } else if (status) {
        entries = &body->entries;
        battle = (BattleEntries020aaf84*)GameState_GetParty(GameState::GetInstance());
        for (i = 0; i < 3; i++) {
            ClearRegion020865ec((char*)&battle->entries[i]);
        }
        if (var25->unknown_0_ && var25->unknown_2_) {
            for (var22 = 0; var22 < var25->unknown_2_; var22++) {
                memcpy(&var24->unknown_f2c_[var22], &var25->unknown_4_[var22], sizeof(Struct_02087574_2));
            }
        }
    }
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state71fc, body->state71fc, 0x2c4);
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state5e6c, body->state5e6c, 0x110);
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
