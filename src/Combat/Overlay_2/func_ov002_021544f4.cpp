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
extern "C" int func_ov002_02154944(char *arg0, int arg1, int arg2, unsigned char *arg3);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);

// USA: func_ov002_021544f4
extern "C" ARM int func_ov002_021544f4(char *self, char *p, char *q, int flag) {
    if (p == 0) return 0;
    if (q == 0) return 0;
    ArrayContainsByteStruct *arr = (ArrayContainsByteStruct *) GameState_GetParty(GameState::GetInstance());
    int *x                       = func_0202ae18();
    int result                   = 0;
    char *entries                = p + 8;
    if (flag) entries = p + 0x20;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(entries + i * 6);
    }
    for (int var5 = 0; var5 < *(unsigned char *) (arg1 + 3); var5++) {
        unsigned char *var6 = (unsigned char *) (var3 + var5 * 6);
        int var7           = *(signed char *) (arg1 + 4 + var5);
        if (!func_02086ef0(var0, var7)) var6[4] = 1;
        if (!func_ov002_02154a6c(arg0, var7, *(signed char *) (arg1 + 2))) {
            var6[0] = 1;
            continue;
        }
        if (func_ov002_02154b94(arg0, var7)) {
            var6[0] = 2;
            continue;
        }
        if (!func_ov002_02154a34(arg0, var7)) continue;
        int var8;
        if (*(short *) arg1 == 411) {
            var8 = 999;
        } else {
            void *var9 = func_02079ee0(*(void **) arg0, (*(unsigned int *) (arg2 + 8) << 10) >> 24);
            if (var9 == 0) continue;
            var8 = func_ov002_021538e4(arg0, arg2, var9, *(signed char *) (arg1 + 2));
        }
        if (var6[4]) {
            *(short *) (var6 + 2) = var8;
            var6[0]               = 3;
        } else {
            *(short *) (var6 + 2) = func_ov002_02154944(arg0, var7, var8, var6);
        }
        if (var6[0] == 0) continue;
        if (func_0202b7d8(var1) && func_02086ef0(var0, var7)) {
            func_ov017_021c9e00(var7, 0, 0, 1);
        }
        var2 = 1;
    }
    return var2;
}
