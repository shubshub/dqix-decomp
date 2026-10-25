#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* GetField6b0_021b8470(void* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c6534 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov017_021c6534_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_[3];
    unsigned char unknown_8_[3];
    Struct_ov017_021c6534 unknown_b_[3];
    unsigned char unknown_e_;
};

struct Struct_ov017_021c6534_3 {
    unsigned char unknown_0_[4];
    Struct_ov017_021c6534_2 unknown_4_;
};

struct Struct_ov017_021c6534_4 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x2a - 0x0a];
    signed char unknown_2a_;
};

struct Struct_ov017_021c6534_5 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0xa - 0x2];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_;
    unsigned char unknown_c_[0x18 - 0x0c];
};

struct Struct_ov017_021c6534_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021c6534_5 unknown_4_[3];
};

// USA: func_ov017_021c6534
extern "C" ARM void func_ov017_021c6534(int arg0, Struct_ov017_021c6534_3* arg1, GameState* arg2, char* arg3) {
#if defined(jpn)
 enum { Enum_ov017_021c6534_1816 = 0x508 };
#else
 enum { Enum_ov017_021c6534_1816 = 0x718 };
#endif
    void* var0 = *(void**)(arg3 + 0x3000 + Enum_ov017_021c6534_1816);

    Struct_ov017_021c6534_4* var1 = (Struct_ov017_021c6534_4*)func_ov017_021b8478(var0);
    if (!var1) return;

    void* var2 = func_ov017_021b8470(var0);
    if (!var2) return;

    if (fieldObj->field_0x2a == GameState_GetProtagonistIndex(battleStruct)) return;
    EvtData021c6534* data = &evt->data;
    if (fieldObj->key != data->key) return;

    Struct_ov017_021c6534_6* var4 = (Struct_ov017_021c6534_6*)((char*)var2 + 0x1b0 + 0x8000);
    unsigned char var5[3];
    unsigned char var6[3];
    var5[0] = var3->unknown_b_[0].unknown_0_0_;
    var5[1] = var3->unknown_b_[1].unknown_0_0_;
    var5[2] = var3->unknown_b_[2].unknown_0_0_;
    var6[0] = var3->unknown_b_[0].unknown_0_4_;
    var6[1] = var3->unknown_b_[1].unknown_0_4_;
    var6[2] = var3->unknown_b_[2].unknown_0_4_;

    int var7 = 0;
    int var8 = 0;
    int var9 = 0;
    for (int var10 = 0; var10 < 3; var10++) {
        Struct_ov017_021c6534_5* var11 = &var4->unknown_4_[var10];
        var11->unknown_0_ = var3->unknown_2_[var10];
        var11->unknown_b_ = var3->unknown_8_[var10];
        var11->unknown_a_0_ = var5[var10];
        var11->unknown_a_4_ = var6[var10];
        if (var11->unknown_0_ != 0) {
            var7++;
            var8 += var11->unknown_a_0_;
            var9 += var11->unknown_a_4_;
        }
    }
    var4->unknown_1_4_ = var7;
    var4->unknown_1_6_ = var3->unknown_e_;
    var4->unknown_0_ = var8;
    var4->unknown_1_0_ = var9;
}
