#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0200fd48(GameState* battleStruct, int id);

struct Struct_02057f00 {
    int value;
    char pad[0x1ec - 4];
    struct Struct_02057f00* next;
};

struct Struct_02057f00_2 {
    struct Struct_02057f00* head;
};

// USA: func_02057f00
extern "C" ARM void func_02057f00(void* obj, int value) {
    struct Struct_02057f00* node = ((struct Struct_02057f00_2*)obj)->head;
    struct Struct_02057f00* prev = 0;
    GameState* battleStruct = GameState::GetInstance();
    int i;
    for (i = 0; i < 16; i++) {
        if (value == *(int*)((char*)obj + i * 0xd4 + 0xd8)) {
            func_0200fd48(battleStruct, i + 0xd0);
        }
    }
    while (node != 0) {
        if (value == node->value) break;
        prev = node;
        node = node->next;
    }
    if (node == 0) return;
    if (prev == 0) {
        ((struct Struct_02057f00_2*)obj)->head = node->next;
    } else {
        prev->next = node->next;
    }
}
