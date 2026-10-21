#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>

struct Struct_0205d81c;
struct Struct_0204c610;
struct Struct_0205d0e0 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0x12];
    unsigned short unknown_c2_;
};
struct Struct_ov000_021707f0_2 {
    char unknown_0_[0x3b];
    unsigned char : 3;
    unsigned char unknown_3b_3_ : 1;
    unsigned char unknown_3b_4_ : 4;
};
struct Struct_ov000_021707f0_3 {
    char unknown_0_[0x320];
    char unknown_320_[0x14];
    int unknown_334_;
    int unknown_338_;
    char unknown_33c_[6];
    unsigned char unknown_342_;
    char unknown_343_[3];
    unsigned char unknown_346_;
};
struct Struct_ov000_021707f0_4 {
    char unknown_0_[0x54];
};
struct Struct_ov000_021707f0_5 {
    char unknown_0_[0x11c];
    Struct_ov000_021707f0_4 unknown_11c_;
    Struct_ov000_021707f0_3* unknown_170_;
    char unknown_174_[8];
    int unknown_17c_;
#if defined(jpn)
    char unknown_180_[0x1f98 - 0x180];
#else
    char unknown1_180_[0x1d60 - 0x180];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;

    Struct_ov000_021707f0_4* inline_ov000_021707f0() { return &unknown_11c_; }
};
struct Struct_ov000_021707f0 {
    char unknown_0_[0x38];
    Struct_0205d81c* unknown_38_;
#if defined(jpn)
    char unknown_3c_[0x470 - 0x3c];
#else
    char unknown1_3c_[0x430 - 0x3c];
#endif
    unsigned short unknown_430_[2];
    float unknown_434_;
};

void* GetOffsetPtr02160f08(void*);
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
int IsField0x9cEqual3_0204c7cc(unsigned char*);
void GetFourShortsAtIndex(ShortArrays0204c610*, int, short*, short*, short*, short*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" double func_02009424(double);
extern "C" void func_0205ac40(void*, void*);
struct Struct_ov000_02183488 {
    short unknown_0_;
    short unknown_2_[2];
};
#if defined(jpn)
#define data_ov000_02183488 data_ov000_02184510
#define data_ov000_0218348a data_ov000_02184512
#define data_ov000_0218348c data_ov000_02184514
#endif
extern Struct_ov000_02183488 data_ov000_02183488[];
extern Struct_ov000_02183488 data_ov000_0218348a[];
extern Struct_ov000_02183488 data_ov000_0218348c[];

// USA: func_ov000_021707f0
extern "C" ARM void func_ov000_021707f0(Struct_ov000_021707f0* arg0) {
    float var0;
    GameState* var1 = GameState::GetInstance();
    if (!var1) {
        return;
    }
    GameResources* resources = state->GetResources();
    if (!resources || !resources->unknown_ptr_3718) {
        return;
    }
    void* var3 = func_ov017_021b8468(var2->unknown_ptr_3718);
    if (!var3) {
        return;
    }
    Struct_ov000_021707f0_5* var4 = (Struct_ov000_021707f0_5*)func_ov000_02160f08(var3);
    if (!var4) {
        return;
    }
    Struct_ov000_021707f0_4* var5 = var4->inline_ov000_021707f0();
    if (!var5 || !var4->unknown_170_) {
        return;
    }
    Struct_ov000_021707f0_3* var6 = var4->unknown_170_;
    if (var4->unknown_1d60_[var4->unknown_1d68_] != 13) {
        return;
    }
    short var7 = 0;
    short var8 = 0;
    short var9 = 0;
    short var10 = 0;
    Struct_0205d0e0* var11 = func_0205d81c(arg0->unknown_38_, 13);
    signed char var12 = 0;
    short var13 = 0;
    GameObject* var14 = GameState::GetInstance()->GetCombatantByIndex(var4->unknown_17c_);
    if (var14) {
        Struct_ov000_021707f0_2* var15 = (Struct_ov000_021707f0_2*)var14->currentStats_;
        if (var15->unknown_3b_3_) {
            if (var15->unknown_3b_4_ == 1) {
                var12 = 4;
                var13 = 1;
            } else {
                var13 = 1;
                if (var15->unknown_3b_4_ == 0) {
                    var12 = 0;
                }
            }
        }
    }
    if (!var11 || !var13) {
        return;
    }
    if (!func_0204c7cc((unsigned char*)var11)) {
        return;
    }
    if (var11->unknown_c2_) {
        return;
    }
    short var16 = var11->unknown_ac_;
    short var17 = var11->unknown_ae_;
    func_0204c610((Struct_0204c610*)var11, 5, &var7, &var8, &var9, &var10);
    var6->unknown_334_ = (var7 + (short)(var16 * 8)) << 12;
    var6->unknown_338_ = (var8 + (short)(var17 * 8)) << 12;
    var6->unknown_342_ = 0x7c;
    var6->unknown_346_ = 0;
    if (var12) {
        float var18 = (float)func_02009424(arg0->unknown_434_);
        int var19 = 0;
        if (var18 >= 0.5f) {
            var19 = 1;
        }
        var13 = 0;
        for (; var13 < 2; var12 += 2, ++var13) {
            int var20 = var12 + var19;
            arg0->unknown_430_[var13] = data_ov000_02183488[var20].unknown_0_ |
                (data_ov000_0218348a[var20].unknown_0_ << 5) | (data_ov000_0218348c[var20].unknown_0_ << 10);
        }
    } else {
        var0 = (float)func_02009424(arg0->unknown_434_);
        var13 = 0;
        for (; var13 < 2; var12 += 2, ++var13) {
            int var21 = var12;
            int var22 = var12 + 1;
            short var23 = data_ov000_02183488[var21].unknown_0_ +
                (int)((data_ov000_02183488[var22].unknown_0_ - data_ov000_02183488[var21].unknown_0_) * var0);
            short var24 = data_ov000_0218348a[var21].unknown_0_ +
                (int)((data_ov000_0218348a[var22].unknown_0_ - data_ov000_0218348a[var21].unknown_0_) * var0);
            short var25 = data_ov000_0218348c[var21].unknown_0_ +
                (int)((data_ov000_0218348c[var22].unknown_0_ - data_ov000_0218348c[var21].unknown_0_) * var0);
            arg0->unknown_430_[var13] = var23 | (var24 << 5) | (var25 << 10);
        }
    }
    CleanInvalidateCacheRange(arg0->unknown_430_, 4);
    LoadToSubObjStandardPalette(arg0->unknown_430_, 0x142, 4);
    func_0205ac40(var5, var6->unknown_320_);
}
