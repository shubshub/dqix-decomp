#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02088f68;

struct Struct_ov024_021e05fc {
    unsigned int unknown_0_0_ : 10;
    unsigned int pad : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int rest : 2;
};

struct Struct_ov024_021e05fc_2 {
    char pad0[0x24];
    struct Struct_ov024_021e05fc msgs;
};

struct Struct_ov024_021e05fc_3 {
    char pad0[0xc];
    int fc;
};

struct Struct_ov024_021e05fc_4 { unsigned char pad : 7; unsigned char flag : 1; };

struct Struct_ov024_021e05fc_5 {
    char pad0[0xc];
    void* fc;
    void* f10;
};

extern "C" signed char func_ov000_02159e60(void* obj, int mode);
extern "C" void func_ov000_021554f4(void* world, int id, int other, struct Struct_ov024_021e05fc_2* rec, int a4, int a5);
extern "C" void func_02088f68(struct Struct_02088f68* obj);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" void* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long bits, int flag);

// USA: func_ov024_021e05fc
extern "C" ARM void* func_ov024_021e05fc(struct Struct_ov024_021e05fc_5* obj, int other, int id, struct Struct_ov024_021e05fc_2* rec) {
    GameObject* c = GetCombatantByID((int)obj->f10, id);
    if (!c) return 0;
    GameState::GetInstance();
    int var1 = func_ov000_02159e60(obj->f10, id);
    int var2 = func_ov000_02159e60(obj->f10, other);
    int ok = 0;
    if (var2 > var1) {
        if (var2 - var1 >= 7) ok = 1;
    }
    struct Struct_ov024_021e05fc_3* pending = *(struct Struct_ov024_021e05fc_3**)((char*)obj->f10 + 0x8e18);
    if (pending) {
        if (pending->fc >= 0) ok = 0;
    }
    int count = *(unsigned char*)((char*)c->currentStats_ + 0x48);
    unsigned short msg = 0;
    unsigned long long bits = 0;
    if (count >= 1 && ok) {
        GameObject* t = GetCombatantByID((int)obj->f10, id);
        if (t) {
            msg = rec->msgs.unknown_0_0_;
            func_ov000_021554f4(obj->f10, id, other, rec, 0, 4);
            t->currentStats_->primaryStats.currHP = 0;
            func_02088f68((struct Struct_02088f68*)t->currentStats_);
            func_ov000_02159eac(obj->f10, &bits, 0x24);
            ((unsigned char*)obj->f10)[0x8e15]++;
        }
    } else {
        msg = rec->msgs.unknown_2_4_;
    }
    void* entry = func_ov000_0215e958(obj->f10);
    if (!entry) return 0;
    func_ov000_0215a88c(obj->f10, entry, msg);
    struct Struct_ov024_021e05fc_4* var10 = (struct Struct_ov024_021e05fc_4*)((char*)obj->fc + 0x1c);
    func_ov000_0215cd44(obj->f10, entry, c, 0, bits, var10->flag != 0);
    return entry;
}
