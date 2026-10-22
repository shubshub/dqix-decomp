#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Entry_0205d6a0;
struct SePlayer;
struct BattleCommand {
    char padding0[0x10];
    signed char commands[8];
    signed char selected;
    char padding19[4];
    signed char previous;
    char padding1e[8];
    unsigned short action;
    char padding28[6];
    signed char variant;
};
struct Struct_ov004_021707e8 {
    char unknown_0_[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0x16b];
#if defined(jpn)
    char unknown_188_[0x1e10];
#else
    char unknown_188_[0x1bd8];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[9];
    unsigned short unknown_1d72_;
    char unknown_1d74_[5];
    unsigned char unknown_1d79_;
};
struct Struct_ov000_0217e870_2 {
    char unknown_0_[0xf78];
    signed char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
extern SePlayer g_sePlayer;
#if defined(jpn)
extern int data_ov000_02184294[3];
#define G02184294(i) data_ov000_02184294[(i) + 1]
#else
extern int data_ov000_02184294[2];
#define G02184294(i) data_ov000_02184294[i]
#endif
int GetField0x3acValue_020100a8(GameState*);
int GetActiveScaledSum0205d794(Struct_0205c570*);
extern "C" BattleCommand* func_ov000_02161318(BattleMenuState*, int);
extern "C" int func_ov000_0217c594(BattleMenuState*, int);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov000_02176e3c(BattleMenuState*, BattleCommand*, int, int, int, int);
extern "C" void func_ov000_02170db0(BattleCommand*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(BattleMenuState*, int, int);
extern "C" void func_ov000_02177038(BattleMenuState*, BattleCommand*, int, int, int);

// USA: func_ov000_0217e870
extern "C" ARM void func_ov000_0217e870(BattleMenuState* state, int first, int second) {
    state->flags |= 0x100;
    state->current = GetActiveScaledSum0205d794((Struct_0205c570*)state->entries);
    GameState* game = GameState::GetInstance();
    PartyState* party = (PartyState*)GetPtrField0x2a04_02010828(game);
    BattleCommand* command = func_ov000_02161318(state, GetField0x3acValue_020100a8(game));
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
    } else if (func_ov000_0217c5f4(arg0)) {
        arg0->unknown_1d72_ &= ~0x100;
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_188_, 0);
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
        arg0->unknown_1d68_--;
        arg0->unknown_1c_ = -1;
        func_ov000_0217c638(arg0, arg1, arg2);
        GameState* var6 = GameState::GetInstance();
        Struct_ov000_0217e870_2* var7 = (Struct_ov000_0217e870_2*)func_02010828(var6);
        Struct_ov000_0217e870* var8 = func_ov000_02161318(arg0, func_020100a8(var6));
        if (!var8) return;
        var8->unknown_10_[var8->unknown_18_] = 0x17;
        unsigned char var9 = var7->unknown_f7c_;
        Struct_ov000_0217e870* var10;
        for (unsigned char var11 = 0; var11 < var9; var11++) {
            var10 = func_ov000_02161318(arg0, var7->unknown_f78_[var11]);
            if (var10) {
                var10->unknown_1d_ = -1;
                var10->unknown_26_ = var8->unknown_26_;
                var10->unknown_2e_ = -1;
                var10->unknown_10_[var10->unknown_18_] = 0x17;
            }
        }
        arg0->unknown_1d79_ = 0;
        func_ov000_02176e3c(arg0, var10, 0x17, G02184294(1), G02184294(0), 0);
    }
    func_ov000_02177038(arg0, var2, 0x19, arg1, arg2);
}
