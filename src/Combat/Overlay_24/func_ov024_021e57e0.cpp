#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021e57e0 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Struct_ov024_021e57e0_2 {
    char pad0[4];
    struct Struct_ov024_021e57e0 f4;
};

struct Struct_ov024_021e57e0_3 {
    char pad0[0x14];
    unsigned char slots[3];
    unsigned char unknown_17_;
};

struct Struct_ov000_0215440c;

struct Struct_ov024_021e57e0_4 {
    int f0;
    struct Struct_ov000_0215440c* f4;
    void* f8;
    char pad0[4];
    void* f10;
};

struct Struct_ov000_021584e8;

extern "C" struct Struct_ov024_021e57e0_3* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" short func_ov000_0215a004(void* world, int arg1, int id2, int value, unsigned long long* bits, struct Struct_ov024_021e57e0_2* rec, int a6, int a7);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* world);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);
extern "C" void func_ov000_0215fe84(void* arg0, void* node, int idx);

static inline short inline_ov024_021e57e0(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov024_021e57e0
extern "C" ARM void func_ov024_021e57e0(struct Struct_ov024_021e57e0_4* self, int id, struct Struct_ov024_021e57e0_2* rec) {
    GameObject* c = GetCombatantByID((int)self->f10, id);
    if (!c) return;
    if (rec->f4.id == 0xaf) {
        struct Struct_ov024_021e57e0_3* node = func_ov000_021600f8(self->f4, 0);
        for (int i = 1; i < node->unknown_17_; i++) {
            if (node->slots[i] == 3) return;
        }
    }
    int var3;
    struct Struct_ov000_021584e8* entry;
    int var5;
    short result;
    int value;
    value = *(int*)((char*)self->f10 + 0x8e38);
    unsigned long long bits = 0;
    result = func_ov000_0215a004(self->f10, id, id, value, &bits, rec, 0, 0);
    entry = func_ov000_0215e958(self->f10);
    if (!entry) return;
    if (value > 0) var3 = 0x1b4; else var3 = 0x165;
    var5 = 0;
    if (func_ov000_02159f18(self->f10, bits, 2)) {
        if (rec->f4.id == 0xaf) var5 = 0x1b3; else var5 = 0x117;
    }
    if (var3) func_ov000_0215a88c(self->f10, entry, var3);
    if (var5) func_ov000_0215a88c(self->f10, entry, var5);
    func_ov000_0215ccbc((int)self->f10, entry, c, value, result, inline_ov024_021e57e0(c), bits, 0);
    func_ov000_0215fe84(self->f8, entry, 2);
    ((unsigned char*)self->f10)[0x8e02]++;
}
