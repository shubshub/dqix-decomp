#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_021571fc_4768 = 0x109c, Enum_ov006_021571fc_4796 = 0x10b8 };
#else
enum { Enum_ov006_021571fc_4768 = 0x12a0, Enum_ov006_021571fc_4796 = 0x12bc };
#endif

#include "std_library_functions.h"

struct Struct_02078398_2;
extern "C" void func_02078484(struct Struct_02078398_2*);
struct Struct_020dbfa4;
extern "C" void func_020dbfa4(struct Struct_020dbfa4*, int);

extern char data_ov006_02160087[];

struct Struct_ov006_021571fc {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int unknown_2c_; int unknown_30_;
    int f34; int unknown_38_; int f3c; int f40;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

// USA: func_ov006_021571fc
extern "C" ARM void func_ov006_021571fc(char* obj) {
    struct Struct_ov006_021571fc buf;
    func_02078484((struct Struct_02078398_2*)&buf);
    buf.b2 = 0;
    buf.f12 = 0;
    strcpy((char*)&buf, data_ov006_02160087);
    buf.unknown_44_ = 0x10a;
    buf.unknown_48_ = 0x10a;
    buf.unknown_4c_ = 0x10a;
    buf.unknown_2c_ = 0xc9 - 0x10a;
    buf.unknown_30_ = (int)0xfffff554;
    buf.f34 = 0x4526;
    func_020dbfa4((struct Struct_020dbfa4*)(obj + Enum_ov006_021571fc_4768), (int)&buf);
    *(unsigned char*)(obj + Enum_ov006_021571fc_4796) = 1;
}
