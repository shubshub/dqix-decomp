#include <globaldefs.h>

#include "NitroSDK/BiosData.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Cache.h"

struct Struct_ov031_02217604 {
    unsigned long long unknown_0_;
    unsigned long long unknown_8_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};
struct Struct_ov031_02217604_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_[11];
    unsigned short unknown_1a_;
    unsigned short unknown_1c_[27];
    unsigned short unknown_52_;
};
struct Struct_ov031_02217604_3 {
    unsigned long unknown_0_;
    unsigned long unknown_4_;
    unsigned long unknown_8_;
    int unknown_c_;
};
struct Struct_ov031_02217604_4 {
    unsigned long unknown_0_;
    unsigned long unknown_4_;
    unsigned long unknown_8_;
};
struct Struct_ov031_02217604_5 {
    char unknown_0_[14];
    char unknown_e_[7];
    char unknown_15_[4];
    char unknown_19_;
    char unknown_1a_[2];
    char unknown_1c_;
    char unknown_1d_;
    char unknown_1e_;
    char unknown_1f_[13];
    char unknown_2c_[3];
    char unknown_2f_[5];
    char unknown_34_[13];
    char unknown_41_[13];
    char unknown_4e_[33];
    char unknown_6f_[14];
    unsigned short unknown_7e_[11];
};
int VariadicForward020c7170(char*, unsigned long, const char*, ...);
int VariadicForward020c7130(char*, const char*, ...);
extern "C" void HaltSystem(void);
extern "C" void OS_GetMacAddress(unsigned char*);
extern "C" void OS_GetOwnerInfo(void*);
int GetOrInitStoredValueAt0x2c_020cf25c(void*, void*);
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
extern "C" ARM int func_ov031_02217604(Struct_ov031_02217604_5* arg0, const Struct_ov031_02217604* arg1) {
    Struct_ov031_02217604_2 var0;
    Struct_ov031_02217604_3 var1;
    Struct_ov031_02217604_4 var2;
    unsigned char var3[6];
    unsigned short var4;
    VectorizedMemset(arg0, 0, sizeof(*arg0));
    if (arg1->unknown_0_ != 0) {
        func_020c7170(arg0->unknown_0_, 14, data_ov031_02249c84, arg1->unknown_0_);
    } else {
        func_020c7170(arg0->unknown_0_, 14, data_ov031_02249c84, arg1->unknown_8_);
    }
    VariadicForward020c7170(report->token, 7, data_ov031_02249c8c, ids->token);
    const unsigned char* gameCode = (const unsigned char*)((const CartridgeHeader*)BIOS_ADDR_CARTRIDGE_HEADER)->gameCode;
    const unsigned char* makerCode = (const unsigned char*)((const CartridgeHeader*)BIOS_ADDR_CARTRIDGE_HEADER)->makerCode;
    if (gameCode[0] == 0) {
        HaltSystem();
    }
    VectorizedInvertedMemcpy(gameCode, report->gameCode, 4);
    if (makerCode[0] == 0) {
        HaltSystem();
    }
    VectorizedInvertedMemcpy(makerCode, report->makerCode, 2);
    report->connectionType = '0';
    OS_GetMacAddress(mac);
    signed long macIndex = 0;
    unsigned char* macByte = mac;
    char* macText = report->macAddress;
    do {
        VariadicForward020c7130(macText, data_ov031_02249c94, *macByte);
        ++macByte;
        ++macIndex;
        macText += 2;
    } while (macIndex < 6);
    OS_GetOwnerInfo(&owner);
    if (owner.language >= 8) {
        owner.language = 1;
    }
    func_020c7170(arg0->unknown_2c_, 3, data_ov031_02249c94, var0.unknown_0_);
    VectorizedInvertedMemcpy(var0.unknown_4_, arg0->unknown_7e_, 20);
    func_020c7170(arg0->unknown_2f_, 5, data_ov031_02249c9c, var0.unknown_2_, var0.unknown_3_);
    if (func_020cf25c(&var1, &var2) != 0) {
        return 0;
    }
    func_020c7170(arg0->unknown_34_, 13, data_ov031_02249ca8,
        var1.unknown_0_, var1.unknown_4_, var1.unknown_8_, var2.unknown_0_, var2.unknown_4_, var2.unknown_8_);
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
    unsigned char* var15 = func_ov031_0220f084(&var4);
    InvalidateDataCacheRange(var15, 32);
    if (var15 == 0) {
        SetIRQInterruptState(var10);
        return 0;
    }
    VectorizedInvertedMemcpy(var15, arg0->unknown_4e_, 32);
    func_ov031_02213054(arg0->unknown_6f_ + 3);
    SetIRQInterruptState(var10);
    return 1;
}
