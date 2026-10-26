#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02162d3c
extern "C" ARM int func_ov001_02162d3c(void* obj) {
    int v = GameState_GetStoryChapter((char*)GameState::GetInstance());
    func_ov017_021d6134(obj, v >= 0x13 ? 1 : 0);
    return 1;
}
