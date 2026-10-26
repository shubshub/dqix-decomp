#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void __clear(void *arg0, int arg1);
extern "C" void func_ov003_02170a7c(char *arg0, char *arg1);
extern "C" void Font_EncodeText(const char *arg0, char *arg1, int arg2);
extern "C" void *Zone3D_GetInstance(void);
extern "C" int func_ov003_021725a4(void *arg0, void *arg1);

struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08 *arg0);
extern "C" int func_0209890c(void *arg0, void *arg1);
#if defined(jpn)
extern "C" void *LinkSession_GetInstance(void);
extern "C" void func_0202bad4(void *arg0, unsigned char arg1);
#endif

extern const char *data_ov003_021805bc[];

struct Struct_ov003_02171fe8_4 {
    char unknown_0_[6];
};
struct Struct_ov003_02171fe8_5 {
    char unknown_0_[11];
};
struct Struct_ov003_02171fe8_6 {
    unsigned short unknown_0_[14];
};
struct Struct_ov003_02171fe8_7 {
    int unknown_0_[6];
};
struct Struct_ov003_02171fe8_8 {
    int unknown_0_[31];
};

struct Struct_ov003_02171fe8_9 {
    unsigned int unknown_0_0_ : 25;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 6;
    int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 2;
    int unknown_8_[29];
};

struct Slot {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_0_ : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int unknown_d_7_ : 17;
    int unknown_10_;
    Struct_ov003_02171fe8_4 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_1a_;
    Struct_ov003_02171fe8_7 unknown_38_;
    Struct_ov003_02171fe8_6 unknown_50_;
    Struct_ov003_02171fe8_8 unknown_6c_;
};

struct Struct_ov003_02171fe8 {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_;
    unsigned int unknown_c_;
    int unknown_10_;
    Struct_ov003_02171fe8_4 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_1a_;
    Struct_ov003_02171fe8_7 unknown_38_;
    Struct_ov003_02171fe8_6 unknown_50_;
    Struct_ov003_02171fe8_8 unknown_6c_;
};

struct Struct_ov003_02171fe8_2 {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    Struct_ov003_02171fe8_4 unknown_e_;
    Struct_ov003_02171fe8_8 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_90_;
    Struct_ov003_02171fe8_7 unknown_ac_;
    TreasureMapMetadata unknown_c4_;
};

struct Struct_ov003_02171fe8_3 {
    char unknown_0_[0x199];
    unsigned char unknown_199_;
#if defined(jpn)
    char unknown_19a_[0x27c - 0x19a];
    Struct_ov003_02171fe8_2 unknown_2a0_;
#else
    char unknown_19a_[0x2a0 - 0x19a];
    Struct_ov003_02171fe8_2 unknown_2a0_;
    char unknown_380_[0x460 - 0x380];
#endif
    Slot unknown_460_[3];
    unsigned char unknown_718_;
    char unknown_719_[3];
    int unknown_71c_;
    int unknown_720_;
    int unknown_724_;
    char unknown_728_[4];
    int unknown_72c_;
};

