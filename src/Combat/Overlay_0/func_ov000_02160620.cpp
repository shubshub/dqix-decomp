#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define func_ov026_021d8ba0 func_ov026_021d9434
#else
#define RG(usa, jpn) (usa)
#endif

struct Struct_0202b2f0;
struct Struct_02039fec_2;
struct Struct_02038598_4;
struct Struct_ov000_02160620_2 {
    unsigned char unknown_0_[RG(0x29c, 0x218)];
    void* unknown_29c_;
    unsigned int unknown_2a0_;
    unsigned int unknown_2a4_;
    unsigned char unknown_2a8_[0xc00];
    int unknown_ea8_;
    int unknown_eac_;
    unsigned char unknown_eb0_[0x18];
    unsigned char unknown_ec8_[RG(0x2898, 0x28d8)];
    unsigned char unknown_3760_[RG(0x1e14, 0x204c)];
    int unknown_5574_;
    unsigned char unknown_5578_[RG(0x54, 0x50)];
    void* unknown_55cc_;
    unsigned char unknown_55d0_[0x24];
    unsigned int unknown_55f4_;
    unsigned char unknown_55f8_[0x4b8];
    unsigned char unknown_5ab0_[0x1394];
    short unknown_6e44_;
    unsigned short unknown_6e46_;
    unsigned short unknown_6e48_;
    unsigned char unknown_6e4a_[0x1b2];
    unsigned char unknown_6ffc_[0x714];
    signed char unknown_7710_;
    unsigned char unknown_7711_;
    unsigned char unknown_7712_[0xbe];
    unsigned char unknown_77d0_;
};
struct Struct_ov000_02160620 {
    unsigned char unknown_0_[RG(0x998, 0x868)];
    int unknown_998_;
};

