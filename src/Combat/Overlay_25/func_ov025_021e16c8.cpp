#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov025_021e16c8 { char pad0[0x10]; unsigned int flags_; };
struct Struct_ov025_021e16c8_2 : GameObject { char unknown_13c_[0xc]; Struct_ov025_021e16c8* unknown_148_; };
struct FormationEntry { unsigned char id_, unknown_1_; char pad2[6]; Struct_ov025_021e16c8_2* actor_; };
struct Struct_ov025_021e16c8_4 { char pad0[0x20]; unsigned short actor_; char unknown_22_[0xe]; Struct_ov025_021e16c8_4* unknown_30_; };
struct Struct_ov025_021e16c8_5 { short id_; char pad2[0xe]; Struct_ov025_021e16c8_4* unknown_10_; };
struct Struct_ov025_021e16c8_6 { char pad0[0x18]; unsigned int flags_; };
struct Struct_ov025_021e16c8_7 { unsigned char unknown_0_[6]; };
struct Struct_01ff8b48_16 { int unknown_0_[3]; int adjacent_; };
inline int* inline_ov025_021dcf14() { static Struct_01ff8b48_16 s __attribute__((aligned(4))); return &s.adjacent_; }
extern "C" void func_ov025_021e169c(unsigned char*, int);
extern "C" unsigned char func_020493a4(unsigned char*);
extern "C" unsigned int func_020493c8(unsigned char*);
extern "C" unsigned int func_020493ec(unsigned char*);
extern "C" void func_020493b8(unsigned char*, unsigned char);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049458(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" void func_ov000_0216f82c(Struct_ov025_021e16c8_7*, const int*);
extern "C" void func_ov025_021e1ff4(Struct_ov025_021e16c8_7*, int, unsigned char*, Struct_ov025_021e16c8_2*, Struct_ov025_021e16c8_2*, void*, void*);
extern "C" void func_ov025_021e120c(unsigned char*, int, unsigned char, unsigned char, int);
extern "C" void func_ov025_021e12f8(unsigned char*, int, int, unsigned char, int, int);
extern "C" void func_ov025_021e13e0(unsigned char*, FormationEntry*);
extern "C" unsigned int func_ov025_021e161c(int, int, unsigned char*, int);
extern "C" void func_ov025_021e1c20(int, unsigned char*, unsigned char*, int, void*, void*, FormationEntry*);
extern "C" unsigned char func_ov025_021e1480(int, unsigned char*, int);
extern "C" Struct_ov025_021e16c8_6* func_02079e2c(char*, int);

static inline int ActorID(FormationEntry* entry) { return entry->actor_->obj3D_.actorIndex_; }
static inline void inline_ov025_021e120c_2(unsigned char* cells, unsigned int index, unsigned char value) {
    if (index < 81) cells[index] = value;
}

// USA: func_ov025_021e16c8
extern "C" ARM void func_ov025_021e16c8(FormationEntry* self, FormationEntry* target, unsigned char* cells,
    Struct_ov025_021e16c8_5* lists, Struct_ov025_021e16c8_6* action, void* work, void* context) {
    unsigned char var0[81];
    unsigned char occupied[81];
    unsigned char var2[81];
    unsigned char var3[12];
    Struct_ov025_021e16c8_7 range;
    unsigned char var5[6];
    Struct_ov025_021e16c8_7 var6;
    func_ov025_021e169c(cells, self->unknown_1_);
    memcpy(var0, cells, 81);
    memset(occupied, 0, 81);
    int var7 = 0;
    for (Struct_ov025_021e16c8_4* node = lists->unknown_10_; node; node = node->unknown_30_) {
        if (node->actor_ == ActorID(self)) { var7 = 1; break; }
    }
    unsigned int position = func_020493a4((unsigned char*)target->actor_);
    if (!var7) {
        position = func_020493ec((unsigned char*)target->actor_);
        if (position == 255) position = func_020493c8((unsigned char*)target->actor_);
        if (position == 255) position = func_020493a4((unsigned char*)target->actor_);
    } else {
        int packed = func_ov025_021e1540(target->id_);
        func_ov000_0216f82c(&var6, &packed);
        range = var6;
        func_ov025_021e1ff4(&range, 6, cells, self->actor_, target->actor_, work, context);
    }
    Struct_ov025_021e16c8* formation = 0;
    int distance = 2;
    int radius = 1;
    if (target->actor_->obj3D_.unknown_0_ & 0x400) formation = target->actor_->unknown_148_;
    if (formation) {
        unsigned int extension = (formation->flags_ << 1) >> 30;
        if (extension) { distance += extension; radius += extension; }
    }
    func_ov025_021e120c(var0, position, distance, radius, 0);
    if (var7) {
        func_ov025_021e120c(occupied, position, distance, radius, 0);
        inline_ov025_021e120c_2(occupied, position, target->unknown_1_);
        unsigned int extension = 0;
        if (formation) {
            unsigned int value = (formation->flags_ << 1) >> 30;
            if (value) extension = value;
        }
        func_ov025_021e12f8(occupied, position, target->unknown_1_, extension, (unsigned char)radius, 0);
    }
    if (formation) {
        unsigned int extension = (formation->flags_ << 1) >> 30;
        if (extension) func_ov025_021e12f8(var0, position, self->unknown_1_, extension, 0, 0);
    }
    int var18 = 0;
    if (var7) {
        int var19 = var0[func_020493a4((unsigned char*)self->actor_)];
        if ((action->flags_ << 16) >> 28 == 2) {
            if (distance == var19) var18 = 1;
        } else if (var19 > 0 && var19 <= distance) {
            var18 = 1;
            if (distance - 1 == var0[func_020493a4((unsigned char*)self->actor_)]) {
                int value = 1;
                int* var21 = inline_ov025_021dcf14();
                *var21 = value;
            }
        }
    } else if (distance == var0[func_020493a4((unsigned char*)self->actor_)]) var18 = 1;
    if (var18) {
        func_ov025_021e13e0(cells, self);
        if (var7) {
            unsigned int alternate = func_ov025_021e161c(func_020493a4((unsigned char*)self->actor_), position, var0, distance);
            if (alternate != 255) {
                func_020493dc((unsigned char*)self->actor_, alternate);
                inline_ov025_021e120c_2(cells, (unsigned char)alternate, self->unknown_1_);
            }
            func_ov025_021e1c20(func_020493a4((unsigned char*)self->actor_), cells, occupied, distance, work, context, self);
        }
        return;
    }
    unsigned char var23 = 0;
    unsigned char var24 = 0;
    for (int i = 0; i < 81; ++i) {
        if (var0[i] == distance - 1) var5[var23++] = i;
        else if (var0[i] == distance) var3[var24++] = i;
    }
    unsigned char selected = 255;
    if (var24 == 1) selected = var3[0];
    else if (var24 > 1) selected = func_ov025_021e1480(func_020493a4((unsigned char*)self->actor_), var3, var24);
    else if (var23 == 1) selected = var5[0];
    else if (var23 > 1) selected = func_ov025_021e1480(func_020493a4((unsigned char*)self->actor_), var5, var23);
    if (var7) {
        Struct_ov025_021e16c8_6* record = func_02079e2c((char*)func_020797dc(), lists->id_);
        if (record && (record->flags_ << 16) >> 28 != 2) {
            memset(var2, 0, 81);
            func_ov025_021e120c(var2, position, 1, radius, 0);
            int current = func_020493a4((unsigned char*)self->actor_);
            if ((current < 81 && var2[current] == 1) || position == current) selected = (unsigned char)current;
        }
    }
    if (selected >= 81) selected = func_020493a4((unsigned char*)self->actor_);
    func_020493b8((unsigned char*)self->actor_, selected);
    if (selected < 81) inline_ov025_021e120c_2(cells, selected, self->unknown_1_);
    if (var7) {
        unsigned int alternate = func_ov025_021e161c(selected, position, var0, distance);
        if (alternate != 255) {
            func_020493dc((unsigned char*)self->actor_, alternate);
            inline_ov025_021e120c_2(cells, (unsigned char)alternate, self->unknown_1_);
        }
    }
    if (var7) func_ov025_021e1c20(selected, cells, occupied, distance, work, context, self);
    func_02049458((unsigned char*)self->actor_, target->id_);
}