// USA: func_ov003_02171fe8
extern "C" ARM void func_ov003_02171fe8(Struct_ov003_02171fe8_3 *arg0, int arg1, void *arg2, unsigned int arg3, unsigned int arg4) {
#if defined(jpn)
    Slot var2;
    if (arg0->unknown_199_ == arg1) {
        arg0->unknown_724_ = 1;
        arg0->unknown_72c_ = 0;
        memcpy((char *) &arg0->unknown_2a0_ + arg4, arg2, arg3);
        if (arg4 + arg3 >= 0xe0) {
            arg0->unknown_71c_ = 1;
            func_0202bad4(LinkSession_GetInstance(), arg0->unknown_199_);
            arg0->unknown_2a0_.unknown_c4_.SetDiscoveryState(DiscoveryState_Undiscovered);
            arg0->unknown_2a0_.unknown_c4_.ClearInitialByteUnknownBit();
            strcpy((char *) &var2.unknown_0_, (char *) &arg0->unknown_2a0_.unknown_0_);
            var2.unknown_c_0_   = arg0->unknown_2a0_.unknown_b_;
            var2.unknown_d_0_  = arg0->unknown_2a0_.unknown_c_;
            var2.unknown_b_7_ = arg0->unknown_2a0_.unknown_d_;
            memcpy(&var2.unknown_6c_, &arg0->unknown_2a0_.unknown_14_, 0x7c);
            memcpy(&var2.unknown_1a_, &arg0->unknown_2a0_.unknown_90_, 0x1c);
            memcpy(&var2.unknown_38_, &arg0->unknown_2a0_.unknown_ac_, 0x18);
            memcpy(&var2.unknown_50_, &arg0->unknown_2a0_.unknown_c4_, 0x1c);
            memcpy(&var2.unknown_14_, &arg0->unknown_2a0_.unknown_e_, 6);
            var2.unknown_6c_.unknown_0_[0] |= 0x4000000;
            char *var8 = (char *) Zone3D_GetInstance();
            if (arg0->unknown_718_ < 3) {
                if (func_0209890c(var8 + 0x860, &var2) != 0) {
                    if (func_ov003_021725a4(arg0, &var2) != 0) {
                        Struct_ov003_02171fe8 *var9  = (Struct_ov003_02171fe8 *) &arg0->unknown_460_[arg0->unknown_718_];
                        var9->unknown_0_    = ((Struct_ov003_02171fe8 *) &var2)->unknown_0_;
                        var9->unknown_b_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_b_;
                        var9->unknown_c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_c_;
                        var9->unknown_10_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_10_;
                        var9->unknown_14_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_14_;
                        var9->unknown_1a_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_1a_;
                        var9->unknown_38_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_38_;
                        var9->unknown_50_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_50_;
                        var9->unknown_6c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_6c_;
                        arg0->unknown_718_ = arg0->unknown_718_ + 1;
                    }
                }
            }
        }
    }
#else
    char var0[11];
    char var1[11];
    Slot var2;
    if (arg0->unknown_199_ == arg1) {
        arg0->unknown_72c_ = 0;
        memcpy((char *) &arg0->unknown_2a0_ + arg4, arg2, arg3);
        if (arg4 + arg3 >= 0xe0) {
            arg0->unknown_71c_ = 1;
            arg0->unknown_724_ = 1;
            if (*(unsigned int *) ((char *) arg0 + 0x34c) >> 31) {
                arg0->unknown_2a0_.unknown_c4_.SetDiscoveryState(DiscoveryState_Undiscovered);
                arg0->unknown_2a0_.unknown_c4_.ClearInitialByteUnknownBit();
                strcpy((char *) &var2.unknown_0_, (char *) &arg0->unknown_2a0_.unknown_0_);
                var2.unknown_c_0_   = arg0->unknown_2a0_.unknown_b_;
                var2.unknown_d_0_  = arg0->unknown_2a0_.unknown_c_;
                var2.unknown_b_7_ = arg0->unknown_2a0_.unknown_d_;
                memcpy(&var2.unknown_6c_, &arg0->unknown_2a0_.unknown_14_, 0x7c);
                memcpy(&var2.unknown_1a_, &arg0->unknown_2a0_.unknown_90_, 0x1c);
                memcpy(&var2.unknown_38_, &arg0->unknown_2a0_.unknown_ac_, 0x18);
                memcpy(&var2.unknown_50_, &arg0->unknown_2a0_.unknown_c4_, 0x1c);
                memcpy(&var2.unknown_14_, &arg0->unknown_2a0_.unknown_e_, 6);
                var2.unknown_6c_.unknown_0_[0] |= 0x4000000;
            } else {
                GameState *var3 = GameState::GetInstance();
                arg0->unknown_2a0_.unknown_c4_.SetDiscoveryState(DiscoveryState_Undiscovered);
                arg0->unknown_2a0_.unknown_c4_.ClearInitialByteUnknownBit();
                var2.unknown_c_0_   = arg0->unknown_2a0_.unknown_b_;
                var2.unknown_d_0_  = arg0->unknown_2a0_.unknown_c_;
                var2.unknown_b_7_ = arg0->unknown_2a0_.unknown_d_;
                memcpy(&var2.unknown_6c_, &arg0->unknown_2a0_.unknown_14_, 0x7c);
                memcpy(&var2.unknown_1a_, &arg0->unknown_2a0_.unknown_90_, 0x1c);
                memcpy(&var2.unknown_38_, &arg0->unknown_2a0_.unknown_ac_, 0x18);
                memcpy(&var2.unknown_50_, &arg0->unknown_2a0_.unknown_c4_, 0x1c);
                memcpy(&var2.unknown_14_, &arg0->unknown_2a0_.unknown_e_, 6);
                var2.unknown_6c_.unknown_0_[0] |= 0x4000000;
                int var4 = GameState_GetLanguage((Struct0200fb08 *) var3);
                int var5  = 0;
                switch (var4) {
                    case 2: var5 = 1; break;
                    case 3: var5 = 2; break;
                    case 4: var5 = 3; break;
                    case 5: var5 = 4; break;
                }
                __clear(var0, 11);
                memset(var0, 0, 0xb);
                func_ov003_02170a7c((char *) &arg0->unknown_2a0_.unknown_0_, var0);
                memset(&arg0->unknown_2a0_.unknown_0_, 0, 0xb);
                Font_EncodeText(var0, (char *) &var2.unknown_0_, 1);
                Font_EncodeText(data_ov003_021805bc[var5], (char *) &var2.unknown_6c_.unknown_0_[2], 1);
                Struct_ov003_02171fe8_9 *var6 = (Struct_ov003_02171fe8_9 *) &var2.unknown_6c_;
                if (var6->unknown_5_1_ >= 100) {
                    if (var6->unknown_5_1_ < 200) {
                        var6->unknown_5_1_ = 396;
                    }
                }
                if (var6->unknown_3_1_ == 1) {
                    if (var6->unknown_6_3_ >= 700 && var6->unknown_6_3_ < 750) {
                        var6->unknown_6_3_ = var6->unknown_6_3_ + 50;
                    } else if (var6->unknown_6_3_ >= 800) {
                        var6->unknown_6_3_ = var6->unknown_6_3_ + 100;
                    }
                }
                char *var7 = (char *) &var2.unknown_50_;
                __clear(var1, 11);
                memset(var0, 0, 0xb);
                memset(var1, 0, 0xb);
                memcpy(var1, var7 + 1, 10);
                func_ov003_02170a7c(var1, var0);
                memset(var7 + 1, 0, 10);
                Font_EncodeText(var0, var7 + 1, 1);
                memset(var0, 0, 0xb);
                memset(var1, 0, 0xb);
                memcpy(var1, var7 + 0xb, 10);
                func_ov003_02170a7c(var1, var0);
                memset(var7 + 0xb, 0, 10);
                Font_EncodeText(var0, var7 + 0xb, 1);
            }
            char *var8 = (char *) Zone3D_GetInstance();
            if (arg0->unknown_718_ < 3) {
                if (func_0209890c(var8 + 0x840, &var2) != 0) {
                    if (func_ov003_021725a4(arg0, &var2) != 0) {
                        Struct_ov003_02171fe8 *var9  = (Struct_ov003_02171fe8 *) &arg0->unknown_460_[arg0->unknown_718_];
                        var9->unknown_0_    = ((Struct_ov003_02171fe8 *) &var2)->unknown_0_;
                        var9->unknown_b_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_b_;
                        var9->unknown_c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_c_;
                        var9->unknown_10_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_10_;
                        var9->unknown_14_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_14_;
                        var9->unknown_1a_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_1a_;
                        var9->unknown_38_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_38_;
                        var9->unknown_50_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_50_;
                        var9->unknown_6c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_6c_;
                        arg0->unknown_718_ = arg0->unknown_718_ + 1;
                    }
                }
            }
        }
    }
#endif
}
