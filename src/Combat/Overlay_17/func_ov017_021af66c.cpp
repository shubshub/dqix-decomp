#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define data_ov017_021d6aec data_ov017_021d6ee4
#endif

struct Struct_ov017_021af66c_4;
typedef unsigned char (*Type_01ff91ac)(Struct_ov017_021af66c_4* obj);

struct Struct_ov017_021d6aec {
    Type_01ff91ac unknown_0_[13];
};

struct Struct_ov017_021af66c_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_[0x1b - 0xe];
    unsigned char unknown_1b_[0x38 - 0x1b];
    unsigned int unknown_38_;
    int unknown_3c_;
    unsigned short unknown_40_;
    unsigned char unknown_42_;
    unsigned char unknown_43_[5];
#if defined(jpn)
    unsigned char unknown_48_[0x210 - 0x48];
#else
    unsigned char unknown_48_[0x280 - 0x48];
#endif
    int unknown_280_;
    int unknown_284_;
    void* unknown_288_;
};

struct Struct_ov017_021af66c {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_3_[0xc8 - 3];
#else
    unsigned char unknown1_3_[0xcc - 3];
#endif
    unsigned char unknown_cc_;
    unsigned char unknown_cd_;
    unsigned char unknown_ce_;
    unsigned char unknown_cf_;
};

struct Struct_ov017_021af66c_2 {
    unsigned char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov017_021af66c_3 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[6];
    int unknown_8_;
};

struct Struct_0202b2f0;
struct Struct_02018300_3;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_02046968;
struct Struct_02038598_4;
struct AllocatorUnion;

extern "C" void* LinkSession_GetInstance();
extern "C" void func_ov017_021c37a4();
extern "C" GrottoInfo02012fe4* Zone3D_GetInstance();
extern "C" void func_ov017_021baedc(CombatMenuNode* node, int v);
extern "C" void func_ov017_021bbae4(CombatMenuNode* node, int param, int v);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void* func_ov017_021b8468(CombatMenuNode* node);
extern "C" void func_ov017_021afb8c(CombatStepObj* obj, unsigned char* p);
extern "C" void func_ov017_0218b5c0(int a, int b);

void* GlobalFlags_GetInstance();
void* GetGlobal02109030_020936f8();
void GameObject_DisableControl(Obj020397cc* obj, int v);
void SetupAndDispatch0205c904(unsigned char* obj, int v);
int LinkSession_IsSlotConnected(SearchStruct* obj, int index);
unsigned char GameState_GetLeaderIndex(GameState* gs);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void ResetEightRegionsAndFlags_02093a14(char* obj);
void SetCombatModeFromCase020dc2d0(int v);
void InvokeIfInputLogBIs3_021dbd1c_ov000_02163b14(void* p, void* q);
void InvokeIfInputLogBIs3_021dbe44_ov000_02163b40(void* p);
void Set3DClearColor(int a, int b, int c, int d, int e);
void ClearListUntilFlagZero(ClearList02046968* list);
void GameObject_EnableControl(void* obj);
void GameObject_ApplyPendingControl(void* obj);
void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* obj);
void FlagWord_ClearBits(FlagWord020466f4* obj, unsigned int mask);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* p);
MessageSystem* MessageSystem_GetInstance();

extern CombatStepTable data_ov017_021d6aec;
extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021af66c_5 {
    char unknown_0_[0xb2];
    unsigned short unknown_b2_;
#if defined(jpn)
    char unknown_b4_[0x144 - 0xb4];
#else
    char unknown1_b4_[0x150 - 0xb4];
#endif
    Struct_ov017_021af66c_2* unknown_150_;
};

