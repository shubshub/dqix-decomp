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

struct FlagWord02046708;
struct Struct_020e25e8;

struct Struct_ov003_02165278 {
    unsigned char unknown_0_[Enum_ov003_02165730_969];
    unsigned char unknown_3c9_0_ : 1;
};

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" Struct_ov003_02165278* func_020936f8(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);

struct PartyList2a04 {
    unsigned char unknown_0_[0xf78];
    unsigned char members[4];
    unsigned char count;
};

struct Struct_ov003_02165730_2 {
    unsigned char unknown_0_[Enum_ov003_02165730_912];
    struct Struct_020e25e8* selection;
    unsigned char unknown_394_[Enum_ov003_02165730_208];
    unsigned int flags;
    unsigned char unknown_468_[0x1c];
    short unknown_484_;
    short unknown_486_;
    unsigned char unknown_488_[0x1b];
    unsigned char state;
    unsigned char step;
    unsigned char unknown_4a5_;
};

// USA: func_ov003_02165730
extern "C" ARM void func_ov003_02165730(Struct_ov003_02165730_2* view) {
    GameResources* resources = GetGameResources();
    void* flagData = GlobalFlags_GetInstance();

    if (view->step == 0) {
        func_020936f8()->unknown_3c9_0_ = 1;
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        view->unknown_484_ = view->unknown_486_ = -1;
        view->unknown_4a5_ = 0;

        GameState* gs = GameState::GetInstance();
        PartyList2a04* party = (PartyList2a04*)GameState_GetParty(gs);
        for (int i = 0; i < party->count; i++) {
            GameObject* member = func_0200ff1c(gs, party->members[i]);
            if (member != NULL) {
                member->obj3D_.MakeVisible();
            }
        }

        if (IsBrightnessTransitionActive(resources) != 0) return;
        UnlockAndSetBrightness(resources, 0, 0xf);
        view->step = 1;
        if (view->selection == NULL) return;
        func_020e25e8(view->selection);
    } else if (view->step == 1) {
        if (IsBrightnessTransitionActive(resources) != 0) return;
        if (FlagWord_TestBits((struct FlagWord02046708*)flagData, 0x41) != 0) {
            view->flags |= 0x800;
        }
        view->step = 2;
    } else if (view->step == 2) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        view->unknown_484_ = view->unknown_486_ = -1;
        view->unknown_4a5_ = 0;
        view->state = 0x10;
        view->step = 0;
    }
}
