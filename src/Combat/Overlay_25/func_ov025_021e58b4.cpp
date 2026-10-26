#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameResources;
int SetMainBrightnessWithDurationMs(GameResources*, int, unsigned int);

struct Struct_ov025_021e58b4 { char pad[8]; unsigned short field_8; signed char field_a; };

// USA: func_ov025_021e58b4
extern "C" ARM int func_ov025_021e58b4(struct Struct_ov025_021e58b4* p) {
    GameResources* obj = GetGameResources();
    SetMainBrightnessWithDurationMs(obj, p->field_a, p->field_8);
    return 1;
}
