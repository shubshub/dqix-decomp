#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_02082828_5 {
    unsigned int field0 : 10;
    unsigned int field10 : 10;
    unsigned int field20 : 10;
    unsigned int reserved : 2;
};
struct Struct_02082cdc {
    Struct_02082828_5 w[3];
};
struct Struct_02082828 {
    unsigned char bytes[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};
struct Struct_020827c4 {
    unsigned char bytes[0x1c];
};
struct Struct_02082828_2;
struct Struct_02082828_3 {
    unsigned int words[10];
    short index;
    unsigned short field2a;
};
struct Struct_02082828_4 {
    Struct_02082828_5 packed[6];
    unsigned int field18;
    unsigned short field1c;
    unsigned short unknown_1e_;
    unsigned char field20;
    Struct_02082828 copied;
    unsigned char unknown_39_[3];
    char name[48];
    unsigned short unknown_6c_;
    unsigned short unknown_6e_;
    unsigned short unknown_70_;
    unsigned short unknown_72_;
    unsigned short unknown_74_;
    unsigned short unknown_76_;
    unsigned int unknown_78_;
    Struct_02082828 details;
    unsigned char stats[0xa4];
    unsigned int unknown_138_[13];
    unsigned short unknown_16c_[13];
    unsigned char flags[13];
    unsigned char unknown_193_[0x161];
    Struct_02082828_3 slots[8];
    unsigned char unknown_454_[16];
    unsigned char unknown_464_[27];
    unsigned char unknown_47f_[9];
    Struct_020827c4 unknown_488_;
    unsigned char unknown_4a4_[0xc0];
    unsigned short unknown_564_;
    unsigned short unknown_566_;
    short unknown_568_;
    unsigned char unknown_56a_;
    unsigned char nibbles;
    unsigned char unknown_56c_;
    unsigned char unknown_56d_;
    unsigned char unknown_56e_;
#if defined(jpn)
    unsigned char unknown_56f_[0x7b8 - 0x56f];
#else
    unsigned char unknown1_56f_[0x850 - 0x56f];
#endif
    Struct_02082cdc triples[13];
    unsigned char unknown_8ec_[36];
    unsigned char unknown_910_[9];
    unsigned char unknown_919_[3];
    Struct_02082828_5 saved[6];
    unsigned char unknown_934_[22];
    unsigned short unknown_94a_;
    unsigned int state;
    unsigned int field950;
    unsigned short unknown_954_;
    unsigned short unknown_956_;
    short unknown_958_;
    unsigned short unknown_95a_;
    unsigned short unknown_95c_;
    short unknown_95e_;
    unsigned short unknown_960_;
    unsigned short unknown_962_;
};
extern "C" void func_020891cc(void*);
extern "C" void func_02082cdc(Struct_02082cdc*);
extern "C" void func_020827c4(Struct_020827c4*);
extern "C" void func_02082d38(Struct_02082828*, Struct_02082828*);
extern "C" void func_02083508(Struct_02082828_2*);
extern "C" void OS_GetMacAddress(void*);
extern char data_020f1010[];
extern char g_stringFormat[];

#if defined(jpn)
extern char data_020f1130[];
#endif

// USA: func_02082828
extern "C" ARM void func_02082828(Struct_02082828_4* object) {
    unsigned char index = 0;
    object->unknown_568_ = -1;
    for (index = 0; index < 13; index++) {
        object->unknown_16c_[index] = 1;
        object->flags[index] = 0;
        object->unknown_138_[index] = 0;
    }
    object->state = 5;
    object->field950 = 0;
    object->unknown_954_ = 0;
    memset(object->name, 0, 48);
    object->unknown_6c_ = 1;
    object->unknown_6e_ = 0;
    object->unknown_70_ = 0;
    object->unknown_72_ = 0;
    object->unknown_74_ = 0;
    object->unknown_78_ &= ~0x3ff;
    object->unknown_78_ &= ~0x40000000;
    memset(object->details.bytes, 100, 22);
    memset(object->packed, 0, 24);
    object->packed[2].field10 = 1;
    memset(object->saved, 0, 24);
    object->saved[2].field10 = 1;
    memset(object->unknown_934_, 100, 22);
    func_020891cc(object->stats);
    for (int i = 0; i < 13; i++) func_02082cdc(&object->triples[i]);
    func_020827c4(&object->unknown_488_);
    memset(object->unknown_4a4_, -1, 192);
    object->saved[0].field0 = 0;
    object->packed[0].field0 = object->saved[0].field0;
    object->saved[0].field20 = 0;
    object->packed[0].field20 = object->saved[0].field20;
    object->saved[0].field10 = 0;
    object->packed[0].field10 = object->saved[0].field10;
    object->saved[1].field0 = 0;
    object->packed[1].field0 = object->saved[1].field0;
    object->saved[1].field10 = 0;
    object->packed[1].field10 = object->saved[1].field10;
    object->saved[1].field20 = 0;
    object->packed[1].field20 = object->saved[1].field20;
    object->saved[2].field0 = 0;
    object->packed[2].field0 = object->saved[2].field0;
    object->saved[2].field10 = 1;
    object->packed[2].field10 = object->saved[2].field10;
    object->saved[2].field20 = 0;
    object->packed[2].field20 = object->saved[2].field20;
    object->unknown_6c_ = object->packed[2].field10;
    object->unknown_6e_ = object->packed[2].field20;
    object->unknown_564_ = 0;
    object->unknown_56c_ = 0;
    object->unknown_56d_ = 0;
    object->unknown_56e_ = 0;
    object->field1c = object->unknown_6c_;
    object->unknown_1e_ = object->unknown_6e_;
    func_02082d38(&object->copied, &object->details);
    object->field18 = 0;
    object->field20 = 0;
    memset(object->unknown_454_, -1, 16);
    memset(object->unknown_464_, 0, 27);
    func_02083508((Struct_02082828_2*)object);
    memset(object->unknown_8ec_, 0, 36);
    memset(object->unknown_910_, 0, 9);
    for (unsigned char slotIndex = 0; slotIndex < 8; slotIndex++) {
        object->slots[slotIndex].words[0] = 0;
        object->slots[slotIndex].words[1] = 0;
        object->slots[slotIndex].words[2] = 0;
        object->slots[slotIndex].words[3] = 0;
        object->slots[slotIndex].words[4] = 0;
        object->slots[slotIndex].words[5] = 0;
        object->slots[slotIndex].words[6] = 0;
        object->slots[slotIndex].words[7] = 0;
        object->slots[slotIndex].words[8] = 0;
        object->slots[slotIndex].words[9] = 0;
        object->slots[slotIndex].index = -1;
    }
    unsigned char hardwareAddress[6];
#if defined(jpn)
    char suffix[11];
    OS_GetMacAddress(hardwareAddress);
    char var4[] = "\x82\x60";
    char var5[] = "\x82\x60";
    signed char first = (hardwareAddress[0] + hardwareAddress[1] + hardwareAddress[2]) % 26;
    var4[1] += first;
    signed char second = (hardwareAddress[3] + hardwareAddress[4] + hardwareAddress[5]) % 26;
    var5[1] += second;
    sprintf(suffix, data_020f1130, var4, var5);
#else
    char suffix[18];
    OS_GetMacAddress(hardwareAddress);
    int first = (hardwareAddress[0] + hardwareAddress[2] + hardwareAddress[4]) % 26;
    int second = (hardwareAddress[1] + hardwareAddress[3] + hardwareAddress[5]) % 26;
    sprintf(suffix, data_020f1010, (signed char)(first + 65), (signed char)(second + 65));
#endif
    sprintf(object->name, g_stringFormat, suffix);
    object->unknown_956_ = 0;
    object->unknown_958_ = -1;
    object->unknown_95a_ = 0;
    object->unknown_95c_ = 0;
    object->unknown_95e_ = -1;
    object->unknown_960_ = 0;
    object->unknown_962_ = 0;
    object->nibbles &= ~15;
    object->nibbles &= ~240;
}
