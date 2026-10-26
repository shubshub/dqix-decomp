#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
extern char g_stringFormat;
#endif

extern "C" void func_02052958(char* combatant, char* name, int arg2);

struct Struct_ov017_021c4618 {
    unsigned char tag;
    unsigned char reserved[3];
    unsigned char combatantId;
    char name[15];
};

struct CombatantNameView {
    char unknown_0_[0x134];
    char* displayName;
};

extern "C" ARM void func_ov017_021c4618(int unused0, char* source, GameState* game, GameResources* resources) {
    Struct_ov017_021c4618* event = (Struct_ov017_021c4618*)source;
    unsigned char partyIndex = event->combatantId;
    GameObject* combatant = func_0200ff1c(game, partyIndex);
    if (combatant == NULL) return;
#if defined(jpn)
    sprintf(((CombatantNameView*)combatant)->displayName, &g_stringFormat, event->name);
    strcpy(resources->partyNames[partyIndex], event->name);
#else
    func_02052958((char*)combatant, event->name, 1);
    strcpy(resources->partyNames[partyIndex], ((CombatantNameView*)combatant)->displayName);
#endif
}
