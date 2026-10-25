#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02160da0;
struct Struct_020a36a8;
struct Struct_ov026_021d8ba0_4;
struct Struct_02053da0;
struct Struct_02033fdc;
struct Struct_02039d84;
struct Struct_02010604;
struct Struct_02010088;
struct Struct_ov026_021d8ba0_10;

struct Struct_ov000_02161e30 {
    char unknown_0_[0x8e20];
    int unknown_8e20_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x2];
    unsigned short unknown_2_;
    char unknown_4_[0x4];
    unsigned short unknown_8_;
    char unknown_a_[0x2];
    int unknown_c_;
    char unknown_10_[0x1a];
    signed char unknown_2a_;
    char unknown_2b_[0xa];
    unsigned char unknown_35_;
};

struct Struct_ov026_021d8ba0_6 {
    char unknown_0_[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0xb];
    unsigned char unknown_24_0_ : 1;
    unsigned char unknown_24_1_ : 7;
    char unknown_25_[0x3];
    int unknown_28_;
};

struct Struct_ov026_021dce34_2 {
    unsigned short unknown_0_;
    char unknown_2_[0x6];
    int unknown_8_;
};

struct Struct_ov026_021dce34_3 { char unknown_0_[0x70]; };
struct Struct_ov017_021ce704 { char unknown_0_[0xc]; };

struct Struct_ov000_021643d4_8 {
    Vector3i unknown_0_;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_ov017_021cbc48 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    int unknown_4_;
    unsigned char unknown_8_;
    signed char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    short unknown_e_;
};

struct Struct_ov026_021dce34 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

struct Struct_ov023_021f2a48_2 {
    char unknown_0_[0xbe];
    unsigned char unknown_be_;
    char unknown_bf_[0x2];
    Struct_ov026_021dce34 unknown_c1_;
    unsigned char unknown_c2_0_ : 5;
    unsigned char unknown_c2_5_ : 1;
    unsigned char unknown_c2_6_ : 2;
    char unknown_c3_[0x6d];
    unsigned int* unknown_130_;
#if defined(jpn)
    char unknown_134_[0x4c];
#else
    char unknown1_134_[0x58];
#endif
    unsigned int unknown_18c_;
};

extern "C" int func_020a36a8(Struct_020a36a8*);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" void func_ov000_02160fbc(void*, int);
extern "C" void func_020a35cc(unsigned char*, unsigned char);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Struct_ov026_021d8ba0_4*, int);
extern "C" void func_02053da0(char*, Struct_02053da0*);
extern "C" void func_0208936c(char*, char*, char*);
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void func_02033fdc(Struct_02033fdc*);
extern "C" void func_02033b88(Struct_02010604*, int);
extern "C" void func_0203409c(unsigned char*);
extern "C" void func_02039d58(unsigned char*);
extern "C" void func_ov000_02168644(char*, int);
extern "C" void func_02039894(unsigned char*);
extern "C" void func_ov000_02167e6c(unsigned char*);
extern "C" int func_02010088(Struct_02010088*);
extern "C" int func_ov026_021dd3c4(Struct_ov026_021d8ba0_10*);
extern "C" void func_ov017_021cbc48(Struct_ov017_021cbc48*);
extern "C" void func_ov017_021cdf80(char*, unsigned char);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov000_02181364(void*);
extern "C" void func_ov000_021816e8(void*, int);
extern "C" void func_ov000_02181694(void*, int);
extern "C" void func_ov000_0217f5d0(void*);

