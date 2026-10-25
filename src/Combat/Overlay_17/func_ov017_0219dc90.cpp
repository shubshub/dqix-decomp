#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202c1a4;
struct Struct_0201bdac_2;

struct Struct_ov017_0219dc90_2 {
    unsigned char unknown_0_[2];
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 2;
    unsigned short unknown_2_4_ : 12;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
#if defined(jpn)
    unsigned char unknown_e_[0x6];
#else
    unsigned char unknown1_e_[0xa];
#endif
    int unknown_18_[3];
    unsigned char unknown_24_[0x10];
    int unknown_34_;
};

struct Struct_ov017_0219dc90_5 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_[5];
    Struct_ov017_0219dc90_2* unknown_8_;
    unsigned char unknown_c_[5];
    unsigned char unknown_11_;
    unsigned short unknown_12_;
#if defined(jpn)

#else
    unsigned char unknown_14_[4];
#endif
};

struct Struct_ov017_0219dc90_6 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_ov017_0219dc90_7 {
    unsigned char unknown_0_[0x44];
    int unknown_44_[3];
    unsigned char unknown_50_[0x68];
    unsigned short unknown_b8_;
    unsigned char unknown_ba_[8];
    unsigned char unknown_c2_;
};

struct Struct_ov017_0219dc90 {
#if defined(jpn)
    unsigned char unknown_0_[0x34f4];
#else
    unsigned char unknown1_0_[0x3704];
#endif
    Struct_0201bdac_2* unknown_3704_;
    unsigned char unknown_3708_[0x3a9c - 0x3708];
    Struct_ov017_0219dc90_5 unknown_3a9c_[4];
#if defined(jpn)
    unsigned char unknown_38dc_[0x4204 - 0x38dc];
#else
    unsigned char unknown_3afc_[0x44b4 - 0x3afc];
#endif
    Struct_ov017_0219dc90_6 unknown_44b4_;
};

extern "C" void* func_0202ae18(void);
InlineEntry* ZoneRecords_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
extern "C" void func_020288e0(InlineEntry* table);
void SetFlagsForFlaggedCombatants_0219e0ec(void* self);
extern "C" int func_02028a54(InlineEntry* base, int id);
extern "C" void func_ov017_0219e180(BattleOverlay0219dc90* self, int id);
struct Entry_02028bd0;
InlineEntry* FindInlineEntryById(Entry_02028bd0*, int);
extern "C" unsigned short func_02028460(int* a, int* b);
int IsInRange0201b588(int id);
struct Struct021b46d8;
void InitStruct_021b46d8(Struct021b46d8*);
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
struct Obj021b4760;
void FieldTask_EndLoadZoneMonsters(Obj021b4760*);
extern "C" void func_02046a8c(TailList020469b4* list, GrottoSlot* node);

// USA: func_ov017_0219dc90
extern "C" ARM void func_ov017_0219dc90(BattleOverlay0219dc90* self, int combatantIdx, int id, unsigned char kind, unsigned short value) {
    GameState* gs = GameState::GetInstance();
    void* search = func_0202ae18();
    InlineEntry* table = ZoneRecords_GetInstance();
    Zone3D_GetInstance();
    Combatant0219dc90* combatant = (Combatant0219dc90*)GetCombatantWithFlag0x100_0200ff1c(gs, combatantIdx);
    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) != 0) return;
    func_020288e0(table);
    SetFlagsForFlaggedCombatants_0219e0ec(self);
    if (combatant == NULL) return;
    int found = func_02028a54(table, id);
    func_ov017_0219e180(self, id);
    InlineEntry* entry = FindInlineEntryById((Entry_02028bd0*)table, id);
    PendingGroup* pending = &self->pending;
    if (entry != NULL) {
        combatant->b8 = entry->f34 != 0 ? func_02028460(entry->vec18, combatant->vec44) : 0;
        signed char* grotto = (signed char*)gs->GetGrottoStruct();
        if (IsInRange0201b588(id) && found) {
            entry->fd = grotto[8];
        }
        var5->unknown_8_ = 0;
        if (var4) {
            if (var6->unknown_0_ == arg2) {
                var5->unknown_2_4_ = var6->unknown_2_;
                var6->unknown_0_ = 0;
                var6->unknown_2_ = 0;
            }
            Struct_ov017_0219dc90_5* var8 = &arg0->unknown_3a9c_[var5->unknown_2_0_];
            if (var8->unknown_2_ == 0) {
                func_ov017_021b46d8((Struct_ov017_0219dc90_3*)var8);
                var8->unknown_8_ = var5;
                var8->unknown_11_ = arg3;
                var8->unknown_12_ = arg4;
                func_020469b4(arg0->unknown_3704_, (Struct_0201bdac*)var8);
            } else {
                FieldTask_EndLoadZoneMonsters((Obj021b4760*)slot);
                func_02046a8c(self->slotList, slot);
                InitStruct_021b46d8((Struct021b46d8*)slot);
                slot->entry = entry;
                slot->kind = kind;
                slot->value = value;
                AppendNodeToTail(self->slotList, (TailNode020469b4*)slot);
            }
        } else {
            var3->unknown_c2_ |= 0x40;
        }
    }
    if (var6->unknown_0_ == arg2) {
        var6->unknown_0_ = 0;
        var6->unknown_2_ = 0;
    }
}
