#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/SearchEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"


struct Struct_0202c1a4;
struct Struct_02033834;
struct Struct_02053f7c_3;
struct Struct_02083508_2 { char unknown_0_[0x20]; };

extern "C" void* func_0202ae18(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_0202c288(void*);
extern "C" void func_02039880(unsigned char*, int);
extern "C" int func_0202c1c0(Struct_0202b2f0* arg0, int arg1);
extern "C" signed char func_0202c1a4(Struct_0202c1a4* arg0);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
signed char GetSignedByte0x1ca_02039888(void*);
void SetVecYFromValue02033874(Obj02033874*, int);
void SetByte0x5cdaAndClearField0xa_020120d4(unsigned char*, unsigned char);
void* GetField0x74deForValidIndex_020120a0(char* p, unsigned int index);
void SetWord0x71f8_0201206c(void*, int);
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c*, unsigned short, int);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206dfe8(void*, int, int);
void CopyRegionsAndClearField0206e70c(char*);
void ApplySlotBytesToBattleStruct_0206df14(unsigned char*);
float GetActiveBitIndex_020103e8(GameState*);
void InitFieldsFromCombatant_0219bcac(unsigned char);
unsigned char* GetField0x3f8Address_0200fd0c(GameState*);
void* GetGlobal02109418_02094d6c();
void* CallFunc0205ec34_020965f8();
void* ItemTable_Construct(void*);
void ItemTable_Init(void*);
void ItemRecord_Clear(StructDE1D4*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
#if defined(jpn)
extern "C" void* func_020e08f0(int arg0, unsigned int* arg1);
#endif
extern "C" int func_020def44(int, int, int, short);
extern "C" void func_0207cbe8(char*);
extern "C" void func_0207cc18(void*, void*);
void* GameState_GetParty(GameState*);
struct KeyMap020a095c;
void AddKeyValueClamped020a095c(KeyMap020a095c*, int, int);
void InitAndAppendEntry020dbc5c(char*, int);
int GameState_GetLeaderIndex(GameState*);
void EnqueueEventTag20_021cee78(int, unsigned char);
extern "C" void func_ov017_02191234(GameResources*);

extern const char* data_020f2a18;
extern const char* data_020f2a0c;

struct Struct_ov017_021b0bc0 {
    char unknown_0_[0x1b34];
    int unknown_1b34_;
    int unknown_1b38_;
    int unknown_1b3c_;
    char unknown_1b40_[0x1b48 - 0x1b40];
    int unknown_1b48_;
    char unknown_1b4c_[0x1b61 - 0x1b4c];
    unsigned char unknown_1b61_;
#if defined(jpn)
    char unknown_1b62_[0x1f94 - 0x1b62];
#else
    char unknown1_1b62_[0x1f74 - 0x1b62];
#endif
    unsigned short unknown_1f74_;
    unsigned short unknown_1f76_;
};

struct Struct_ov017_021b0bc0_2 {
#if defined(jpn)
    char unknown_0_[0x860];
#else
    char unknown1_0_[0x840];
#endif
    Struct_ov017_021b0bc0 unknown_840_;
};

static inline Struct_ov017_021b0bc0* inline_ov017_021b0bc0(Struct_ov017_021b0bc0_2* arg0) {
    return &arg0->unknown_840_;
}

static inline void inline_ov017_021b0bc0_2(Struct_ov017_021b0bc0* arg0, int arg1) { arg0->unknown_1b34_ = arg1; }
static inline void inline_ov017_021b0bc0_3(Struct_ov017_021b0bc0* arg0, int arg1) { arg0->unknown_1b38_ = arg1; }
static inline void inline_ov017_021b0bc0_4(Struct_ov017_021b0bc0* arg0, int arg1) { arg0->unknown_1b3c_ = arg1; }
static inline void inline_ov017_021b0bc0_5(Struct_ov017_021b0bc0* arg0, int arg1) { arg0->unknown_1b48_ = arg1; }
static inline void inline_ov017_021b0bc0_6(Struct_ov017_021b0bc0* arg0, unsigned char arg1) { arg0->unknown_1b61_ = arg1; }

struct Struct_ov017_021b0bc0_3 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    char unknown_4_[0x190];
    char unknown_194_[0x110];
    char unknown_2a4_[0x20];
    int unknown_2c4_;
    int unknown_2c8_;
    int unknown_2cc_;
    unsigned short unknown_2d0_;
    unsigned short unknown_2d2_;
    unsigned char unknown_2d4_;
    unsigned char unknown_2d5_;
    unsigned short unknown_2d6_[4];
};