extern "C" Struct_0202b2f0* func_0202ae18();
extern "C" void func_02015438(void*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_020421a0();
extern "C" void func_ov000_021735d0(void*, unsigned int);
extern "C" Struct_02039fec_2* func_02039e70();
extern "C" void func_02039fec(Struct_02039fec_2*);
extern "C" void func_ov000_021824d8(void*);
extern "C" int func_020a1fa8();
extern "C" void func_ov025_021df794(void*);
extern "C" int func_0202c540(Struct_0202b2f0*);
extern "C" int func_0202c578(Struct_0202b2f0*, int);
extern "C" Struct_02038598_4* func_020d6c00();
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" void* func_020936f8();
extern "C" void func_020939dc(void*);
extern "C" void func_02093a14(char*);
extern "C" void func_02094030(void*, int, int, int);
extern "C" void func_ov000_0215fb04(void*, int);
extern "C" int func_ov017_02195550(unsigned char*);
extern "C" void func_ov000_021682ec(Struct_ov000_02160620_2*);
extern "C" void func_ov000_02163db4(Struct_ov000_02160620_2*);
extern "C" void func_ov000_021640dc(Struct_ov000_02160620_2*);
extern "C" void func_ov000_0216873c(Struct_ov000_02160620_2*);
extern "C" void func_ov000_021688dc(Struct_ov000_02160620_2*);
extern "C" void func_ov026_021d8ba0(Struct_ov000_02160620_2*);
extern "C" void func_ov000_02169770(unsigned char*);
extern "C" void func_ov025_021db038(Struct_ov000_02160620_2*);
extern "C" void func_ov023_021ed9f8(Struct_ov000_02160620_2*);
extern "C" void func_ov023_021f4c04(Struct_ov000_02160620_2*);
extern "C" void func_ov026_021db090(Struct_ov000_02160620_2*);
extern "C" void func_ov000_02160de4(void*);
extern "C" void func_ov000_02160e94(void*);
extern "C" void func_ov000_02160fe4(void*);
extern "C" void func_ov025_021e9558(void*);
extern "C" void func_020a1edc();
extern "C" void func_020a1ef0(int);
extern "C" void func_0205eb80(void*);
extern int data_ov000_02184220;
extern unsigned char g_sePlayer[0xd0];

// USA: func_ov000_02160620
extern "C" ARM void func_ov000_02160620(Struct_ov000_02160620_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_0202b2f0* var1 = func_0202ae18();
    unsigned char* var2 = (unsigned char*)GetGameResources();
    if (arg0->unknown_55f4_ & 0x200) {
        func_02015438(arg0->unknown_ec8_);
        if (arg0->unknown_55cc_)
            func_ov023_021eb43c(arg0->unknown_55cc_);
        if (arg0->unknown_5574_ == 0 && (arg0->unknown_55f4_ & 0x40000) == 0 && (arg0->unknown_55f4_ & 0x80000) != 0 &&
                ((Struct_ov000_02160620*)func_020421a0())->unknown_998_ == 0)
            func_ov000_021735d0(arg0->unknown_3760_, var0->GetTickCount());
        func_02039fec(func_02039e70());
        func_ov000_021824d8(arg0->unknown_6ffc_);
        if (arg0->unknown_ea8_ == 8 && func_020a1fa8() == 4)
            func_ov025_021df794(arg0->unknown_5ab0_);
        GameObject* var3 = var0->GetGameObjectByIndex(0xc8);
        if (var3)
            var3->obj3D_.AdvanceEffects();
        if (func_0202c540(var1) && func_0202c578(var1, 0) && arg0->unknown_77d0_ == 0) {
            func_020466f4(func_020d6c00(), 0x8020);
            void* var4 = func_020936f8();
            func_020939dc(var4);
            func_02093a14((char*)var4);
            func_02094030(var4, 4, -1, 0);
            arg0->unknown_77d0_ = 1;
        }
    }
    for (int var5 = 1; var5 < 4; ++var5) {
        if (func_0202c578(var1, var5))
            func_ov000_0215fb04(arg0->unknown_29c_, var5);
    }
    if (func_ov017_02195550(var2) == 0)
        func_ov000_021682ec(arg0);
    switch (arg0->unknown_ea8_) {
    case 0: func_ov000_02163db4(arg0); break;
    case 1: func_ov000_021640dc(arg0); break;
    case 4: func_ov000_0216873c(arg0); break;
    case 6: func_ov000_021688dc(arg0); break;
    case 7:
        if (func_020a1fa8() == 3)
            func_ov026_021d8ba0(arg0);
        break;
    case 17: func_ov000_02169770((unsigned char*)arg0); break;
    case 8: func_ov025_021db038(arg0); break;
    case 9:
        if (func_020a1fa8() == 1) {
            func_ov023_021ed9f8(arg0);
            break;
        }
    case 10:
        if (func_020a1fa8() == 1) {
            func_ov023_021f4c04(arg0);
            break;
        }
    case 11:
        if (func_020a1fa8() == 3)
            func_ov026_021db090(arg0);
        break;
    case 18: func_ov000_02160de4(arg0); break;
    case 19: func_ov000_02160e94(arg0); break;
    }
    if (arg0->unknown_55f4_ & 0x200)
        func_ov000_02160fe4(arg0);
    if ((arg0->unknown_55f4_ & 0x2000000) &&
            (arg0->unknown_ea8_ == 8 || arg0->unknown_ea8_ == 7 || arg0->unknown_ea8_ == 1 || arg0->unknown_ea8_ == 0 || arg0->unknown_ea8_ == 9)) {
        if (arg0->unknown_ea8_ == 8)
            func_ov025_021e9558(arg0->unknown_2a8_);
        arg0->unknown_55f4_ &= ~0x2000000;
        arg0->unknown_ea8_ = 4;
        arg0->unknown_eac_ = 0;
        data_ov000_02184220 = 1;
    }
    if (data_ov000_02184220) {
        if (arg0->unknown_ea8_ == 7 || arg0->unknown_ea8_ == 11) {
            func_020a1edc();
            func_020a1ef0(3);
        } else if (arg0->unknown_ea8_ == 9 || arg0->unknown_ea8_ == 10) {
            func_020a1edc();
            func_020a1ef0(1);
        }
        data_ov000_02184220 = 0;
    }
    if (arg0->unknown_6e46_) {
        unsigned int var6 = var0->GetEffectiveDeltaTime();
        int var7 = var0->GetGameSpeed();
        unsigned int var8 = (unsigned int)((float)var6 / ((float)var7 / 4096.0f));
        if (var8 < arg0->unknown_6e48_) {
            arg0->unknown_6e48_ -= var8;
        } else if (var8 < arg0->unknown_6e46_) {
            arg0->unknown_6e46_ -= var8;
            var0->SetGameSpeed(arg0->unknown_6e44_);
        } else {
            arg0->unknown_6e48_ = 0;
            arg0->unknown_6e46_ = 0;
            var0->SetGameSpeed(0x1000);
        }
    }
    if (arg0->unknown_7710_ == 0)
        return;
    frame->countdown -= (signed char)game->GetTickCount();
    if (frame->countdown < 0) {
        frame->countdown = 0;
        ForwardField0xc0_0205eb80(g_sePlayer);
        frame->countdownFlag = 0;
    }
}
