#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_0217e1e4_144 = 0x8c };
#else
enum { Enum_ov003_0217e1e4_144 = 0x90 };
#endif

struct Struct_0205d0e0 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);

struct Struct_0205c4a8;
extern "C" void func_0205c4a8(struct Struct_0205c4a8* arg0, int arg1);
struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
struct Struct_0205bcdc;
extern "C" void func_0205bcdc(struct Struct_0205bcdc* arg0, int arg1);
extern "C" void func_0205bb04(void* arg0, int arg1);

struct Struct_ov003_0217e1e4 {
    char unknown_0_[0x4];
    char unknown_4_[0x50];
    char unknown_54_[0x40];
};

struct Struct_ov003_0217e1e4_2 {
    char unknown_0_[Enum_ov003_0217e1e4_144];
    struct Struct_ov003_0217e1e4* unknown_90_;
};

// USA: func_ov003_0217e1e4
extern "C" ARM int func_ov003_0217e1e4(struct Struct_ov003_0217e1e4_2* arg0) {
    int var0;
    int var1;
    if (g_touchInput.pressed_ == 0) {
        goto fail;
    }
    g_touchInput.GetTouchPoint(&var0, &var1);
    struct Struct_0205d0e0* var2 = func_0205d81c((struct Struct_0205d81c*)arg0->unknown_90_, 0);
    if (var2 == NULL) {
        goto fail;
    }
    short var3 = var2->unknown_ac_;
    short var4 = var2->unknown_ae_;
    short var5 = var2->unknown_aa_;
    var3 += var2->unknown_a8_;
    var4 += var5;
    var4 <<= 3;
    if (var4 - 16 <= var1 && var1 < var4) {
        struct Struct_ov003_0217e1e4* var6 = arg0->unknown_90_;
        short var7 = var2->unknown_ac_ << 3;
        if (var0 >= var7 && var0 < var7 + 16) {
            func_0205c4a8((struct Struct_0205c4a8*)var6->unknown_54_, -1);
        }
        var3 <<= 3;
        if (var3 - 16 <= var0 && var0 < var3) {
            func_0205c4a8((struct Struct_0205c4a8*)var6->unknown_54_, 1);
        }
        int index = GridCursor_GetSelectedIndex((struct Struct_0205bb84*)list->scrollState);
        SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)list->indexState, index);
        func_0205bb04(list->scrollState, index);
    }
    return 1;
fail:
    return 0;
}
