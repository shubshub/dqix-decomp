#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_0215e69c_4 {
    short unknown_0_;
    char unknown_2_[0x14 - 0x2];
    short unknown_14_;
};

struct Struct_ov006_0215e69c {
    char unknown_0_[0x14];
    unsigned char unknown_14_;
};

struct Struct_ov006_0215e69c_2 {
#if defined(jpn)
    char unknown_0_[0x962];
    unsigned short unknown_ae2_;
    char unknown_964_[0x109c - 0x964];
#else
    char unknown1_0_[0xae2];
    unsigned short unknown_ae2_;
    char unknown_ae4_[0x12a0 - 0xae4];
#endif
    Struct_ov006_0215e69c unknown_12a0_;

    Struct_ov006_0215e69c* inline_ov006_0215e69c_2() { return &unknown_12a0_; }
};

struct Struct_ov006_0215e69c_3 {
    char unknown_0_[0x4];
    void** unknown_4_;
#if defined(jpn)
    Struct_ov006_0215e69c_2* unknown1_10_;
    void* unknown_14_;
    char unknown_10_[0x2c - 0x10];
    Struct_ov006_0215e69c_4* unknown_34_;
    char unknown_30_[0x34 - 0x30];
    char unknown_3c_[0x6c - 0x34];
    char unknown_74_[0x140 - 0x6c];
    char unknown_14c_[0x164 - 0x140];
    char unknown_164_[0x17c - 0x164];
#else
    char unknown_8_[0x10 - 0x8];
    Struct_ov006_0215e69c_2* unknown1_10_;
    void* unknown_14_;
    char unknown_18_[0x34 - 0x18];
    Struct_ov006_0215e69c_4* unknown_34_;
    char unknown_38_[0x3c - 0x38];
    char unknown_3c_[0x74 - 0x3c];
    char unknown_74_[0x14c - 0x74];
    char unknown_14c_[0x170 - 0x14c];
    char unknown_170_[0x17c - 0x170];
#endif
    char unknown_17c_[0x1ec - 0x17c];
    short unknown_1ec_;
    char unknown_1ee_[0x37e - 0x1ee];
    short unknown_37e_;
    char unknown_380_[0x382 - 0x380];
    short unknown_382_;
    char unknown_384_[0x387 - 0x384];
    unsigned char unknown_387_;
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    char unknown_38a_[0x38f - 0x38a];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    char unknown_391_;
    unsigned char unknown_392_;
    char unknown_393_;
    unsigned short unknown_394_;
    unsigned char unknown_396_;
    unsigned char unknown_397_;
    char unknown_398_[0x3b4 - 0x398];
    int unknown_3b4_;
    char unknown_3b8_[0x428 - 0x3b8];
    int unknown_428_;
    unsigned char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;

    int inline_ov006_0215e69c() { return (unknown_394_ & 0x40) != 0; }
};

extern "C" int func_ov006_02153f24(void* arg0, int arg1);
struct Struct_ov006_0215a33c;
extern "C" void func_ov006_0215a33c(Struct_ov006_0215a33c*, int);
extern "C" int func_ov006_0215a384(Struct_ov006_0215e69c_3* arg0, int arg1);
extern "C" void func_ov006_0215fe34(Struct_ov006_0215e69c_3* arg0, void* arg1);
extern "C" int func_ov006_0215fecc(Struct_ov006_0215e69c_3* arg0);
extern "C" void func_ov006_02159db0(Struct_ov006_0215e69c_3* arg0);
extern "C" int func_ov006_02159e50(Struct_ov006_0215e69c_3* arg0);
void* GetBTRandom(void);
struct Random;
unsigned int NextRandomMax(Random*, int);
struct Struct_0207fdcc_2;
extern "C" void func_02080c04(Struct_0207fdcc_2*, int);
extern "C" void func_02080c20(Struct_0207fdcc_2*, int);
extern "C" int func_ov006_02158c70(Struct_ov006_0215e69c_3* arg0);
extern "C" void func_ov006_02153cbc(void* arg0, int arg1, int arg2, void* arg3);
extern "C" void func_ov006_0215759c(void* arg0, Struct_ov006_0215e69c_4* arg1, int arg2);
extern "C" void func_ov006_02158de0(Struct_ov006_0215e69c_3* arg0);
extern "C" unsigned int* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
struct Struct_020a9ea4;
extern "C" void func_020a9ea4(Struct_020a9ea4*);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* arg0);
extern "C" int func_020aad1c(void* arg0, void* arg1, int arg2, int arg3);
struct Struct_02038598_4;
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" void** func_020e5294(void* arg0, int arg1);
#if defined(jpn)
struct Container020e0310;
int KeyTable_Get(Container020e0310*, int);
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
extern "C" void func_02080c68(void* arg0, int arg1, int arg2);
struct Struct_ov006_0215e5f8;
extern "C" void func_ov006_0215e5f8(Struct_ov006_0215e5f8*, Struct_0207fdcc_2*, int, unsigned char*);

