#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"


struct Struct_ov017_021c37a4_6 {
    char unknown_0_[0x100d];
    unsigned char unknown_100d_;
    char unknown_100e_[0x1029 - 0x100e];
    unsigned char unknown_1029_;
};

struct Struct_ov017_021c37a4_7 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};

struct Struct_ov017_021c37a4_8 {
    char unknown_0_[0x130];
    Struct_ov017_021c37a4_7* unknown_130_;
    char* unknown_134_;
#if defined(jpn)
    char unknown_138_[0x180 - 0x138];
#else
    char unknown1_138_[0x18c - 0x138];
#endif
    unsigned int unknown_18c_;
};

struct Struct_ov017_021c37a4_9 {
    unsigned char unknown_0_[6];
    signed char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
};

struct Struct_ov017_021c37a4_10 {
#if defined(jpn)
    char unknown_0_[0x5a6c];
#else
    char unknown1_0_[0x5ccc];
#endif
    unsigned int unknown_5ccc_;
#if defined(jpn)
    char unknown_5a70_[0x7280 - 0x5a70];
#else
    char unknown_5cd0_[0x74c0 - 0x5cd0];
#endif
    Struct_ov017_021c37a4_9 unknown_74c0_[3];
    char unknown_74de_[0x7e74 - 0x74de];
    int unknown_7e74_;
};

struct Struct_ov017_021c37a4 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0x2c94 - 0xf7d];
    int unknown_2c94_;
};

struct Struct_ov017_021c37a4_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
};

struct Struct_ov017_021c37a4_3 {
#if defined(jpn)
    char unknown_0_[0x1b64];
#else
    char unknown1_0_[0x64];
#endif
    unsigned short unknown_64_;
};

struct Struct_ov017_021c37a4_4 {
#if defined(jpn)
    char unknown_0_[0x860];
#else
    char unknown1_0_[0x2340];
#endif
    Struct_ov017_021c37a4_3 unknown_2340_;
#if defined(jpn)
    char unknown_23c6_[0x2860 - 0x23c6];
#else
    char unknown_23a6_[0x2820 - 0x23a6];
#endif
    unsigned char unknown_2820_;
    Struct_ov017_021c37a4_3* inline_ov017_021c37a4() { return &unknown_2340_; }};

struct Struct_02109bf4_11 {
    char unknown_0_[0xc8];
    unsigned char unknown_c8_;
};

struct Struct_ov017_021c37a4_5 {
#if defined(jpn)
    char unknown_0_[0x1790];
#else
    char unknown1_0_[0x1962];
#endif
    unsigned char unknown_1962_;
};

struct Struct_02039d84;
struct Struct_0205faf4_13;
struct Struct_0206e2a0;
struct Struct_02061c04_7;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_020e3004;
struct Struct_020e358c;
struct Struct_020e3814;
struct Struct_02109bf4_4;
struct Struct_02109bf4_3;
struct Struct_02038598_4;

extern "C" void* func_0202ae18(void);
void* GetData02100044_0202ae24(void);
void* GetData02153637_020e2ff8(void);
void* GetData02153634_020e3580(void);
void* GetData02153660_020e3808(void);
void* GlobalFlags_GetInstance(void);
extern "C" int func_0202c540(void* obj);
int GetFieldAt0x0_0202ba00(int* obj);
void UpdatePlayClocks020ac4f8(int arg);
extern "C" void __clear(void* buf, int len);
void Clear0x20BytesAt0x74de_02012084(unsigned char* obj);
void ClearFieldKeepBit0x10_02011af0(void* obj);
extern "C" void func_02046a8c(void* a, void* b);
void BlankFunction020d84e0(void);
extern "C" void func_0202b0f4(void* obj);
extern "C" void func_0205e22c(void* obj);
unsigned char GameState_GetProtagonistIndex(GameState* gs);
int GetByte0x26c_02039d7c(char* obj);
void ResetObjectState02039d84(Obj02039d84* obj);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int idx);
int GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_ov017_02190264(void* obj, int idx);
extern "C" void func_ov017_021c32b0(Swap021c37a4* swap, int count);
extern "C" void func_0202c288(void* obj);
void SetField0x3acValue_020100a0(GameState* gs, int value);
extern "C" void func_020dcd40(void);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_ov017_02191108(void* obj, int a, int b, int c, int d);
void SetField0x2d0_020546a0(void* obj, int value);
void SetByte0x1c8_02039858(unsigned char* obj, int value);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
void* GetFieldIfFlag4_020100f8(char* obj);
void SetField0x21c_020a2770(void* obj, short value);
extern "C" void* Scenario_GetInstance(void);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc* arr, int idx);
extern "C" void func_020abd20(int arg);
void SetPackedNibbleFlag0x8(PackedNibbleArray0206e2a0* arr, int idx);
void Init020d9ae8(Struct020d9ae8* obj, int arg);
void CopyStringInto020d9dc4(char* dst, char* src);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void DecrementKeyEverywhere02086d88(unsigned char* obj, int key);
void ClearByteField17201_0218d500(void* obj);
void ClearAllTreasureMapUnknownBits_020116c8(void* obj);
extern "C" void func_02048150(void* obj, int a, int b);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);
extern "C" void VectorizedMemset(void* dst, int value, int len);
char* GetGlobal02109030_020936f8(void);
void ResetEightRegionsAndFlags_02093a14(char* obj);
extern "C" Field021c37a4* Zone3D_GetInstance(void);
void ClearTwoBytesAtField_02195748(unsigned char* obj);
void ApplyVecFromField0x246_020a2718(char* obj);
void InitSlotTable020e3004(SlotTable020e3004* p);
void ClearThreeBytes020e358c(Bytes020e358c* p);
void ResetEntryArray020e3814(Entry020e3840* p);
int GetField0xcd0209c3ac(char* obj);
extern "C" void func_0209c2e0(void* obj, int a, int b);
void BgmPlayer_FadeOut(Actor0209c678* obj, int state);
extern "C" void func_020bbd9c(void);
int IsHandleB8Active0209c6bc(void* obj);
void InitActorContext0209c20c(Actor0209c20c* obj);
void FlagWord_ClearBits(FlagWord020466f4* obj, unsigned int flags);
Global021c37a4* MessageSystem_GetInstance(void);

