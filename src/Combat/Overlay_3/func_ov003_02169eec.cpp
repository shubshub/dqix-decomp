#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02169eec_228 = 0xe0, Enum_ov003_02169eec_8 = 12, Enum_ov003_02169eec_0 = 1, Enum_ov003_02169eec_312 = 0x134 };
#else
enum { Enum_ov003_02169eec_228 = 0xe4, Enum_ov003_02169eec_8 = 8, Enum_ov003_02169eec_0 = 0, Enum_ov003_02169eec_312 = 0x138 };
#endif

struct Struct_0205bbcc;
struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0205bcdc;
struct Struct_0205bd58;
struct Struct_ov003_02169eec_2;
struct Struct_0205d81c;
struct Struct_0205bc2c;
struct Struct_0205bd04;
struct Struct_0205bc10;
struct Struct_0205c570;
struct Struct_0205bf3c;
struct Struct_0205bb84;
struct Struct_02000c9c_8;
struct Struct_02108760;
struct Struct_0205cf1c;

extern "C" void func_ov003_02169594(void* arg0);
extern "C" void func_ov003_021696f4(void* arg0, int arg1);
extern "C" int func_ov003_02169674(void* arg0, int arg1, int arg2, void* arg3);
extern "C" void func_0205bb04(void* arg0, int arg1);
extern "C" int func_0205bf58(void* arg0, int arg1);

void SetChannelAFlag0205cef8(void* chan);
void SetChannelBFlag0205cf04(void* chan);
void Init0205bbcc(Struct_0205bbcc* obj);
void SetupPointerTable0205ba68(Struct_0205ba68* obj, int a, int b, int c);
void SetField0AndPropagate0205bacc(Node0205bacc* obj, int v);
void SetIndexIfValid0205bcdc(Struct_0205bcdc* obj, int v);
void SetFields0205bd58(Struct_0205bd58* obj, int a, int b, int c, int d, int e);
void ClearFields_0216a85c(S0216a85c* obj);
unsigned char* FindElementForFieldB0_0205d8c4(Struct_0205d81c* chan);
void GetFourSubstructPointers_0204f138(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);
void SetFieldAt0x30_0205bc24(void* obj, int v);
int UpdateActiveState0205bc2c(Struct_0205bc2c*, int);
int GetScaledSumIfActive0205bd04(Struct_0205bd04* obj);
int GetField0_0205bafc(void* obj);
void ClearFlagFields_02169658(void* self);
void ClearBytes0x4cTo0x4e(Struct_0205bc10* obj);
int GetActiveScaledSum0205d794(Struct_0205c570* chan);
void UpdateEntryAndField4ea_021694b8(void* self, int v);
void ResetState0205bf3c(Struct_0205bf3c* obj);
int GridCursor_GetSelectedIndex(Struct_0205bb84* obj);
int NormalizeField5_0200fb08(Struct0200fb08* gs);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
void ClearChannelAFlag0205cf10(void* chan);
void ClearFlagByte0205cf1c(Struct0205cf1c* chan);

extern unsigned char data_ov003_0217f544[];
extern unsigned char data_ov003_0217f545[];
extern unsigned char data_ov003_0217f546[];
extern unsigned char data_ov003_0217f547[];
extern unsigned char data_ov003_0217f548[];
extern Struct_02108760 data_02108760;

struct Struct_ov003_02169674 {
    short unknown_0_;
    short unknown_2_;
    signed char unknown_4_;
    char unknown_5_;
    short* unknown_8_;
    short* unknown_c_;
    short* unknown_10_;
    short* unknown_14_;
};

struct Struct_ov003_02169eec {
    char unknown_0_[Enum_ov003_02169eec_228];
    char unknown_e4_[0x179 - 0xe4];
    unsigned char unknown_179_;
    char unknown_17a_[0x4e9 - 0x17a];
    unsigned char unknown_4e9_;
    unsigned char unknown_4ea_;
    char unknown_4eb_[3];
    signed char unknown_4ee_;
    signed char unknown_4ef_[4];
    signed char unknown_4f3_[4];
    char unknown_4f7_;
    unsigned int unknown_4f8_;
    char unknown_4fc_[0x53c - 0x4fc];
    char unknown_53c_[4];
    int unknown_540_;
    char unknown_544_[0x574 - 0x544];
    short unknown_574_;
    short unknown_576_;
    char unknown_578_[0x588 - 0x578];
    unsigned char unknown_588_;
    char unknown_589_[3];
    short unknown_58c_[8];
    signed char unknown_59c_;
    unsigned char unknown_59d_;
    signed char unknown_59e_;
    char unknown_59f_;
    unsigned int unknown_5a0_;
    char unknown_5a4_[2];
    unsigned char unknown_5a6_;
    unsigned char unknown_5a7_;
    Struct_ov003_02169674 unknown_5a8_;
    Struct_ov003_02169674 unknown_5c0_;
};

