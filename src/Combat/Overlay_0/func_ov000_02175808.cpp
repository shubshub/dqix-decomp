#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

#if defined(jpn)
struct Struct_ov000_02175808_2 { char unknown_0_[0x8b8]; int unknown_950_; };
#else
struct Struct_ov000_02175808_2 { char unknown_0_[0x950]; int unknown_950_; };
#endif
#if defined(jpn)
struct Struct_ov000_02175808_3 : GameObject { char unknown_13c_[8]; Struct_ov000_02175808_2* unknown_150_; };
#else
struct Struct_ov000_02175808_3 : GameObject { char unknown_13c_[0x14]; Struct_ov000_02175808_2* unknown_150_; };
#endif
struct Struct_0205d6a0 { int unknown_0_; };
struct Struct_ov000_021735d0_3 {
    char unknown_0_[0x10];
    unsigned short unknown_10_[5];
    unsigned char unknown_1a_;
    char unknown_1b_[5];
    int unknown_20_;
    char unknown_24_[0x158];
    int unknown_17c_;
    char unknown_180_[8];
    Struct_0205d6a0 unknown_188_;
#if defined(jpn)
    char unknown_18c_[0x1f98-0x18c];
#else
    char unknown1_18c_[0x1d60-0x18c];
#endif
    unsigned char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[4];
    unsigned char unknown_1d6d_;
    char unknown_1d6e_[0x13];
    unsigned char unknown_1d81_;
};
struct Struct_ov000_02175808_4 { char unknown_0_[0xf78]; signed char unknown_f78_[4]; unsigned char unknown_f7c_; };
struct Struct_ov000_02175808 { char unknown_0_[0x10]; unsigned char unknown_10_[8]; signed char unknown_18_; };
extern "C" void __clear(void*, unsigned long);
extern "C" void func_ov000_021757ac(Struct0217f8c0*, unsigned short);
int GameState_GetProtagonistIndex(GameState*);
extern "C" CombatCommand* func_ov000_02161318(Struct0217f8c0*, int);
void Window_ClosePane(Entry_0205d6a0*, int);
int FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(Struct0217f8c0*, int, int, int, int);
extern unsigned short data_ov000_0218342a[];
extern int data_ov000_02184288[3];
extern int data_ov000_02183ff0;

// USA: func_ov000_02175808
extern "C" ARM void func_ov000_02175808(Struct_ov000_021735d0_3* arg0) {
    memset(arg0->unknown_10_, 0, 10);
    arg0->unknown_1a_ = 0;
    unsigned char var0[13];
    __clear(var0, 13);
    unsigned char var1 = 0;
    GameState* var2 = GameState::GetInstance();
    for (signed char var3 = 0; var3 < 4; ++var3) {
        Struct_ov000_02175808_3* var4 = (Struct_ov000_02175808_3*)var2->GetPartyMemberByIndex(var3);
        if (!var4) return;
        int var5 = var4->unknown_150_->unknown_950_;
        if (arg0->unknown_20_ >= 0 && data_ov000_0218342a[var5] == 0x20a) continue;
        var0[var5] = 1;
    }
    for (signed char var6 = 0; var6 < 13; ++var6) {
        if (var0[var6]) {
            func_ov000_021757ac(arg0, data_ov000_0218342a[var6]);
            ++var1;
        }
    }
    if (!count) return;
    GameState* current = GameState::GetInstance();
    self->protagonist = GameState_GetProtagonistIndex(current);
    func_ov000_021757ac(self, 0);
    PartySlots* party = (PartySlots*)GameState_GetParty(current);
    unsigned char slots = party->count;
    for (unsigned char i = 0; i < slots; ++i) {
        CombatCommand* command = func_ov000_02161318(self, party->ids[i]);
        if (command) command->commands[command->index] = 13;
    }
    Window_ClosePane(&self->list, 1);
    self->step = 0;
    ++self->commandIndex;
    self->commands[self->commandIndex] = 0x17;
    int entry = FindMatchingTableEntry0217f8c0(self);
    func_ov000_02176634(self, entry, 0x17, data_ov000_02183ff0, data_ov000_02184288[1]);
    self->state = 0;
}
