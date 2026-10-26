#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215b0fc_16 = 8, Enum_ov006_0215b0fc_2786 = 0x962 };
#else
enum { Enum_ov006_0215b0fc_16 = 0x10, Enum_ov006_0215b0fc_2786 = 0xae2 };
#endif

#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

struct Struct_ov006_0215b0fc {
    unsigned char pad0[Enum_ov006_0215b0fc_16];
    void* f10;
    unsigned char pad1[0x38f - Enum_ov006_0215b0fc_16 - 4];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char pad2[0x394 - 0x391];
    unsigned short unknown_394_;
    unsigned char pad3[0x397 - 0x396];
    unsigned char unknown_397_;
};

// USA: func_ov006_0215b0fc
extern "C" ARM void func_ov006_0215b0fc(struct Struct_ov006_0215b0fc* obj) {
    int ctx = (int)GameState::GetInstance()->GetResources();
    unsigned char state = obj->unknown_390_;
    if (state == 0) {
        unsigned short flags = *(unsigned short*)((char*)obj->f10 + Enum_ov006_0215b0fc_2786);
        if (flags & 0x1008) {
            obj->unknown_390_ = state + 1;
        }
        return;
    }
    if (state == 1) {
        SetBrightness((GameResources*)ctx, 0, 8);
        obj->unknown_390_ = obj->unknown_390_ + 1;
        return;
    }
    if (state != 2) {
        return;
    }
    if (IsBrightnessTransitionActive((GameResources*)ctx) != 0) {
        return;
    }
    obj->unknown_38f_ = 4;
    obj->unknown_390_ = 0;
    if (obj->unknown_394_ & 2) {
        obj->unknown_397_ = 2;
        obj->unknown_38f_ = 2;
    }
}
