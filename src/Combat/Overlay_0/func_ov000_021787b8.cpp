#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205ba68;
struct Struct_0205bacc;

struct Struct_ov000_02178074_4 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
};
struct Struct_ov000_021787b8_2 {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[0xa];
};
struct Struct_ov000_021787b8_3 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x48];
};
struct Struct_ov000_021787b8_4 {
    char unknown_0_[0x188];
    Struct_ov000_021787b8_2 unknown_188_;
    Struct_ov000_021787b8_3 unknown_244_;
};

TextWorkspace* GetGlobalField0x1c020421a0();
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);
extern "C" int func_ov000_0217538c(void* objRaw);
extern "C" int func_ov000_021753d8(void* objRaw, int targetIndex);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02178938(void* obj, void* in, int b, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

struct Struct_ov000_021787b8 {
    char unknown_0_[0x1d];
    signed char unknown_1d_;
    char unknown_1e_[0x44 - 0x1e];
    int unknown_44_;
    int unknown_48_;
};

// USA: func_ov000_021787b8
extern "C" ARM void func_ov000_021787b8(Struct_ov000_021787b8_4* arg0, struct Struct_ov000_021787b8* arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        return;
    }
    int var0 = arg1->unknown_44_;
    int var1 = arg1->unknown_48_;
    int var2 = func_ov000_0217538c(arg0);
    int var3 = func_ov000_021753d8(arg0, arg1->unknown_1d_);
    func_ov000_0217ab8c(arg1, arg2, arg3);
    Struct_ov000_021787b8_2* var4 = &arg0->unknown_188_;
#if defined(jpn)
    var4->unknown_a0_ = 1;
#else
    var4->unknown_a0_ = 0x10;
#endif
    var4->unknown_a2_ = 1;
    var4->unknown_a4_ = (var0 >> 3) + 0xe;
#if defined(jpn)
    var4->unknown_a6_ = (var1 >> 3) + 1;
#else
    var4->unknown_a6_ = var1 >> 3;
#endif
    panel->fieldA8 = 0xc;
    panel->fieldAA = 6;
    panel->fieldAC = 0xa;
    panel->fieldAE = 0x10;
    panel->elementId = 0xe;
    GridCursor_SetDimensions((struct Struct_0205ba68*)&menu->groups, 1, groupCount, 0);
    menu->groups.pages = 1;
    GridCursor_SetCount((struct Node0205bacc*)&menu->groups, groupCount);
    GridCursor_SetSelectedIndex(&menu->groups, group);
    char* text = GetGlobalField0x1c020421a0()->textBuffer;
#if defined(jpn)
    memset(var5, 0, 0x800);
#else
    memset(var5, 0, 0x960);
#endif
    func_ov000_02178938(arg0, arg1, arg3, var5);
#if defined(jpn)
    func_0205d304(var4, var5, 0, 1, 0, 1, 0);
#else
    func_0205d304(var4, var5, 0, 1, 0, 1, 0, 0);
#endif
}
