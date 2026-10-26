#include <globaldefs.h>

#if defined(jpn)
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif
#include "GameState/GameState.h"

struct List_02028430;
struct ListEntry_02028430;
extern "C" ListEntry_02028430* NodeGraph_GetNode(List_02028430* list, int index);

struct Struct_02073d58 {
    unsigned short kind : 2;
    unsigned short pad : 14;
};

// USA: func_02073d58
extern "C" ARM int func_02073d58(int entryId, void* spawnGroup, int arg2) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 0xc; i++) {
        int kind = ((struct Struct_02073d58*)((char*)spawnGroup + 2))->kind;
        int var3 = kind * 12 + 0x70;
        int id = i + var3;
        if (arg2 != -1 && id == arg2) continue;
        GameObject* combatant = bs->GetWanderingMonsterByIndex(id);
        if (!combatant) continue;
        if (!combatant->obj3D_.IsVisible()) continue;
        unsigned short field_b8 = combatant->combatFields_.unknown_b8_;
        ListEntry_02028430* entry = NodeGraph_GetNode((List_02028430*)((char*)spawnGroup + EntryListOffset), field_b8);
        if (!entry) continue;
        if (*(unsigned char*)entry == entryId) return 1;
    }
    return 0;
}
