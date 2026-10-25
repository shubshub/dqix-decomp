#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_02109bf4_5;
struct Struct_0205d0e0_2;
struct Struct_0205d6a0;
struct Struct_0205def8;
struct Struct_ov000_02179cdc_2 {
    unsigned char unknown_0_[0xc4];
    unsigned char unknown_c4_;
};
struct Struct_ov000_0217e870 {
    unsigned char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    unsigned char unknown_19_[0xb];
    unsigned char unknown_24_;
#if defined(jpn)
    unsigned char unknown_25_[0xa2];
#else
    unsigned char unknown1_25_[0x62];
#endif
    unsigned char unknown_87_;
};
struct Struct_ov004_021707e8 {
    unsigned char unknown_0_[0x70];
    signed char unknown_70_[4];
    unsigned char unknown_74_[0x108];
    int unknown_17c_;
    unsigned char unknown_180_[8];
#if defined(jpn)
    unsigned char unknown_188_[0x1f98 - 0x188];
#else
    unsigned char unknown_188_[0x1bd8];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    unsigned char unknown_1d69_[2];
    signed char unknown_1d6b_;
    unsigned char unknown_1d6c_[3];
    unsigned char unknown_1d6f_;
    unsigned char unknown_1d70_[0xa];
    unsigned char unknown_1d7a_;
};
struct Struct_ov000_0217e870_2 {
    unsigned char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};
extern Actor0209c73c g_bgmPlayer;
int IsAnimationActive0209ca2c(void*);
void DispatchActorState0209c73c(Actor0209c73c*);
extern "C" int func_0205d97c(void*);
extern "C" int func_ov000_021815c8(void*);
extern "C" int* func_0202ae18();
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" BattleCommand* func_ov000_02161318(BattleMenuState*, int);
int HasAnyFlags_021719f8_021719f8(int*);
extern "C" void func_ov000_02171c04(BattleCommand*);
MenuEntry* Window_GetTopPane(Struct0205d888*);
void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(BattleMenuState*, int, int);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);

// USA: func_ov000_0217eb28
extern "C" ARM void func_ov000_0217eb28(BattleMenuState* state, int first, int second) {
    if (state->animation) {
        if (IsAnimationActive0209ca2c(&g_bgmPlayer)) return;
        DispatchActorState0209c73c(&g_bgmPlayer);
    }
    int var0 = g_keyManager.TestKeysPressed(0x601);
    var0 |= g_keyManager.TestKeysPressed(0x802);
    var0 |= func_0205d97c(arg0->unknown_188_) == 2;
    if (!var0) return;
    if (arg0->unknown_1d60_[arg0->unknown_1d68_] == 0x20) {
        arg0->unknown_1d7a_ = 0;
        while (arg0->unknown_1d60_[arg0->unknown_1d68_] != 2) {
            arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
            arg0->unknown_1d68_--;
        }
        int var1 = func_ov000_021815c8(arg0);
        if (func_0202b7d8(func_0202ae18()))
            func_ov017_021c3fb4(var1, 1);
        GameResources* var2 = GetGameResources();
        BackgroundLoader::GetInstance();
        func_ov017_0218f5a4(var2, var1, 1, 0, 0);
        Struct_ov000_0217e870* var3 = func_ov000_02161318(arg0, var1);
        if (!var3) return;
        if (func_ov000_021719f8((int*)var3)) {
            var3->unknown_10_[var3->unknown_18_] = 0x64;
            var3->unknown_24_ &= ~4;
        }
        func_ov000_02171c04(command);
        MenuEntry* entry = Window_GetTopPane((Struct0205d888*)state->entries);
        while (entry) {
            if (entry->type == 2) break;
            Window_ClosePane((Entry_0205d6a0*)state->entries, 0);
            entry = Window_GetTopPane((Struct0205d888*)state->entries);
        }
        unsigned char count = ((PartyState*)GameState_GetParty(GameState::GetInstance()))->count;
        for (unsigned char i = 0; i < count; i++) {
            int id = state->party[i];
            BattleCommand* candidate = func_ov000_02161318(state, id);
            if (candidate && !HasAnyFlags_021719f8_021719f8((int*)candidate) && candidate->active) {
                state->current = id;
                break;
            }
        }
        func_ov000_0217c638(arg0, arg1, arg2);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 1);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 2);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 5);
        arg0->unknown_1d6b_ = -1;
        arg0->unknown_1d6f_ = 0;
    } else {
        Window_ClosePane((Entry_0205d6a0*)state->entries, 0);
        state->commands[state->selected] = 0;
        state->selected--;
        func_ov000_0217c638(state, first, second);
    }
}
