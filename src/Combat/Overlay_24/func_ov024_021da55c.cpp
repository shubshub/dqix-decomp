#include <globaldefs.h>

struct Struct_020e6d5c_10 {
    unsigned int a;
    unsigned int b;
};
extern struct Struct_020e6d5c_10 __ptmf_null;

extern unsigned int data_ov024_02200140;

struct Struct_ov024_021ff1e0 {
    unsigned int fn;
    unsigned int unknown_4_;
};
extern struct Struct_ov024_021ff1e0 data_ov024_021ff1e0[0x43];

struct Struct_ov024_021da55c {
    char unk_0[0x18];
    unsigned int unknown_18_0_ : 18;
    unsigned int unknown_1a_2_ : 9;
    unsigned int unknown_1b_3_ : 5;
};

typedef int (*Type_ov024_021da55c)(void* self, int a2, int a3, unsigned short a4, struct Struct_ov024_021da55c* action, int fallback);

// USA: func_ov024_021da55c
extern "C" ARM int func_ov024_021da55c(int* obj, int a1, int a2, int a3, unsigned short a4, struct Struct_ov024_021da55c* action, int arg6) {
    unsigned int flags = data_ov024_02200140;
    if (!(flags & 1)) {
        struct Struct_020e6d5c_10 var1 = __ptmf_null;
        data_ov024_021ff1e0[0].fn = var1.a;
        data_ov024_021ff1e0[0].unknown_4_ = var1.b;
        data_ov024_021ff1e0[46].fn = var1.a;
        data_ov024_021ff1e0[46].unknown_4_ = var1.b;
        data_ov024_021ff1e0[51].fn = var1.a;
        data_ov024_021ff1e0[51].unknown_4_ = var1.b;
        data_ov024_021ff1e0[53].fn = var1.a;
        data_ov024_021ff1e0[53].unknown_4_ = var1.b;
        data_ov024_02200140 = flags | 1;
    }
    *obj = a1;
    if (action == NULL) {
        return arg6;
    }
    unsigned int idx = action->unknown_1a_2_;
    if (idx >= 0x43) {
        return arg6;
    }
    if (data_ov024_021ff1e0[idx].fn == 0) {
        return arg6;
    }
    struct Struct_ov024_021ff1e0* d = &data_ov024_021ff1e0[idx];
    void* base = (char*)obj + ((int)d->unknown_4_ >> 1);
    Type_ov024_021da55c callback;
    if (d->unknown_4_ & 1) {
        callback = *(Type_ov024_021da55c*)((char*)*(void**)base + d->fn);
    } else {
        callback = (Type_ov024_021da55c)d->fn;
    }
    return callback(base, a2, a3, a4, action, arg6);
}
