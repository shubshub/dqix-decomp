#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Entry_0205d6a0;
struct SePlayer;
struct BattleCommand {
    char padding0[0x10];
    signed char commands[8];
    signed char selected;
    char unknown_19_[4];
    signed char previous;
    char unknown_1e_[8];
    unsigned short action;
    char padding28[6];
    signed char variant;
};
struct Struct_ov004_021707e8 {
    char padding0[0x1c];
    signed char current;
    char unknown_1d_[0x16b];
#if defined(jpn)
    char entries[0x1e10];
#else
    char entries[0x1bd8];
#endif
    signed char commands[8];
    signed char selected;
    char unknown_1d69_[9];
    unsigned short flags;
    char unknown_1d74_[5];
    unsigned char unknown_1d79_;
};
struct PartyState {
    char padding0[0xf78];
    signed char ids[4];
    unsigned char count;
};
extern SePlayer g_sePlayer;
#if defined(jpn)
extern int data_ov000_02184294[3];
#define G02184294(i) data_ov000_02184294[(i) + 1]
#else
extern int data_ov000_02184294[2];
#define G02184294(i) data_ov000_02184294[i]
#endif
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" BattleCommand* func_ov000_02161318(Struct_ov004_021707e8*, int);
extern "C" int func_ov000_0217c594(Struct_ov004_021707e8*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov000_02176e3c(Struct_ov004_021707e8*, BattleCommand*, int, int, int, int);
extern "C" void func_ov000_02170db0(BattleCommand*);
extern "C" int func_ov000_0217c5f4(void*);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(Struct_ov004_021707e8*, int, int);
extern "C" void func_ov000_02177038(Struct_ov004_021707e8*, BattleCommand*, int, int, int);

// USA: func_ov000_0217e870
extern "C" ARM void func_ov000_0217e870(Struct_ov004_021707e8* state, int first, int second) {
    state->flags |= 0x100;
    state->current = Window_GetSelectedIndex((Struct_0205c570*)state->entries);
    GameState* game = GameState::GetInstance();
    PartyState* party = (PartyState*)GameState_GetParty(game);
    BattleCommand* command = func_ov000_02161318(state, GameState_GetProtagonistIndex(game));
    if (func_ov000_0217c594(state, 0)) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (!command) return;
        func_ov000_02176e3c(state, command, state->commands[state->selected], G02184294(1), G02184294(0), 1);
        state->flags &= ~0x100;
        state->selected++;
        state->commands[state->selected] = 0x64;
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            BattleCommand* candidate = func_ov000_02161318(state, party->ids[i]);
            if (candidate) {
                candidate->previous = state->current;
                candidate->action = command->action;
                candidate->variant = -1;
                candidate->commands[candidate->selected] = 0x64;
                func_ov000_02170db0(candidate);
            }
        }
    } else if (func_ov000_0217c5f4(state)) {
        state->flags &= ~0x100;
        Window_ClosePane((Entry_0205d6a0*)state->entries, 0);
        state->commands[state->selected] = 0;
        state->selected--;
        state->current = -1;
        func_ov000_0217c638(state, first, second);
        GameState* game = GameState::GetInstance();
        PartyState* party = (PartyState*)GameState_GetParty(game);
        BattleCommand* current = func_ov000_02161318(state, GameState_GetProtagonistIndex(game));
        if (!current) return;
        current->commands[current->selected] = 0x17;
        unsigned char count = party->count;
        BattleCommand* candidate;
        for (unsigned char i = 0; i < count; i++) {
            candidate = func_ov000_02161318(state, party->ids[i]);
            if (candidate) {
                candidate->previous = -1;
                candidate->action = current->action;
                candidate->variant = -1;
                candidate->commands[candidate->selected] = 0x17;
            }
        }
        state->unknown_1d79_ = 0;
        func_ov000_02176e3c(state, candidate, 0x17, G02184294(1), G02184294(0), 0);
    }
    func_ov000_02177038(state, command, 0x19, first, second);
}
