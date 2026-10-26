#include <globaldefs.h>

#include "NitroSDK/BiosData.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Cache.h"

struct Struct_ov031_02217604 {
    unsigned long long primary;
    unsigned long long unknown_8_;
    unsigned short token;
    unsigned short unknown_12_;
};
struct Struct_ov031_02217604_2 {
    unsigned char language;
    unsigned char favoriteColor;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_[11];
    unsigned short unknown_1a_;
    unsigned short comment[27];
    unsigned short commentLength;
};
struct Struct_ov031_02217604_3 {
    unsigned long year;
    unsigned long month;
    unsigned long day;
    int unknown_c_;
};
struct Struct_ov031_02217604_4 {
    unsigned long unknown_0_;
    unsigned long unknown_4_;
    unsigned long second;
};
struct Struct_ov031_02217604_5 {
    char unknown_0_[14];
    char token[7];
    char unknown_15_[4];
    char unknown_19_;
    char unknown_1a_[2];
    char unknown_1c_;
    char unknown_1d_;
    char unknown_1e_;
    char macAddress[13];
    char language[3];
    char birthday[5];
    char unknown_34_[13];
    char unknown_41_[13];
    char ssid[33];
    char unknown_6f_[14];
    unsigned short unknown_7e_[11];
};
extern "C" int func_020c7170(char*, unsigned long, const char*, ...);
extern "C" int func_020c7130(char*, const char*, ...);
extern "C" void HaltSystem(void);
extern "C" void OS_GetMacAddress(unsigned char*);
extern "C" void OS_GetOwnerInfo(void*);
extern "C" int func_020cf25c(void*, void*);
extern "C" unsigned char* func_ov031_0220f040(void);
extern "C" unsigned char* func_ov031_0220f084(unsigned short*);
extern "C" unsigned char func_ov031_02213024(void);
extern "C" int func_ov031_02213054(void*);
extern char data_ov031_02249c84[];
extern char data_ov031_02249c8c[];
extern char data_ov031_02249c94[];
extern char data_ov031_02249c9c[];
extern char data_ov031_02249ca8[];
extern char data_ov031_02249cc4[];

// USA: func_ov031_02217604
extern "C" ARM int func_ov031_02217604(Struct_ov031_02217604_5* arg0, const Struct_ov031_02217604* ids) {
    Struct_ov031_02217604_2 owner;
    Struct_ov031_02217604_3 date;
    Struct_ov031_02217604_4 time;
    unsigned char mac[6];
    unsigned short var4;
    VectorizedMemset(arg0, 0, sizeof(*arg0));
    if (ids->primary != 0) {
        func_020c7170(arg0->unknown_0_, 14, data_ov031_02249c84, ids->primary);
    } else {
        func_020c7170(arg0->unknown_0_, 14, data_ov031_02249c84, ids->unknown_8_);
    }
    func_020c7170(arg0->token, 7, data_ov031_02249c8c, ids->token);
    const unsigned char* var5 = (const unsigned char*)((const CartridgeHeader*)BIOS_ADDR_CARTRIDGE_HEADER)->gameCode;
    const unsigned char* var6 = (const unsigned char*)((const CartridgeHeader*)BIOS_ADDR_CARTRIDGE_HEADER)->makerCode;
    if (var5[0] == 0) {
        HaltSystem();
    }
    VectorizedInvertedMemcpy(var5, arg0->unknown_15_, 4);
    if (var6[0] == 0) {
        HaltSystem();
    }
    VectorizedInvertedMemcpy(var6, arg0->unknown_1a_, 2);
    arg0->unknown_1d_ = '0';
    OS_GetMacAddress(mac);
    signed long var7 = 0;
    unsigned char* var8 = mac;
    char* var9 = arg0->macAddress;
    do {
        func_020c7130(var9, data_ov031_02249c94, *var8);
        ++var8;
        ++var7;
        var9 += 2;
    } while (var7 < 6);
    OS_GetOwnerInfo(&owner);
    if (owner.language >= 8) {
        owner.language = 1;
    }
    func_020c7170(arg0->language, 3, data_ov031_02249c94, owner.language);
    VectorizedInvertedMemcpy(owner.unknown_4_, arg0->unknown_7e_, 20);
    func_020c7170(arg0->birthday, 5, data_ov031_02249c9c, owner.unknown_2_, owner.unknown_3_);
    if (func_020cf25c(&date, &time) != 0) {
        return 0;
    }
    func_020c7170(arg0->unknown_34_, 13, data_ov031_02249ca8,
        date.year, date.month, date.day, time.unknown_0_, time.unknown_4_, time.second);
    unsigned long var10 = DisableIRQInterrupts();
    unsigned char* var11 = func_ov031_0220f040();
    InvalidateDataCacheRange(var11, 6);
    if (var11 == 0) {
        SetIRQInterruptState(var10);
        return 0;
    }
    char* var12 = arg0->unknown_41_;
    signed long var13 = 0;
    do {
        func_020c7130(var12, data_ov031_02249c94, var11[var13]);
        ++var13;
        var12 += 2;
    } while (var13 < 6);
    unsigned char var14 = func_ov031_02213024();
    if (var14 == 0xff || var14 > 99) {
        var14 = 99;
    }
    func_020c7170(arg0->unknown_6f_, 14, data_ov031_02249cc4, var14);
    unsigned char* ssid = func_ov031_0220f084(&var4);
    InvalidateDataCacheRange(ssid, 32);
    if (ssid == 0) {
        SetIRQInterruptState(var10);
        return 0;
    }
    VectorizedInvertedMemcpy(ssid, arg0->ssid, 32);
    func_ov031_02213054(arg0->unknown_6f_ + 3);
    SetIRQInterruptState(var10);
    return 1;
}
