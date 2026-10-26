#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov024_021e56c0 { int lo; int hi; };

extern "C" short func_ov000_0215a1d4(void* unused, int id, int delta, short* arg3);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021e56c0* words, int effect);
extern "C" void func_ov000_0215ccbc(
    int unused, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    struct Struct_ov024_021e56c0 words, unsigned char arg7);
extern "C" void func_ov000_0215fe84(void* obj, void* node, int idx);

struct Struct_ov024_021e56c0_2 { char pad[0x24]; short mp; };
struct Struct_ov024_021e56c0_3 {
    char pad0[8];
    struct Struct_ov024_021e56c0_2* unknown_8_;
    char pad1[4];
    void* ctx;
};

// USA: func_ov024_021e56c0
extern "C" ARM void func_ov024_021e56c0(struct Struct_ov024_021e56c0_3* obj, int id, int unused, int value) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return;
    int amount = value >> 3;
    if (amount <= 0) return;
    short var2 = 0;
    short mp = func_ov000_0215a1d4(obj->ctx, id, amount, &var2);
    obj->unknown_8_->mp = mp;
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return;
    func_ov000_0215a88c(obj->ctx, entry, 0x214);
    struct Struct_ov024_021e56c0 words;
    words.lo = 0;
    words.hi = 0;
    func_ov000_02159eac(obj->ctx, &words, 0x22);
    func_ov000_0215ccbc((int)obj->ctx, entry, c, -amount,
        c->currentStats_->primaryStats.currHP, mp, words, 0);
    func_ov000_0215fe84(obj->unknown_8_, entry, 2);
    ((unsigned char*)obj->ctx)[0x8e02]++;
}
