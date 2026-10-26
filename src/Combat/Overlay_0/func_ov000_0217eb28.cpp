#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Actor0209c73c;
struct Struct0205d888;
struct Entry_0205d6a0;
struct Struct_0205def8;
struct MenuEntry {
    unsigned char padding0[0xc4];
    unsigned char type;
};
struct BattleCommand {
    unsigned char padding0[0x10];
    signed char commands[8];
    signed char selected;
    unsigned char unknown_19_[0xb];
    unsigned char flags;
#if defined(jpn)
    unsigned char unknown_25_[0xa2];
#else
    unsigned char unknown1_25_[0x62];
#endif
    unsigned char active;
};
struct Struct_ov004_021707e8 {
    unsigned char padding0[0x70];
    signed char party[4];
    unsigned char unknown_74_[0x108];
    int current;
    unsigned char unknown_180_[8];
#if defined(jpn)
    unsigned char entries[0x1f98 - 0x188];
#else
    unsigned char entries[0x1bd8];
#endif
    signed char commands[8];
    signed char selected;
    unsigned char unknown_1d69_[2];
    signed char character;
    unsigned char unknown_1d6c_[3];
    unsigned char unknown_1d6f_;
    unsigned char unknown_1d70_[0xa];
    unsigned char animation;
};
struct PartyState {
    unsigned char padding0[0xf7c];
    unsigned char count;
};
extern Actor0209c73c g_bgmPlayer;
extern "C" int func_0209ca2c(void*);
extern "C" void func_0209c73c(Actor0209c73c*);
extern "C" int func_0205d97c(void*);
extern "C" int func_ov000_021815c8(void*);
extern "C" int* LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" BattleCommand* func_ov000_02161318(Struct_ov004_021707e8*, int);
extern "C" int func_ov000_021719f8(int*);
extern "C" void func_ov000_02171c04(BattleCommand*);
extern "C" MenuEntry* Window_GetTopPane(Struct0205d888*);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(Struct_ov004_021707e8*, int, int);
extern "C" void func_0205def8(Struct_0205def8*, int, int);

// USA: func_ov000_0217eb28
extern "C" ARM void func_ov000_0217eb28(Struct_ov004_021707e8* state, int first, int second) {
    if (state->animation) {
        if (func_0209ca2c(&g_bgmPlayer)) return;
        func_0209c73c(&g_bgmPlayer);
    }
    int triggered = g_keyManager.TestKeysPressed(0x601);
    triggered |= g_keyManager.TestKeysPressed(0x802);
    triggered |= func_0205d97c(state->entries) == 2;
    if (!triggered) return;
    if (state->commands[state->selected] == 0x20) {
        state->animation = 0;
        while (state->commands[state->selected] != 2) {
            state->commands[state->selected] = 0;
            state->selected--;
        }
        int character = func_ov000_021815c8(state);
        if (LinkSession_IsActive(LinkSession_GetInstance()))
            func_ov017_021c3fb4(character, 1);
        GameResources* resources = GetGameResources();
        BackgroundLoader::GetInstance();
        func_ov017_0218f5a4(resources, character, 1, 0, 0);
        BattleCommand* command = func_ov000_02161318(state, character);
        if (!command) return;
        if (func_ov000_021719f8((int*)command)) {
            command->commands[command->selected] = 0x64;
            command->flags &= ~4;
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
            if (candidate && !func_ov000_021719f8((int*)candidate) && candidate->active) {
                state->current = id;
                break;
            }
        }
        func_ov000_0217c638(state, first, second);
        func_0205def8((Struct_0205def8*)state->entries, 1, 1);
        func_0205def8((Struct_0205def8*)state->entries, 1, 2);
        func_0205def8((Struct_0205def8*)state->entries, 1, 5);
        state->character = -1;
        state->unknown_1d6f_ = 0;
    } else {
        Window_ClosePane((Entry_0205d6a0*)state->entries, 0);
        state->commands[state->selected] = 0;
        state->selected--;
        func_ov000_0217c638(state, first, second);
    }
}
