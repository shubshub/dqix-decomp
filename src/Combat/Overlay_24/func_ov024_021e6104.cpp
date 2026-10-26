#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;
struct Struct_ov024_021e6104_5 { int lo; int hi; };

extern "C" int func_020850fc(unsigned char* obj);
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" void* func_ov000_0215fff4(void* obj, int limit, int idx);
extern "C" short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021e6104_5* words, int effect);
extern "C" void func_ov000_0215ccbc(
    int unused, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    struct Struct_ov024_021e6104_5 words, unsigned char arg7);
extern "C" void func_ov000_0215fe84(void* obj, void* node, int idx);

struct Struct_ov000_0215440c { char pad0[9]; unsigned char count; };
struct Struct_ov000_021600f8 { char pad0[0x18]; unsigned char depth; };
struct Struct_ov024_021e6104 { char pad0[0xc]; short value; };
struct Struct_ov024_021e6104_2 {
#if defined(jpn)
 char pad0[0x144];
#else
 char pad0[0x150];
#endif
 unsigned char* ext; };
struct Struct_ov024_021e6104_3 { char pad0[0x10]; int flags; };
struct Struct_ov024_021e6104_4 {
    char pad0[4];
    struct Struct_ov000_0215440c* list;
    void* unknown_8_;
    char unknown_c_[4];
    void* ctx;
};

static inline short inline_ov000_021584e8_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

static inline unsigned short inline_ov000_021584e8(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }

static inline unsigned short MaxHP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.maxHP; }

static inline int inline_ov024_021ddf5c(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e6104
extern "C" ARM int func_ov024_021e6104(struct Struct_ov024_021e6104_4* obj, int id, struct Struct_ov024_021e6104_3* skill) {
    GameObject* c = func_0200ff1c(GameState::GetInstance(), id);
    if (!c) return 0;
    if ((skill->flags & 0x400000) && inline_ov024_021ddf5c(id) && func_020850fc(((struct Struct_ov024_021e6104_2*)c)->ext)) {
        int total = 0;
        for (int i = 0; i < obj->list->count; i++) {
            struct Struct_ov000_021600f8* node = func_ov000_021600f8(obj->list, i);
            if (!node) continue;
            for (int j = 0; j < node->depth; j++) {
                struct Struct_ov024_021e6104* d = (struct Struct_ov024_021e6104*)func_ov000_0215fff4(node, j, 0);
                if (d) total += d->value;
            }
        }
        int var6 = total >> 2;
        if (var6 > 0 && inline_ov000_021584e8(c) < MaxHP(c)) {
            short var7 = 0;
            short hp = func_ov000_0215a16c(obj->ctx, id, var6, &var7);
            struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
            if (!entry) return 0;
            func_ov000_0215a88c(obj->ctx, entry, 0x215);
            struct Struct_ov024_021e6104_5 words;
            words.lo = 0;
            words.hi = 0;
            func_ov000_02159eac(obj->ctx, &words, 0x25);
            func_ov000_0215ccbc((int)obj->ctx, entry, c, -var7, hp,
                inline_ov000_021584e8_2(c), words, 0);
            func_ov000_0215fe84(obj->unknown_8_, entry, 3);
            ((unsigned char*)obj->ctx)[0x8e02]++;
        }
    }
    return 0;
}
