#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_ov006_0215cc70 {
    short unknown_0_;
    char unknown_2_[0x14 - 0x2];
    short unknown_14_;
};

struct Struct_ov006_0215cc70_2 {
#if defined(jpn)
    char unknown_0_[0x962];
#else
    char unknown1_0_[0xae2];
#endif
    unsigned short unknown_ae2_;
};

struct Struct_ov006_0215cc70_3 {
#if defined(jpn)
    char unknown_0_[0x8];
#else
    char unknown1_0_[0x4];
    void** unknown_4_;
    char unknown_8_[0x10 - 0x8];
#endif
    Struct_ov006_0215cc70_2* unknown_10_;
    void* unknown_14_;
    char unknown_18_[0x34 - 0x18];
    Struct_ov006_0215cc70* unknown_34_;
    char unknown_38_[0x3c - 0x38];
    char unknown_3c_[0x74 - 0x3c];
#if defined(jpn)
    char unknown_74_[0x140 - 0x6c];
    char unknown_14c_[0x164 - 0x140];
    char unknown_164_[0x17c - 0x164];
#else
    char unknown_74_[0x14c - 0x74];
    char unknown_14c_[0x170 - 0x14c];
    char unknown_170_[0x17c - 0x170];
#endif
    char unknown_17c_[0x1ec - 0x17c];
    short unknown_1ec_;
    char unknown_1ee_[0x364 - 0x1ee];
    short unknown_364_;
    char unknown_366_[0x378 - 0x366];
    short unknown_378_[3];
    short unknown_37e_;
    char unknown_380_[0x382 - 0x380];
    short unknown_382_;
    char unknown_384_[0x387 - 0x384];
    unsigned char unknown_387_;
    char unknown_388_[0x38c - 0x388];
    unsigned char unknown_38c_[3];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    char unknown_391_;
    unsigned char unknown_392_;
    char unknown_393_;
    unsigned short unknown_394_;
    unsigned char unknown_396_;
    char unknown_397_[0x3b4 - 0x397];
    int unknown_3b4_;
    char unknown_3b8_[0x428 - 0x3b8];
    int unknown_428_;
    unsigned char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;
    char unknown_430_[0x432 - 0x430];
    unsigned char unknown_432_;

    int inline_ov006_0215cc70() { return (unknown_394_ & 0x40) != 0; }
};

extern "C" Struct_ov006_0215cc70* func_ov006_0215fd60(void*, short*, unsigned char*, int);
extern "C" int func_ov006_02153f24(void* arg0, int arg1);
struct Struct_ov006_02159094;
extern "C" void func_ov006_02159094(Struct_ov006_02159094*);
struct Struct_ov006_0215a33c;
extern "C" void func_ov006_0215a33c(Struct_ov006_0215a33c*, int);
extern "C" int func_ov006_0215a384(Struct_ov006_0215cc70_3* arg0, int arg1);
extern "C" void func_ov006_0215fe34(Struct_ov006_0215cc70_3* arg0, void* arg1);
extern "C" int func_ov006_0215fecc(Struct_ov006_0215cc70_3* arg0);
extern "C" int func_020100a8(GameState* arg0);
extern "C" int func_020dd4c4(signed char arg0, void* arg1);
extern "C" void func_ov006_02159db0(Struct_ov006_0215cc70_3* arg0);
extern "C" int func_ov006_02159e50(Struct_ov006_0215cc70_3* arg0);
extern "C" int func_ov006_021570b4(char*);
void* GetBTRandom(void);
struct Random;
unsigned int NextRandomMax(Random*, int);
struct Struct_0207fdcc_2;
extern "C" void func_02080c04(Struct_0207fdcc_2*, int);
extern "C" void func_02080c20(Struct_0207fdcc_2*, int);
extern "C" int func_ov006_02158c70(Struct_ov006_0215cc70_3* arg0);
extern "C" void func_ov006_02153cbc(void* arg0, int arg1, int arg2, void* arg3);
extern "C" void func_ov006_0215759c(void* arg0, Struct_ov006_0215cc70* arg1, int arg2);
extern "C" void func_ov006_02158de0(Struct_ov006_0215cc70_3* arg0);
extern "C" unsigned int* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
struct Struct_020a9ea4;
extern "C" void func_020a9ea4(Struct_020a9ea4*);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* arg0);
extern "C" int func_020aad1c(void* arg0, void* arg1, int arg2, int arg3);
struct Struct_02038598_4;
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
#if defined(jpn)
struct Container020e0310;
int KeyTable_Get(struct Container020e0310*, int);
#else
extern "C" void** func_020e5294(void* arg0, int arg1);
#endif
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" void func_020e4864(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5);
struct Struct_02080f8c;
extern "C" void func_02080f8c(Struct_02080f8c*, int, int);
extern "C" void func_020805f4(void* arg0, int arg1);
extern "C" void func_020813ec(void* arg0, int arg1);
extern "C" void func_ov006_021571fc(char*);
struct Struct_02109bf4_2;
extern "C" void func_0209c830(Struct_02109bf4_2*, int);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" void func_ov006_0215728c(void*);

