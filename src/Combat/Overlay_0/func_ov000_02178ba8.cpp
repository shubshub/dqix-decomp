#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Struct_0205d0e0 {
    char unknown_0_[0xc2];
    short unknown_c2_;
};

struct Struct_0205d81c {
    char unknown_0_[0x54];
    int unknown_54_;
    char unknown_58_[0xa0 - 0x58];
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

struct Struct_ov000_02178ba8 {
    char unknown_0_[REGION_OFFSET_0];
    void* unknown_5c_;
};

struct Struct_ov000_02178ba8_2 {
    char unknown_0_[0x44];
    int unknown_44_;
    int unknown_48_;
};

struct Struct_ov000_02178ba8_3 {
    char unknown_0_[0x188];
    Struct_0205d81c unknown_188_;
};

GlobalField1c* MessageSystem_GetInstance();
int GridCursor_GetCount(void* obj);
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void func_ov000_02178d28(Obj02178ba8* obj, Entry02178ba8* entry);
extern "C" void func_ov000_0217ab8c(Entry02178ba8* entry, int a, int b);
extern "C" void func_ov000_02178f28(Obj02178ba8* obj, Entry02178ba8* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void func_ov000_02176210(Struct_0205d81c* arg0, int arg1, int arg2);

// USA: func_ov000_02178ba8
extern "C" ARM void func_ov000_02178ba8(Struct_ov000_02178ba8_3* arg0, Struct_ov000_02178ba8_2* arg1, int arg2, int arg3) {
    func_ov000_02178d28(arg0, arg1);
    int var0 = arg1->unknown_44_;
    int var1 = arg1->unknown_48_;
    func_ov000_0217ab8c(arg1, arg2, arg3);
    Struct_0205d81c* var2 = &arg0->unknown_188_;
#if defined(jpn)
    var2->unknown_a0_ = 0xd;
#else
    var2->unknown_a0_ = 0x10;
#endif
    var2->unknown_a2_ = 9;
#if defined(jpn)
    var2->unknown_a4_ = (var0 >> 3) + 9;
#else
    var2->unknown_a4_ = (var0 >> 3) + 0x10;
#endif
    panel->y = y >> 3;
    panel->fieldA8 = 0xc;
    panel->fieldAA = 8;
    panel->fieldAC = 0xa;
    panel->fieldAE = 0xc;
    panel->fieldB1 = 0xf;
    int flag = 0;
    if (GridCursor_GetCount(&panel->field54) > 4) {
        flag = 1;
    }
    void* buf = MessageSystem_GetInstance()->buffer;
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02178f28(obj, entry, buf);
#if defined(jpn)
    Window_OpenPane(panel, buf, 0, 0, flag, 1, 0);
#else
    Window_OpenPane(panel, buf, 0, 0, flag, 1, 0, 0);
#endif
    Struct_0205d0e0* var5 = func_0205d81c(var2, 0x22);
    if (var5 != NULL) {
        var5->unknown_c2_ = 0;
    }
    func_ov000_02176210(&arg0->unknown_188_, 0xf, 0x22);
}
