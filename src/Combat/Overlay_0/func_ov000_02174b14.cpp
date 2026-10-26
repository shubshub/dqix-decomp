#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0217228c(void* obj);
extern "C" void* LinkSession_GetInstance(GameState* gs);

struct Struct_ov000_02174b14 {
    char pad0[0x24];
    unsigned char field24;
    char unknown_25_[0x44 - 0x25];
    int posX;
    int unknown_48_;
    int combatantId;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov000_02174b14_2 {
    char pad0[0x6c];
    signed char order[4];
    char unknown_70_[0x958 - 0x70];
    struct Struct_ov000_02174b14 entries[4];
};

// USA: func_ov000_02174b14
extern "C" ARM void func_ov000_02174b14(struct Struct_ov000_02174b14_2* obj) {
    func_ov000_0217228c(obj);
    LinkSession_GetInstance(GameState::GetInstance());
    int any = 0;
    for (int i = 0; i < 4; i++) {
        struct Struct_ov000_02174b14* entry = &obj->entries[obj->order[i]];
        if (entry->combatantId < 0) {
            continue;
        }
        int flag = (entry->field24 & 4) ? 1 : 0;
        any = (any | flag) ? 1 : 0;
    }
    int y = 0;
    if (!any) {
        y = 0x20;
    }
    struct Struct_ov000_02174b14* entry;
    for (int j = 0; j < 4; j++) {
        entry = &obj->entries[obj->order[j]];
        int id = entry->combatantId;
        int var8 = 0;
        if (id >= 0) {
            var8 = id <= 3;
        }
        if (!var8) {
            continue;
        }
        entry->posX = 0;
        entry->unknown_48_ = y;
        if (entry->field24 & 4) {
            y += 0x48;
        } else {
            y += 0x28;
        }
    }
}
