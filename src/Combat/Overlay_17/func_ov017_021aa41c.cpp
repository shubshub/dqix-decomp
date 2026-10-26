#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" int GameState_GetStoryStep(char* obj);
void SetBrightness(GameResources*, int, int);
extern "C" void func_ov017_0219bcac(unsigned char flag);
extern "C" void GameState_SetStoryChapter(char* obj, int v);
extern "C" void GameState_SetStoryPart(char* obj, int v);
extern "C" void GameState_SetStoryStep(char* base, int val);

struct Struct_ov017_021aa41c {
    unsigned char unk0;
    unsigned char flag1;
    unsigned char pad2[6];
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
};

// USA: func_ov017_021aa41c
extern "C" ARM void func_ov017_021aa41c(Struct_ov017_021aa41c* p) {
    GameState* battleStruct = GameState::GetInstance();
    char* obj = (char*)battleStruct;
    int v0 = GameState_GetStoryChapter(obj);
    int v4 = GameState_GetStoryPart(obj);
    int v8 = GameState_GetStoryStep(obj);
    if (v0 * 10000 + v4 * 100 + v8 != p->f8 * 10000 + p->fa * 100 + p->fc) {
        func_ov017_0219bcac(0);
    } else {
        GameResources* ov = GetGameResources();
        SetBrightness(ov, 0, 30);
    }
    GameState_SetStoryChapter(obj, p->f8);
    GameState_SetStoryPart(obj, p->fa);
    GameState_SetStoryStep(obj, p->fc);
    p->flag1 = 1;
}
