#include <globaldefs.h>
#include "GameState/GameState.h"

void GameState_SetStoryChapter(char* obj, int v);
void GameState_SetStoryPart(char* obj, int v);
void GameState_SetStoryStep(char* base, int val);

// USA: func_0206df14
ARM void ApplySlotBytesToBattleStruct_0206df14(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    GameState_SetStoryChapter((char*)bs, (obj + obj[0x332] * 0x1c)[0]);
    GameState_SetStoryPart((char*)bs, (obj + obj[0x332] * 0x1c)[1]);
    GameState_SetStoryStep((char*)bs, (obj + obj[0x332] * 0x1c)[2]);
}
