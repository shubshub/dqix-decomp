#include <globaldefs.h>

struct Struct_02074c18_2 {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short unknown_0_6_ : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short unknown_1_5_ : 1;
    unsigned short screenSize : 2;
};

struct Struct_02074c18 {
    Struct_02074c18_2 unknown_0_;
    Struct_02074c18_2 unknown_2_;
    Struct_02074c18_2 unknown_4_;
    Struct_02074c18_2 unknown_6_;
    Struct_02074c18_2 unknown_8_;
    Struct_02074c18_2 unknown_a_;
    Struct_02074c18_2 unknown_c_;
    Struct_02074c18_2 unknown_e_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
};

#define REG_DB_BG0CNT (*(volatile unsigned short*)0x4001008)
#define REG_DB_BG1CNT (*(volatile unsigned short*)0x400100a)
#define REG_DB_BG2CNT (*(volatile unsigned short*)0x400100c)
#define REG_DB_BG3CNT (*(volatile unsigned short*)0x400100e)

// USA: func_02074e54
extern "C" ARM void func_02074e54(struct Struct_02074c18* backup) {
    if (!backup->unknown_11_) return;
    REG_DB_BG0CNT = (unsigned short)(((short)backup->unknown_2_.screenSize << 14) | (REG_DB_BG0CNT & 0x43) |
                                     ((short)backup->unknown_2_.colorMode << 7) | ((short)backup->unknown_2_.screenBase << 8) |
                                     ((short)backup->unknown_2_.charBase << 2) | ((short)backup->unknown_2_.unknown_1_5_ << 13));
    REG_DB_BG1CNT = (unsigned short)(((short)backup->unknown_6_.screenSize << 14) | (REG_DB_BG1CNT & 0x43) |
                                     ((short)backup->unknown_6_.colorMode << 7) | ((short)backup->unknown_6_.screenBase << 8) |
                                     ((short)backup->unknown_6_.charBase << 2) | ((short)backup->unknown_6_.unknown_1_5_ << 13));
    REG_DB_BG2CNT = (unsigned short)(((short)backup->unknown_a_.screenSize << 14) | (REG_DB_BG2CNT & 0x43) |
                                     ((short)backup->unknown_a_.colorMode << 7) | ((short)backup->unknown_a_.screenBase << 8) |
                                     ((short)backup->unknown_a_.charBase << 2));
    REG_DB_BG3CNT = (unsigned short)(((short)backup->unknown_e_.screenSize << 14) | (REG_DB_BG3CNT & 0x43) |
                                     ((short)backup->unknown_e_.colorMode << 7) | ((short)backup->unknown_e_.screenBase << 8) |
                                     ((short)backup->unknown_e_.charBase << 2));
    REG_DB_BG0CNT = (unsigned short)((REG_DB_BG0CNT & ~3) | backup->unknown_2_.priority);
    REG_DB_BG1CNT = (unsigned short)((REG_DB_BG1CNT & ~3) | backup->unknown_6_.priority);
    REG_DB_BG2CNT = (unsigned short)((REG_DB_BG2CNT & ~3) | backup->unknown_a_.priority);
    REG_DB_BG3CNT = (unsigned short)((REG_DB_BG3CNT & ~3) | backup->unknown_e_.priority);
    if (backup->unknown_2_.unknown_0_6_) {
        REG_DB_BG0CNT |= 0x40;
    } else {
        REG_DB_BG0CNT &= ~0x40;
    }
    if (backup->unknown_6_.unknown_0_6_) {
        REG_DB_BG1CNT |= 0x40;
    } else {
        REG_DB_BG1CNT &= ~0x40;
    }
    if (backup->unknown_a_.unknown_0_6_) {
        REG_DB_BG2CNT |= 0x40;
    } else {
        REG_DB_BG2CNT &= ~0x40;
    }
    if (backup->unknown_e_.unknown_0_6_) {
        REG_DB_BG3CNT |= 0x40;
    } else {
        REG_DB_BG3CNT &= ~0x40;
    }
}
