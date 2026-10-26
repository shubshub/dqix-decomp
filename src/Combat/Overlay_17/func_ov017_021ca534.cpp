#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca534_4 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x22 - 0xc];
    unsigned short unknown_22_0_ : 2;
    unsigned short unknown_22_2_ : 4;
    unsigned short unknown_22_6_ : 3;
    unsigned short unknown_23_1_ : 3;
    unsigned short unknown_23_4_ : 2;
    unsigned short unknown_23_6_ : 2;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    unsigned char unknown_26_[0xa4 - 0x26];
};

struct Struct_ov017_021ca534_5 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x158 - 0xa];
    Struct_ov017_021ca534_4 unknown_158_[8];
};

struct Struct_ov017_021ca534_6 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[0x18 - 0xb];
};

struct Struct_ov017_021ca534 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021ca534_6 unknown_4_[4];
};

struct Struct_ov017_021ca534_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_0_ : 2;
    unsigned short unknown_4_2_ : 4;
    unsigned short unknown_4_6_ : 3;
    unsigned short unknown_5_1_ : 3;
    unsigned short unknown_5_4_ : 2;
    unsigned short unknown_5_6_ : 2;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
};

struct Struct_ov017_021ca534_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021ca534_2 unknown_4_;
};

// USA: func_ov017_021ca534
extern "C" ARM void func_ov017_021ca534(Struct_ov017_021ca534* arg0) {
#if defined(jpn)
 enum { Enum_ov017_021ca534_1816 = 0x508 };
#else
 enum { Enum_ov017_021ca534_1816 = 0x718 };
#endif
    GameState::GetInstance();
    unsigned char* ov = (unsigned char*)GetGameResources();
    void* h = *(void**)(ov + 0x3000 + regionalOffset);
    Combatants021ca534* c = (Combatants021ca534*)func_ov017_021b8478(h);
    void* p = LinkMessageQueue_GetInstance();

    for (int var4 = 0; var4 < arg0->unknown_1_4_; var4++) {
        Struct_ov017_021ca534_6* var5 = &arg0->unknown_4_[var4];
        Struct_ov017_021ca534_3 var6;
        for (int var7 = 0; var7 < var5->unknown_a_0_; var7++) {
            unsigned char var8 = var5->unknown_2_[var7];
            if (var8 >= 8) continue;
            Struct_ov017_021ca534_4* var9 = &var2->unknown_158_[var8];
            Struct_ov017_021ca534_2* var10 = &var6.unknown_4_;

            var6.unknown_0_ = 0x5d;
            var10->unknown_0_ = var2->unknown_8_;
            var10->unknown_2_ = var5->unknown_2_[var7] + 0xc0;
            var10->unknown_4_0_ = (unsigned char)var9->unknown_22_0_;
            var10->unknown_4_2_ = (unsigned char)var9->unknown_22_2_;
            var10->unknown_4_6_ = (unsigned char)var9->unknown_22_6_;
            var10->unknown_5_1_ = (unsigned char)var9->unknown_23_1_;
            var10->unknown_5_4_ = (unsigned char)var9->unknown_23_4_;
            var10->unknown_6_ = var9->unknown_24_;
            var10->unknown_7_ = var9->unknown_25_;
            var10->unknown_8_ = var9->unknown_4_;
            var10->unknown_a_ = var9->unknown_6_;
            var10->unknown_c_ = var9->unknown_8_;
            var10->unknown_e_ = var9->unknown_a_;
            func_0205e330(var3, &var6, 0);
        }
    }
}