static inline short* inline_ov006_0215cc70_2(Struct_ov006_0215e69c_3* arg0) { return (short*)((char*)arg0 + 0x382); }
static inline short* inline_ov006_0215cc70_3(Struct_ov006_0215e69c_3* arg0) { return (short*)arg0; }

static inline int inline_01ff91ac_4(Struct_ov006_0215e69c* arg0) { return arg0 != 0 && arg0->unknown_14_ != 0; }

extern int data_0211e33c;
extern int data_02109bf4;

// USA: func_ov006_0215e69c
extern "C" ARM void func_ov006_0215e69c(Struct_ov006_0215e69c_3* arg0) {
    Struct_ov006_0215e69c_2* var0 = arg0->unknown1_10_;
    BackgroundLoader::GetInstance();

    if (arg0->unknown_390_ == 0) {
        arg0->unknown_3b4_ = 0;
        if (func_ov006_02158c70(arg0)) {
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
            func_02080c68(arg0->unknown_14_, 9, 0);
            arg0->unknown_394_ &= ~0x40;
            if (arg0->unknown_34_->unknown_14_ >= 0) {
                arg0->unknown_382_ = func_ov006_02153f24(arg0->unknown_74_, arg0->unknown_34_->unknown_14_);
                arg0->unknown_37e_ = 0xd;
                arg0->unknown_392_ = 0;
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_390_++;
                if (NextRandomMax((Random*)GetBTRandom(), 10000) / 100 < arg0->unknown_382_) {
                    arg0->unknown_394_ |= 0x40;
                }
                func_ov006_0215a33c((Struct_ov006_0215a33c*)arg0, arg0->inline_ov006_0215e69c());
            } else {
                var0->unknown_ae2_ &= ~0x40;
                arg0->unknown_42d_ = 0;
                arg0->unknown_42e_ = 100;
                arg0->unknown_390_ = 0x96;
                func_ov006_0215e5f8((Struct_ov006_0215e5f8*)arg0, (Struct_0207fdcc_2*)arg0->unknown_14_, 0, &arg0->unknown_397_);
            }
        }
    } else if (arg0->unknown_390_ == 1) {
        if (func_ov006_02158c70(arg0) && arg0->unknown_428_ == -1) {
            if (func_ov006_0215a384(arg0, arg0->inline_ov006_0215e69c())) {
                func_ov006_0215fe34(arg0, arg0->unknown_17c_);
            }
        } else if (arg0->unknown_428_ != -1) {
            if (func_ov006_0215fecc(arg0)) {
                arg0->unknown_37e_ = arg0->unknown_396_ + 0xe;
                arg0->unknown_392_ = 0;
                arg0->unknown_390_++;
            }
        }
    } else if (arg0->unknown_390_ == 2) {
        if (func_ov006_02158c70(arg0)) {
            short var1 = 0x10;
            if (arg0->unknown_382_ >= 3 && arg0->unknown_382_ < 10) {
                var1 = 0x11;
            } else if (*inline_ov006_0215cc70_2(arg0) >= 10 && *inline_ov006_0215cc70_2(arg0) <= 99) {
                var1 = 0x12;
            } else if (inline_ov006_0215cc70_3(arg0)[0x382 / 2] == 100) {
                var1 = arg0->unknown_396_ + 0x16;
            }
            arg0->unknown_37e_ = var1;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 3) {
        if (func_ov006_02158c70(arg0)) {
            short var2 = 0x13;
            arg0->unknown_390_++;
            if (arg0->unknown_382_ == 100) {
                arg0->unknown_390_ = 6;
                var2 = 0x18;
            }
            arg0->unknown_37e_ = var2;
            arg0->unknown_392_ = 0;
        }
    } else if (arg0->unknown_390_ == 4) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x14;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 5) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x15;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 6) {
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 7) {
        int var3 = func_ov006_02159e50(arg0);
        if (var3 != -1) {
            if (var3 == 1) {
                unsigned char var4;
                unsigned char var5;
                if (arg0->inline_ov006_0215e69c()) {
                    func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_14_, arg0->unknown_34_->unknown_0_, arg0->unknown_14c_);
                } else {
                    func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_0_, -1, arg0->unknown_14c_);
                }
                func_ov006_0215759c(arg0->unknown_17c_, arg0->unknown_34_, arg0->unknown_387_);
                var4 = arg0->unknown_388_;
                var5 = arg0->unknown_389_;
                func_ov006_02158de0(arg0);
                arg0->unknown_388_ = var4;
                arg0->unknown_389_ = var5;
                arg0->unknown_390_++;
            }
        } else {
            arg0->unknown_37e_ = 0x19;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ = (arg0->unknown_394_ | 0x20) & ~0x40;
            arg0->unknown_390_ = 0x5a;
        }
    } else if (arg0->unknown_390_ == 0x5a) {
        if (func_ov006_02158c70(arg0)) {
            func_02080c20((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            arg0->unknown_37e_ = 1;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_390_ = 0x79;
        }
    } else if (arg0->unknown_390_ == 8) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 9) {
        arg0->unknown_37e_ = 0x36;
        arg0->unknown_392_ = 0;
        func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0xa) {
        arg0->unknown_394_ |= 0x200;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            func_020466e4(func_020d6c00(), 0x80);
            func_020a9ea4((Struct_020a9ea4*)arg0->unknown_3c_);
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0xb) {
        int var6;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        var6 = 8;
        if (func_0202c540(func_0202ae18())) {
            var6 = 0x14;
        }
        if (func_020aad1c(arg0->unknown_3c_, &data_0211e33c, var6, 0) == 1) {
            func_020466f4((Struct_02038598_4*)func_020d6c00(), 0x80);
            arg0->unknown_390_++;
            arg0->unknown_394_ &= ~0x200;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (arg0->unknown_390_ == 0xc) {
        arg0->unknown_37e_ = 0x37;
        arg0->unknown_392_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0xd) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x1a;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0xe) {
        arg0->unknown_42c_ = 0;
        if (func_ov006_02158c70(arg0)) {
            func_ov006_0215e5f8((Struct_ov006_0215e5f8*)arg0, (Struct_0207fdcc_2*)arg0->unknown_14_, 0, &arg0->unknown_397_);
            var0->unknown_ae2_ &= ~0x40;
            arg0->unknown_42d_ = 0;
            arg0->unknown_42e_ = 0xf;
            arg0->unknown_390_ = 0x96;
        }
    } else if (arg0->unknown_390_ == 0xf) {
        var0->unknown_ae2_ |= 0x100;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x10) {
        var0->unknown_ae2_ |= 0x200;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x11) {
        void** var7;
        int var8;
        arg0->unknown_3b4_ = 1;
#if defined(jpn)
        SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f,
            KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
        var7 = func_020e5294(arg0->unknown_170_, arg0->unknown_1ec_);
        if (var7 != 0) {
            memset(*arg0->unknown_4_, 0, 0x80);
            func_020e4864(*var7, *arg0->unknown_4_, 1, 0, 0, 0);
            func_02080f8c((Struct_02080f8c*)arg0->unknown_14_, 0x7f, (int)(*arg0->unknown_4_));
        }
        func_020805f4(arg0->unknown_14_, 0x7f);
#endif
        func_020813ec(arg0->unknown_14_, 0x12);
        var0->unknown_ae2_ |= 0x400;
        arg0->unknown_42f_ = 1;
        var8 = 0x3e;
        if (arg0->inline_ov006_0215e69c()) {
            var8 = 0x3f;
            func_ov006_021571fc((char*)arg0->unknown1_10_);
        }
        func_0209c830((Struct_02109bf4_2*)&data_02109bf4, var8);
        func_02080c04((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
        arg0->unknown_37e_ = 0xc;
        arg0->unknown_392_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x12) {
        if (func_ov006_02158c70(arg0)) {
            if (arg0->inline_ov006_0215e69c()) {
                func_ov006_0215728c(var0);
            }
            arg0->unknown_37e_ = 0x38;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0x13) {
        if (func_ov006_02158c70(arg0)) {
            short var9;
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0x12);
            arg0->unknown_3b4_ = 0;
            var0->unknown_ae2_ &= ~0x800;
            var9 = 0x1f;
            if (arg0->inline_ov006_0215e69c()) {
                var9 = arg0->unknown_396_ + 0x1b;
            }
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = var9;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    } else if (arg0->unknown_390_ == 0x14) {
        if (func_ov006_02158c70(arg0)) {
            short var10 = 0x20;
            if (arg0->inline_ov006_0215e69c()) {
                var10 = arg0->unknown_396_ + 0x1d;
            }
            arg0->unknown_37e_ = var10;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_ = 0x78;
        }
    } else if (arg0->unknown_390_ == 100) {
        var0->unknown_ae2_ |= 0x100;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x65) {
        var0->unknown_ae2_ |= 0x200;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x66) {
        void** var11;
        unsigned char var12;
        unsigned char var13;
        func_ov006_02153cbc(arg0->unknown_74_, arg0->unknown_34_->unknown_0_, -1, arg0->unknown_14c_);
        func_ov006_0215759c(arg0->unknown_17c_, arg0->unknown_34_, arg0->unknown_387_);
        var12 = arg0->unknown_388_;
        var13 = arg0->unknown_389_;
        func_ov006_02158de0(arg0);
        arg0->unknown_388_ = var12;
        arg0->unknown_389_ = var13;
        arg0->unknown_3b4_ = 1;
#if defined(jpn)
        SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f,
            KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
        var11 = func_020e5294(arg0->unknown_170_, arg0->unknown_1ec_);
        if (var11 != 0) {
            memset(*arg0->unknown_4_, 0, 0x80);
            func_020e4864(*var11, *arg0->unknown_4_, 1, 0, 0, 0);
            func_02080f8c((Struct_02080f8c*)arg0->unknown_14_, 0x7f, (int)(*arg0->unknown_4_));
        }
        func_020805f4(arg0->unknown_14_, 0x7f);
#endif
        func_020813ec(arg0->unknown_14_, 0x12);
        var0->unknown_ae2_ |= 0x400;
        arg0->unknown_42f_ = 1;
        func_0209c830((Struct_02109bf4_2*)&data_02109bf4, 0x3e);
        arg0->unknown_37e_ = 0xc;
        arg0->unknown_392_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 0x67) {
        if (func_ov006_02158c70(arg0)) {
            arg0->unknown_37e_ = 0x38;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_ = 0x78;
        }
    } else if (arg0->unknown_390_ == 0x78) {
        if (arg0->unknown_42f_ != 0) {
            arg0->unknown_42c_ = 0;
        } else {
            Struct_ov006_0215e69c* var14 = var0->inline_ov006_0215e69c_2();
            if (!(var14 != 0 && var14->unknown_14_ != 0) && func_ov006_02158c70(arg0)) {
                func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0x12);
                arg0->unknown_3b4_ = 0;
                var0->unknown_ae2_ &= ~0x800;
                arg0->unknown_37e_ = 1;
                arg0->unknown_392_ = 0;
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_390_++;
            }
        }
    } else if (arg0->unknown_390_ == 0x79) {
        if (func_ov006_02158c70(arg0)) {
            func_ov006_0215e5f8((Struct_ov006_0215e5f8*)arg0, (Struct_0207fdcc_2*)arg0->unknown_14_, 1, &arg0->unknown_397_);
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
            arg0->unknown_38f_ = 0xa;
            arg0->unknown_390_ = 0;
        }
    } else if (arg0->unknown_390_ == 0x96) {
        unsigned short* var15 = &var0->unknown_ae2_;
        var0->unknown_ae2_ |= 0x2000;
        arg0->unknown_42d_++;
        if (arg0->unknown_42d_ >= 10) {
            arg0->unknown_42d_ = 0;
            *var15 &= ~0x2000;
            *var15 |= 0x80;
            arg0->unknown_390_ = arg0->unknown_42e_;
        }
    }
}
