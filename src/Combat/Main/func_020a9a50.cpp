#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void GameState_SetStoryChapter(char* obj, int v);
extern "C" void GameState_SetStoryPart(char* obj, int v);
extern "C" void GameState_SetStoryStep(char* base, int val);
extern "C" void func_02010810(char* obj, int value);
struct Struct020a99d0;
extern "C" void func_020a99d0(struct Struct020a99d0* dst, struct Struct020a99d0* src);

struct Struct_020a9a50 {
    int f0;
    int f4;
    int f8;
    int fc;
    char pad10[0x342 - 0x10];
    unsigned char unknown_342_;
};

// USA: func_020a9a50
extern "C" ARM int func_020a9a50(Struct_020a9a50* ctx, char* dst, int flag) {
    char* battle = (char*)GameState::GetInstance();
    GameState_SetStoryChapter(battle, ctx->f0);
    GameState_SetStoryPart(battle, ctx->f4);
    GameState_SetStoryStep(battle, ctx->f8);
    func_02010810(battle, ctx->fc);
    if (flag != 0) {
        memcpy(dst, (char*)ctx + 0x10, 0x8c);
        memcpy(dst + 0x8c, (char*)ctx + 0x9c, 0x15f);
        memcpy(dst + 0x2c0, (char*)ctx + 0x2d0, 0xc);
        memcpy(dst + 0x2cc, (char*)ctx + 0x2dc, 0x66);
        *(unsigned char*)(dst + 0x332) = ctx->unknown_342_;
    } else {
        func_020a99d0((struct Struct020a99d0*)dst, (struct Struct020a99d0*)((char*)ctx + 0x10));
    }
    return 1;
}
