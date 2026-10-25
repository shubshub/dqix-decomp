#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215af9c_2456 = 0x868 };
#else
enum { Enum_ov003_0215af9c_2456 = 0x998 };
#endif
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov003_021594c4_2 {
    char unknown_0_[0x64];
    char unknown_64_[0x580 - 0x64];
    unsigned char unknown_580_;
    char unknown_581_[0x587 - 0x581];
    unsigned char unknown_587_;
    unsigned char unknown_588_;
    char unknown_589_[0x59d - 0x589];
    unsigned char unknown_59d_;
};

struct Struct_ov003_0215af9c {
    char unknown_0_[Enum_ov003_0215af9c_2456];
    int unknown_998_;
};

BattleGlobals* MessageSystem_GetInstance(void);
int IsBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
int GameState_GetLeaderIndex(GameState*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
extern "C" void func_02046380(BattleGlobals*);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(BattleMessageScene*, void*);

// USA: func_ov003_0215af9c
extern "C" ARM void func_ov003_0215af9c(BattleMessageScene* self) {
    GameResources* res = GetGameResources();
    BattleGlobals* g = MessageSystem_GetInstance();
    unsigned char step = self->step;

    if (var2 == 0) {
        if (!IsBrightnessTransitionActive(var0) &&
            GetBrightness((GameResources*)var0, false) &&
            GetBrightness((GameResources*)var0, true)) {
            SetMainBrightness(var0, 0, 0xf);
        }
        arg0->unknown_580_++;
    }

    if (var2 == 1) {
        if (arg0->unknown_59d_ != 0) return;
        if (IsBrightnessTransitionActive(var0)) return;
        if (GetBrightness((GameResources*)var0, false)) return;

        if (self->actorSlot == 1) {
            GameState* gs = GameState::GetInstance();
            GameObject* obj = GetCombatantWithFlag0x100_0200ff1c(gs, GameState_GetLeaderIndex(gs));
            func_02046380(g);
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)obj->baseStats_);
        }
        g->messageActive = 1;
        func_ov003_02159250(self, KeyTable_Get((Container020e0310*)self->messages, (short)(self->actorSlot + 0x438)));
        self->step++;
    }

    if (var2 == 2 && var1->unknown_998_ == 0) {
        arg0->unknown_588_ = 0xb;
        arg0->unknown_580_ = 0;
    }
}
