#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void (*Type_02001aec)(char*);
struct Struct_ov031_02248ef8 { Type_02001aec unknown_0_[5]; };
struct Struct_ov031_02248ee0 { unsigned char unknown_0_[8]; unsigned char unknown_8_[5]; unsigned char unknown_d_[0x18 - 0xd]; };
struct Struct_ov031_0222d720 { unsigned char unknown_0_[4]; unsigned short unknown_4_0_ : 10; unsigned short unknown_5_2_ : 2; };
struct Struct_ov031_0222d720_2 {
    int unknown_0_;
    Struct_ov031_0222d720* unknown_4_;
    char unknown_8_[12];
    unsigned char unknown_14_;
    unsigned char unknown_15_;
};

extern Struct_ov031_02248ef8 data_ov031_02248ef8;
extern Struct_ov031_02248ee0 data_ov031_02248ee0;
extern Struct_ov031_0222d720_2* data_ov031_02290c98;
extern unsigned char data_ov031_0224ba7c[];

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
void GetFields181c_02227520(int*, int*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" void func_ov031_0222d894(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02223518(int);
extern "C" int func_ov031_0223c560(int, int);
extern "C" int func_ov031_0223be44(int, int);
extern "C" void func_ov031_0222e048(void);
extern "C" void func_ov031_0222df84(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222d950(void);

// USA: func_ov031_0222d720
extern "C" ARM void func_ov031_0222d720(void) {
    Struct_ov031_02248ef8 var0 = data_ov031_02248ef8;
    unsigned char var1[5];
    var1[0] = data_ov031_02248ee0.unknown_8_[0];
    var1[1] = data_ov031_02248ee0.unknown_8_[1];
    var1[2] = data_ov031_02248ee0.unknown_8_[2];
    var1[3] = data_ov031_02248ee0.unknown_8_[3];
    var1[4] = data_ov031_02248ee0.unknown_8_[4];
    data_ov031_02290c98 = (Struct_ov031_0222d720_2*)func_ov031_0223cf4c(0x18, 4);

    int var2;
    func_ov031_02227520(&var2, 0);
    var0.unknown_0_[var2](data_ov031_02290c98->unknown_8_);

    State_0222d720* state = data_ov031_02290c98;
    if (memcmp(state->digits, data_ov031_0224ba7c, 3) != 0) {
        state->cursor = 3;
    } else {
        VectorizedMemset(var3->unknown_8_, 0, 0xc);
        data_ov031_02290c98->unknown_14_ = 0;
    }
    func_ov031_0222d894();
    func_ov031_02223998(var2 + 0xb);
    func_ov031_0222336c(var1[var2], -1, 0);
    func_ov031_02223518(2);
    data_ov031_02290c98->unknown_0_ = func_ov031_0223c560(0, 0);
    data_ov031_02290c98->unknown_4_ = (Struct_ov031_0222d720*)func_ov031_0223be44(0, 0x3f);
    data_ov031_02290c98->unknown_4_->unknown_5_2_ = 3;
    func_ov031_0222e048();
    func_ov031_0222df84();
    func_ov031_022274c0((int)func_ov031_0222d950);
}
