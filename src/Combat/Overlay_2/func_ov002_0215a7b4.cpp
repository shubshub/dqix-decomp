#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "GameState/GameState.h"

struct Element020de650 { unsigned int v[8]; };
struct Struct_02061c04_22 { unsigned char pad[0x454]; short slots[8]; };
struct Struct_02061c04_23 { short* keys; signed char* unknown_4_; short count; };

extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" int func_020dddcc(void* obj);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);
extern "C" int func_020ddcbc(int n, int idx, struct ItemTable* container, int unused4);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0208386c(struct Struct_02061c04_22* s, int idx);

#if defined(jpn)
#define CONTAINER_0215a7b4 0x750
#define DIRTY_0215a7b4 0x22a8
#else
#define CONTAINER_0215a7b4 0x7ec
#define DIRTY_0215a7b4 0x2478
#endif

// USA: func_ov002_0215a7b4
extern "C" ARM void func_ov002_0215a7b4(char* self, int type, int key, int extra, unsigned char flag) {
    GameState* battle = GameState::GetInstance();
    if (type == 4) {
        if (flag != 0) {
            struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + CONTAINER_0215a7b4), key);
            if (elem != 0) {
                func_020dddcc(elem);
            }
        } else {
            void* p2a04 = GameState_GetParty(battle);
            func_020a0a08((struct Struct_02061c04_23*)p2a04, key, 1);
        }
        *(unsigned char*)(self + DIRTY_0215a7b4) = 1;
        return;
    }
    if (flag != 0) {
        func_020ddcbc(type, extra, (struct ItemTable*)(self + CONTAINER_0215a7b4), 0);
    } else {
        GameObject* combatant = func_0200ff1c(battle, type);
        if (combatant == 0) return;
        {
            int field150 = func_02053c6c((unsigned char*)combatant);
            func_0208386c((struct Struct_02061c04_22*)field150, (signed char)extra);
        }
    }
    *(unsigned char*)(self + DIRTY_0215a7b4) = 1;
}
