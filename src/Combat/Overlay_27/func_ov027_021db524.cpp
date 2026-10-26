#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>


struct Struct_ov027_021e33e0 {
    unsigned char unknown_0_[8];
    unsigned char* unknown_8_;
    unsigned char* unknown_c_;
};

extern Struct_ov027_021e33e0 data_ov027_021e33e0;

struct Struct_ov027_021dd8ec {
    unsigned char unknown_0_[0xc];
    int unknown_c_;
};

extern Struct_ov027_021dd8ec data_ov027_021dd8ec;

struct Struct_ov027_021db524 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
};

struct Struct_0202db64;

typedef void (*Type_ov027_021db524)(int, void*);

extern "C" ARM void func_ov027_021db524(Struct_ov027_021db524* arg0);
extern "C" void func_ov027_021db4e0(int arg0);
extern "C" int func_ov027_021db430(void);
extern "C" void func_ov027_021dd0cc(int arg0, int arg1);
extern "C" void func_020d4770(int arg0, int arg1, int arg2);
extern "C" void func_020c976c(unsigned int cycles);
extern "C" void HaltSystem(void);

extern "C" void func_ov027_021db490(void);
extern "C" int func_020d507c(int arg0, Struct_0202db64* arg1);
extern "C" int func_020d6a84(int arg0, int arg1);
extern "C" int func_020d51a8(int arg0, int arg1);
extern "C" int func_020d503c(int arg0);
extern "C" int func_020d57f4(int arg0, int arg1, int arg2, int arg3, unsigned short arg4, unsigned short arg5,
                      unsigned short arg6, int arg7, int arg8, int arg9, int arg10);
extern "C" int func_020d472c(void* arg0);

#pragma optimize_for_size off

