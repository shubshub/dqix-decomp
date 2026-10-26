#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif


enum Enum_ov027_021dbdec { Enum_ov027_021dbdec_0 = 0, Enum_ov027_021dbdec_1 = 1 };

struct Struct_ov027_021dbdec {
    int unknown_0_[0x20];
};

struct Struct_ov027_021dbdec_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char unknown_a_[6];
    unsigned char unknown_10_[0x36 - 0x10];
    unsigned short unknown_36_;
    Struct_ov027_021dbdec unknown_38_;
};

struct Struct_ov027_021dbdec_3 {
    unsigned char unknown_0_[0xc0];
    Struct_ov027_021dbdec_2 unknown_c0_;
    unsigned char unknown_178_[0x180 - 0xc0 - sizeof(Struct_ov027_021dbdec_2)];
};

typedef void (*Type_0201282c_3)(int, void*);

struct Struct_ov027_021dbdec_4 {
    unsigned char unknown_0_[0x40];
    unsigned char unknown_40_[0x400];
    unsigned char unknown_440_[0xc4];
    int unknown_504_;
    unsigned char unknown_508_[4];
    unsigned char unknown_50c_;
    unsigned char unknown_50d_[0x518 - 0x50d];
    unsigned short unknown_518_;
    unsigned short unknown_51a_;
    Type_0201282c_3 unknown_51c_;
    int unknown_520_;
    unsigned char unknown_524_[2];
    unsigned short unknown_526_;
    unsigned short unknown_528_;
    unsigned short unknown_52a_;
    unsigned short unknown_52c_;
    unsigned char unknown_52e_[0x5e0 - 0x52e];
    unsigned short unknown_5e0_;
    unsigned short unknown_5e2_;
    int unknown_5e4_;
    int unknown_5e8_;
    int unknown_5ec_;
    unsigned char unknown_5f0_[0x10];
    Struct_ov027_021dbdec_3 unknown_600_[0x10];
};

struct Struct_ov027_021e3400 {
    void* unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_[6];
};

struct Struct_ov027_021e33e0_5 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[6];
    Struct_ov027_021dbdec_4* unknown_8_;
    unsigned char unknown_c_[0x14];
    Struct_ov027_021e3400 unknown_20_;
};

extern Struct_ov027_021e33e0_5 data_ov027_021e33e0;

struct Struct_ov027_021dd8ec_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

extern Struct_ov027_021dd8ec_3 data_ov027_021dd8ec;
extern Struct_ov027_021e3400 data_ov027_021e3400 __attribute__((aligned(32)));

struct Struct_020d5254;

extern "C" ARM void func_ov027_021dbdec(void* arg0);
extern "C" void func_ov027_021dbd7c(void);
extern "C" void func_ov027_021db4e0(int arg0);
extern "C" int func_ov027_021db430(void);
extern "C" int func_ov027_021db3c0(Struct_ov027_021e3400* arg0);
extern "C" void func_ov027_021dcc8c(void);
extern "C" void func_ov027_021dd0cc(int arg0, int arg1);
extern "C" int func_020d4770(int arg0, int arg1, int arg2);
extern "C" int func_020d54d0(void* arg0, void* arg1, void* arg2, int arg3, unsigned short arg4);
extern "C" void func_020ca3b8(const void* src, void* dst, unsigned int len);
extern "C" void HaltSystem(void);

extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
void DMAMemcpySynchronous16Bit(int chan, unsigned int src, unsigned int dst, unsigned int len);
extern "C" int func_020d6ad4(int arg0, int arg1, int arg2, int arg3, unsigned short arg4);
extern "C" int func_020d5254(int arg0, Struct_020d5254* arg1);
extern "C" int func_020d503c(int arg0);
extern "C" int func_020d57f4(int arg0, int arg1, int arg2, int arg3, unsigned short arg4, unsigned short arg5,
                               unsigned short arg6, int arg7, int arg8, int arg9, int arg10);

