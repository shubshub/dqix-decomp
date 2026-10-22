#include <globaldefs.h>

struct Struct_020e6d5c_10 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
};
extern struct Pair_021da55c __ptmf_null;

extern unsigned int data_ov024_02200140;

struct Struct_ov024_021ff1e0 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
};
extern struct Struct_ov024_021ff1e0 data_ov024_021ff1e0[0x43];

struct Struct_ov024_021da55c {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 18;
    unsigned int unknown_1a_2_ : 9;
    unsigned int unknown_1b_3_ : 5;
};

typedef int (*Type_ov024_021da55c)(void* self, int a2, int a3, unsigned short a4, struct Struct_ov024_021da55c* action, int fallback);

// USA: func_ov024_021da55c
extern "C" ARM int func_ov024_021da55c(int* obj, int a1, int a2, int a3, unsigned short a4, struct Action_021da55c* action, int fallback) {
    unsigned int flags = data_ov024_02200140;
    if (!(flags & 1)) {
        struct Pair_021da55c nullEntry = __ptmf_null;
        data_ov024_021ff1e0[0].fn = nullEntry.a;
        data_ov024_021ff1e0[0].locator = nullEntry.b;
        data_ov024_021ff1e0[46].fn = nullEntry.a;
        data_ov024_021ff1e0[46].locator = nullEntry.b;
        data_ov024_021ff1e0[51].fn = nullEntry.a;
        data_ov024_021ff1e0[51].locator = nullEntry.b;
        data_ov024_021ff1e0[53].fn = nullEntry.a;
        data_ov024_021ff1e0[53].locator = nullEntry.b;
        data_ov024_02200140 = flags | 1;
    }
    *arg0 = arg1;
    if (arg5 == NULL) {
        return arg6;
    }
    unsigned int var2 = arg5->unknown_1a_2_;
    if (var2 >= 0x43) {
        return arg6;
    }
    if (data_ov024_021ff1e0[var2].unknown_0_ == 0) {
        return arg6;
    }
    struct Struct_ov024_021ff1e0* var3 = &data_ov024_021ff1e0[var2];
    void* var4 = (char*)arg0 + ((int)var3->unknown_4_ >> 1);
    Type_ov024_021da55c var5;
    if (var3->unknown_4_ & 1) {
        var5 = *(Type_ov024_021da55c*)((char*)*(void**)var4 + var3->unknown_0_);
    } else {
        var5 = (Type_ov024_021da55c)var3->unknown_0_;
    }
    return var5(var4, arg2, arg3, arg4, arg5, arg6);
}
