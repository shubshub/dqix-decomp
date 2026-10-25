#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_02048150;

void *GameState_GetParty(GameState *gameState);
extern "C" int *func_0202ae18();
extern "C" int func_02086ef0(Struct_02048150 *arg0, int arg1);
extern "C" int func_ov002_02154b94(void *arg0, int arg1);
extern "C" int func_ov002_02154a34(void *arg0, int arg1);
extern "C" void *func_02079ee0(void *arg0, int arg1);
extern "C" int func_0202b7d8(int *arg0);
extern "C" void func_ov002_02153e90(char *arg0);
extern "C" int func_ov002_02154a6c(char *arg0, int arg1, int arg2);
extern "C" int func_ov002_021538e4(char *arg0, char *arg1, void *arg2, int arg3);
extern "C" int func_ov002_021548c4(char *arg0, int arg1, int arg2, unsigned char *arg3);
extern "C" int func_ov002_021549c8(char *arg0, int arg1, int arg2, unsigned char *arg3);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);

// USA: func_ov002_02154020
extern "C" ARM int func_ov002_02154020(char *self, char *p, char *q) {
    if (p == 0) return 0;
    if (q == 0) return 0;
    ArrayContainsByteStruct *arr = (ArrayContainsByteStruct *) GameState_GetParty(GameState::GetInstance());
    int *x                       = func_0202ae18();
    int result                   = 0;
    char *first                  = p + 8;
    char *second                 = p + 0x20;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(first + i * 6);
        func_ov002_02153e90(second + i * 6);
    }
    for (int var6 = 0; var6 < *(unsigned char *) (arg1 + 3); var6++) {
        unsigned char *var7 = (unsigned char *) (var3 + var6 * 6);
        unsigned char *var8 = (unsigned char *) (var4 + var6 * 6);
        int var9           = *(signed char *) (arg1 + 4 + var6);
        if (!func_02086ef0(var0, var9)) {
            var7[4] = 1;
            var8[4] = 1;
        }
        if (!func_ov002_02154a6c(arg0, var9, *(signed char *) (arg1 + 2))) {
            var7[0] = 1;
            continue;
        }
        if (func_ov002_02154b94(arg0, var9)) {
            var7[0] = 2;
            continue;
        }
        if (!func_ov002_02154a34(arg0, var9)) continue;
        void *var10 = func_02079ee0(*(void **) arg0, (*(unsigned int *) (arg2 + 8) << 10) >> 24);
        if (var10 == 0) continue;
        int var11 = func_ov002_021538e4(arg0, arg2, var10, *(signed char *) (arg1 + 2));
        if (var7[4]) {
            *(short *) (var7 + 2) = var11;
            var7[0]               = 3;
        } else {
            *(short *) (var7 + 2) = func_ov002_021548c4(arg0, var9, var11, var7);
        }
        if (var8[4]) {
            *(short *) (var8 + 2) = 1;
            var8[0]               = 3;
        } else {
            *(short *) (var8 + 2) = func_ov002_021549c8(arg0, var9, 2, var8);
        }
        if (var7[0] == 0 && var8[0] == 0) continue;
        if (func_0202b7d8(var1) && func_02086ef0(var0, var9)) {
            func_ov017_021c9e00(var9, 0, 0, 1);
        }
        var2 = 1;
    }
    return var2;
}
