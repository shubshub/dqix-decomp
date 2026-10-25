#include <globaldefs.h>
#include "GameState/GameState.h"

int MessageSystem_GetInstance(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);

struct Obj02186280 { char pad[0xb11]; unsigned char b11; };

// USA: func_ov008_02186280
ARM void ResetCounterIfIdle_02186280(struct Obj02186280* obj) {
    int v = (int)GameState::GetInstance()->GetResources();
    MessageSystem_GetInstance();
    if (obj->b11 == 0) {
        SetBrightness((GameResources*)v, 0, 0xf);
        obj->b11++;
    }
}