static inline short* inline_ov006_0215cc70_2(Struct_ov006_0215cc70_3* arg0) { return (short*)((char*)arg0 + 0x382); }
static inline short* inline_ov006_0215cc70_3(Struct_ov006_0215cc70_3* arg0) { return (short*)arg0; }
#if defined(jpn)
static inline Struct_ov006_0215cc70* inline_ov006_0215cc70_4(Struct_ov006_0215cc70_3* arg0) { return *(Struct_ov006_0215cc70**)((char*)arg0 + 0x2c); }
#else
static inline Struct_ov006_0215cc70* inline_ov006_0215cc70_4(Struct_ov006_0215cc70_3* arg0) { return *(Struct_ov006_0215cc70**)((char*)arg0 + 0x34); }
#endif

extern int data_0211e33c;
extern int data_02109bf4;

// USA: func_ov006_0215cc70
extern "C" ARM void func_ov006_0215cc70(Struct_ov006_0215cc70_3* arg0) {
    Struct_ov006_0215cc70_2* var0 = arg0->unknown_10_;
    BackgroundLoader::GetInstance();

    if (arg0->unknown_390_ == 0) {
        Struct_ov006_0215cc70* var1;
        arg0->unknown_3b4_ = 0;
        arg0->unknown_387_ = 0;
        var1 = func_ov006_0215fd60(arg0, arg0->unknown_378_, arg0->unknown_38c_, (int)&arg0->unknown_387_);
        arg0->unknown_34_ = var1;
        if (var1 != 0) {
            arg0->unknown_382_ = func_ov006_02153f24(arg0->unknown_74_, var1->unknown_0_);
            arg0->unknown_390_++;
        } else {
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            arg0->unknown_390_ = 0x78;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0xb;
            arg0->unknown_392_ = 0;
        }
    } else if (arg0->unknown_390_ == 1) {
        func_ov006_0215a33c((Struct_ov006_0215a33c*)arg0, 0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 2) {
        if (arg0->unknown_428_ == -1) {
            if (func_ov006_0215a384(arg0, 0)) {
                func_ov006_0215fe34(arg0, arg0->unknown_17c_);
            }
        } else if (func_ov006_0215fecc(arg0)) {
            int var2 = func_020dd4c4(func_020100a8(GameState::GetInstance()), arg0->unknown_17c_);
            arg0->unknown_390_ = 5;
            if (var2 & 0x10) {
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_37e_ = arg0->unknown_396_ + 4;
                arg0->unknown_392_ = 0;
                arg0->unknown_390_++;
            }
        }
    } else if (arg0->unknown_390_ == 3) {
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 4) {
        int var3 = func_ov006_02159e50(arg0);
        if (var3 != -1) {
            if (var3 == 1) {
                arg0->unknown_390_++;
            }
        } else {
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            arg0->unknown_390_ = 0x78;
        }
    } else if (arg0->unknown_390_ == 5) {
        if (func_ov006_021570b4((char*)var0) == 0) {
            arg0->unknown_394_ &= ~0x40;
            bool var4 = false;
            if (arg0->unknown_34_ != 0 && arg0->unknown_34_->unknown_14_ > 0) {
                var4 = true;
            }
            if (var4) {
                arg0->unknown_382_ = func_ov006_02153f24(arg0->unknown_74_, inline_ov006_0215cc70_4(arg0)->unknown_14_);
                arg0->unknown_37e_ = 0xd;
                arg0->unknown_392_ = 0;
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_390_++;
                if (NextRandomMax((Random*)GetBTRandom(), 10000) / 100 < arg0->unknown_382_) {
                    arg0->unknown_394_ |= 0x40;
                }
                func_ov006_0215a33c((Struct_ov006_0215a33c*)arg0, arg0->inline_ov006_0215cc70());
            } else {
                func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0x10);
                func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0x11);
                func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
                func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
                arg0->unknown_10_->unknown_ae2_ |= 0x10;
                arg0->unknown_432_ = 1;
                arg0->unknown_42d_ = 0;
                arg0->unknown_42e_ = 100;
                arg0->unknown_390_ = 0x96;
            }
        }
    } else if (arg0->unknown_390_ == 6) {
        if (func_ov006_02158c70(arg0) && arg0->unknown_428_ == -1) {
            if (func_ov006_0215a384(arg0, arg0->inline_ov006_0215cc70())) {
                func_ov006_0215fe34(arg0, arg0->unknown_17c_);
            }
        } else if (arg0->unknown_428_ != -1) {
            if (func_ov006_0215fecc(arg0)) {
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_37e_ = arg0->unknown_396_ + 0xe;
                arg0->unknown_392_ = 0;
                arg0->unknown_390_++;
            }
        }
    } else if (arg0->unknown_390_ == 7) {
        if (func_ov006_02158c70(arg0)) {
            short var5 = 0x10;
            if (arg0->unknown_382_ >= 3 && arg0->unknown_382_ < 10) {
                var5 = 0x11;
            } else if (*inline_ov006_0215cc70_2(arg0) >= 10 && *inline_ov006_0215cc70_2(arg0) <= 99) {
                var5 = 0x12;
            } else if (inline_ov006_0215cc70_3(arg0)[0x382 / 2] == 100) {
                var5 = arg0->unknown_396_ + 0x16;
            }
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = var5;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 8) {
        if (func_ov006_021570b4((char*)var0) == 0) {
            if (func_ov006_02158c70(arg0)) {
                short var6 = 0x13;
                arg0->unknown_390_++;
                if (arg0->unknown_382_ == 100) {
                    arg0->unknown_390_ = 0xb;
                    var6 = 0x18;
                }
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_37e_ = var6;
                arg0->unknown_392_ = 0;
            }
        }
    } else if (arg0->unknown_390_ == 9) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0x14;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 10) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0x15;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0xb) {
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0xc) {
        int var7 = func_ov006_02159e50(arg0);
        if (var7 != -1) {
            if (var7 == 1) {
                if (arg0->inline_ov006_0215cc70()) {
                    func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_14_, arg0->unknown_34_->unknown_0_, arg0->unknown_14c_);
                } else {
                    func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_0_, -1, arg0->unknown_14c_);
                }
                func_ov006_0215759c(arg0->unknown_17c_, arg0->unknown_34_, arg0->unknown_387_);
                func_ov006_02158de0(arg0);
                arg0->unknown_364_ = -1;
                arg0->unknown_390_++;
            }
        } else {
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            arg0->unknown_394_ = (arg0->unknown_394_ | 0x20) & ~0x40;
            func_02080c20((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_37e_ = 0x19;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_390_ = 0x5a;
        }
    } else if (arg0->unknown_390_ == 0x5a) {
        if (func_ov006_02158c70(arg0)) {
            func_02080c20((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_37e_ = 0x24;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_394_ |= 0x100;
            arg0->unknown_38f_ = 5;
            arg0->unknown_390_ = 0;
        }
    } else if (arg0->unknown_390_ == 0xd) {
        arg0->unknown_37e_ = 0x36;
        arg0->unknown_392_ = 0;
        func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0xe) {
        arg0->unknown_394_ |= 0x200;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            func_020466e4(func_020d6c00(), 0x80);
            func_020a9ea4((Struct_020a9ea4*)arg0->unknown_3c_);
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0xf) {
        int var8;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        var8 = 8;
        if (func_0202c540(func_0202ae18())) {
            var8 = 0x14;
        }
        if (func_020aad1c(arg0->unknown_3c_, &data_0211e33c, var8, 0) == 1) {
            func_020466f4((Struct_02038598_4*)func_020d6c00(), 0x80);
            arg0->unknown_390_++;
            arg0->unknown_394_ &= ~0x200;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (arg0->unknown_390_ == 0x10) {
        arg0->unknown_37e_ = 0x37;
        arg0->unknown_392_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x11) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x1a;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20;
            func_02080c20((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0x12) {
        arg0->unknown_42c_ = 0;
        if (func_ov006_02158c70(arg0)) {
            func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0x10);
            func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0x11);
            func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
            func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_10_->unknown_ae2_ |= 0x10;
            arg0->unknown_432_ = 1;
            arg0->unknown_42d_ = 0;
            arg0->unknown_42e_ = 0x13;
            arg0->unknown_390_ = 0x96;
        }
    } else if (arg0->unknown_390_ == 0x13) {
        var0->unknown_ae2_ |= 0x100;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x14) {
        var0->unknown_ae2_ |= 0x200;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x15) {
        void** var9;
        int var10;
        arg0->unknown_3b4_ = 1;
#if defined(jpn)
        SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f,
                                   KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
        var9 = func_020e5294(arg0->unknown_170_, arg0->unknown_1ec_);
        if (var9 != 0) {
            memset(*arg0->unknown_4_, 0, 0x80);
            func_020e4864(*var9, *arg0->unknown_4_, 1, 0, 0, 0);
            func_02080f8c((Struct_02080f8c*)arg0->unknown_14_, 0x7f, (int)(*arg0->unknown_4_));
        }
        func_020805f4(arg0->unknown_14_, 0x7f);
#endif
        func_020813ec(arg0->unknown_14_, 0x12);
        var0->unknown_ae2_ |= 0x400;
        arg0->unknown_42f_ = 1;
        var10 = 0x3e;
        if (arg0->inline_ov006_0215cc70()) {
            var10 = 0x3f;
            func_ov006_021571fc((char*)arg0->unknown_10_);
        }
        func_0209c830((Struct_02109bf4_2*)&data_02109bf4, var10);
        arg0->unknown_37e_ = 0xc;
        arg0->unknown_392_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x16) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x38;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0x17) {
        if (func_ov006_02158c70(arg0)) {
            short var11;
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0x12);
            arg0->unknown_3b4_ = 0;
            var0->unknown_ae2_ &= ~0x800;
            var11 = 0x1f;
            if (arg0->inline_ov006_0215cc70()) {
                func_ov006_0215728c(arg0->unknown_10_);
                var11 = arg0->unknown_396_ + 0x1b;
            }
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = var11;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0x18) {
        if (func_ov006_02158c70(arg0)) {
            short var12 = 0x20;
            if (arg0->inline_ov006_0215cc70()) {
                var12 = arg0->unknown_396_ + 0x1d;
            }
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = var12;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_ = 0x78;
            arg0->unknown_394_ &= ~0x40;
        }
    } else if (arg0->unknown_390_ == 100) {
        var0->unknown_ae2_ |= 0x100;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x65) {
        var0->unknown_ae2_ |= 0x200;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x66) {
        if (arg0->unknown_34_ != 0) {
            void** var13;
            arg0->unknown_3b4_ = 1;
#if defined(jpn)
            SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f,
                                       KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
            var13 = func_020e5294(arg0->unknown_170_, arg0->unknown_1ec_);
            if (var13 != 0) {
                memset(*arg0->unknown_4_, 0, 0x80);
                func_020e4864(*var13, *arg0->unknown_4_, 1, 0, 0, 0);
                func_02080f8c((Struct_02080f8c*)arg0->unknown_14_, 0x7f, (int)(*arg0->unknown_4_));
            }
            func_020805f4(arg0->unknown_14_, 0x7f);
#endif
            func_020813ec(arg0->unknown_14_, 0x12);
            func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_0_, -1, arg0->unknown_14c_);
            func_ov006_0215759c(arg0->unknown_17c_, arg0->unknown_34_, arg0->unknown_387_);
            func_ov006_02158de0(arg0);
            arg0->unknown_364_ = -1;
            arg0->unknown_42f_ = 1;
            func_0209c830((Struct_02109bf4_2*)&data_02109bf4, 0x3e);
            var0->unknown_ae2_ |= 0x400;
            func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_37e_ = 0xc;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        } else {
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_02159094((Struct_ov006_02159094*)arg0);
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0xb;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_ = 0x78;
        }
    } else if (arg0->unknown_390_ == 0x67) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x38;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_ = 0x78;
        }
    } else if (arg0->unknown_390_ == 0x78) {
        if (arg0->unknown_42f_ != 0) {
            arg0->unknown_42c_ = 0;
        } else if (func_ov006_02158c70(arg0)) {
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0x12);
            var0->unknown_ae2_ &= ~0x800;
            func_02080c20((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0x24;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x100;
            arg0->unknown_38f_ = 5;
            arg0->unknown_390_ = 0;
        }
    } else if (arg0->unknown_390_ == 0x96) {
        unsigned short* var14 = &var0->unknown_ae2_;
        var0->unknown_ae2_ |= 0x2000;
        arg0->unknown_42d_++;
        if (arg0->unknown_42d_ >= 10) {
            arg0->unknown_42d_ = 0;
            *var14 &= ~0x2000;
            *var14 |= 0x80;
            arg0->unknown_390_ = arg0->unknown_42e_;
        }
    }
}