struct Struct_ov017_021b0bc0_4 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[2];
    signed char* unknown_4_;
    char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_[2];
    unsigned char unknown_c_;
#if defined(jpn)
    char unknown_d_[0x214 - 0xd];
#else
    char unknown1_d_[0x284 - 0xd];
#endif
    unsigned char unknown_284_;
    char unknown_285_[3];
    Struct_ov017_021b0bc0_3* unknown_288_;
};

struct Struct_ov017_021b0bc0_5 {
    SafeAllocator unknown_0_;
    char unknown_14_[0x18];
    void* unknown_2c_;
    int unknown_30_;
    int unknown_34_;
};

// USA: func_ov017_021b0bc0
// JPN: func_ov017_021b1258
extern "C" ARM void func_ov017_021b0bc0(Struct_ov017_021b0bc0_4* arg0) {
    char var0[0x18];
    Struct_02083508_2 var1;
    Struct_ov017_021b0bc0_5 var2;
    short var3[4];
    unsigned int var4;

    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    SearchStruct* search = (SearchStruct*)func_0202ae18();
    Zone021b0bc0* zone = (Zone021b0bc0*)Zone3D_GetInstance();
#if defined(jpn)
    Struct_ov017_021b0bc0* var9 = inline_ov017_021b0bc0(var8);
#endif
    func_0202c288(var7);

    int var10 = 1;
    if (arg0->unknown_4_ != NULL && *arg0->unknown_4_ == 10) {
        var10 = 0;
    }
    GameObject* leader = gs->GetPartyMemberByIndex(self->leader);
    if (leader != NULL) {
        SetByte0x1ca_02039880((unsigned char*)leader, leader->obj3D_.actorIndex_);
    }
    short* var12 = var3;
    for (int var13 = 0; var13 < 4; var13++, var12++) {
        GameObject* var14 = var5->GetPartyMemberByIndex(var13);
        if (var14 != NULL) {
            *var12 = *(short*)((char*)var14 + 0xae);
        }
    }

    for (int var15 = 0; var15 < 4; var15++) {
        if (func_0202c1c0(var7, var15) == 0) {
            continue;
        }
        if (var15 == func_0202c1a4((Struct_0202c1a4*)var7)) {
            if (arg0->unknown_284_ == 0) {
                var10 = 0;
            }
            func_ov017_02191108(var6, 1, var10, 1, 1);
        } else {
            func_ov017_021907dc((int)var6, var15, 1, var10, 1);
        }
    }

    if (arg0->unknown_9_ == 2) {
        var12 = var3;
        for (int var16 = 0; var16 < 4; var16++, var12++) {
            GameObject* var17 = var5->GetPartyMemberByIndex(var16);
            if (var17 == NULL) {
                continue;
            }
            if (var16 == func_02039888(var17)) {
                continue;
            }
            if (var16 != 0 && !(var17->obj3D_.unknown_0_ & 0x1000)) {
                continue;
            }
            func_02033874((Struct_02033834*)var17, *var12);
        }
        ClearFlags00(var6, 0x40);

        Struct_ov017_021b0bc0_3* var18 = arg0->unknown_288_;
        func_020120d4((unsigned char*)var5, var18->unknown_0_);
#if defined(jpn)
        memcpy((char*)var5 + 0x5a7c, var18->unknown_4_, sizeof(var18->unknown_4_));
        memcpy((char*)var5 + 0x5c0c, var18->unknown_194_, sizeof(var18->unknown_194_));
#else
        memcpy((char*)var5 + 0x5cdc, var18->unknown_4_, sizeof(var18->unknown_4_));
        memcpy((char*)var5 + 0x5e6c, var18->unknown_194_, sizeof(var18->unknown_194_));
#endif
        memcpy(func_020120a0((char*)var5, 0), var18->unknown_2a4_, sizeof(var18->unknown_2a4_));
        func_0201206c(var5, var18->unknown_2c4_);
#if defined(jpn)
        inline_ov017_021b0bc0_2(var9, var18->unknown_2c8_);
        inline_ov017_021b0bc0_5(var9, var18->unknown_2cc_);
        inline_ov017_021b0bc0_3(var9, var18->unknown_2d0_);
        inline_ov017_021b0bc0_4(var9, (unsigned char)var18->unknown_2d2_);
        inline_ov017_021b0bc0_6(var9, 0);
#else
        inline_ov017_021b0bc0_2(inline_ov017_021b0bc0(var8), var18->unknown_2c8_);
        inline_ov017_021b0bc0_5(inline_ov017_021b0bc0(var8), var18->unknown_2cc_);
        inline_ov017_021b0bc0_3(inline_ov017_021b0bc0(var8), var18->unknown_2d0_);
        inline_ov017_021b0bc0_4(inline_ov017_021b0bc0(var8), (unsigned char)var18->unknown_2d2_);
        inline_ov017_021b0bc0_6(inline_ov017_021b0bc0(var8), 0);
#endif
        var8->unknown_840_.unknown_1f74_ = var18->unknown_2d4_;
        var8->unknown_840_.unknown_1f76_ = var18->unknown_2d5_;
        for (int var19 = 0; var19 < 4; var19++) {
            GameObject* var20 = var5->GetPartyMemberByIndex(var19);
            if (var20 != NULL) {
                func_02053f7c((Struct_02053f7c_3*)var20, var18->unknown_2d6_[var19], 1);
            }
        }

        void* save = Scenario_GetInstance();
        func_0206dfe8(save, 0x38e, 0x3e8);
        func_0206dfe8(save, 0x79e, 0x2bc);
        CopyRegionsAndClearField0206e70c((char*)save);
        ApplySlotBytesToBattleStruct_0206df14((unsigned char*)save);
        gs->SetDayTimer(GetActiveBitIndex_020103e8(gs));
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = gs->GetDayTimer();
        lighting->timeOfDayIndex_ = gs->GetTimeOfDay();
        InitFieldsFromCombatant_0219bcac(1);
        GetField0x3f8Address_0200fd0c(gs)[0xa] = 0;
        GetGlobal02109418_02094d6c();
        CallFunc0205ec34_020965f8();

        ItemTable_Construct(list);
        ItemTable_Init(list);
        ItemRecord_Clear(&entry);
        BackgroundLoader::AddLockGlobal();
#if defined(jpn)
        void* var23 = func_020e08f0(8, &var4);
#else
        void* var23 = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &var4);
#endif
        if (var23 != NULL) {
            func_020def44((int)&var1, (int)var23, var4, 0x5612);
        }
        BackgroundLoader::RemoveLockGlobal();
        context.allocator.ResetAllocatorPointer();
        ItemTable_Construct(context.list);
        InitStruct0207cbe8((char*)&context);
        InitStruct0207cbe8((char*)&context);
        func_0207cc18(&context, &entry);
        AddKeyValueClamped020a095c((KeyMap020a095c*)GameState_GetParty(gs), 0x5612, 1);
    } else if (self->mode == 0) {
        InitAndAppendEntry020dbc5c((char*)res, self->leader);
        unsigned char* slots = (unsigned char*)GameState_GetParty(gs) + 0xf78;
        for (int i = 0; i < 4; i++, slots++) {
            unsigned char id = *slots;
            if (id != GameState_GetLeaderIndex(gs)) {
                EnqueueEventTag20_021cee78(id, 0);
            }
        }
    }

    func_ov017_02191234(var6);
    arg0->unknown_1_ = 1;
}
