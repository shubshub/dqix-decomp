#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

struct Struct_ov025_021e2f54_3 {
    char pad0[0x1c4];
    unsigned int flags;
    char unknown_1c8_[0x22c - 0x1c8];
    char queue[4];
};

struct Struct_ov025_021ef988_5 {
#if defined(jpn)
    char pad0[4];
#else
    char pad0[0xc];
#endif
    struct Struct_ov025_021e2f54_3* ctx;
};

struct Struct_ov025_021e2f54 {
    char pad0[0x14];
    unsigned int : 28;
    unsigned int kind : 4;
};

struct Struct_ov025_021e2f54_2 {
    char pad0[0x26];
    unsigned short state;
};

struct Struct_ov000_0215440c;

extern struct Struct_ov025_021ef988_5 data_ov025_021ef988;

extern "C" struct Struct_ov025_021e2f54* func_02079e2c(char* p, int key);
extern "C" void* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021ecc54(void* queue, struct Struct_ov025_021e2f54_2* ev);
extern "C" int func_ov000_0215fc60(char* base);

static inline int inline_ov025_021e2f54(void* node) {
    return func_ov000_0215ffa0(node) >= 0xc0 && func_ov000_0215ffa0(node) <= 0xc7;
}

// USA: func_ov025_021e2f54
extern "C" ARM void func_ov025_021e2f54(struct Struct_ov025_021e2f54_2* ev, short* list, char* world) {
    struct Struct_ov025_021e2f54_3* ctx = data_ov025_021ef988.ctx;
    struct Struct_ov025_021e2f54* rec = func_02079e2c((char*)func_020797dc(), *list);
    void* node = func_ov000_021600f8((struct Struct_ov000_0215440c*)list, 0);
    if (rec != 0 && node != 0) {
        if (inline_ov025_021e2f54(node) && rec->kind == 4) {
            ev->state |= 8;
            func_ov025_021ecc54(ctx->queue, ev);
            ev->state = 7;
            func_ov025_021ecc54(ctx->queue, ev);
        } else {
            func_ov025_021ecc54(ctx->queue, ev);
        }
    } else {
        func_ov025_021ecc54(ctx->queue, ev);
    }
    if (func_ov000_0215fc60(world) != 0) {
        data_ov025_021ef988.ctx->flags |= 0x10;
    }
}
