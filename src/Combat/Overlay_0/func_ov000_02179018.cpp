#include <globaldefs.h>

#include "std_library_functions.h"

struct Struct_0205d0e0 {
    char unknown_0_[0xC2];
    short unknown_c2_;
    unsigned char unknown_c4_;
    char unknown_c5_[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char unknown_0_[0x54];
    char unknown_54_[0x98 - 0x54];
    int unknown_98_;
    struct Struct_0205d0e0* unknown_9c_;
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
    char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
};

struct Struct_ov000_02179018 {
    char unknown_0_[0x188];
    struct Struct_0205d81c unknown_188_;
};

struct Struct_ov000_02179018_2 {
    char unknown_0_[0x44];
    int unknown_44_;
    int unknown_48_;
};

int MessageSystem_GetInstance();
int GridCursor_GetCount(void* obj);
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02179194(struct Owner_02179018* obj, struct Entry_02179018* entry);
extern "C" void func_ov000_0217ab8c(struct Entry_02179018* entry, int a, int b);
extern "C" void func_ov000_0217936c(struct Owner_02179018* obj, struct Entry_02179018* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void func_ov000_02176210(struct Struct_0205d81c* arg0, int arg1, int arg2);

// USA: func_ov000_02179018
extern "C" ARM void func_ov000_02179018(struct Struct_ov000_02179018* arg0, struct Struct_ov000_02179018_2* arg1, int arg2, int arg3) {
    func_ov000_02179194(arg0, arg1);
    int var0 = arg1->unknown_44_;
    int var1 = arg1->unknown_48_;
    func_ov000_0217ab8c(arg1, arg2, arg3);
    struct Struct_0205d81c* var2 = &arg0->unknown_188_;
#if defined(jpn)
    var2->unknown_a0_ = 0xe;
#else
    var2->unknown_a0_ = 0x10;
#endif
    var2->unknown_a2_ = 9;
#if defined(jpn)
    var2->unknown_a4_ = (var0 >> 3) + 9;
#else
    var2->unknown_a4_ = (var0 >> 3) + 0x10;
#endif
    s->fieldA6 = y >> 3;
    s->fieldA8 = 0xc;
    s->fieldAA = 8;
    s->fieldAC = 0xa;
    s->fieldAE = 0xc;
    s->fieldB1 = 0x10;
    int many = 0;
    if (GridCursor_GetCount(s->field54) > 4) {
        many = 1;
    }
#if defined(jpn)
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217936c(arg0, arg1, var4);
#if defined(jpn)
    Window_OpenPane(s, buf, 0, 0, many, 1, 0);
#else
    Window_OpenPane(s, buf, 0, 0, many, 1, 0, 0);
#endif
    struct Struct_0205d0e0* var5 = func_0205d81c(var2, 0x23);
    if (var5 != 0) {
        var5->unknown_c2_ = 0;
    }
    func_ov000_02176210(&arg0->unknown_188_, 0x10, 0x23);
}
