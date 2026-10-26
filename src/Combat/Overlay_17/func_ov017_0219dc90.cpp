#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct TailList020469b4;

struct InlineEntry {
    unsigned char unk0[2];
    unsigned short slotIndex : 2;
    unsigned short unknown_2_2_ : 2;
    unsigned short group : 12;
    unsigned short f4;
    unsigned char unknown_6_[2];
    int f8;
    unsigned char unkc;
    unsigned char unknown_d_;
#if defined(jpn)
    unsigned char unknown_e_[0x6];
#else
    unsigned char unknown1_e_[0xa];
#endif
    int vec18[3];
    unsigned char unknown_24_[0x10];
    int f34;
};

struct Struct_ov017_0219dc90_5 {
    unsigned char unk0[2];
    unsigned char used;
    unsigned char unknown_3_[5];
    InlineEntry* entry;
    unsigned char unkc[5];
    unsigned char kind;
    unsigned short value;
#if defined(jpn)

#else
    unsigned char unknown_14_[4];
#endif
};

struct Struct_ov017_0219dc90_6 {
    unsigned short id;
    unsigned short group;
};

struct Struct_ov017_0219dc90_7 {
    unsigned char unk0[0x44];
    int vec44[3];
    unsigned char unk50[0x68];
    unsigned short b8;
    unsigned char unknown_ba_[8];
    unsigned char c2;
};

struct Struct_ov017_0219dc90 {
#if defined(jpn)
    unsigned char unk0[0x34f4];
#else
    unsigned char unk0[0x3704];
#endif
    TailList020469b4* unknown_3704_;
    unsigned char unknown_3708_[0x3a9c - 0x3708];
    Struct_ov017_0219dc90_5 slots[4];
#if defined(jpn)
    unsigned char unknown_38dc_[0x4204 - 0x38dc];
#else
    unsigned char unknown_3afc_[0x44b4 - 0x3afc];
#endif
    Struct_ov017_0219dc90_6 pending;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" InlineEntry* ZoneRecords_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void ZoneRecords_ReleaseUnoccupied(InlineEntry* table);
extern "C" void func_ov017_0219e0ec(void* self);
extern "C" int ZoneRecords_Add(InlineEntry* base, int id);
extern "C" void func_ov017_0219e180(Struct_ov017_0219dc90* self, int id);
struct Entry_02028bd0;
extern "C" InlineEntry* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" unsigned short NodeGraph_FindClosestNode(int* a, int* b);
extern "C" int ZoneId_IsGrotto(int id);
struct Struct_ov017_0219dc90_3;
extern "C" void func_ov017_021b46d8(Struct_ov017_0219dc90_3*);
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
struct Obj021b4760;
extern "C" void FieldTask_EndLoadZoneMonsters(Obj021b4760*);
extern "C" void func_02046a8c(TailList020469b4* list, Struct_ov017_0219dc90_5* node);

// USA: func_ov017_0219dc90
extern "C" ARM void func_ov017_0219dc90(Struct_ov017_0219dc90* self, int arg1, int id, unsigned char kind, unsigned short value) {
    GameState* gs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    InlineEntry* table = ZoneRecords_GetInstance();
    Zone3D_GetInstance();
    Struct_ov017_0219dc90_7* combatant = (Struct_ov017_0219dc90_7*)func_0200ff1c(gs, arg1);
    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) != 0) return;
    ZoneRecords_ReleaseUnoccupied(table);
    func_ov017_0219e0ec(self);
    if (combatant == NULL) return;
    int found = ZoneRecords_Add(table, id);
    func_ov017_0219e180(self, id);
    InlineEntry* entry = ZoneRecords_Find((Entry_02028bd0*)table, id);
    Struct_ov017_0219dc90_6* pending = &self->pending;
    if (entry != NULL) {
        combatant->b8 = entry->f34 != 0 ? NodeGraph_FindClosestNode(entry->vec18, combatant->vec44) : 0;
        signed char* grotto = (signed char*)gs->GetGrottoStruct();
        if (ZoneId_IsGrotto(id) && found) {
            entry->unknown_d_ = grotto[8];
        }
        entry->f8 = 0;
        if (found) {
            if (pending->id == id) {
                entry->group = pending->group;
                pending->id = 0;
                pending->group = 0;
            }
            Struct_ov017_0219dc90_5* slot = &self->slots[entry->slotIndex];
            if (slot->used == 0) {
                func_ov017_021b46d8((Struct_ov017_0219dc90_3*)slot);
                slot->entry = entry;
                slot->kind = kind;
                slot->value = value;
                func_020469b4(self->unknown_3704_, (TailNode020469b4*)slot);
            } else {
                FieldTask_EndLoadZoneMonsters((Obj021b4760*)slot);
                func_02046a8c(self->unknown_3704_, slot);
                func_ov017_021b46d8((Struct_ov017_0219dc90_3*)slot);
                slot->entry = entry;
                slot->kind = kind;
                slot->value = value;
                func_020469b4(self->unknown_3704_, (TailNode020469b4*)slot);
            }
        } else {
            combatant->c2 |= 0x40;
        }
    }
    if (pending->id == id) {
        pending->id = 0;
        pending->group = 0;
    }
}
