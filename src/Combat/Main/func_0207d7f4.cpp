#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct Struct_0207d798;

struct Entry0207d9bc {
    unsigned short id;
    unsigned short field2;
    signed char field4;
    unsigned char field5;
    char pad6[2];
    signed char bytes[4];
};

extern "C" void* func_0207d9f4(unsigned char* arr, int offset);
extern "C" void func_0207d7c0(struct Struct_0207d798* o);
extern "C" struct Entry0207d9bc* func_0207d9bc(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" int func_0207d978(struct Entry0207d9bc* arr, unsigned short key);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);

// USA: func_0207d7f4
extern "C" ARM int func_0207d7f4(struct Entry0207d9bc* entries, unsigned short id, int arg2, int flag,
                      signed char field4, unsigned short field2, unsigned char field5) {
    signed char v;
    GameState* game = GameState::GetInstance();
    struct Entry0207d9bc* entry;
    struct SearchStruct* search;
    GameObject* combatant;
    int i;

    if (flag != 0) {
        entry = (struct Entry0207d9bc*)func_0207d9f4((unsigned char*)entries, arg2);
        if (entry != NULL && entry->id != id) {
            func_0207d7c0((struct Struct_0207d798*)entry);
        }
    }
    entry = func_0207d9bc(entries, id);
    if (entry == NULL) {
        entry = func_0207d9bc(entries, 0);
        if (entry == NULL) return 0;
        func_0207d7c0((struct Struct_0207d798*)entry);
        entry->id = id;
        search = (struct SearchStruct*)LinkSession_GetInstance();
        for (i = 0; i < 4; i++) {
            if (!LinkSession_IsSlotMember(search, i) || game->GetPartyMemberByIndex(i) == NULL)
                entry->bytes[i] = 0;
        }
    } else if (game->GetGameObjectByIndex(arg2) == NULL) {
        entry->bytes[arg2] = 0;
        return func_0207d978(entries, id);
    }
    v = (signed char)flag;
    entry->bytes[arg2] = v;
    for (i = 0; i < 4; i++) {
        combatant = func_0200ff58(game, i);
        if (combatant != NULL && func_020546a8(combatant) == arg2)
            entry->bytes[i] = v;
    }
    if (flag != 0 && entry->field4 < 0 && field4 >= 0) {
        entry->field4 = field4;
        entry->field2 = field2;
        entry->field5 = field5;
    }
    return func_0207d978(entries, id);
}
