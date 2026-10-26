#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov025_021dc324 { char pad0[0x20]; unsigned short id; };
struct Struct_ov025_021dc324_3 { char pad0[0xe]; short id; char pad10[0x10]; Struct_ov025_021dc324_3* next; };
struct Struct_ov025_021dc324_4 { unsigned short id; char pad2[0xe]; Struct_ov025_021dc324* actor; Struct_ov025_021dc324_3* target; };
struct Struct_ov025_021dc324_5 {
    int field0;
    unsigned int id:12, unknown_5_4_:20;
    char pad8[12]; unsigned int unknown_14_0_:28, kind:4;
};
struct Struct_ov025_021dc324_6 { char pad0[0xc00]; char unknown_c00_[0x260]; unsigned char active; };
struct Struct_ov025_021dc324_7 { char pad0[0x5ce]; short delay; char unknown_5d0_[0xe78 - 0x2a8 - 0x5d0]; };
struct Struct_ov025_021dc324_8 { char pad0[0x5800]; Object3D object; };
struct Struct_ov025_021dc324_9 {
    union {
        struct { char pad0[0x18]; Struct_ov025_021dc324_6 body; };
        struct { char unknown1_0_[0x154]; Struct_ov025_021dc324_8 unknown_154_; };
        struct {
            char unknown2_0_[0x29c]; char* battle; char unknown_2a0_[8]; Struct_ov025_021dc324_7 display;
            unsigned char active; char unknown_e79_[0x33]; int state;
            char unknown_eb0_[0x5954 - 0xeb0]; Object3D unknown_5954_;
            Object3D unknown_5a00_; char unknown_5aac_[4]; char task[0x5c3a - 0x5ab0]; unsigned char unknown_5c3a_;
        };
    };
};
struct Struct_ov025_021ef404 { int field0; int active; };
struct Struct_ov025_021dc324_2 { unsigned char flag; char pad1; unsigned short remaining; };
extern Struct_ov025_021ef404 data_ov025_021ef404;
extern "C" Struct_ov025_021dc324_2 _ZZ21inline_ov025_021dcf14vE1s;
extern "C" Struct_ov025_021dc324_4* func_ov000_02160f20(void*);
extern "C" int func_ov025_021ea46c(void*);
extern "C" int func_ov000_0216f0bc(void*);
extern "C" Struct_ov025_021dc324_5* func_02079e2c(char*, int);
extern "C" int func_ov000_02163690(int);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov025_021df5e4(void*, int, int);
extern "C" int func_ov025_021df9f4(GameObject*);
extern "C" int func_0204936c(unsigned char*);
extern "C" void func_0204a030(unsigned char*, int);
extern "C" void GameObject_FaceGameObject(GameObject*, int, int);
extern "C" void func_ov025_021ea474(void*);
extern "C" void func_ov025_021eb6fc(void*, int);

// USA: func_ov025_021dc324
extern "C" ARM void func_ov025_021dc324(Struct_ov025_021dc324_9* self) {
    GameState* game = GameState::GetInstance();
    char* battle = self->battle;
    Struct_ov025_021dc324_6* body;
    Struct_ov025_021dc324_4* slot = func_ov000_02160f20(self);
    body = &self->body;
    if (!func_ov025_021ea46c(&self->display)) return;
    ActionDataTables* data = func_020797dc();
    Struct_ov025_021dc324_8* var5 = &self->unknown_154_;
    if (data_ov025_021ef404.active) {
        if (!func_ov000_0216f0bc(body->unknown_c00_)) return;
        var5->object.MakeHidden();
        self->unknown_5a00_.MakeHidden();
        int special = 0;
        Struct_ov025_021dc324_5* skill = func_02079e2c((char*)data, (short)slot->id);
        if (func_ov000_02163690(slot->id)) special = 1;
        else if (skill) {
            if (skill->kind == 2) special = 1;
            if (skill->id == 0xae) special = 1;
        }
        if (special && slot->actor && slot->target) {
            int var8;
            int actor = slot->actor->id;
            int target = slot->target->id;
            var8 = 1;
            if (func_ov000_0215fc60(battle)) {
                if (actor == 0) var8 = 0;
            }
            if (!body->active) var8 = 0;
            if (var8) {
                func_ov025_021df5e4(self->task, actor, target);
            }
            GameObject* combatant = game->GetCombatantByIndex(target);
            if (func_ov025_021df9f4(combatant)) {
                if (skill->id == 0xae && func_0204936c((unsigned char*)combatant)) return;
                if (_ZZ21inline_ov025_021dcf14vE1s.flag) func_0204a030((unsigned char*)combatant, actor);
                else GameObject_FaceGameObject(combatant, actor, 1);
            }
        }
        if (!self->unknown_5c3a_) self->state = 3;
        func_ov025_021ea474(&self->display);
        data_ov025_021ef404.active = 0;
        _ZZ21inline_ov025_021dcf14vE1s.remaining = 0;
    } else {
        unsigned int elapsed = game->GetEffectiveDeltaTime();
        if (_ZZ21inline_ov025_021dcf14vE1s.remaining < elapsed) {
            Struct_ov025_021dc324_3* target;
            GameState* var14 = GameState::GetInstance();
            target = slot->target;
            int var15;
            while (target) {
                GameObject* combatant = var14->GetCombatantByIndex(target->id);
                if (combatant && func_0204936c((unsigned char*)combatant)) { var15 = 0; goto readinessDone; }
                target = target->next;
            }
            var15 = 1;
        readinessDone:
            if (var15) self->state = 3;
        } else _ZZ21inline_ov025_021dcf14vE1s.remaining -= elapsed;
    }
    if (slot->id == 0xdb) { self->display.delay = 750; return; }
    func_ov025_021eb6fc(&self->display, 0);
}