static inline short inline_ov003_02169eec(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_0_;
}
static inline short inline_ov003_02169eec_2(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_2_;
}
static inline short* inline_02000c9c_11(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_c_;
}

static inline short inline_ov003_02169eec_3(unsigned char* arg0) {
    return *(short*)(arg0 + 0xac);
}
static inline short inline_ov003_02169eec_4(unsigned char* arg0) {
    return *(short*)(arg0 + 0xae);
}

// USA: func_ov003_02169eec
extern "C" ARM int func_ov003_02169eec(Struct_ov003_02169eec* arg0, unsigned int arg1) {
    int var0;
    int var1;
    int var2;
    int var3;

    if (arg0->unknown_4e9_ == 0) {
        func_ov003_02169594(arg0);
        func_0205cef8(arg0->unknown_e4_);
        func_0205cf04(arg0->unknown_e4_);
        func_ov003_021696f4(arg0, arg0->unknown_4ee_);
        func_0205bbcc((Struct_0205bbcc*)arg0->unknown_53c_);
        func_0205ba68((Struct_0205ba68*)arg0->unknown_53c_, 1, 2, 0);
        arg0->unknown_540_ = 1;
        func_0205bacc((Struct_0205bacc*)arg0->unknown_53c_, 2);
        func_0205bcdc((Struct_0205bcdc*)arg0->unknown_53c_, 0);
        arg0->unknown_58c_[0] = 0;
        arg0->unknown_58c_[1] = 0;
        arg0->unknown_58c_[2] = 0;
        arg0->unknown_58c_[3] = 0x10;
        arg0->unknown_58c_[4] = Enum_ov003_02169eec_8;
        arg0->unknown_58c_[5] = Enum_ov003_02169eec_8;
        arg0->unknown_58c_[6] = 0x10;
        arg0->unknown_58c_[7] = 0x10;
        func_0205bd58((Struct_0205bd58*)arg0->unknown_53c_, 2, (int)&arg0->unknown_58c_[0], (int)&arg0->unknown_58c_[2],
                          (int)&arg0->unknown_58c_[4], (int)&arg0->unknown_58c_[6]);
        func_ov003_0216a85c((Struct_ov003_02169eec_2*)&arg0->unknown_5a8_);
        arg0->unknown_5a8_.unknown_4_ = 2;
        arg0->unknown_5a8_.unknown_8_ = &arg0->unknown_58c_[Enum_ov003_02169eec_0];
        arg0->unknown_5a8_.unknown_c_ = &arg0->unknown_58c_[2];
        arg0->unknown_5a8_.unknown_10_ = &arg0->unknown_58c_[4];
        arg0->unknown_5a8_.unknown_14_ = &arg0->unknown_58c_[6];
        func_ov003_0216a85c((Struct_ov003_02169eec_2*)&arg0->unknown_5c0_);
        unsigned char* var4 = func_0205d8c4((Struct_0205d81c*)arg0->unknown_e4_);
        short var5 = inline_ov003_02169eec_3(var4);
        short var6 = inline_ov003_02169eec_4(var4);
        arg0->unknown_5c0_.unknown_0_ = var5 << 3;
        arg0->unknown_5c0_.unknown_2_ = var6 << 3;
        arg0->unknown_5c0_.unknown_4_ = 4;
        func_0204f138(var4, (unsigned char**)&arg0->unknown_5c0_.unknown_8_, (unsigned char**)&arg0->unknown_5c0_.unknown_c_,
                                 (unsigned char**)&arg0->unknown_5c0_.unknown_10_, (unsigned char**)&arg0->unknown_5c0_.unknown_14_);
        arg0->unknown_4e9_++;
    } else if (arg0->unknown_4e9_ == 1) {
        signed char var7;
        signed char* var8 = arg0->unknown_4ef_;
        var7 = arg0->unknown_4ee_;
        if (g_touchInput.pressed_ != 0 || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
            g_touchInput.released_ != 0) {
            g_touchInput.GetTouchPoint(&var0, &var1);
            int var9 = (func_0205d8c4((Struct_0205d81c*)arg0->unknown_e4_)[0xc5] & 2) != 0;
            unsigned char var10 = 0;
            if (g_touchInput.pressed_ != 0) {
                short var11 = inline_ov003_02169eec(arg0);
                short var12 = inline_ov003_02169eec_2(arg0);
                int var13 = arg0->unknown_4ee_;
#if defined(jpn)
                short var14 = (short)(var11 + arg0->unknown_5c0_.unknown_8_[var13]);
                short var15 = (short)(var12 + arg0->unknown_5c0_.unknown_c_[var13]);
                if (var9 == 0) {
                    var14 = (short)(var14 - 1);
                    var15 = (short)(var15 - 10);
                }
#else
                short var14 = (short)(var11 + (var13 * 8 + 0x24));
                short var15 = (short)(var12 + arg0->unknown_5c0_.unknown_c_[var13]);
                if (var9 == 0) {
                    var15 = (short)(var15 - 10);
                }
#endif
                arg0->unknown_574_ = var14;
                arg0->unknown_576_ = var15;
                arg0->unknown_5a8_.unknown_0_ = var14;
                arg0->unknown_5a8_.unknown_2_ = var15;
                func_0205bc24(arg0->unknown_53c_, func_ov003_02169674(arg0, var0, var1, &arg0->unknown_5a8_));
                if (func_ov003_02169674(arg0, var0, var1, &arg0->unknown_5a8_) >= 0) {
                    var10 = 1;
                    if (func_0205bc2c((Struct_0205bc2c*)arg0->unknown_53c_, arg1) != 0) {
                        arg0->unknown_59d_ = var10;
                        arg0->unknown_4ea_ = 2;
                        arg0->unknown_59e_ = 0x14;
                        int var16 = func_0205bd04((Struct_0205bd04*)arg0->unknown_53c_);
                        int var17 = (signed char)func_0205bafc(arg0->unknown_4fc_);
                        if (var16 == 0) {
                            var8[var7]++;
                            signed char var18 = var8[var7];
                            if (var18 == var17) {
                                var8[var7] = 0;
                            }
                            arg0->unknown_59c_ = 1;
                            arg0->unknown_5a6_ = 1;
                            arg0->unknown_5a7_ = 0;
                        } else if (var16 == 1) {
                            var8[var7]--;
                            if (var8[var7] == -1) {
                                var8[var7] = var17 - 1;
                            }
                            arg0->unknown_59c_ = -1;
                            arg0->unknown_5a6_ = 0;
                            arg0->unknown_5a7_ = 1;
                        }
                    }
                }
            } else {
                int var19 = (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0);
                unsigned char var20 = g_touchInput.isRepeatValid_;
                if (!(var19 == 0 && g_touchInput.released_ == 0)) {
                    if (arg0->unknown_59d_ != 0) {
                        var10 = 1;
                        if (var20 != 0 && g_touchInput.currentReading_.isHeld != 0) {
                            if (arg1 < (unsigned int)arg0->unknown_59e_) {
                                arg0->unknown_59e_ -= arg1;
                            } else {
                                arg0->unknown_59e_ = 10;
                                var8[var7] += arg0->unknown_59c_;
                                signed char var21 = func_0205bafc(arg0->unknown_4fc_);
                                if (var8[var7] > var21 - 1) {
                                    var8[var7] = var21 - 1;
                                }
                                if (var8[var7] < 0) {
                                    var8[var7] = 0;
                                }
                                arg0->unknown_4ea_ = 2;
                            }
                        }
                        if (g_touchInput.released_ != 0) {
                            if (arg0->unknown_588_ != 0) {
                                arg0->unknown_4ea_ = 4;
                            } else {
                                arg0->unknown_4ea_ = 3;
                            }
                            func_ov003_02169658(arg0);
                            func_0205bc10((Struct_0205bc10*)arg0->unknown_53c_);
                        }
                    }
                }
            }
            if (var10 == 0) {
                int var22 = func_0205d794((Struct_0205c570*)arg0->unknown_e4_);
                arg0->unknown_179_ = 0;
                func_ov003_021694b8(arg0, arg1);
                arg0->unknown_179_ = 1;
                int var23 = func_0205d794((Struct_0205c570*)arg0->unknown_e4_);
                if (var22 != var23) {
                    func_ov003_021696f4(arg0, var23);
                }
            }
            if (var9 != 0 && g_touchInput.released_ != 0) {
                if (func_ov003_02169674(arg0, var0, var1, &arg0->unknown_5c0_) < 0) {
                    arg0->unknown_4ea_ = 3;
                }
            }
        } else {
            if (g_keyManager.TestKeysHeld(0x40) || g_keyManager.TestKeysPressed(0x40) ||
                g_keyManager.TestKeysReleased(0x40) || g_keyManager.TestKeysHeld(0x80) ||
                g_keyManager.TestKeysPressed(0x80) ||
                g_keyManager.TestKeysReleased(0x80)) {
                ResetState0205bf3c((Struct_0205bf3c*)((char*)self + kResetOffset));
                int old = cells[cur];
                int n = GetField0_0205bafc(self->list);
                func_0205bb04(self->list, n - 1 - cells[cur]);
                if (func_0205bf58(self->list, sb) != 0) {
                    cells[cur] = n - 1 - GridCursor_GetSelectedIndex((Struct_0205bb84*)self->list);
                    if (old != cells[cur]) {
                        self->code = 1;
                    }
                }
            } else {
                int var26 = func_0205d794((Struct_0205c570*)arg0->unknown_e4_);
                func_ov003_021694b8(arg0, arg1);
                int var27 = func_0205d794((Struct_0205c570*)arg0->unknown_e4_);
                if (var26 != var27) {
                    func_ov003_021696f4(arg0, var27);
                }
                if (g_keyManager.TestKeysPressed(0x10) && arg0->unknown_4ee_ == 3) {
                    for (int var28 = 0; var28 < 4; var28++) {
                        arg0->unknown_4ef_[var28] = 0;
                    }
                    arg0->unknown_4ea_ = 1;
                } else if (g_keyManager.TestKeysPressed(0x20) && arg0->unknown_4ee_ == 0) {
                    for (int var29 = 0; var29 < 4; var29++) {
                        arg0->unknown_4ef_[var29] = arg0->unknown_4f3_[var29];
                    }
                    arg0->unknown_4ea_ = 1;
                }
            }
        }

        arg0->unknown_4ee_ = func_0205d794((Struct_0205c570*)arg0->unknown_e4_);
        unsigned int var30 = 0;
        unsigned int var31 = 1000;
        for (int var32 = 3; var32 >= 0; var32--) {
            var30 += var31 * arg0->unknown_4ef_[var32];
            var31 *= 10;
        }
        if (var30 > arg0->unknown_4f8_) {
            for (int var33 = 0; var33 < 4; var33++) {
                arg0->unknown_4ef_[var33] = arg0->unknown_4f3_[var33];
            }
        }

        int var34 = 0;
        int var35 = 0;
        if (g_touchInput.pressed_ != 0) {
            g_touchInput.GetTouchPoint(&var2, &var3);
            if (var3 >= 0x60 && var3 < 0x6b) {
#if defined(jpn)
                short var37 = 0x8f;
                short var38 = 0xbb;
                short var39 = 0xc8;
                short var40 = 0xec;
#else
                int var36 = func_0200fb08((Struct_02000c9c_8*)GameState::GetInstance());
                short var37 = 0x8f;
                short var38 = 0xba;
                short var39 = 0xc5;
                short var40 = 0xed;
                for (int var41 = 0; var41 < 5; var41++) {
                    if (var36 == data_ov003_0217f544[var41 * 5]) {
                        var37 = data_ov003_0217f545[var41 * 5] - 1;
                        var38 = data_ov003_0217f546[var41 * 5] + var37 + 2;
                        var39 = data_ov003_0217f547[var41 * 5] - 1;
                        var40 = data_ov003_0217f548[var41 * 5] + var39 + 2;
                        break;
                    }
                }
#endif
                if (var2 >= var37 && var2 < var38) {
                    var34 = 1;
                } else if (var2 >= var39 && var2 < var40) {
                    var35 = 1;
                    func_0205eaa0(&data_02108760, var35, 0);
                }
            }
        }
        int var42 = g_keyManager.TestKeysPressed(1);
        int var43 = g_keyManager.TestKeysPressed(0x400);
        if ((var42 | var43) != 0) {
            var34 = 1;
        } else if (g_keyManager.TestKeysPressed(2) != 0) {
            var35 = 1;
        }
        if (var34 != 0) {
            func_0205eaa0(&data_02108760, 1, 0);
            unsigned int var44 = 1000;
            for (int var45 = 3; var45 >= 0; var45--) {
                arg0->unknown_5a0_ += var44 * arg0->unknown_4ef_[var45];
                var44 *= 10;
            }
            func_0205cf10(arg0->unknown_e4_);
            func_0205cf1c((Struct_0205cf1c*)arg0->unknown_e4_);
            arg0->unknown_4e9_ = 0;
            return arg0->unknown_5a0_ == 0 ? -2 : 0;
        }
        if (var35 != 0) {
            func_0205cf10(arg0->unknown_e4_);
            func_0205cf1c((Struct_0205cf1c*)arg0->unknown_e4_);
            arg0->unknown_4e9_ = 0;
            return -2;
        }
    }
    return -1;
}
