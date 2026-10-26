#include "GameState/GameState.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;

extern "C" void *GameState_GetParty(GameState *gameState);
extern "C" int *LinkSession_GetInstance();
extern "C" int func_02086ef0(ArrayContainsByteStruct *arr, int value);
extern "C" int func_ov002_02154b94(void *self, int id);
extern "C" int func_ov002_02154a34(void *self, int id);
extern "C" void *func_02079ee0(void *table, int key);
extern "C" int LinkSession_IsActive(int *p);
extern "C" void func_ov002_02153e90(char *entry);
extern "C" int func_ov002_02154a6c(char *self, int id, int arg);
extern "C" int func_ov002_021538e4(char *self, char *q, void *elem, int arg);
extern "C" int func_ov002_021548c4(char *self, int id, int value, unsigned char *entry);
extern "C" int func_ov002_021549c8(char *self, int id, int value, unsigned char *entry);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02154020
extern "C" ARM int func_ov002_02154020(char *self, char *p, char *q) {
    if (p == 0) return 0;
    if (q == 0) return 0;
    ArrayContainsByteStruct *arr = (ArrayContainsByteStruct *) GameState_GetParty(GameState::GetInstance());
    int *x                       = LinkSession_GetInstance();
    int result                   = 0;
    char *first                  = p + 8;
    char *second                 = p + 0x20;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(first + i * 6);
        func_ov002_02153e90(second + i * 6);
    }
    for (int j = 0; j < *(unsigned char *) (p + 3); j++) {
        unsigned char *e = (unsigned char *) (first + j * 6);
        unsigned char *f = (unsigned char *) (second + j * 6);
        int id           = *(signed char *) (p + 4 + j);
        if (!func_02086ef0(arr, id)) {
            e[4] = 1;
            f[4] = 1;
        }
        if (!func_ov002_02154a6c(self, id, *(signed char *) (p + 2))) {
            e[0] = 1;
            continue;
        }
        if (func_ov002_02154b94(self, id)) {
            e[0] = 2;
            continue;
        }
        if (!func_ov002_02154a34(self, id)) continue;
        void *elem = func_02079ee0(*(void **) self, (*(unsigned int *) (q + 8) << 10) >> 24);
        if (elem == 0) continue;
        int v = func_ov002_021538e4(self, q, elem, *(signed char *) (p + 2));
        if (e[4]) {
            *(short *) (e + 2) = v;
            e[0]               = 3;
        } else {
            *(short *) (e + 2) = func_ov002_021548c4(self, id, v, e);
        }
        if (f[4]) {
            *(short *) (f + 2) = 1;
            f[0]               = 3;
        } else {
            *(short *) (f + 2) = func_ov002_021549c8(self, id, 2, f);
        }
        if (e[0] == 0 && f[0] == 0) continue;
        if (LinkSession_IsActive(x) && func_02086ef0(arr, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        result = 1;
    }
    return result;
}
