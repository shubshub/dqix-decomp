#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_ov000_02155184;
extern "C" Struct_ov000_02155184* func_0200fea4(GameState*, int);
struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
extern "C" void* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" void* func_0206f4f0(Struct_0206f01c_2*, int);

struct Struct_ov000_02155184 {
    char p0[2]; unsigned short key; char p1[0x138-4];
    unsigned char* details; char p2[8]; unsigned short* unknown_144_;
    char p3[0x17c-0x148]; unsigned char action, unknown_17d_, flags;
    char p4[5]; unsigned char alternate; char p5;
    unsigned short unknown_186_; char p6[4]; unsigned char unknown_18c_;
};
struct Struct_ov000_02155184_4 {
    unsigned short action:3, count:11, flagA:1, unknown_1_7_:1;
    unsigned short key, unknown_4_;
    unsigned char flags, unknown_7_, unknown_8_, unknown_9_;
};
struct Struct_ov000_02155184_5 { char p[22]; unsigned char unknown_16_, flagA; };
struct Struct_ov000_02155184_6 {
    char p0[0x81b4]; Struct_ov000_02155184_5 actions[3];
    char p1[0x8d66-0x81fc]; Struct_ov000_02155184_4 entries[12];
    char p2[0x8e18-0x8dde]; char* info;
    char p3[12]; int total; int unknown_8e2c_; int unknown_8e30_; int unknown_8e34_;
};
struct Struct_ov000_02155184_2 { char p[8]; int total; unsigned short unknown_c_; };
struct Struct_ov000_02155184_3 { char p[10]; unsigned short unused:12, special:1, rest:3; };

static inline int inline_ov000_02155184(Struct_ov000_02155184* unit) { return unit->action; }
static inline int inline_ov000_02155184_2(int id) { return id >= 0 && id <= 3; }

// USA: func_ov000_02155184
extern "C" ARM void func_ov000_02155184(Struct_ov000_02155184_6* obj, int id, int flags) {
    if (inline_ov000_02155184_2(id)) return;
    Struct_ov000_02155184* unit = func_0200fea4(GameState::GetInstance(), id);
    if (!unit) return;
    char* search = obj->info + 0x284;
    unsigned short key = unit->key;
    Struct_ov000_02155184_2* record;
    char* var4 = obj->info + 0x678;
    int action = unit->action;
    if (unit->alternate) { key = unit->unknown_186_; action = unit->unknown_18c_; }
    record = (Struct_ov000_02155184_2*)func_02070fd0((Struct_02070b6c_3*)(search + 0x400), key);
    if (!record) return;
    Struct_ov000_02155184_3* var6 = (Struct_ov000_02155184_3*)func_0206f4f0((Struct_0206f01c_2*)var4, (short)key);
    if (!var6 || unit->unknown_17d_) return;
    int var7 = 0;
    if (!(flags & 0x10) && !(flags & 0x20)) {
        obj->total += record->total;
        obj->unknown_8e2c_ += record->unknown_c_;
        var7 = 1;
        if (var6 && var6->special) obj->unknown_8e34_ += record->total;
        unit->unknown_17d_ = 1;
    }
    Struct_ov000_02155184_4* entry;
    int found = 0;
    for (int i = 0; i < obj->unknown_8e30_; i++) {
        entry = &obj->entries[i];
        if (entry->key == key && action == entry->action) {
            Struct_ov000_02155184_5* a = &obj->actions[entry->action];
            entry->count = (unsigned short)(entry->count + 1);
            entry->flagA = a->flagA;
            entry->unknown_1_7_ = a->unknown_16_;
            entry->flags |= unit->flags;
            unsigned char var12 = unit->details[0x3d];
            var12 = entry->unknown_7_ | var12;
            entry->unknown_7_ = var12;
            entry->unknown_8_ |= var7;
            if ((flags & 0x10) || (flags & 0x20)) entry->unknown_9_++;
            found = 1;
            break;
        }
    }
    if (found) return;
    if (obj->unknown_8e30_ >= 12) return;
    if (inline_ov000_02155184(unit) >= 3) return;
    {
        Struct_ov000_02155184_5* a = &obj->actions[unit->action];
        entry = &obj->entries[obj->unknown_8e30_];
        memset(entry, 0, sizeof(*entry));
        entry->key = key;
        entry->action = (unsigned short)action;
        entry->count = 1;
        entry->flagA = a->flagA;
        entry->unknown_1_7_ = a->unknown_16_;
        entry->flags |= unit->flags;
        unsigned char var14 = unit->details[0x3d];
            var14 = entry->unknown_7_ | var14;
            entry->unknown_7_ = var14;
        entry->unknown_8_ |= var7;
        if ((flags & 0x10) || (flags & 0x20)) entry->unknown_9_++;
        if (unit->unknown_144_) entry->unknown_4_ = unit->unknown_144_[8];
        obj->unknown_8e30_++;
    }
}
