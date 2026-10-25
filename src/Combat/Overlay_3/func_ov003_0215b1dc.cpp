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

BattleGlobals* MessageSystem_GetInstance(void);
struct Actor0209c678;
void BgmPlayer_FadeOut(Actor0209c678*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsMainBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
extern "C" void MessageSystem_Stop(BattleGlobals*);
void MessageSystem_Reset(char*);
extern "C" void func_ov003_0215c270(BattleMessageScene*, unsigned int, unsigned int);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(BattleMessageScene*, void*);
extern "C" int* func_0202ae18(void);
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021c37a4(void);

extern unsigned char g_bgmPlayer;

// USA: func_ov003_0215b1dc
extern "C" ARM void func_ov003_0215b1dc(BattleMessageScene* self) {
    BattleGlobals* g = MessageSystem_GetInstance();
    GameResources* res = GameState::GetInstance()->GetResources();

    if (var0->unknown_9a0_ == 3) {
        var0->unknown_19ae_ = 0;
    }

    unsigned char var2 = arg0->unknown_580_;

    if (step == 0) {
        if (g->linkState != 3) return;
        BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0xb4);
        SetBrightness(res, -16, 0xb4);
        self->step++;
    }

    if (step == 1) {
        if (IsBrightnessTransitionActive(res)) return;
        MessageSystem_Stop(g);
        MessageSystem_Reset((char*)g);
        SetMainBrightness(res, 0, 0x3c);
        self->step++;
    }

    if (var2 == 2) {
        func_ov003_0215c270(arg0, 0, 0x1f);
        if (IsMainBrightnessTransitionActive(var1)) return;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
        g->messageActive = 1;
        func_ov003_02159250(self, KeyTable_Get((Container020e0310*)self->messages, 0x6e));
        if (CheckField0NonZero_0202b7d8(func_0202ae18())) {
            func_ov017_021c37a4();
        }
        arg0->unknown_580_++;
    }

    if (var2 == 3) {
        func_ov003_0215c270(arg0, 0, 0x1f);
    }
}
