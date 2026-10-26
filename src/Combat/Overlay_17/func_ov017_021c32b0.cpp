#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c32b0 { unsigned char source, destination; };
struct Struct_ov017_021c32b0_2 { signed char ids[11]; };
struct Struct_ov017_021c32b0_3 {
#if defined(jpn)
    unsigned char unknown0[0x41ac];
#else
    unsigned char unknown0[0x445c];
#endif
    Struct_ov017_021c32b0_2 party[4];
};
struct Struct_ov017_021c32b0_4 { GameObject* unknown_0_; GameObject* attachments[9]; };
struct Struct_ov017_021c32b0_5 { unsigned short partySlot; };
struct Struct_ov017_021c32b0_6 {
#if defined(jpn)
    unsigned char unknown0[0x148];
#else
    unsigned char unknown0[0x154];
#endif
    Struct_ov017_021c32b0_5* models;
};
struct Struct_ov017_021c32b0_7 { char pad[0x568]; unsigned short slot; };
extern "C" void func_0200fd48(GameState*, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" Struct_ov017_021c32b0_7* func_02053c6c(unsigned char*);

// USA: func_ov017_021c32b0
extern "C" ARM void func_ov017_021c32b0(Struct_ov017_021c32b0* arg0, int count) {
    Struct_ov017_021c32b0_4 saved[4];
    Struct_ov017_021c32b0_2 var1[4];
    Struct_ov017_021c32b0_3* resources;
    GameState* game;
    game = GameState::GetInstance();
    resources = (Struct_ov017_021c32b0_3*)GetGameResources();
    int i = 0;
    while (i < count) {
        unsigned char id = arg0[i].source;
        saved[i].unknown_0_ = game->GetGameObjectByIndex(id);
        func_0200fd48(game, id);
        saved[i].attachments[0] = game->GetGameObjectByIndex(id * 12 + 0x13);
        func_0200fd48(game, id * 12 + 0x13);
        saved[i].attachments[1] = game->GetGameObjectByIndex(id * 12 + 0x14);
        func_0200fd48(game, id * 12 + 0x14);
        saved[i].attachments[2] = game->GetGameObjectByIndex(id * 12 + 0x15);
        func_0200fd48(game, id * 12 + 0x15);
        saved[i].attachments[3] = game->GetGameObjectByIndex(id * 12 + 0x16);
        func_0200fd48(game, id * 12 + 0x16);
        saved[i].attachments[4] = game->GetGameObjectByIndex(id * 12 + 0x17);
        func_0200fd48(game, id * 12 + 0x17);
        saved[i].attachments[5] = game->GetGameObjectByIndex(id * 12 + 0x19);
        func_0200fd48(game, id * 12 + 0x19);
        saved[i].attachments[6] = game->GetGameObjectByIndex(id * 12 + 0x1b);
        func_0200fd48(game, id * 12 + 0x1b);
        saved[i].attachments[7] = game->GetGameObjectByIndex(id * 12 + 0x1c);
        func_0200fd48(game, id * 12 + 0x1c);
        saved[i].attachments[8] = game->GetGameObjectByIndex(id * 12 + 0x1d);
        func_0200fd48(game, id * 12 + 0x1d);
        memcpy(&var1[i], &resources->party[id], sizeof(Struct_ov017_021c32b0_2));
        i++;
    }
    int j = 0;
    while (j < count) {
        int id = arg0[j].destination;
        func_0200fd38(game, id, saved[j].unknown_0_);
        func_0200fd38(game, id * 12 + 0x13, saved[j].attachments[0]);
        func_0200fd38(game, id * 12 + 0x14, saved[j].attachments[1]);
        func_0200fd38(game, id * 12 + 0x15, saved[j].attachments[2]);
        func_0200fd38(game, id * 12 + 0x16, saved[j].attachments[3]);
        func_0200fd38(game, id * 12 + 0x17, saved[j].attachments[4]);
        func_0200fd38(game, id * 12 + 0x19, saved[j].attachments[5]);
        func_0200fd38(game, id * 12 + 0x1b, saved[j].attachments[6]);
        func_0200fd38(game, id * 12 + 0x1c, saved[j].attachments[7]);
        func_0200fd38(game, id * 12 + 0x1d, saved[j].attachments[8]);
        Struct_ov017_021c32b0_6* combatant = (Struct_ov017_021c32b0_6*)func_0200ff1c(game, id);
        if (combatant) {
            Struct_ov017_021c32b0_7* data = func_02053c6c((unsigned char*)combatant);
            if (data) data->slot = id;
            if (combatant->models) combatant->models->partySlot = id;
        }
        memcpy(&resources->party[id], &var1[j], sizeof(Struct_ov017_021c32b0_2));
        j++;
    }
}
