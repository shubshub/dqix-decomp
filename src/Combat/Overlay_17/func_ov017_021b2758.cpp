#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov017_021b2758_261 = 0x125, Enum_ov017_021b2758_268 = 0x12c };
#else
enum { Enum_ov017_021b2758_261 = 0x105, Enum_ov017_021b2758_268 = 0x10c };
#endif

extern "C" void GameState_SetCamera(GameState* battleStruct, int value);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a27ac(void* obj);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" void func_ov017_0218f758(void* self);

struct Struct_ov011_021849bc;
extern "C" int func_ov011_021849bc(struct Struct_ov011_021849bc* obj, int mask);

struct Obj021b2200;
extern "C" void func_ov017_021b2200(struct Obj021b2200* self);

extern "C" void* Zone3D_GetInstance(void);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void func_ov017_0219bd1c(int, int, int, int);

struct Struct_ov017_021d83f0_8 { unsigned int field0; int slot; };
extern Struct_ov017_021d83f0_8 data_ov017_021d83f0;

struct Struct_ov017_021b2758 { unsigned char pad[0x90]; int f90; unsigned char pad2[4]; int unknown_98_; };

union Struct_ov017_021b2758_2 {
    unsigned int raw;
    struct {
        unsigned int bit0 : 1;
        unsigned int unknown_0_1_ : 1;
        unsigned int bit2 : 1;
        unsigned int : 2;
        unsigned int unknown_0_5_ : 1;
        unsigned int : 26;
    } b;
};

struct Struct_ov017_021b2758_3 {
    unsigned char pad0[0x38];
    Struct_ov017_021b2758_2 field0x38;
    unsigned char pad1[2];
    unsigned char unknown_3e_;
    unsigned char pad2[1];
    int unknown_40_;
    int field0x44;
    unsigned char unknown_48_;
};

// USA: func_ov017_021b2758
extern "C" ARM int func_ov017_021b2758(Struct_ov017_021b2758_3* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    GameState_SetCamera(battleStruct, self->field0x44);

    if (data_ov017_021d83f0.slot != 0) {
        if (func_ov011_021849bc((struct Struct_ov011_021849bc*)data_ov017_021d83f0.slot, 1)) self->field0x38.b.bit0 = 1;
        if (func_ov011_021849bc((struct Struct_ov011_021849bc*)data_ov017_021d83f0.slot, 2)) self->field0x38.raw |= 2;
        if (func_ov011_021849bc((struct Struct_ov011_021849bc*)data_ov017_021d83f0.slot, 4)) self->field0x38.raw |= 4;
        func_ov017_021b2200((struct Obj021b2200*)self);
        ROMFilesystem_InitFileTables();
    }

    ClearFlags00(ov, 0x10);
    if (self->field0x38.b.bit0) {
        Zone3D_GetInstance();
        ClearFlags00(ov, 4);
        func_ov017_0219bd1c(1, 0, 0, 0);
        self->field0x38.raw &= ~2;
        void* p = GameState_GetZoneTransition(battleStruct);
        if (self->unknown_48_ != 0) ((char*)p)[0x67] = 1;
        return 5;
    }
    if (self->field0x38.b.unknown_0_1_) return 6;
    if (self->field0x38.b.bit2) return 7;

    battleStruct->GetLeader();
    int flagVal = GameState_GetFollowCamera((char*)battleStruct);
    unsigned char* ctx = (unsigned char*)Zone3D_GetInstance();
    if (flagVal != 0) {
        func_020a28b0((unsigned char*)flagVal, 2);
        if (self->unknown_3e_ != 0) {
            func_020a28a0((unsigned char*)flagVal, 2);
        }
        func_020a27ac((void*)flagVal);
    }
    if (ctx != 0) {
        ctx[Enum_ov017_021b2758_261] &= ~1;
    }

    if (!self->field0x38.b.unknown_0_5_) {
        ClearFlags04(ov, 0x609fe);
        SetFlags04(ov, self->unknown_40_);
    }

    Struct_ov017_021b2758* d = (Struct_ov017_021b2758*)LightingManager::GetInstance();
    int f90 = d->f90;
    int idx = d->unknown_98_;
    unsigned char* base = ctx + Enum_ov017_021b2758_268;
    if (f90 != 0) idx = f90;
    unsigned short color;
    if (*(int*)(base + 0x304) == 1) {
        color = *(unsigned short*)(base + idx * 2 + 0x8c);
    } else {
        color = *(unsigned short*)(base + idx * 2 + 0x126);
    }
    Set3DClearColor(color, 0x10, 0x7fff, 0, 0);
    func_ov017_0218f758(ov);
    return 4;
}
