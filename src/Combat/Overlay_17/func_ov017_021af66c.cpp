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
    Type_01ff91ac fn[13];
};

struct Struct_ov017_021af66c_4 {
    unsigned char unk0;
    unsigned char unknown_1_;
    unsigned char unk2[6];
    unsigned char unknown_8_;
    unsigned char mode;
    unsigned char state;
    unsigned char unknown_b_;
    unsigned char searchIndex;
    unsigned char unknown_d_;
    unsigned char unknown_e_[0x1b - 0xe];
    unsigned char slots[0x38 - 0x1b];
    unsigned int unknown_38_;
    int mainBrightness;
    unsigned short clearColor;
    unsigned char unknown_42_;
    unsigned char unknown_43_[5];
#if defined(jpn)
    unsigned char dispatcher[0x210 - 0x48];
#else
    unsigned char dispatcher[0x280 - 0x48];
#endif
    int unknown_280_;
    int unknown_284_;
    void* allocation;
};

struct Struct_ov017_021af66c {
    unsigned char unk0[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unknown_3_[0xc8 - 3];
#else
    unsigned char unknown1_3_[0xcc - 3];
#endif
    unsigned char kind;
    unsigned char value397c;
    unsigned char unknown_ce_;
    unsigned char phase;
};

struct Struct_ov017_021af66c_2 {
    unsigned char unk0[0x49c];
    unsigned char bit0 : 1;
};

struct GrottoInfo02012fe4 {
    unsigned short type;
    unsigned char unk2[6];
    int param;
};

struct SearchStruct;
struct Obj020397cc;
struct TailList020469b4;
struct TailNode020469b4;
struct Struct_02046968;
struct FlagWord020466f4;
struct AllocatorUnion;

extern "C" void* LinkSession_GetInstance();
extern "C" void func_ov017_021c37a4();
extern "C" GrottoInfo02012fe4* Zone3D_GetInstance();
extern "C" void func_ov017_021baedc(Struct_ov017_021af66c* node, int v);
extern "C" void func_ov017_021bbae4(Struct_ov017_021af66c* node, int param, int v);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void* func_ov017_021b8468(Struct_ov017_021af66c* node);
extern "C" void func_ov017_021afb8c(Struct_ov017_021af66c_4* obj, unsigned char* p);
extern "C" void func_ov017_0218b5c0(int a, int b);

extern "C" void* GlobalFlags_GetInstance();
extern "C" void* func_020936f8();
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int v);
extern "C" void func_0205c904(unsigned char* obj, int v);
extern "C" int LinkSession_IsSlotConnected(SearchStruct* obj, int index);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* gs);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_02093a14(char* obj);
extern "C" void func_020dc2d0(int v);
extern "C" void func_ov000_02163b14(void* p, void* q);
extern "C" void func_ov000_02163b40(void* p);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" void func_02046968(Struct_02046968* list);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void GameObject_ApplyPendingControl(void* obj);
extern "C" void func_0205ce94(unsigned char* obj);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* obj, unsigned int mask);
extern "C" void func_020daf9c(int a, int b, int c, int d);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* p);
extern "C" MessageSystem* MessageSystem_GetInstance();

extern Struct_ov017_021d6aec data_ov017_021d6aec;
extern AllocatorUnion g_mainAllocator;

struct CombatantView {
    char unk0[0xb2];
    unsigned short unknown_b2_;
#if defined(jpn)
    char unknown_b4_[0x144 - 0xb4];
#else
    char unknown1_b4_[0x150 - 0xb4];
#endif
    Struct_ov017_021af66c_2* flags;
};

