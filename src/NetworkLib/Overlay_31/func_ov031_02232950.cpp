#include <globaldefs.h>

extern "C" ARM int func_ov031_02222e0c(void);
extern "C" ARM unsigned int func_ov031_02227558(void);
extern "C" int func_ov031_02236878(int index);
extern "C" ARM void func_ov031_02222e98(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02227ce4(void);
extern "C" ARM void func_ov031_02222e40(int v);
extern "C" ARM unsigned char func_ov031_0223607c(int idx);
extern "C" ARM unsigned char func_ov031_02227548(void);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" void func_ov031_02232f58(void);
extern "C" void func_ov031_02232fe8(void);
extern "C" void func_ov031_02236094(void);
extern "C" void func_ov031_02233178(void);
extern "C" void func_ov031_02232a84(void);
extern signed char data_ov031_0224910c[];

struct Struct_ov031_02232950 { unsigned char pad[0x1d]; unsigned char unknown_1d_; };
struct Struct_ov031_02290cc0_3 { unsigned char field0; unsigned char pad[3]; Struct_ov031_02232950 *unknown_4_; };
extern Struct_ov031_02290cc0_3 data_ov031_02290cc0;

// USA: func_ov031_02232950
extern "C" ARM void func_ov031_02232950(void) {
    int var0 = func_ov031_02222e0c();
    if (var0 == 0) goto handleZero;
    if (var0 == 1) goto handleOne;
    return;

handleZero:
    {
        unsigned int f8 = func_ov031_02227558();
        switch (f8) {
        case 0: goto setField1dAndFinal;
        case 1: goto handleF8One;
        default: goto final;
        }
    }

setField1dAndFinal:
    func_ov031_02236878(7);
    data_ov031_02290cc0.unknown_4_->unknown_1d_ = 2;
    goto final;

handleF8One:
    func_ov031_02222e98();
    func_ov031_022274c0((int)func_ov031_02227ce4);
    return;

handleOne:
    {
        data_ov031_02290cc0.unknown_4_->unknown_1d_ = 1;
        unsigned char b0 = data_ov031_02290cc0.field0;
        if (b0 < 4) goto lowField0;

        int idx = b0 - 4;
        unsigned char e = func_ov031_0223607c(idx);
        if (e == 0xff) {
            func_ov031_02236878(9);
            func_ov031_02222e40(-1);
            return;
        }
        func_ov031_02236878(6);
        signed char v = data_ov031_0224910c[func_ov031_02227548()];
        int next = idx + 1;
        func_ov031_02237b2c(0x46, 0, 1, v, next);
        func_ov031_02232f58();
        func_ov031_02222e98();
        func_ov031_022274c0((int)func_ov031_02232fe8);
        return;
    }

lowField0:
    {
        unsigned char b0 = data_ov031_02290cc0.field0;
        if (b0 <= 2) {
            func_ov031_02236094();
        }
        func_ov031_02236878(6);
        func_ov031_02233178();
        goto final;
    }

final:
    func_ov031_022274c0((int)func_ov031_02232a84);
}
