#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define func_ov026_021d8ba0 func_ov026_021d9434
#else
#define RG(usa, jpn) (usa)
#endif

struct SearchStruct;
struct Obj02039fec;
struct FlagWord020466f4;
struct Struct_ov000_02160620_2 {
    unsigned char field_0x0[RG(0x29c, 0x218)];
    void* unknown_29c_;
    unsigned int unknown_2a0_;
    unsigned int unknown_2a4_;
    unsigned char action[0xc00];
    int state;
    int nextState;
    unsigned char unknown_eb0_[0x18];
    unsigned char elements[RG(0x2898, 0x28d8)];
    unsigned char unknown_3760_[RG(0x1e14, 0x204c)];
    int mode;
    unsigned char unknown_5578_[RG(0x54, 0x50)];
    void* unknown_55cc_;
    unsigned char unknown_55d0_[0x24];
    unsigned int flags;
    unsigned char unknown_55f8_[0x4b8];
    unsigned char effect[0x1394];
    short unknown_6e44_;
    unsigned short unknown_6e46_;
    unsigned short unknown_6e48_;
    unsigned char unknown_6e4a_[0x1b2];
    unsigned char unknown_6ffc_[0x714];
    signed char countdown;
    unsigned char unknown_7711_;
    unsigned char unknown_7712_[0xbe];
    unsigned char resetDone;
};
struct BattleManager {
    unsigned char field_0x0[RG(0x998, 0x868)];
    int blocked;
};

extern "C" SearchStruct* LinkSession_GetInstance();
extern "C" void Zone3D_Update(void*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov000_021735d0(void*, unsigned int);
extern "C" Obj02039fec* NumberPopups_GetInstance();
extern "C" void NumberPopups_Update(Obj02039fec*);
extern "C" void func_ov000_021824d8(void*);
extern "C" int func_020a1fa8();
extern "C" void func_ov025_021df794(void*);
extern "C" int LinkSession_IsGuest(SearchStruct*);
extern "C" int LinkSession_IsSlotLost(SearchStruct*, int);
extern "C" FlagWord020466f4* GlobalFlags_GetInstance();
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
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
extern "C" void SePlayer_UnloadExtraArchiveA(void*);
extern int data_ov000_02184220;
extern unsigned char g_sePlayer[0xd0];

// USA: func_ov000_02160620
extern "C" ARM void func_ov000_02160620(Struct_ov000_02160620_2* frame) {
    GameState* game = GameState::GetInstance();
    SearchStruct* search = LinkSession_GetInstance();
    unsigned char* context = (unsigned char*)GetGameResources();
    if (frame->flags & 0x200) {
        Zone3D_Update(frame->elements);
        if (frame->unknown_55cc_)
            func_ov023_021eb43c(frame->unknown_55cc_);
        if (frame->mode == 0 && (frame->flags & 0x40000) == 0 && (frame->flags & 0x80000) != 0 &&
                ((BattleManager*)MessageSystem_GetInstance())->blocked == 0)
            func_ov000_021735d0(frame->unknown_3760_, game->GetTickCount());
        NumberPopups_Update(NumberPopups_GetInstance());
        func_ov000_021824d8(frame->unknown_6ffc_);
        if (frame->state == 8 && func_020a1fa8() == 4)
            func_ov025_021df794(frame->effect);
        GameObject* object = game->GetGameObjectByIndex(0xc8);
        if (object)
            object->obj3D_.AdvanceEffects();
        if (LinkSession_IsGuest(search) && LinkSession_IsSlotLost(search, 0) && frame->resetDone == 0) {
            FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x8020);
            void* state = func_020936f8();
            func_020939dc(state);
            func_02093a14((char*)state);
            func_02094030(state, 4, -1, 0);
            frame->resetDone = 1;
        }
    }
    for (int i = 1; i < 4; ++i) {
        if (LinkSession_IsSlotLost(search, i))
            func_ov000_0215fb04(frame->unknown_29c_, i);
    }
    if (func_ov017_02195550(context) == 0)
        func_ov000_021682ec(frame);
    switch (frame->state) {
    case 0: func_ov000_02163db4(frame); break;
    case 1: func_ov000_021640dc(frame); break;
    case 4: func_ov000_0216873c(frame); break;
    case 6: func_ov000_021688dc(frame); break;
    case 7:
        if (func_020a1fa8() == 3)
            func_ov026_021d8ba0(frame);
        break;
    case 17: func_ov000_02169770((unsigned char*)frame); break;
    case 8: func_ov025_021db038(frame); break;
    case 9:
        if (func_020a1fa8() == 1) {
            func_ov023_021ed9f8(frame);
            break;
        }
    case 10:
        if (func_020a1fa8() == 1) {
            func_ov023_021f4c04(frame);
            break;
        }
    case 11:
        if (func_020a1fa8() == 3)
            func_ov026_021db090(frame);
        break;
    case 18: func_ov000_02160de4(frame); break;
    case 19: func_ov000_02160e94(frame); break;
    }
    if (frame->flags & 0x200)
        func_ov000_02160fe4(frame);
    if ((frame->flags & 0x2000000) &&
            (frame->state == 8 || frame->state == 7 || frame->state == 1 || frame->state == 0 || frame->state == 9)) {
        if (frame->state == 8)
            func_ov025_021e9558(frame->action);
        frame->flags &= ~0x2000000;
        frame->state = 4;
        frame->nextState = 0;
        data_ov000_02184220 = 1;
    }
    if (data_ov000_02184220) {
        if (frame->state == 7 || frame->state == 11) {
            func_020a1edc();
            func_020a1ef0(3);
        } else if (frame->state == 9 || frame->state == 10) {
            func_020a1edc();
            func_020a1ef0(1);
        }
        data_ov000_02184220 = 0;
    }
    if (frame->unknown_6e46_) {
        unsigned int delta = game->GetEffectiveDeltaTime();
        int speed = game->GetGameSpeed();
        unsigned int elapsed = (unsigned int)((float)delta / ((float)speed / 4096.0f));
        if (elapsed < frame->unknown_6e48_) {
            frame->unknown_6e48_ -= elapsed;
        } else if (elapsed < frame->unknown_6e46_) {
            frame->unknown_6e46_ -= elapsed;
            game->SetGameSpeed(frame->unknown_6e44_);
        } else {
            frame->unknown_6e48_ = 0;
            frame->unknown_6e46_ = 0;
            game->SetGameSpeed(0x1000);
        }
    }
    if (frame->countdown == 0)
        return;
    frame->countdown -= (signed char)game->GetTickCount();
    if (frame->countdown < 0) {
        frame->countdown = 0;
        SePlayer_UnloadExtraArchiveA(g_sePlayer);
        frame->unknown_7711_ = 0;
    }
}
