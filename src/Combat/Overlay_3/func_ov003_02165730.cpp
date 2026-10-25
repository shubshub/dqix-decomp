#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02165730_969 = 0x139 };
enum { Enum_ov003_02165730_912 = 0x278 };
enum { Enum_ov003_02165730_208 = 0x10 };
#else
enum { Enum_ov003_02165730_969 = 0x3c9 };
enum { Enum_ov003_02165730_912 = 0x390 };
enum { Enum_ov003_02165730_208 = 0xd0 };
#endif
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

struct Struct_02012de8;
struct Struct_020e25e8;

struct Struct_ov003_02165278 {
    unsigned char unknown_0_[Enum_ov003_02165730_969];
    unsigned char unknown_3c9_0_ : 1;
};

void* GlobalFlags_GetInstance(void);
Global02109030* GetGlobal02109030_020936f8(void);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

struct Struct_ov003_02165730 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov003_02165730_2 {
    unsigned char unknown_0_[Enum_ov003_02165730_912];
    struct Struct_020e25e8* unknown_390_;
    unsigned char unknown_394_[Enum_ov003_02165730_208];
    unsigned int unknown_464_;
    unsigned char unknown_468_[0x1c];
    short unknown_484_;
    short unknown_486_;
    unsigned char unknown_488_[0x1b];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
    unsigned char unknown_4a5_;
};

// USA: func_ov003_02165730
extern "C" ARM void func_ov003_02165730(BattleView02165730* view) {
    GameResources* resources = GetGameResources();
    void* flagData = GlobalFlags_GetInstance();

    if (view->step == 0) {
        GetGlobal02109030_020936f8()->flag3c9 = 1;
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        view->field_0x484 = view->field_0x486 = -1;
        view->field_0x4a5 = 0;

        GameState* gs = GameState::GetInstance();
        PartyList2a04* party = (PartyList2a04*)GameState_GetParty(gs);
        for (int i = 0; i < party->count; i++) {
            GameObject* member = GetCombatantWithFlag0x100_0200ff1c(gs, party->members[i]);
            if (member != NULL) {
                member->obj3D_.MakeVisible();
            }
        }

        if (IsBrightnessTransitionActive(var0) != 0) return;
        UnlockAndSetBrightness(var0, 0, 0xf);
        arg0->unknown_4a4_ = 1;
        if (arg0->unknown_390_ == NULL) return;
        func_020e25e8(arg0->unknown_390_);
    } else if (arg0->unknown_4a4_ == 1) {
        if (IsBrightnessTransitionActive(var0) != 0) return;
        if (func_02046708((struct Struct_02012de8*)var1, 0x41) != 0) {
            arg0->unknown_464_ |= 0x800;
        }
        view->step = 2;
    } else if (view->step == 2) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        view->field_0x484 = view->field_0x486 = -1;
        view->field_0x4a5 = 0;
        view->state = 0x10;
        view->step = 0;
    }
}
