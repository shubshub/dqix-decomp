#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0207fdcc_2;
struct Struct_02080f8c;
struct Struct_ov006_02159fb0;
struct Struct_ov006_0215a00c;
struct Struct_ov006_0215a00c_2 { char unknown_0_[4]; short unknown_4_; };
struct Struct_0207d538 { int unknown_0_[3]; };

struct Struct_020465c0 {
    void* unknown_0_;
    char unknown_4_[0x14];
    void* unknown_18_;
    char unknown_1c_[0x40];
    char* unknown_5c_;
};

struct Struct_01ff8b48_23 { char unknown_0_[0x7c]; };
struct Struct_ov006_0215a00c_3 { char unknown_0_[5]; signed char unknown_5_0_:6; };

struct Struct_ov006_0215a00c_4 {
    char unknown_0_[0x4c];
    int unknown_4c_;
    char unknown_50_[0x78 - 0x50];
    short unknown_78_[3];
    short unknown_7e_;
    unsigned short unknown_80_;
    short unknown_82_;
    char unknown_84_[3];
    unsigned char unknown_87_;
    char unknown_88_[0x92 - 0x88];
    unsigned char unknown_92_;
    char unknown_93_[1];
    unsigned short unknown_94_;
    char unknown_96_[2];
};

struct Struct_ov006_0215a00c_5 {
    int unknown_0_;
    char unknown_4_[0x10];
    void* unknown_14_;
    char unknown_18_[0x1c];
    int unknown_34_;
    char unknown_38_[0x158 - 0x38];
    struct Struct_0201099c_3 unknown_158_;
    char unknown_160_[0x170 - 0x160];
    struct Struct_01ff8b48_23 unknown_170_;
    short unknown_1ec_;
    char unknown_1ee_[0x300 - 0x1ee];
    struct Struct_ov006_0215a00c_4 unknown_300_;
    char unknown_398_[0x3b0 - 0x398];
    int unknown_3b0_;
};

extern "C" void func_02080c20(struct Struct_0207fdcc_2*, int);
extern "C" void func_020813ec(void*, int);
int KeyTable_Get(struct Container020e0310*, int);
struct StoreStruct* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(struct StoreStruct*);
void* CallFunc020e52a0_020e5294(void*, int);
void StoreInArray0x8b0_020465c0(struct StoreStruct*, int, int);
void InitObjFromCombatantId020e4bf4(void*, int);
extern "C" void func_02046608(struct StoreStruct*, int, const char*, char*, int, int, int);
char* Font_FindCharacter(int, int);
extern "C" void __clear(void*, int);
extern "C" void func_02080f8c(Struct_02080f8c*, int, int);
extern "C" void func_ov006_02159fb0(struct Struct_ov006_02159fb0*);
extern char data_ov006_0215ffd2[];
extern char data_ov006_0215ffea[];

// USA: func_ov006_0215a00c
extern "C" ARM void func_ov006_0215a00c(struct Struct_ov006_0215a00c_5* arg0) {
    char var0[0x400];
    struct Struct_0207d538 var1;
    int var2;

    unsigned char var3 = arg0->unknown_300_.unknown_92_;
    if (var3 == 0) {
        if (arg0->unknown_300_.unknown_94_ & 0x20) {
            func_02080c20((struct Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            func_020813ec(arg0->unknown_14_, 0);
        }
        self->sub.field94 &= ~0x20;
        self->sub.field80 = 0;
        if (KeyTable_Get(&self->field158, self->sub.field7e) == 0) {
            self->sub.field7e = -1;
        }
        arg0->unknown_3b0_ = -1;
        arg0->unknown_300_.unknown_92_ = arg0->unknown_300_.unknown_92_ + 1;
        return;
    }
    if (var3 == 1) {
        struct Struct_020465c0* var4 = func_020421a0();
        char* var5 = var4->unknown_5c_;
        memset(var5, 0, 0x960);
        func_02046380(var4);

        unsigned short var6 = 0;
        if (arg0->unknown_34_ != 0) {
            void* var7 = func_020e5294(&arg0->unknown_170_, arg0->unknown_1ec_);
            if (var7 != 0) {
                var4->unknown_18_ = var7;
            }
            var6 = (unsigned short)((arg0->unknown_300_.unknown_82_ / 10) * 10);
        }
        func_020465c0(var4, 0, arg0->unknown_300_.unknown_87_);
        func_020465c0(var4, 1, var6);

        struct Struct_ov006_0215a00c_2* var8 = (struct Struct_ov006_0215a00c_2*)((GameState*)((struct Struct_ov006_0215a00c*)GameState::GetInstance()))->GetUnknownGameObject();
        if (var8 != 0) {
            func_020e4bf4(&var1, var8->unknown_4_);
            var4->unknown_0_ = &var1;
        }

        short* var9 = (short*)data_ov006_0215ffd2;
        for (var2 = 0; ; var2++) {
            short var10 = *var9;
            if (var10 < 0) break;
            if (var10 == arg0->unknown_300_.unknown_7e_) {
                void* var11 = func_020e5294(&arg0->unknown_170_, arg0->unknown_300_.unknown_78_[var2]);
                if (var11 != 0) {
                    var4->unknown_18_ = var11;
                }
                break;
            }
            var9++;
        }

        const char* msg = (const char*)KeyTable_Get(&self->field158, self->sub.field7e);
        func_02046608(fmt, 0xc, msg, base, 0xe3, 0, 1);

        char* var13 = var5 + arg0->unknown_300_.unknown_80_;
        unsigned short var14 = arg0->unknown_300_.unknown_80_;
        int var15 = arg0->unknown_0_ >> 4;
        arg0->unknown_0_ += (arg0->unknown_300_.unknown_4c_ << 4);
        var2 = arg0->unknown_0_ >> 4;
        int var16 = var2 - var15;
        if (arg0->unknown_0_ >= 0xffffff) {
            arg0->unknown_0_ = 0;
        }

        int var17 = 0;
        int var18 = 1;
        while (var17 < var16) {
            signed char var19 = ((signed char*)var13)[0];
            if (var19 == 0) break;
            signed char var20 = 1;
            if (var19 == 0x5c && ((signed char*)var13)[1] == 0x6e) {
                var13 += 2;
                var14 += 2;
            } else {
                ParseEntry* e = (ParseEntry*)Font_FindCharacter((int)p, 1);
                if (e != 0) {
                    step = e->adv;
                }
                var13 += var20;
                var14 = (unsigned short)(var14 + var20);
            }
            var17++;
        }
        if (arg0->unknown_300_.unknown_80_ >= var14) {
            arg0->unknown_300_.unknown_7e_ = -1;
        }
        arg0->unknown_300_.unknown_80_ = var14;
        __clear(var0, 0x400);
        memcpy(var0, var5, var14);
        func_02080f8c((struct Struct_02080f8c*)arg0->unknown_14_, 1, (int)var0);
        func_020813ec(arg0->unknown_14_, 1);
        func_02080c20((struct Struct_0207fdcc_2*)arg0->unknown_14_, 1);
        arg0->unknown_3b0_ = 1;

        short* var22 = (short*)data_ov006_0215ffea;
        for (;;) {
            short var23 = *var22;
            if (var23 < 0) break;
            if (var23 == arg0->unknown_300_.unknown_7e_) {
                arg0->unknown_3b0_ = -1;
                break;
            }
            var22++;
        }
        func_ov006_02159fb0((struct Struct_ov006_02159fb0*)arg0);
    }
}
