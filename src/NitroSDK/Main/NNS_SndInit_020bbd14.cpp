#include <globaldefs.h>

extern "C" void func_020d21c0(void);
extern "C" void func_020bbdd8(void);
extern "C" void func_020bbe10(void);
extern "C" void func_020bbf18(void);
extern "C" void func_020bce9c(void);
extern "C" void func_020bc23c(void);

struct Struct_0210cfd0 { char unknown_0_[8]; struct Struct_0210cfd0* next; };
extern "C" void func_020cef34(struct Struct_0210cfd0* node);

struct Struct_0210cfdc { char unknown_0_[8]; struct Struct_0210cfdc* next; };
extern "C" void func_020cef4c(struct Struct_0210cfdc* node);

extern struct Struct_0210cfd0 data_0210cfd0;
extern struct Struct_0210cfdc data_0210cfdc;

struct Struct_0210cfc0 {
    char byte0;
    char pad1[3];
    int field4;
    char pad2[0xc - 8];
    int unknown_c_;
    void (*field10)(void);
    int field14;
    char pad3[0x1c - 0x18];
    void (*field1c)(void);
    int field20;
};
extern struct Struct_0210cfc0 data_0210cfc0;

// Main, originally func_020bbd14 (USA 0x020bbd14, EUR 0x020bbd24, JPN 0x020bd7e0)
extern "C" ARM void NNS_SndInit(void) {
    if (data_0210cfc0.unknown_c_ != 0) return;
    data_0210cfc0.unknown_c_ = 1;
    func_020d21c0();
    data_0210cfc0.field10 = func_020bbdd8;
    data_0210cfc0.field14 = 0;
    data_0210cfc0.field1c = func_020bbe10;
    data_0210cfc0.field20 = 0;
    func_020cef34(&data_0210cfd0);
    func_020cef4c(&data_0210cfdc);
    func_020bbf18();
    func_020bce9c();
    func_020bc23c();
    data_0210cfc0.byte0 = -1;
    data_0210cfc0.field4 = 1;
}
