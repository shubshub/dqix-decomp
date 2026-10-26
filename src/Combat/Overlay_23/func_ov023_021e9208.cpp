#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9208
extern "C" ARM int func_ov023_021e9208(void* obj) {
    char* bs = (char*)GameState::GetInstance();
    func_ov017_021d6134(obj, GameState_GetStoryChapter(bs));
    func_ov017_021d6134((char*)obj + 0x8, GameState_GetStoryPart(bs));
    return 1;
}