extern "C" {
int* func_0202ae18();
int func_ov000_0215fad4(Struct_ov000_02161e30*);
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
void func_ov000_02174738(void*, int);
void* memset(void*, int, unsigned int);
void func_02049c88(void*, void*);
void func_ov026_021dc8fc(Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, void*, int);
void func_020531f0(void*);
void func_ov000_02167fb0(void*, GameObject*);
int func_0202c540(int*);
int func_ov017_0219c774(int, int, int);
void func_ov017_021917f0(int, int);
void func_ov000_021675a0(Struct_ov000_02160da0*);
void func_ov026_021daec8(Struct_ov000_02161e30*, void*, int);
void func_ov000_021676a8(Struct_ov000_02160da0*);
void func_ov000_02174b14(void*);
void func_ov000_0217a8f4(void*);
void func_ov017_021c847c();
void func_ov000_0217fcc4(void*, int);
}

// USA: func_ov026_021dce34
extern "C" ARM void func_ov026_021dce34(int arg0, Struct_ov000_02160da0* arg1, Struct_ov000_02161e30* arg2, Struct_ov000_0217e870_2* arg3,
                                        void* arg4, Struct_ov026_021dce34_2* arg5, Struct_ov026_021dce34_3* arg6, Struct_ov017_021ce704* arg7,
                                        void* arg8, void* arg9, Struct_ov000_021643d4_8* arg10, void* arg11) {
    Struct_ov017_021cbc48 var0;
    short var1[4];
    short var2[4];
    GameState* var3 = GameState::GetInstance();
    GetGameResources();
    int* var4 = func_0202ae18();
    if (!func_020a36a8((Struct_020a36a8*)arg3) && !func_ov000_02160fd4(arg1, 0x80000000)) {
        return;
    }
    func_ov000_02160fbc(arg1, 0x80000000);
    int var5 = 0;
    int var6 = func_ov000_0215fad4(arg2);
    func_ov000_0215e9fc(arg2, var1, 4, 0);
    while (var6 >= 0) {
        func_020a35cc((unsigned char*)arg3, var6);
        func_ov000_02174738(arg4, var6);
        Struct_ov026_021d8ba0_6* var7 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg4, var6);
        if (var7) {
            GameObject* var8 = var3->GetPartyMemberByIndex(var6);
            if (var8) {
                var7->unknown_28_ = *((Struct_ov023_021f2a48_2*)var8)->unknown_130_;
            }
        }
        if (arg0 >= 0) {
            Struct_ov026_021d8ba0_6* var9 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg4, var6);
            if (var9) {
                var9->unknown_10_[var9->unknown_18_] = 100;
                var9->unknown_24_0_ = 0;
            }
        }
        unsigned short var10 = arg5->unknown_0_;
        GameObject* var11 = var3->GetPartyMemberByIndex(var6);
        if (var11) {
            var11->obj3D_.MakeHidden();
            var11->obj3D_.SetField06(var10);
            memset(&arg6[var6], 0, sizeof(Struct_ov026_021dce34_3));
            func_02049c88(var11, &arg6[var6]);
            func_02053da0((char*)var11, (Struct_02053da0*)&arg7[var6]);
            func_0208936c((char*)var11->currentStats_, (char*)((Struct_ov023_021f2a48_2*)var11)->unknown_130_, (char*)var11->baseStats_);
            func_ov026_021dc8fc(arg1, arg2, arg3, arg4, arg8, arg9, var6);
            func_020531f0(var11);
            func_02039d84((Struct_02039d84*)var11);
            ((Struct_ov023_021f2a48_2*)var11)->unknown_c1_.unknown_0_0_ |= 3;
            ((Struct_ov023_021f2a48_2*)var11)->unknown_c2_5_ = 1;
            func_02033fdc((Struct_02033fdc*)var11);
            func_02033b88((Struct_02010604*)var11, 0);
            func_0203409c((unsigned char*)var11);
            var11->obj3D_.SetInheritedAlpha(0x1f);
            func_02039d58((unsigned char*)var11);
            if (!(*((Struct_ov023_021f2a48_2*)var11)->unknown_130_ & 1)) {
                if (((Struct_ov023_021f2a48_2*)var11)->unknown_18c_ & 1) {
                    ((Struct_ov023_021f2a48_2*)var11)->unknown_18c_ &= ~1;
                }
            }
            if (*((Struct_ov023_021f2a48_2*)var11)->unknown_130_ & 1) {
                if (!(((Struct_ov023_021f2a48_2*)var11)->unknown_18c_ & 1)) {
                    ((Struct_ov023_021f2a48_2*)var11)->unknown_18c_ |= 1;
                }
            }
            entries[id].pos = m->obj3D_.position_;
            entries[id].angle = m->obj3D_.rotation_.y;
            added = 1;
            AddEntry02168644((char*)self, id);
            SetFlag0x1ceBit0x1_02039894((unsigned char*)m);
            func_ov000_02167fb0(self, m);
            if (m->obj3D_.actorIndex_ == 0 && func_0202c540(link)) {
                func_ov017_0219c774(events->handle, 0, 0);
            }
        }
        func_ov017_021917f0(var6, 1);
        var6 = func_ov000_0215fad4(arg2);
    }
    if (var5) {
        func_ov000_02160fbc(arg1, 0x80000000);
        func_ov000_021675a0(arg1);
        func_ov000_02167e6c((unsigned char*)arg1);
        func_ov026_021daec8(arg2, arg11, 0);
        if (arg2->unknown_8e20_ == 0) {
            func_ov000_021676a8(arg1);
        }
        func_ov000_02174b14(arg4);
        func_ov000_0217a8f4(arg4);
        if (func_020a36a8((Struct_020a36a8*)arg3)) {
            unsigned char var12 = 0;
            unsigned char var13 = 0;
            int var14 = func_ov000_0215e9fc(arg2, var2, 4, 0);
            int var15;
            for (var15 = 0; var15 < var14; var15++) {
                GameObject* var16 = var3->GetCombatantByIndex(var2[var15]);
                if (var16 && ((Struct_ov023_021f2a48_2*)var16)->unknown_be_ != 4 && ((Struct_ov023_021f2a48_2*)var16)->unknown_be_ != 6) {
                    var12 |= 1 << var15;
                }
            }
            for (var15 = 0; var15 < 8; var15++) {
                GameObject* var17 = var3->GetCombatantByIndex(var15 + 0xc0);
                if (var17 && var17->obj3D_.IsVisible() && !func_02010088((Struct_02010088*)var17) &&
                    !func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)var17)) {
                    var13 |= 1 << var15;
                }
            }
            var0.unknown_0_ = arg3->unknown_8_;
            var0.unknown_b_ = var13;
            var0.unknown_a_ = var12;
            var0.unknown_4_ = arg0;
            var0.unknown_c_ = arg3->unknown_35_;
            var0.unknown_e_ = arg3->unknown_c_;
            for (int var18 = 0; var18 < 4; var18++) {
                if (func_020a35e0((unsigned char*)arg3, var18)) {
                    var0.unknown_8_ |= 1 << var18;
                } else {
                    var0.unknown_8_ &= ~(1 << var18);
                }
            }
            var0.unknown_9_ = arg3->unknown_2a_;
            var0.unknown_2_ = arg3->unknown_2_;
            func_ov017_021cbc48(&var0);
            func_ov017_021cdf80((char*)arg2, 1);
            func_ov017_021c847c();
            if (arg3->unknown_35_ == 2) {
                func_ov000_0217fcc4(arg4, -1);
            }
        }
    }
    if (func_ov000_0215fc60((char*)arg2) != 0) {
        if (func_0202c540(func_0202ae18()) != 0) {
            func_ov000_02181364(arg4);
            func_ov000_0217fcc4(arg4, -1);
            func_ov000_021816e8(arg4, -1);
            func_ov000_02181694(arg4, 0);
        } else {
            for (int var19 = 1; var19 < 4; var19++) {
                Struct_ov026_021d8ba0_6* var20 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg4, var19);
                if (var20 != 0) {
                    func_ov000_0217f5d0(var20);
                    var20->unknown_10_[var20->unknown_18_] = 100;
                }
            }
        }
    }
}
