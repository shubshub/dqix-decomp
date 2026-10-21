#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215b1dc_2456 = 0x868 };
enum { Enum_ov003_0215b1dc_2460 = 0x86c };
enum { Enum_ov003_0215b1dc_2464 = 0x870 };
enum { Enum_ov003_0215b1dc_2468 = 0x874 };
enum { Enum_ov003_0215b1dc_6574 = 0x17de };
#else
enum { Enum_ov003_0215b1dc_2456 = 0x998 };
enum { Enum_ov003_0215b1dc_2460 = 0x99c };
enum { Enum_ov003_0215b1dc_2464 = 0x9a0 };
enum { Enum_ov003_0215b1dc_2468 = 0x9a4 };
enum { Enum_ov003_0215b1dc_6574 = 0x19ae };
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov003_021594c4_2 {
    char unknown_0_[0x64];
    char unknown_64_[0x580 - 0x64];
    unsigned char unknown_580_;
};

struct Struct_ov003_0215af9c {
    char unknown_0_[Enum_ov003_0215b1dc_2456];
    int unknown_998_;
    char unknown_99c_[Enum_ov003_0215b1dc_2464 - Enum_ov003_0215b1dc_2460];
    int unknown_9a0_;
    char unknown_9a4_[Enum_ov003_0215b1dc_6574 - Enum_ov003_0215b1dc_2468];
    unsigned char unknown_19ae_;
};

BattleGlobals* GetGlobalField0x1c020421a0(void);
struct Actor0209c678;
void DispatchContextByState0209c678(Actor0209c678*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsMainBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
extern "C" void func_02043124(Struct_ov003_0215af9c*);
extern "C" void func_02043204(char*);
extern "C" void func_ov003_0215c270(Struct_ov003_021594c4_2*, unsigned int, unsigned int);
struct Struct_0201099c_3;
extern "C" void* func_020e0434(Struct_0201099c_3*, int);
extern "C" void func_ov003_02159250(Struct_ov003_021594c4_2*, void*);
extern "C" int* func_0202ae18(void);
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021c37a4(void);

extern unsigned char data_02109bf4;

// USA: func_ov003_0215b1dc
extern "C" ARM void func_ov003_0215b1dc(BattleMessageScene* self) {
    BattleGlobals* g = GetGlobalField0x1c020421a0();
    GameResources* res = GameState::GetInstance()->GetResources();

    if (var0->unknown_9a0_ == 3) {
        var0->unknown_19ae_ = 0;
    }

    unsigned char var2 = arg0->unknown_580_;

    if (var2 == 0) {
        if (var0->unknown_9a0_ != 3) return;
        func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0xb4);
        SetBrightness(var1, -16, 0xb4);
        arg0->unknown_580_++;
    }

    if (var2 == 1) {
        if (IsBrightnessTransitionActive(var1)) return;
        func_02043124(var0);
        func_02043204((char*)var0);
        SetMainBrightness(var1, 0, 0x3c);
        arg0->unknown_580_++;
    }

    if (var2 == 2) {
        func_ov003_0215c270(arg0, 0, 0x1f);
        if (IsMainBrightnessTransitionActive(var1)) return;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
        var0->unknown_998_ = 1;
        func_ov003_02159250(arg0, func_020e0434((Struct_0201099c_3*)arg0->unknown_64_, 0x6e));
        if (func_0202b7d8(func_0202ae18())) {
            func_ov017_021c37a4();
        }
        arg0->unknown_580_++;
    }

    if (var2 == 3) {
        func_ov003_0215c270(arg0, 0, 0x1f);
    }
}
