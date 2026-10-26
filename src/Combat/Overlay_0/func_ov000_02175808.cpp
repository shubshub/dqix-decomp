#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

#if defined(jpn)
struct Struct_ov000_02175808_2 { char pad0[0x8b8]; int vocation; };
#else
struct Struct_ov000_02175808_2 { char pad0[0x950]; int vocation; };
#endif
#if defined(jpn)
struct Struct_ov000_02175808_3 : GameObject { char unknown_13c_[8]; Struct_ov000_02175808_2* record; };
#else
struct Struct_ov000_02175808_3 : GameObject { char unknown_13c_[0x14]; Struct_ov000_02175808_2* record; };
#endif
struct Entry_0205d6a0 { int field0; };
struct Struct0217f8c0 {
    char pad0[0x10];
    unsigned short values[5];
    unsigned char count;
    char unknown_1b_[5];
    int mode;
    char pad24[0x158];
    int protagonist;
    char unknown_180_[8];
    Entry_0205d6a0 list;
#if defined(jpn)
    char unknown_18c_[0x1f98-0x18c];
#else
    char unknown1_18c_[0x1d60-0x18c];
#endif
    unsigned char commands[8];
    signed char unknown_1d68_;
    char unknown_1d69_[4];
    unsigned char step;
    char unknown_1d6e_[0x13];
    unsigned char state;
};
struct PartySlots { char pad0[0xf78]; signed char ids[4]; unsigned char count; };
struct Struct_ov000_02175808 { char pad0[0x10]; unsigned char commands[8]; signed char index; };
extern "C" void __clear(void*, unsigned long);
extern "C" void func_ov000_021757ac(Struct0217f8c0*, unsigned short);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" Struct_ov000_02175808* func_ov000_02161318(Struct0217f8c0*, int);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" int func_ov000_0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(Struct0217f8c0*, int, int, int, int);
extern unsigned short data_ov000_0218342a[];
extern int data_ov000_02184288[3];
extern int data_ov000_02183ff0;

// USA: func_ov000_02175808
extern "C" ARM void func_ov000_02175808(Struct0217f8c0* self) {
    memset(self->values, 0, 10);
    self->count = 0;
    unsigned char var0[13];
    __clear(var0, 13);
    unsigned char count = 0;
    GameState* game = GameState::GetInstance();
    for (signed char i = 0; i < 4; ++i) {
        Struct_ov000_02175808_3* member = (Struct_ov000_02175808_3*)game->GetPartyMemberByIndex(i);
        if (!member) return;
        int vocation = member->record->vocation;
        if (self->mode >= 0 && data_ov000_0218342a[vocation] == 0x20a) continue;
        var0[vocation] = 1;
    }
    for (signed char i = 0; i < 13; ++i) {
        if (var0[i]) {
            func_ov000_021757ac(self, data_ov000_0218342a[i]);
            ++count;
        }
    }
    if (!count) return;
    GameState* current = GameState::GetInstance();
    self->protagonist = GameState_GetProtagonistIndex(current);
    func_ov000_021757ac(self, 0);
    PartySlots* party = (PartySlots*)GameState_GetParty(current);
    unsigned char slots = party->count;
    for (unsigned char i = 0; i < slots; ++i) {
        Struct_ov000_02175808* command = func_ov000_02161318(self, party->ids[i]);
        if (command) command->commands[command->index] = 13;
    }
    Window_ClosePane(&self->list, 1);
    self->step = 0;
    ++self->unknown_1d68_;
    self->commands[self->unknown_1d68_] = 0x17;
    int entry = func_ov000_0217f8c0(self);
    func_ov000_02176634(self, entry, 0x17, data_ov000_02183ff0, data_ov000_02184288[1]);
    self->state = 0;
}
