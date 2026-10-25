#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Struct_0205d5d0;

struct Struct_0205d0e0 {
    char unknown_0_[0xc2];
    short unknown_c2_;
};

struct Struct_ov000_02178074 {
    char unknown_0_[0x58];
    int unknown_58_;
    char unknown_5c_[0x44];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02178074_2 {
    char unknown_0_[0x188];
    struct Struct_ov000_02178074 unknown_188_;
};

struct Struct_ov000_02178074_3 {
    char unknown_0_[0x44];
    int unknown_44_;
    int unknown_48_;
};

struct Struct_ov000_02178074_4 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
};

TextWorkspace* MessageSystem_GetInstance();
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_021781f8(struct Owner_02178074* obj, struct InStruct_02178074* in);
extern "C" void func_ov000_0217c638(struct Owner_02178074* obj, int a, int b);
extern "C" void func_ov000_0217831c(struct Owner_02178074* obj, void* textBuffer);
extern "C" void func_ov000_02176210(struct Panel_02178074* panel, int slot, int key);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02178074
extern "C" ARM void func_ov000_02178074(struct Struct_ov000_02178074_2* arg0, struct Struct_ov000_02178074_3* arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        return;
    }
    int var0 = arg1->unknown_44_;
    int var1 = arg1->unknown_48_;
    func_ov000_021781f8(arg0, arg1);
    func_ov000_0217c638(arg0, arg2, arg3);
    struct Struct_ov000_02178074* var2 = &arg0->unknown_188_;
#if defined(jpn)
    var2->unknown_a0_ = 0x10;
#else
    var2->unknown_a0_ = 0x12;
#endif
    var2->unknown_a2_ = 9;
#if defined(jpn)
    var2->unknown_a4_ = (var0 >> 3) + 9;
#else
    var2->unknown_a4_ = (var0 >> 3) + 0xe;
#endif
    var2->unknown_a6_ = var1 >> 3;
    var2->unknown_a8_ = 0xc;
    var2->unknown_aa_ = 8;
    var2->unknown_ac_ = 0xa;
    var2->unknown_ae_ = 0xc;
    var2->unknown_b1_ = 7;
#if defined(jpn)
    char* var4;
#endif
    int var3 = var2->unknown_58_;
#if defined(jpn)
    textBuffer = MessageSystem_GetInstance()->textBuffer;
#else
    char* textBuffer = MessageSystem_GetInstance()->textBuffer;
#endif
#if defined(jpn)
    memset(var4, 0, 0x800);
#else
    memset(var4, 0, 0x960);
#endif
    func_ov000_0217831c(arg0, var4);
    int var5 = (var3 > 1) ? 1 : 0;
#if defined(jpn)
    Window_OpenPane(&obj->panel, textBuffer, 0, 0, multiplePages, 1, 0);
#else
    Window_OpenPane(panel, textBuffer, 0, 0, multiplePages, 1, 0, 0);
#endif
    struct Struct_0205d0e0* var6 = func_0205d81c((struct Struct_0205d81c*)var2, 0x21);
    if (var6 != 0) {
        var6->unknown_c2_ = 0;
    }
#if defined(jpn)
    func_ov000_02176210(&arg0->unknown_188_, 7, 0x21);
#else
    func_ov000_02176210(var2, 7, 0x21);
#endif
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)&obj->panel, 7, (int)textBuffer, 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)panel, 7, (int)textBuffer, 1, 0);
#endif
}