// USA: func_ov027_021db524
extern "C" ARM void func_ov027_021db524(Struct_ov027_021db524* arg0) {
    switch (arg0->unknown_0_) {
    case 0:
        if (arg0->unknown_2_ != 0) {
            Type_ov027_021db524 var0 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var0(0x100, arg0);
        } else {
            func_ov027_021db490();
        }
        break;

    case 0x1d:
        if (arg0->unknown_2_ != 0) {
            Type_ov027_021db524 var1 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var1(0x100, arg0);
        } else {
            func_ov027_021dd0cc(7, func_020d507c((int)func_ov027_021db524,
                (Struct_0202db64*)data_ov027_021e33e0.unknown_8_));
        }
        break;

    case 7: {
        Type_ov027_021db524 var2 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
        var2(0x15, arg0);
        func_ov027_021dd0cc(0x19, func_020d6a84((int)func_ov027_021db524, 1));
        break;
    }

    case 0x19:
        if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 0) {
            if (arg0->unknown_2_ != 0) {
                Type_ov027_021db524 var3 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var3(0x100, arg0);
            } else {
                func_ov027_021dd0cc(8, func_020d51a8((int)func_ov027_021db524,
                    data_ov027_021dd8ec.unknown_c_));
            }
        } else {
            if (arg0->unknown_2_ != 0) {
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) = 0;
                {
                    Type_ov027_021db524 var4 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var4(0x100, arg0);
                }
            } else {
                func_ov027_021db4e0((int)arg0);
            }
        }
        break;

    case 8:
        if (arg0->unknown_2_ != 0) {
            Type_ov027_021db524 var5 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var5(0x100, arg0);
        } else {
            switch (arg0->unknown_8_) {
            case 0:
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52a) = 0;
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x528) = 0;
                break;

            case 7: {
                if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 1) break;
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52a) |= 1 << arg0->unknown_10_;
                {
                    Type_ov027_021db524 var6 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var6(0, arg0);
                }
                if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x528) == 0) {
                    unsigned char* var7 = data_ov027_021e33e0.unknown_c_;
                    var7 += 0x1000;
                    if (*(int*)(var7 + 0x31c) == 0) {
                        int var8 = 1;
                        *(int*)(var7 + 0x31c) = var8;
                        if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52c) != 0) var8 = 0;
                        func_ov027_021dd0cc(0xe, func_020d57f4((int)func_ov027_021db524,
                            *(int*)(data_ov027_021e33e0.unknown_8_ + 0x504),
                            *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x51a),
                            (int)(data_ov027_021e33e0.unknown_8_ + 0x40),
                            *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x518),
                            (unsigned short)var8, 0, 0, 0, 1, 1));
                        break;
                    }
                }
                if (func_ov027_021db430() != 0) {
                    Type_ov027_021db524 var9 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var9(0x19, 0);
                }
                break;
            }

            case 9: {
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52a) &= ~(1 << arg0->unknown_10_);
                {
                    Type_ov027_021db524 var10 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var10(1, arg0);
                }
                break;
            }

            case 2: {
                if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 1) break;
                Type_ov027_021db524 var11 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var11(0x1c, arg0);
                break;
            }

            case 0x1a:
                break;

            default: {
                Type_ov027_021db524 var12 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var12(0x100, arg0);
                break;
            }
            }
        }
        break;

    case 14:
        *(int*)(data_ov027_021e33e0.unknown_c_ + 0x131c) = 0;
        switch (arg0->unknown_4_) {
        case 0xa:
            *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x528) = 1;
            if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 0) {
                Type_ov027_021db524 var13 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var13(0x19, 0);
            }
            break;

        case 0xb: {
            Type_ov027_021db524 var14 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var14(3, *(void**)((char*)arg0 + 8));
            break;
        }

        default: {
            Type_ov027_021db524 var15 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var15(0x100, arg0);
            break;
        }
        }
        break;

    case 15:
        if (*(int*)(data_ov027_021e33e0.unknown_c_ + 0x74c8) != 0) {
            unsigned int var16;
            unsigned int var17 = 0;
            var16 = 0;
            do {
                if (*(int*)(data_ov027_021e33e0.unknown_c_ + (var16 << 2) + 0x14e8) != 0) {
                    var17++;
                    if (var17 >= 2) break;
                }
                var16++;
            } while (var16 < 0xf);
            if (var17 == 1) {
                func_020c976c(0x32c8);
            }
        }
        data_ov027_021e33e0.unknown_8_[0x50c] = 0;
        if (arg0->unknown_2_ == 0) {
            {
                Type_ov027_021db524 var18 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var18(2, arg0);
            }
            if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 0) {
                Type_ov027_021db524 var19 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var19(0x19, 0);
            }
        } else if (arg0->unknown_2_ == 0xa) {
            Type_ov027_021db524 var20 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var20(0x2a, arg0);
        } else {
            {
                Type_ov027_021db524 var21 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var21(0x13, arg0);
            }
            if (*(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) == 0) {
                Type_ov027_021db524 var22 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var22(0x19, 0);
            }
        }
        break;

    case 1:
        if (*(int*)(data_ov027_021e33e0.unknown_c_ + 0x1320) == 0) {
            if (arg0->unknown_2_ != 0) {
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) = 0;
                {
                    Type_ov027_021db524 var23 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var23(0x100, arg0);
                }
            } else {
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52a) = 0;
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x528) = 0;
                func_ov027_021dd0cc(2, func_020d503c((int)func_ov027_021db524));
            }
        } else {
            func_020d4770(1, 0, 0);
            func_020d472c(0);
            if (arg0->unknown_2_ != 0) {
                *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) = 0;
                {
                    Type_ov027_021db524 var24 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                    var24(0x100, arg0);
                }
            } else {
                func_ov027_021dd0cc(0x19, func_020d6a84((int)func_ov027_021db524, 0));
            }
        }
        break;

    case 2:
        if (arg0->unknown_2_ != 0) {
            *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x526) = 0;
            {
                Type_ov027_021db524 var25 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
                var25(0x100, arg0);
            }
        } else {
            func_ov027_021db4e0((int)arg0);
        }
        break;

    case 13:
        if (arg0->unknown_2_ != 0) break;
        *(unsigned short*)(data_ov027_021e33e0.unknown_8_ + 0x52a) &= ~arg0->unknown_a_;
        break;

    case 0x80:
        switch (arg0->unknown_4_) {
        case 0x10: {
            Type_ov027_021db524 var26 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var26(0x1d, arg0);
            break;
        }
        case 0x11: {
            Type_ov027_021db524 var27 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var27(0x1f, arg0);
            break;
        }
        case 0x12: {
            Type_ov027_021db524 var28 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var28(0x20, arg0);
            break;
        }
        case 0x13: {
            Type_ov027_021db524 var29 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
            var29(0x21, arg0);
            break;
        }
        case 0x16:
            HaltSystem();
            break;
        case 0x17:
            break;
        default:
            break;
        }
        break;

    default: {
        Type_ov027_021db524 var30 = *(Type_ov027_021db524*)(data_ov027_021e33e0.unknown_8_ + 0x51c);
        var30(0x100, arg0);
        break;
    }
    }
}
