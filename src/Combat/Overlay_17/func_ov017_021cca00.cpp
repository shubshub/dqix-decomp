#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* combatant);

struct Struct_ov017_021cca00 {
    unsigned short combatantId;
    unsigned short unknown_2_;
    unsigned char unknown_4_[12];
};

struct Struct_ov017_021cca00_2 {
    unsigned char tag;
    unsigned char reserved[3];
    Struct_ov017_021cca00 payload;
};

struct Struct_ov017_021cca00_3 {
    char unknown_0_[0x186];
    unsigned char unknown_186_[13];
#if defined(jpn)
    char unknown_193_[0x8b8 - 0x193];
#else
    char unknown1_193_[0x950 - 0x193];
#endif
    int unknown_950_;
    unsigned short unknown_954_;
};

extern "C" ARM void func_ov017_021cca00(int unused0, unsigned char* source, GameState* game, int arg3) {
    Struct_ov017_021cca00* event = &((Struct_ov017_021cca00_2*)source)->payload;
    GameObject* combatant = func_0200ff1c(game, event->combatantId);
    if (combatant == NULL) return;
    Struct_ov017_021cca00_3* slots = (Struct_ov017_021cca00_3*)func_02053c6c((unsigned char*)combatant);
    if (slots == NULL) return;
    slots->unknown_954_ = event->unknown_2_;
    for (int i = 0; i < 12; ++i) {
        slots->unknown_186_[i + 1] = event->unknown_4_[i];
    }
}
