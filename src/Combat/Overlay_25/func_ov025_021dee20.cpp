#if defined(jpn)
enum { Enum_ov025_021dee20_30476 = 0x78fc };
#else
enum { Enum_ov025_021dee20_30476 = 0x770c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov025_021ded50_2 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

struct Struct_ov025_021ded50;
struct Struct_ov000_0215fef0;

extern "C" int func_ov025_021deda0(struct Struct_ov025_021ded50* table, struct Struct_ov025_021ded50_2* out);
extern "C" void func_ov000_02160030(void* obj);
extern "C" void func_ov000_0215fe64(void* p);
extern "C" void func_ov000_0215fef0(struct Struct_ov000_0215fef0* obj);

struct Struct_ov025_021dee20_2 {
    unsigned short unknown_0_;
    unsigned char pad1[0x8 - 0x2];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char pad2[0xb - 0xa];
    unsigned char unknown_b_;
    unsigned char pad3[0x10 - 0xc];
    void* unknown_10_;
    void* unknown_14_;
    unsigned short unknown_18_;
};

struct Struct_ov025_021dee20_3 {
    unsigned char pad0[0x20];
    unsigned short unknown_20_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    unsigned char pad1[0x30 - 0x26];
    int unknown_30_;
};

struct Struct_ov025_021dee20 {
    unsigned char pad0[0xe];
    unsigned short unknown_e_;
    unsigned char pad1[0x20 - 0x10];
    int unknown_20_;
};

// USA: func_ov025_021dee20
extern "C" ARM void func_ov025_021dee20(void* obj) {
    struct Struct_ov025_021ded50_2 row;
    if (!func_ov025_021deda0((struct Struct_ov025_021ded50*)obj, &row)) {
        return;
    }

    SafeAllocator* alloc = (SafeAllocator*)((char*)obj + 0x30);
    struct Struct_ov025_021dee20_2* rec = (struct Struct_ov025_021dee20_2*)alloc->Allocate(0x28);
    if (!rec) {
        return;
    }
    func_ov000_02160030(rec);
    rec->unknown_0_ = row.b;

    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetCombatantByIndex(row.a);
    if (!combatant) {
        return;
    }

    rec->unknown_8_ = 1;
    rec->unknown_10_ = alloc->Allocate(0x34);
    void* var5 = rec->unknown_10_;
    if (!var5) {
        return;
    }
    func_ov000_0215fe64(var5);
    ((struct Struct_ov025_021dee20_3*)var5)->unknown_30_ = 0;
    ((struct Struct_ov025_021dee20_3*)rec->unknown_10_)->unknown_20_ = row.a;
    ((struct Struct_ov025_021dee20_3*)rec->unknown_10_)->unknown_22_ = combatant->currentStats_->primaryStats.currHP;
    ((struct Struct_ov025_021dee20_3*)rec->unknown_10_)->unknown_24_ = combatant->currentStats_->primaryStats.currMP;
    rec->unknown_9_ = 1;

    rec->unknown_14_ = alloc->Allocate(0x24);
    void* rec3 = rec->unknown_14_;
    if (!rec3) {
        return;
    }
    func_ov000_0215fef0((struct Struct_ov000_0215fef0*)rec3);
    ((struct Struct_ov025_021dee20*)rec3)->unknown_20_ = 0;
    ((struct Struct_ov025_021dee20*)rec->unknown_14_)->unknown_e_ = row.a;
    rec->unknown_18_ = row.c;
    rec->unknown_b_ |= 4;

    *(void**)((char*)obj + Enum_ov025_021dee20_30476) = rec;
}
