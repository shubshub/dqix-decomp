#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x21c
#else
#define REGION_OFFSET_0 0x2a0
#endif

#include "GameState/GameState.h"

struct Struct_ov000_02163b90 { char pad[REGION_OFFSET_0]; unsigned char* unknown_2a0_; };

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_02049f28(unsigned char* obj);
extern "C" void func_02049f3c(unsigned char* obj);

// USA: func_ov000_02163b90
extern "C" ARM void func_ov000_02163b90(struct Struct_ov000_02163b90* self, int clear) {
    GameState* bs = GameState::GetInstance();
    int id;
    for (id = 0; id <= 3; id++) {
        GameObject* c = func_0200ff1c(bs, id);
        if (!c) continue;
        if (!func_020a35e0(self->unknown_2a0_, id & 0xff)) continue;
        if (clear) {
            ((Object3D*)((unsigned char*)c))->MakeVisible();
            func_02049f28((unsigned char*)c);
        } else {
            ((Object3D*)((unsigned char*)c))->MakeHidden();
            func_02049f3c((unsigned char*)c);
        }
    }
}
