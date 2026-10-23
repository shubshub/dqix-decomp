#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/SearchEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0202c1a4;
struct Struct_02033834;
struct Struct_02053f7c_3;
struct Struct_02083508_2 { char unknown_0_[0x20]; };

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" void func_0202c288(void*);
extern "C" void func_02039880(unsigned char*, int);
extern "C" int func_0202c1c0(Struct_0202b2f0* arg0, int arg1);
extern "C" signed char func_0202c1a4(Struct_0202c1a4* arg0);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" signed char func_02039888(void*);
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" void func_020120d4(unsigned char*, unsigned char);
extern "C" void* func_020120a0(char* arg0, unsigned int arg1);
extern "C" void func_0201206c(void*, int);
extern "C" void func_02053f7c(Struct_02053f7c_3*, unsigned short, int);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206dfe8(void*, int, int);
void CopyRegionsAndClearField0206e70c(char*);
void ApplySlotBytesToBattleStruct_0206df14(unsigned char*);
float GetActiveBitIndex_020103e8(GameState*);
void InitFieldsFromCombatant_0219bcac(unsigned char);
unsigned char* GetField0x3f8Address_0200fd0c(GameState*);
void* GetGlobal02109418_02094d6c();
void* CallFunc0205ec34_020965f8();
void* ZeroInitReturn020de824(void*);
void ItemTable_Init(void*);
void InitStruct020de1d4(StructDE1D4*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
#if defined(jpn)
extern "C" void* func_020e08f0(int arg0, unsigned int* arg1);
#endif
extern "C" int func_020def44(int, int, int, short);
extern "C" void func_0207cbe8(char*);
extern "C" void func_0207cc18(void*, void*);
extern "C" void* func_02010828(GameState*);
struct Struct_0207cf30_4;
extern "C" void func_020a095c(Struct_0207cf30_4*, int, int);
extern "C" void func_020dbc5c(char*, int);
extern "C" int func_020100b0(GameState*);
extern "C" void func_ov017_021cee78(int, unsigned char);
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

    GameState* var5 = GameState::GetInstance();
    GameResources* var6 = GetGameResources();
    Struct_0202b2f0* var7 = (Struct_0202b2f0*)func_0202ae18();
    Struct_ov017_021b0bc0_2* var8 = (Struct_ov017_021b0bc0_2*)func_02012fe4();
#if defined(jpn)
    Struct_ov017_021b0bc0* var9 = inline_ov017_021b0bc0(var8);
#endif
    func_0202c288(var7);

    int var10 = 1;
    if (arg0->unknown_4_ != NULL && *arg0->unknown_4_ == 10) {
        var10 = 0;
    }
    GameObject* var11 = var5->GetPartyMemberByIndex(arg0->unknown_c_);
    if (var11 != NULL) {
        func_02039880((unsigned char*)var11, var11->obj3D_.unknown_4_);
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

        void* var21 = func_0205ec34();
        func_0206dfe8(var21, 0x38e, 0x3e8);
        func_0206dfe8(var21, 0x79e, 0x2bc);
        func_0206e70c((char*)var21);
        func_0206df14((unsigned char*)var21);
        var5->SetDayTimer(func_020103e8(var5));
        LightingManager* var22 = LightingManager::GetInstance();
        var22->dayNightTimer_ = var5->GetDayTimer();
        var22->timeOfDayIndex_ = var5->GetTimeOfDay();
        func_ov017_0219bcac(1);
        func_0200fd0c(var5)[0xa] = 0;
        func_02094d6c();
        func_020965f8();

        ZeroInitReturn020de824(list);
        ItemTable_Init(list);
        InitStruct020de1d4(&entry);
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
        var2.unknown_0_.ResetAllocatorPointer();
        func_020de824(var2.unknown_14_);
        func_0207cbe8((char*)&var2);
        func_0207cbe8((char*)&var2);
        func_0207cc18(&var2, &var1);
        func_020a095c((Struct_0207cf30_4*)func_02010828(var5), 0x5612, 1);
    } else if (arg0->unknown_9_ == 0) {
        func_020dbc5c((char*)var6, arg0->unknown_c_);
        unsigned char* var24 = (unsigned char*)func_02010828(var5) + 0xf78;
        for (int var25 = 0; var25 < 4; var25++, var24++) {
            unsigned char var26 = *var24;
            if (var26 != func_020100b0(var5)) {
                func_ov017_021cee78(var26, 0);
            }
        }
    }

    func_ov017_02191234(var6);
    arg0->unknown_1_ = 1;
}
