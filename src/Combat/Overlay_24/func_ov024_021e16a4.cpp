#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02070b6c_3;
struct Struct_ov024_021e16a4_4 { char pad0[2]; unsigned char kind; };
extern "C" struct Struct_ov024_021e16a4_4* func_02070fd0(struct Struct_02070b6c_3* container, int key);
extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e16a4_5 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021e16a4_6 { char pad[0x24]; struct Struct_ov024_021e16a4_5 f24; };

struct Struct_ov024_021e16a4_7 {
    unsigned short id;
    char pad2[0x14];
    unsigned char used;
    char unknown_17_;
};
struct Struct_ov024_021e16a4_8 { char pad0[0x24]; unsigned char f24; unsigned char f25; };
struct Struct_ov024_021e16a4_9 {
    char pad0[0x81b4];
    struct Struct_ov024_021e16a4_7 records[3];
    char unknown_81fc_[0x8e18 - 0x81fc];
    struct Struct_ov024_021e16a4_8* sub;
};
struct Struct_ov024_021e16a4 { char pad0[0x1c]; unsigned short code; };
struct Struct_ov024_021e16a4_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e16a4_3 {
    char pad0[4];
    struct Struct_ov024_021e16a4* out;
    char pad8[4];
    void* unknown_c_;
    struct Struct_ov024_021e16a4_9* ctx;
    char unknown_14_[0x6e - 0x14];
    unsigned char done;
};

// USA: func_ov024_021e16a4
extern "C" ARM void* func_ov024_021e16a4(struct Struct_ov024_021e16a4_3* obj, int unused, int id, struct Struct_ov024_021e16a4_6* range) {
    GameObject* c = func_ov000_021536f8((int)obj->ctx, id);
    if (!c) return 0;
    if (obj->done == 0) {
        int slot = *((unsigned char*)c + 0x17c);
        if (slot >= 3) return 0;
        struct Struct_ov024_021e16a4_7* rec = &obj->ctx->records[slot];
        struct Struct_ov024_021e16a4_4* e = func_02070fd0(
            (struct Struct_02070b6c_3*)((char*)obj->ctx->sub + 0x684), rec->id);
        if (rec->used != 0 || (e != 0 && e->kind == 7)) {
            obj->out->code = range->f24.c;
            obj->done = 1;
        } else {
            int var4 = 100;
            struct Struct_ov024_021e16a4_8* sub = obj->ctx->sub;
            if (sub != 0 && (sub->f24 != 0 || sub->f25 != 0)) var4 = 50;
            if (NextRandomMax((struct Random*)obj->ctx, 100) < var4) {
                obj->out->code = range->f24.a;
                obj->done = 1;
                rec->used = 1;
            } else {
                obj->out->code = range->f24.c;
                obj->done = 1;
            }
        }
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    struct Struct_ov024_021e16a4_2* var7 = (struct Struct_ov024_021e16a4_2*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0, var7->flag != 0);
    return entry;
}
