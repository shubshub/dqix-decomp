#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <globaldefs.h>

extern "C" GameObject *func_0200ff1c(GameState *gameState, int combatantId);

// USA: func_ov002_02154a6c
extern "C" ARM int func_ov002_02154a6c(void *self, int idA, int arg2) {
    GameState *gs = GameState::GetInstance();
    GameObject *a = func_0200ff1c(gs, idA);
    if (a == NULL) return 0;
    GameObject *b = func_0200ff1c(gs, arg2);
    if (b == NULL) return 0;

    if (a->obj3D_.GetField06() == b->obj3D_.GetField06()) return 1;

    if ((a->obj3D_.GetField06() == 10000 && b->obj3D_.GetField06() == 5900) ||
        (a->obj3D_.GetField06() == 5900 && b->obj3D_.GetField06() == 10000))
    {
        return 1;
    }

    if ((a->obj3D_.GetField06() == 10100 && b->obj3D_.GetField06() == 6401) ||
        (a->obj3D_.GetField06() == 6401 && b->obj3D_.GetField06() == 10100))
    {
        return 1;
    }

    return 0;
}
