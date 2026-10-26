#include <globaldefs.h>
#include "Util/Random.h"
#include "GameState/GameState.h"


struct Obj0208e7d0 {
    char pad0[0xc];
    short* table;
};

extern "C" void* Scenario_GetInstance(void);
extern "C" int GameState_GetStoryChapter(char* obj);

// USA: func_0208e7d0
extern "C" ARM int func_0208e7d0(struct Obj0208e7d0* obj) {
    if (obj->table == 0) {
        return 0;
    }
    int count = 8;
    GameState* bs = GameState::GetInstance();
    Scenario_GetInstance();
    if (GameState_GetStoryChapter((char*)bs) >= 0x13) {
        count = 0x10;
    }
    struct Random* rng = GetBTRandom();
    int idx = NextRandomMax(rng, count);
    return obj->table[idx];
}
