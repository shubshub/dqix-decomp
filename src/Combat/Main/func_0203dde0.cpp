#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0203f370(void* obj);

struct Struct_0203dde0 {
    char pad[0x14];
    void* field14;
};

struct Struct_0203dde0_2 {
    char pad0[0xc];
    struct Struct_0203dde0* entries[0x20];
    char pad2[0xc];
    unsigned int field98;
};

// USA: func_0203dde0
extern "C" ARM void func_0203dde0(struct Struct_0203dde0_2* obj) {
    int i;
    if (obj->field98 & 0x1) {
        return;
    }
    GameState::GetInstance();
    for (i = 0; i < 0x20; i++) {
        struct Struct_0203dde0* entry = obj->entries[i];
        if (entry != NULL && entry->field14 != NULL) {
            func_0203f370(entry->field14);
        }
    }
}
