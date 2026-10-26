#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);

struct Struct_ov008_02186280 { char pad[0xb11]; unsigned char unknown_b11_; };

// USA: func_ov008_02186280
extern "C" ARM void func_ov008_02186280(struct Struct_ov008_02186280* obj) {
    int v = (int)GameState::GetInstance()->GetResources();
    MessageSystem_GetInstance();
    if (obj->unknown_b11_ == 0) {
        SetBrightness((GameResources*)v, 0, 0xf);
        obj->unknown_b11_++;
    }
}
