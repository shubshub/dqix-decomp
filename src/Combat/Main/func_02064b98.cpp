#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void GameState_SetStoryChapter(char* obj, int v);
extern "C" void GameState_SetStoryPart(char* obj, int v);
extern "C" void GameState_SetStoryStep(char* base, int val);

// USA: func_02064b98
extern "C" ARM void func_02064b98(unsigned char* table, int arg1) {
    unsigned char* entry;
    if ((arg1 >= 0x1068 && arg1 <= 0x106a) || (arg1 >= 0x2328 && arg1 <= 0x2330)) {
        table[0x332] = 1;
        table += 0x1c;
        entry = table;
    } else if ((arg1 >= 0x6a4 && arg1 <= 0x6aa) || (arg1 >= 0x708 && arg1 <= 0x710) ||
               (arg1 >= 0x1770 && arg1 <= 0x1771) || (arg1 >= 0x1e14 && arg1 <= 0x1e1d)) {
        table[0x332] = 2;
        table += 0x38;
        entry = table;
    } else if ((arg1 >= 0xc8 && arg1 <= 0xdb) || (arg1 >= 0x1e7a && arg1 <= 0x1e81)) {
        table[0x332] = 3;
        table += 0x54;
        entry = table;
    } else if ((arg1 >= 0x834 && arg1 <= 0x83d) || (arg1 >= 0x206d && arg1 <= 0x206f)) {
        table[0x332] = 4;
        table += 0x70;
        entry = table;
    } else {
        table[0x332] = 0;
        entry = table;
    }
    GameState* bs = GameState::GetInstance();
    GameState_SetStoryChapter((char*)bs, entry[0]);
    GameState_SetStoryPart((char*)bs, entry[1]);
    GameState_SetStoryStep((char*)bs, entry[2]);
}
