#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021ca6dc_14104 = 0x3508 };
#else
enum { Enum_ov017_021ca6dc_14104 = 0x3718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021ca6dc {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 4;
    unsigned short unknown_0_6_ : 3;
    unsigned short unknown_1_1_ : 3;
    unsigned short unknown_1_4_ : 2;
    unsigned short unknown_1_6_ : 2;
};

struct Struct_ov017_021ca6dc_2 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    char unknown_c_[0x22 - 0xc];
    struct Struct_ov017_021ca6dc unknown_22_;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
};

struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* arg0, unsigned short arg1);

struct Struct_ov017_021ca6dc_3 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    struct Struct_ov017_021ca6dc unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021ca6dc
extern "C" ARM void func_ov017_021ca6dc(void* arg0, struct Struct_ov017_021ca6dc_3* arg1, GameState* arg2, char* arg3) {
    void* var0 = func_ov017_021b8478(*(void**)(arg3 + Enum_ov017_021ca6dc_14104));
    if (!var0) {
        return;
    }
    int val = GameState_GetProtagonistIndex(battleStruct);
    if (*(signed char*)((char*)p1c + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)var0 + 0x8) != arg1->unknown_4_) {
        return;
    }
    int var2 = arg1->unknown_6_ - 0xc0;
    if (var2 < 0) {
        return;
    }
    if (var2 >= 8) {
        return;
    }
    struct Struct_ov017_021ca6dc_2* var3 = (struct Struct_ov017_021ca6dc_2*)((char*)var0 + 0x158 + var2 * 0xa4);
    unsigned char var4 = arg1->unknown_8_.unknown_0_0_;
    var3->unknown_22_.unknown_0_0_ = var4;
    unsigned char var5 = arg1->unknown_8_.unknown_0_2_;
    var3->unknown_22_.unknown_0_2_ = var5;
    unsigned char var6 = arg1->unknown_8_.unknown_0_6_;
    var3->unknown_22_.unknown_0_6_ = var6;
    unsigned char var7 = arg1->unknown_8_.unknown_1_1_;
    func_02088818((struct Struct_020886dc_2*)var3, var7);
    unsigned char var8 = arg1->unknown_8_.unknown_1_4_;
    var3->unknown_22_.unknown_1_4_ = var8;
    var3->unknown_24_ = arg1->unknown_a_;
    var3->unknown_25_ = arg1->unknown_b_;
    var3->unknown_4_ = arg1->unknown_c_;
    var3->unknown_6_ = arg1->unknown_e_;
    var3->unknown_8_ = arg1->unknown_10_;
    var3->unknown_a_ = arg1->unknown_12_;
}