// USA: func_ov027_021dbdec
extern "C" ARM void func_ov027_021dbdec(void* arg0) {
    Struct_ov027_021dbdec_2* var0 = (Struct_ov027_021dbdec_2*)arg0;
    Struct_ov027_021dbdec_4* var1 = data_ov027_021e33e0.unknown_8_;

    switch (var0->unknown_0_) {
    case 0:
        if (var0->unknown_2_ != 0) {
            var1->unknown_51c_(0x100, var0);
        } else {
            var1->unknown_51c_(0x15, var0);
            func_ov027_021dd0cc(0x1d, func_020d6ad4((int)func_ov027_021dbdec,
                data_ov027_021dd8ec.unknown_6_, data_ov027_021dd8ec.unknown_2_, data_ov027_021dd8ec.unknown_0_,
                data_ov027_021dd8ec.unknown_4_));
        }
        return;

    case 0x1d:
        if (var0->unknown_2_ != 0) {
            var1->unknown_51c_(0x100, var0);
        } else {
            data_ov027_021e33e0.unknown_20_.unknown_0_ = var1->unknown_440_;
            if (data_ov027_021e33e0.unknown_20_.unknown_4_ == 0) {
                data_ov027_021e33e0.unknown_20_.unknown_4_ = 1;
            }
            if (data_ov027_021e33e0.unknown_20_.unknown_6_ == 0) {
                data_ov027_021e33e0.unknown_20_.unknown_6_ = 0xc8;
            }
            data_ov027_021e33e0.unknown_20_.unknown_8_[0] = 0xff;
            data_ov027_021e33e0.unknown_20_.unknown_8_[1] = 0xff;
            data_ov027_021e33e0.unknown_20_.unknown_8_[2] = 0xff;
            data_ov027_021e33e0.unknown_20_.unknown_8_[3] = 0xff;
            data_ov027_021e33e0.unknown_20_.unknown_8_[4] = 0xff;
            data_ov027_021e33e0.unknown_20_.unknown_8_[5] = 0xff;
            var1->unknown_5e4_ = 1;
            var1->unknown_5e8_ = 1;
            func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                (Struct_020d5254*)&data_ov027_021e3400));
        }
        return;

    case 10:
        if (var0->unknown_2_ != 0) {
            var1->unknown_51c_(0x100, var0);
        } else {
            switch (var0->unknown_8_) {
            case 3:
                return;

            case 5: {
                Struct_ov027_021dbdec_3* var2 = var1->unknown_600_;
                int var3;
                for (var3 = 0; var3 < var1->unknown_5e0_; var3++) {
                    int var4;
                    int var5;
                    int var6;
                    int var7;
                    int var8;
                    var4 = 0;
                    var8 = 0;
                    var5 = 0;
                    var6 = 0;
                    var7 = 0;
                    if (var0->unknown_a_[0] == var2[var3].unknown_c0_.unknown_a_[0] && var0->unknown_a_[1] == var2[var3].unknown_c0_.unknown_a_[1]) var8 = 1;
                    if (var8) {
                        if (var0->unknown_a_[2] == var2[var3].unknown_c0_.unknown_a_[2]) var7 = 1;
                    }
                    if (var7) {
                        if (var0->unknown_a_[3] == var2[var3].unknown_c0_.unknown_a_[3]) var6 = 1;
                    }
                    if (var6) {
                        if (var0->unknown_a_[4] == var2[var3].unknown_c0_.unknown_a_[4]) var5 = 1;
                    }
                    if (var5) {
                        if (var0->unknown_a_[5] == var2[var3].unknown_c0_.unknown_a_[5]) var4 = 1;
                    }
                    if (var4) {
                        var2[var3].unknown_c0_.unknown_36_ = var0->unknown_36_;
                        var2[var3].unknown_c0_.unknown_38_ = var0->unknown_38_;
                        InvalidateDataCacheRange(&var1->unknown_600_[var3], 0xc0);
                        DMAMemcpySynchronous16Bit(data_ov027_021e33e0.unknown_0_, (unsigned int)var1->unknown_440_,
                            (unsigned int)&var1->unknown_600_[var3], 0xc0);
                        var1->unknown_5ec_ = var3;
                        goto found;
                    }
                }
                if (var3 < 0x10) {
                    var1->unknown_5e0_ = var3 + 1;
                    func_020ca3b8(var0, &var2[var3].unknown_c0_, 0xb8);
                    InvalidateDataCacheRange(&var1->unknown_600_[var3], 0xc0);
                    DMAMemcpySynchronous16Bit(data_ov027_021e33e0.unknown_0_, (unsigned int)var1->unknown_440_,
                        (unsigned int)&var1->unknown_600_[var3], 0xc0);
                    var1->unknown_5ec_ = var3;
                }
            found:
                var1->unknown_51c_(4, var0);
                if (var1->unknown_5e4_ == 0) return;
                if (var1->unknown_5e8_ != 0 && func_ov027_021db3c0(&data_ov027_021e3400) == 0) {
                    func_ov027_021dcc8c();
                }
                func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                    (Struct_020d5254*)&data_ov027_021e3400));
                return;
            }

            case 4:
                var1->unknown_51c_(5, var0);
                if (var1->unknown_5e4_ == 0) return;
                if (var1->unknown_5e8_ != 0 && func_ov027_021db3c0(&data_ov027_021e3400) == 0) {
                    func_ov027_021dcc8c();
                }
                func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                    (Struct_020d5254*)&data_ov027_021e3400));
                return;

            default:
                var1->unknown_51c_(0x100, var0);
                return;
            }
        }
        return;

    case 11:
        if (var0->unknown_2_ != 0) {
            var1->unknown_51c_(0x100, var0);
        } else {
            arg0 = (void*)var1->unknown_520_;
            func_ov027_021dd0cc(0xc, func_020d54d0((void*)func_ov027_021dbdec, arg0, 0, 1, 0));
        }
        return;

    case 12:
        if (var0->unknown_2_ != 0) {
            var1->unknown_5e0_ = 0;
            var1->unknown_51c_(0xb, var0);
        } else {
            switch (var0->unknown_8_) {
            case 6:
                var1->unknown_52a_ = 0;
                var1->unknown_528_ = 1;
                return;

            case 7:
                var1->unknown_5e2_ = *(unsigned short*)var0->unknown_a_;
                var1->unknown_51c_(6, var0);
                var1->unknown_52a_ = 1;
                if (func_020d4770(1, (int)func_ov027_021dbd7c, 0) != 0) return;
                func_ov027_021dd0cc(0xe, func_020d57f4((int)func_ov027_021dbdec,
                    var1->unknown_504_, var1->unknown_51a_, (int)var1->unknown_40_, var1->unknown_518_,
                    var1->unknown_52c_ ? Enum_ov027_021dbdec_0 : Enum_ov027_021dbdec_1, 0, 0, 0, 1, 1));
                return;

            case 9:
                var1->unknown_51c_(0xa, var0);
                var1->unknown_52a_ = 0;
                var1->unknown_528_ = 0;
                return;

            case 0x1a:
                return;

            default:
                var1->unknown_51c_(0x100, var0);
                return;
            }
        }
        return;

    case 14:
        switch (var0->unknown_4_) {
        case 0xa:
            var1->unknown_528_ = 1;
            if (func_ov027_021db430() != 0) {
                var1->unknown_51c_(0x19, 0);
            }
            return;

        case 0xc:
            return;

        case 0xd:
            return;

        default:
            var1->unknown_51c_(0x100, var0);
            return;
        }
        return;

    case 15:
        var1->unknown_50c_ = 0;
        if (var0->unknown_2_ == 0) {
            var1->unknown_51c_(8, var0);
        } else if (var0->unknown_2_ == 9) {
            var1->unknown_51c_(0x29, var0);
        } else {
            var1->unknown_51c_(0x12, var0);
        }
        if (data_ov027_021e33e0.unknown_8_->unknown_526_ == 0) {
            var1->unknown_51c_(0x19, 0);
        }
        return;

    case 1:
        if (var0->unknown_2_ != 0) {
            var1->unknown_526_ = 0;
            var1->unknown_51c_(0x100, var0);
        } else {
            var1->unknown_52a_ = 0;
            data_ov027_021e33e0.unknown_8_->unknown_528_ = 0;
            func_ov027_021dd0cc(2, func_020d503c((int)func_ov027_021dbdec));
        }
        return;

    case 2:
        if (var0->unknown_2_ != 0) {
            var1->unknown_526_ = 0;
            var1->unknown_51c_(0x100, var0);
        } else {
            func_ov027_021db4e0((int)var0);
        }
        return;

    case 0x15:
        if (func_ov027_021db430() != 0) {
            var1->unknown_51c_(0x19, 0);
        }
        return;

    case 0x80:
        switch (var0->unknown_4_) {
        case 0x16:
            HaltSystem();
            return;
        case 0x17:
            return;
        default:
            return;
        }
        return;

    default:
        var1->unknown_51c_(0x100, var0);
        return;
    }
}