extern Actor021c37a4 g_bgmPlayer;

// USA: func_ov017_021c37a4
extern "C" ARM void func_ov017_021c37a4(void) {
    GameState* gs = GameState::GetInstance();
    Battle021c37a4* battle = (Battle021c37a4*)gs;
    SearchState021c37a4* search = (SearchState021c37a4*)func_0202ae18();
    GameResources* res = GetGameResources();
    void* d100044 = GetData02100044_0202ae24();
    void* d153637 = GetData02153637_020e2ff8();
    void* d153634 = GetData02153634_020e3580();
    void* d153660 = GetData02153660_020e3808();
    void* d114e04 = GlobalFlags_GetInstance();
    int active = func_0202c540(search);
    int state = GetFieldAt0x0_0202ba00((int*)search);
    int mode = search->mode;
#if defined(jpn)
    char var12[0xb];
#else
    char var12[0x30];
#endif
    unsigned char var13[0x1a];
    Struct_ov017_021c37a4_2 var14;
    Struct_ov017_021c37a4_2 var15;

    if ((var10 == 5 && var11 > 1) || var10 == 6) {
        func_020ac4f8(1);
    }

#if !defined(jpn)
    __clear(var12, 0x30);
#endif
    if (var9) {
#if defined(jpn)
        Struct_ov017_021c37a4_8* var16 = (Struct_ov017_021c37a4_8*)var0->GetPartyMemberByIndex(0);
        memset(var12, 0, sizeof(var12));
        char* var17 = var16->unknown_134_;
#else
        char* var17 = ((Struct_ov017_021c37a4_8*)var0->GetPartyMemberByIndex(0))->unknown_134_;
#endif
        memcpy(name, src, strlen(src));
        Clear0x20BytesAt0x74de_02012084((unsigned char*)gs);
        ClearFieldKeepBit0x10_02011af0(gs);
        func_02046a8c(res->fieldTaskQueue_, res->fieldTasks_[0x14]);
    }

    SetFlags00(var3, 2);
    func_020d84e0();
    func_0202b0f4(var2);
    func_0205e22c(var4);
#if !defined(jpn)
    var2->unknown_1029_ &= ~0x10;
#endif

    for (int i = 0; i < 4; i++) {
        if (i == GameState_GetProtagonistIndex(gs)) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (active && member && GetByte0x26c_02039d7c((char*)member)) {
                ResetObjectState02039d84((Obj02039d84*)member);
            }
        } else {
            GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(gs, i);
            if (combatant && GetSignedByte0x2d0_020546a8(combatant) == GameState_GetProtagonistIndex(gs)) {
                continue;
            }
            func_ov017_02190264(var3, var18);
        }
    }

    leader.from = GameState_GetProtagonistIndex(gs);
    leader.to = 0;
    if (leader.from != leader.to) {
        func_ov017_021c32b0(&leader, 1);
    }

    for (int var21 = 3; var21 >= 0; var21--) {
        GameObject* var22 = var0->GetGameObjectByIndex(var21);
        if (var22 && (var22->obj3D_.unknown_0_ & 0x1000)) {
            int var23 = -1;
            for (int var24 = 3; var21 < var24; var24--) {
                if (var0->GetGameObjectByIndex(var24) == NULL) {
                    var23 = var24;
                    break;
                }
            }
            if (var23 != -1) {
                var15.unknown_0_ = var21;
                var15.unknown_1_ = var23;
                if (var15.unknown_0_ != var15.unknown_1_) {
                    func_ov017_021c32b0(&var15, 1);
                }
            }
        }
    }

    func_0202c288(var2);
    func_020100a0(var0, 0);
    if (var9) {
        func_020dcd40();
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        func_ov017_02191234(var3);
        func_ov017_02191108(var3, 1, 1, 1, 1);
    }

    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(gs, i);
        if (combatant) {
            SetField0x2d0_020546a0(combatant, GameState_GetProtagonistIndex(gs));
            SetByte0x1c8_02039858((unsigned char*)combatant, GameState_GetProtagonistIndex(gs));
            ClearBytesAndZeroBlock02039d24((unsigned char*)combatant);
        }
    }

    void* var27 = func_020100f8((char*)var0);
    if (var27) {
        func_020a2770(var27, 0);
    }
    func_ov017_02191108(var3, 1, 0, 1, 1);
    func_ov017_02191234(var3);
    var1->unknown_5ccc_ |= 2;

    Party021c37a4* party = (Party021c37a4*)GameState_GetParty(gs);
    if (active) {
        void* store = Scenario_GetInstance();
        memset(bits, 0, 0x1a);
        unsigned char* p = bits;
        unsigned char bit = 0;
        for (int i = 0; i < 0xcc; i++) {
            if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)store, i)) {
                *p |= 1 << bit;
            }
            var31++;
            if (var31 == 8) {
                var30++;
                var31 = 0;
            }
        }
        func_020abd20(0);
        var28->unknown_2c94_ = var1->unknown_7e74_;

        var31 = 0;
        var30 = var13;
        bool var33 = false;
        for (int var34 = 0; var34 < 0xcc; var34++) {
            if (*var30 & (1 << var31)) {
                if (!func_0206e2dc((Struct_0205faf4_13*)var29, var34)) {
                    var33 = true;
                }
                func_0206e2a0((Struct_0206e2a0*)var29, var34);
            }
            var31++;
            if (var31 == 8) {
                var30++;
                var31 = 0;
            }
        }
        if (changed) {
            void* list;
            void* node = res->fieldTasks_[0x31];
            list = res->fieldTaskQueue_;
            Init020d9ae8((Struct020d9ae8*)node, 0);
            CopyStringInto020d9dc4((char*)node, name);
            AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
        }
    }

    func_02086d88((unsigned char*)var28, 0x5612);
    func_ov017_0218d500(var3);
    if (var9) {
        func_020116c8(var0);
    }

    Struct_ov017_021c37a4_8* var37 = (Struct_ov017_021c37a4_8*)var0->GetPartyMemberByIndex(0);
    if (var37 && (var37->unknown_130_->unknown_0_ & 1)) {
        func_02048150(var37, 0, 1);
        var37->unknown_130_->unknown_4_ = 1;
        var37->unknown_18c_ &= ~1;
    }

    Party021c37a4* members = (Party021c37a4*)GameState_GetParty(gs);
    for (int i = 0; i < members->memberCount; i++) {
        unsigned char id = members->memberIds[i];
        if (GetCombatantWithFlag0x100_0200ff1c(gs, id)) {
            func_ov017_02191aac(res, 0, id, 2);
        }
    }

    Struct_ov017_021c37a4_9* var41 = var1->unknown_74c0_;
    for (int var42 = 0; var42 < 3; var42++, var41++) {
        VectorizedMemset(var41, 0, 6);
        var41->unknown_6_ = -1;
        var41->unknown_7_ = 0;
        var41->unknown_8_ = 0;
        var41->unknown_9_ = -1;
    }

    ResetEightRegionsAndFlags_02093a14(GetGlobal02109030_020936f8());
    Field021c37a4* field = Zone3D_GetInstance();
    FieldTimer021c37a4* timer = field->GetTimer();
    timer->value = 0;
    res->unknown_flag_42e2 = 0;
    ClearTwoBytesAtField_02195748((unsigned char*)res);
    ApplyVecFromField0x246_020a2718((char*)follower);
    InitSlotTable020e3004((SlotTable020e3004*)d153637);
    ClearThreeBytes020e358c((Bytes020e358c*)d153634);
    ResetEntryArray020e3814((Entry020e3840*)d153660);
    field->flag = 1;

    if (GetField0xcd0209c3ac((char*)&g_bgmPlayer) != 0x7f) {
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
        func_020bbd9c();
    }
    g_bgmPlayer.flags &= ~4;
    if (!IsHandleB8Active0209c6bc(&g_bgmPlayer)) {
        InitActorContext0209c20c((Actor0209c20c*)&g_bgmPlayer);
    }
    FlagWord_ClearBits((FlagWord020466f4*)d114e04, 0x800);
    MessageSystem_GetInstance()->flag = 0;
}
