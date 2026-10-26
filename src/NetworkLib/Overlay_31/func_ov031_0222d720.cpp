#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void (*Type_02001aec)(char*);
struct Struct_ov031_02248ef8 { Type_02001aec unknown_0_[5]; };
struct Struct_ov031_02248ee0 { unsigned char pad[8]; unsigned char sounds[5]; unsigned char pad2[0x18 - 0xd]; };
struct Struct_ov031_0222d720 { unsigned char pad[4]; unsigned short pad2 : 10; unsigned short priority : 2; };
struct Struct_ov031_0222d720_2 {
    int field0;
    Struct_ov031_0222d720* oam;
    char digits[12];
    unsigned char cursor;
    unsigned char status;
};

extern Struct_ov031_02248ef8 data_ov031_02248ef8;
extern Struct_ov031_02248ee0 data_ov031_02248ee0;
extern Struct_ov031_0222d720_2* data_ov031_02290c98;
extern unsigned char data_ov031_0224ba7c[];

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void func_ov031_02227520(int*, int*);
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
    Struct_ov031_02248ef8 table = data_ov031_02248ef8;
    unsigned char sounds[5];
    sounds[0] = data_ov031_02248ee0.sounds[0];
    sounds[1] = data_ov031_02248ee0.sounds[1];
    sounds[2] = data_ov031_02248ee0.sounds[2];
    sounds[3] = data_ov031_02248ee0.sounds[3];
    sounds[4] = data_ov031_02248ee0.sounds[4];
    data_ov031_02290c98 = (Struct_ov031_0222d720_2*)func_ov031_0223cf4c(0x18, 4);

    int mode;
    func_ov031_02227520(&mode, 0);
    table.unknown_0_[mode](data_ov031_02290c98->digits);

    Struct_ov031_0222d720_2* state = data_ov031_02290c98;
    if (memcmp(state->digits, data_ov031_0224ba7c, 3) != 0) {
        state->cursor = 3;
    } else {
        VectorizedMemset(state->digits, 0, 0xc);
        data_ov031_02290c98->cursor = 0;
    }
    func_ov031_0222d894();
    func_ov031_02223998(mode + 0xb);
    func_ov031_0222336c(sounds[mode], -1, 0);
    func_ov031_02223518(2);
    data_ov031_02290c98->field0 = func_ov031_0223c560(0, 0);
    data_ov031_02290c98->oam = (Struct_ov031_0222d720*)func_ov031_0223be44(0, 0x3f);
    data_ov031_02290c98->oam->priority = 3;
    func_ov031_0222e048();
    func_ov031_0222df84();
    func_ov031_022274c0((int)func_ov031_0222d950);
}