// USA: func_ov017_021af66c
extern "C" ARM void func_ov017_021af66c(Struct_ov017_021af66c_4* obj, void* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    CombatantView* combatant = (CombatantView*)gs->GetLeader();
    FlagWord020466f4* flags = (FlagWord020466f4*)GlobalFlags_GetInstance();
    char* global = (char*)func_020936f8();
    Struct_ov017_021af66c* menu = static_cast<Struct_ov017_021af66c*>(res->unknown_ptr_3718);
    GameObject_DisableControl((Obj020397cc*)combatant, 0);
    combatant->unknown_b2_ = 0;
    Struct_ov017_021d6aec table = data_ov017_021d6aec;
    if (table.fn[obj->state] != 0) {
        int tick = gs->GetTickCount();
        if (tick == 0) {
            tick = 1;
        }
        func_0205c904(obj->dispatcher, tick);
        obj->state = table.fn[obj->state](obj);
    }
    if (obj->unknown_8_ != 0) {
        obj->unknown_1_ = 1;
    }
    if (obj->mode != 2 && *reinterpret_cast<int*>(reinterpret_cast<char*>(search) + 0xfc0) == 0) {
        if (LinkSession_IsSlotConnected(search, obj->searchIndex) == 0) {
            obj->unknown_1_ = 1;
        }
    }
    if (res->unknown_42e2_ != 0) {
        if (obj->mode == 2) {
            func_ov017_021c37a4();
            res->unknown_42e3[0] = 1;
            GrottoInfo02012fe4* info = Zone3D_GetInstance();
            if (info->type == 1) {
                SetBrightness(res, 0, 30);
                UnlockAndSetBrightness(res, 0, 30);
            }
            Struct_ov017_021af66c* node = static_cast<Struct_ov017_021af66c*>(res->unknown_ptr_array_371c[6]);
            if (node->active == 0) {
                func_ov017_021baedc(node, 1);
                func_ov017_021bbae4(node, info->param, 2);
                node->value397c = GameState_GetLeaderIndex(gs);
                node->unknown_ce_ = combatant->flags->bit0;
                node->kind = 1;
                node->phase = 3;
                func_020469b4((TailList020469b4*)list, (TailNode020469b4*)node);
            }
            ClearFlags00(res, 0x40);
        } else {
            func_ov017_0219577c(0, 0, 0);
            Struct_ov017_021af66c* node = static_cast<Struct_ov017_021af66c*>(res->unknown_ptr_array_371c[6]);
            if (node->active != 0 && node->phase == 2) {
                func_02093a14(global);
                func_020dc2d0(0);
            }
        }
        obj->unknown_1_ = 1;
    }
    int slot = func_ov017_02195658(res);
    if (slot > 0) {
        obj->slots[slot] = 0;
        if (menu->active != 0) {
            void* p = func_ov017_021b8468(menu);
            if (p != 0) {
                func_ov000_02163b14(p, (void*)slot);
                func_ov017_021afb8c(obj, obj->unknown_e_);
            }
        }
    }
    if (menu->active != 0) {
        void* p = func_ov017_021b8468(menu);
        if (p != 0) {
            func_ov000_02163b40(p);
        }
    }
    if (obj->unknown_1_ == 0) {
        return;
    }
    if (obj->unknown_42_ != 0) {
        SetMainBrightness(res, obj->mainBrightness, 0);
        Set3DClearColor(obj->clearColor, 0, 0x7fff, 0, 0);
        ClearFlags04(res, 0xffffffff);
        SetFlags04(res, obj->unknown_38_);
    }
    obj->unknown_b_ = 0;
    func_02046968((Struct_02046968*)list);
    Struct_ov017_021af66c* node = static_cast<Struct_ov017_021af66c*>(res->unknown_ptr_array_371c[6]);
    int var16 = 1;
    if (node->active != 0 && node->phase == 2) {
        var16 = 0;
    }
    if (var16) {
        GameObject* c = gs->GetLeader();
        if (c != 0) {
            GameObject_EnableControl(c);
            GameObject_ApplyPendingControl(c);
        }
    }
    func_0205ce94(obj->dispatcher);
    FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x800000);
    func_ov017_0218b5c0(1, -1);
    func_020daf9c(0, 1, 0, 1);
    DISPCNT = (DISPCNT & ~0x1f00) | (obj->unknown_280_ << 8);
    ClearFlags04(res, 0x40);
    if (obj->allocation != 0) {
        AllocatorUnion_Free(&g_mainAllocator, obj->allocation);
        obj->allocation = 0;
    }
    MessageSystem* messages = MessageSystem_GetInstance();
#if defined(jpn)
    messages->flags17ff.flag2 = 0;
#else
    messages->unknown_19d0_ = 0;
#endif
    if (static_cast<Struct_ov017_021af66c*>(res->unknown_ptr_3718)->active == 0) {
        FlagWord_ClearBits(flags, 0x40000);
    }
}
