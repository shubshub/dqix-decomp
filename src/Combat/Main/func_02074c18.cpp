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

#define REG_DB_BG0CNT (*(volatile unsigned short*)0x4000008)
#define REG_DB_BG1CNT (*(volatile unsigned short*)0x400000a)
#define REG_DB_BG2CNT (*(volatile unsigned short*)0x400000c)
#define REG_DB_BG3CNT (*(volatile unsigned short*)0x400000e)

// USA: func_02074c18
extern "C" ARM void func_02074c18(struct Struct_02074c18* backup) {
    if (!backup->unknown_10_) return;
    REG_DB_BG0CNT = (unsigned short)(((short)backup->unknown_0_.screenSize << 14) | (REG_DB_BG0CNT & 0x43) |
                                     ((short)backup->unknown_0_.colorMode << 7) | ((short)backup->unknown_0_.screenBase << 8) |
                                     ((short)backup->unknown_0_.charBase << 2) | ((short)backup->unknown_0_.unknown_1_5_ << 13));
    REG_DB_BG1CNT = (unsigned short)(((short)backup->unknown_4_.screenSize << 14) | (REG_DB_BG1CNT & 0x43) |
                                     ((short)backup->unknown_4_.colorMode << 7) | ((short)backup->unknown_4_.screenBase << 8) |
                                     ((short)backup->unknown_4_.charBase << 2) | ((short)backup->unknown_4_.unknown_1_5_ << 13));
    REG_DB_BG2CNT = (unsigned short)(((short)backup->unknown_8_.screenSize << 14) | (REG_DB_BG2CNT & 0x43) |
                                     ((short)backup->unknown_8_.colorMode << 7) | ((short)backup->unknown_8_.screenBase << 8) |
                                     ((short)backup->unknown_8_.charBase << 2));
    REG_DB_BG3CNT = (unsigned short)(((short)backup->unknown_c_.screenSize << 14) | (REG_DB_BG3CNT & 0x43) |
                                     ((short)backup->unknown_c_.colorMode << 7) | ((short)backup->unknown_c_.screenBase << 8) |
                                     ((short)backup->unknown_c_.charBase << 2));
    REG_DB_BG0CNT = (unsigned short)((REG_DB_BG0CNT & ~3) | backup->unknown_0_.priority);
    REG_DB_BG1CNT = (unsigned short)((REG_DB_BG1CNT & ~3) | backup->unknown_4_.priority);
    REG_DB_BG2CNT = (unsigned short)((REG_DB_BG2CNT & ~3) | backup->unknown_8_.priority);
    REG_DB_BG3CNT = (unsigned short)((REG_DB_BG3CNT & ~3) | backup->unknown_c_.priority);
    if (backup->unknown_0_.unknown_0_6_) {
        REG_DB_BG0CNT |= 0x40;
    } else {
        REG_DB_BG0CNT &= ~0x40;
    }
    if (backup->unknown_4_.unknown_0_6_) {
        REG_DB_BG1CNT |= 0x40;
    } else {
        REG_DB_BG1CNT &= ~0x40;
    }
    if (backup->unknown_8_.unknown_0_6_) {
        REG_DB_BG2CNT |= 0x40;
    } else {
        REG_DB_BG2CNT &= ~0x40;
    }
    if (backup->unknown_c_.unknown_0_6_) {
        REG_DB_BG3CNT |= 0x40;
    } else {
        REG_DB_BG3CNT &= ~0x40;
    }
}
