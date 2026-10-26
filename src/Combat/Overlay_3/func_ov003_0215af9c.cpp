#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215af9c_2456 = 0x868 };
#else
enum { Enum_ov003_0215af9c_2456 = 0x998 };
#endif
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov003_021594c4_2 {
    char unk_0[0x64];
    char messages[0x580 - 0x64];
    unsigned char step;
    char unknown_581_[0x587 - 0x581];
    unsigned char actorSlot;
    unsigned char unknown_588_;
    char unknown_589_[0x59d - 0x589];
    unsigned char busy;
};

struct BattleGlobals {
    char unk_0[Enum_ov003_0215af9c_2456];
    int unknown_998_;
};

extern "C" BattleGlobals* MessageSystem_GetInstance(void);
int IsBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" void func_02046380(BattleGlobals*);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(Struct_ov003_021594c4_2*, void*);

// USA: func_ov003_0215af9c
extern "C" ARM void func_ov003_0215af9c(Struct_ov003_021594c4_2* self) {
    GameResources* res = GetGameResources();
    BattleGlobals* g = MessageSystem_GetInstance();
    unsigned char step = self->step;

    if (step == 0) {
        if (!IsBrightnessTransitionActive(res) &&
            GetBrightness((GameResources*)res, false) &&
            GetBrightness((GameResources*)res, true)) {
            SetMainBrightness(res, 0, 0xf);
        }
        self->step++;
    }

    if (step == 1) {
        if (self->busy != 0) return;
        if (IsBrightnessTransitionActive(res)) return;
        if (GetBrightness((GameResources*)res, false)) return;

        if (self->actorSlot == 1) {
            GameState* gs = GameState::GetInstance();
            GameObject* obj = func_0200ff1c(gs, GameState_GetLeaderIndex(gs));
            func_02046380(g);
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)obj->baseStats_);
        }
        g->unknown_998_ = 1;
        func_ov003_02159250(self, KeyTable_Get((Container020e0310*)self->messages, (short)(self->actorSlot + 0x438)));
        self->step++;
    }

    if (step == 2 && g->unknown_998_ == 0) {
        self->unknown_588_ = 0xb;
        self->step = 0;
    }
}
