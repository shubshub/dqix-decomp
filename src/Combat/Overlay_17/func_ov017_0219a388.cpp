#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* arg0, unsigned int arg1);
extern "C" int func_02039730(void* arg0, int arg1);
extern "C" void func_ov017_0219a544(unsigned char* arg0, char* arg1, int arg2, int arg3);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

extern "C" int Window_Update(void* objPtr, int val);
void ClearFourHalfwords_0219a644(void* base, int value);

struct Struct_ov017_021d6448 { short unknown_0_[4]; };
struct Struct_ov017_021d6444 { unsigned char unknown_0_[4]; };
struct Struct_ov017_021d6484 { int unknown_0_[7]; };

extern struct Struct_ov017_021d6448 data_ov017_021d6458;
extern struct Struct_ov017_021d6448 data_ov017_021d6450;
extern struct Struct_ov017_021d6448 data_ov017_021d6448;
extern struct Struct_ov017_021d6444 data_ov017_021d6444;
extern struct Struct_ov017_021d6484 data_ov017_021d6484;

struct Struct_ov017_0219a388 {
    unsigned char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_[3];
    unsigned char unknown_b5_;
};

// USA: func_ov017_0219a388
extern "C" ARM void func_ov017_0219a388(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_0219a388_3248=0xa90};
#else
 enum {Enum_ov017_0219a388_3248=0xcb0};
#endif
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetProtagonist();
    struct Struct_ov017_021d6448 var2 = data_ov017_021d6458;
    struct Struct_ov017_021d6448 var3 = data_ov017_021d6450;
    struct Struct_ov017_021d6448 var4 = data_ov017_021d6448;
    struct Struct_ov017_021d6444 var5 = data_ov017_021d6444;
    struct Struct_ov017_021d6484 var6 = data_ov017_021d6484;
    char var7[0x80];
    Struct_ov017_0219a388* var8 = *(Struct_ov017_0219a388**)(arg0 + 0x3000 + Enum_ov017_0219a388_3248);
    int var9;

    for (var9 = 0; var9 < 4; var9++) {
        var8->unknown_a0_ = var2.unknown_0_[var9];
        var8->unknown_a2_ = 2;
        var8->unknown_a4_ = var3.unknown_0_[var9];
        var8->unknown_a6_ = var4.unknown_0_[var9];
        var8->unknown_a8_ = 2;
        var8->unknown_aa_ = 2;
        var8->unknown_ac_ = 0xa;
        var8->unknown_ae_ = 0xb;
        unsigned char var10 = var5.unknown_0_[var9];
        var8->unknown_b1_ = var10;
        var8->unknown_b5_ = 1;
        __clear(var7, 0x80);
        func_ov017_0219a544(arg0, var7, var10, (signed char)func_02039730(var1, var6.unknown_0_[var9]));
#if defined(jpn)
        func_0205d304(var8, var7, 0, 0, 0, 1, 0);
#else
        func_0205d304(var8, var7, 0, 0, 0, 1, 0, 0);
#endif

        Window_Update(win, gs->GetTickCount());
    }
    func_ov017_0219a644(arg0, 0xff);
}
