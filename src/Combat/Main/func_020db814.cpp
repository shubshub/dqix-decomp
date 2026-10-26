#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameResources;
void Stub(GameResources*);
void UpdateBrightnessTransitions(GameResources*);
void ApplyBrightness(GameResources*);

struct Struct_020db814 {
    char pad[0x28];
    unsigned char unknown_28_;
};

// USA: func_020db814
extern "C" ARM void func_020db814(void*) {
    struct Struct_020db814* obj = (struct Struct_020db814*)GetGameResources();
    if (obj == NULL) {
        return;
    }
    obj->unknown_28_ = 1;
    Stub((GameResources*)obj);
    UpdateBrightnessTransitions((GameResources*)obj);
    ApplyBrightness((GameResources*)obj);
}