// USA: func_ov017_021af66c
extern "C" ARM void func_ov017_021af66c(CombatStepObj* obj, void* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    CombatantView* combatant = (CombatantView*)gs->GetLeader();
    FlagWord020466f4* flags = (FlagWord020466f4*)GlobalFlags_GetInstance();
    char* global = (char*)GetGlobal02109030_020936f8();
    CombatMenuNode* menu = static_cast<CombatMenuNode*>(res->unknown_ptr_3718);
    GameObject_DisableControl((Obj020397cc*)combatant, 0);
    combatant->pendingAction = 0;
    CombatStepTable table = data_ov017_021d6aec;
    if (table.fn[obj->state] != 0) {
        int tick = gs->GetTickCount();
        if (tick == 0) {
            tick = 1;
        }
        func_0205c904(arg0->unknown_48_, var8);
        arg0->unknown_a_ = var7.unknown_0_[arg0->unknown_a_](arg0);
    }
    if (arg0->unknown_8_ != 0) {
        arg0->unknown_1_ = 1;
    }
    if (obj->mode != 2 && *reinterpret_cast<int*>(reinterpret_cast<char*>(search) + 0xfc0) == 0) {
        if (LinkSession_IsSlotConnected(search, obj->searchIndex) == 0) {
            obj->finished = 1;
        }
    }
    if (var1->unknown_42e2_ != 0) {
        if (arg0->unknown_9_ == 2) {
            func_ov017_021c37a4();
            res->unknown_42e3[0] = 1;
            GrottoInfo02012fe4* info = Zone3D_GetInstance();
            if (info->type == 1) {
                SetBrightness(res, 0, 30);
                UnlockAndSetBrightness(res, 0, 30);
            }
            CombatMenuNode* node = static_cast<CombatMenuNode*>(res->unknown_ptr_array_371c[6]);
            if (node->active == 0) {
                func_ov017_021baedc(node, 1);
                func_ov017_021bbae4(node, info->param, 2);
                node->value397c = GameState_GetLeaderIndex(gs);
                node->flagBit = combatant->flags->bit0;
                node->kind = 1;
                node->phase = 3;
                AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
            }
            ClearFlags00(var1, 0x40);
        } else {
            func_ov017_0219577c(0, 0, 0);
            Struct_ov017_021af66c* var11 = static_cast<Struct_ov017_021af66c*>(var1->unknown_ptr_array_371c[6]);
            if (var11->unknown_2_ != 0 && var11->unknown_cf_ == 2) {
                func_02093a14(var5);
                func_020dc2d0(0);
            }
        }
        arg0->unknown_1_ = 1;
    }
    int var12 = func_ov017_02195658(var1);
    if (var12 > 0) {
        arg0->unknown_1b_[var12] = 0;
        if (var6->unknown_2_ != 0) {
            void* var13 = func_ov017_021b8468(var6);
            if (var13 != 0) {
                func_ov000_02163b14(var13, (void*)var12);
                func_ov017_021afb8c(arg0, arg0->unknown_e_);
            }
        }
    }
    if (var6->unknown_2_ != 0) {
        void* var14 = func_ov017_021b8468(var6);
        if (var14 != 0) {
            func_ov000_02163b40(var14);
        }
    }
    if (arg0->unknown_1_ == 0) {
        return;
    }
    if (obj->restoreDisplay != 0) {
        SetMainBrightness(res, obj->mainBrightness, 0);
        Set3DClearColor(obj->clearColor, 0, 0x7fff, 0, 0);
        ClearFlags04(res, 0xffffffff);
        SetFlags04(res, obj->field4Bits);
    }
    arg0->unknown_b_ = 0;
    func_02046968((Struct_02046968*)arg1);
    Struct_ov017_021af66c* var15 = static_cast<Struct_ov017_021af66c*>(var1->unknown_ptr_array_371c[6]);
    int var16 = 1;
    if (var15->unknown_2_ != 0 && var15->unknown_cf_ == 2) {
        var16 = 0;
    }
    if (restore) {
        GameObject* c = gs->GetLeader();
        if (c != 0) {
            GameObject_EnableControl(c);
            GameObject_ApplyPendingControl(c);
        }
    }
    ResetGlobalObjAndInitSelfPointer0205ce94(obj->dispatcher);
    FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x800000);
    func_ov017_0218b5c0(1, -1);
    DispatchWithGlobalContext020daf9c(0, 1, 0, 1);
    DISPCNT = (DISPCNT & ~0x1f00) | (obj->bgMode << 8);
    ClearFlags04(res, 0x40);
    if (obj->allocation != 0) {
        AllocatorUnion_Free(&g_mainAllocator, obj->allocation);
        obj->allocation = 0;
    }
    MessageSystem* messages = MessageSystem_GetInstance();
#if defined(jpn)
    var18->unknown_17ff_.unknown_0_2_ = 0;
#else
    var18->unknown_19d0_ = 0;
#endif
    if (static_cast<CombatMenuNode*>(res->unknown_ptr_3718)->active == 0) {
        FlagWord_ClearBits(flags, 0x40000);
    }
}
