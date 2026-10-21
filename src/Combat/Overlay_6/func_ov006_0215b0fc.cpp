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
    unsigned char unknown_0_[Enum_ov006_0215b0fc_16];
    void* unknown_10_;
    unsigned char unknown_14_[0x38f - Enum_ov006_0215b0fc_16 - 4];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_[0x394 - 0x391];
    unsigned short unknown_394_;
    unsigned char unknown_396_[0x397 - 0x396];
    unsigned char unknown_397_;
};

// USA: func_ov006_0215b0fc
extern "C" ARM void func_ov006_0215b0fc(struct Struct0215b0fc* obj) {
    int ctx = (int)GameState::GetInstance()->GetResources();
    unsigned char state = obj->f390;
    if (state == 0) {
        unsigned short flags = *(unsigned short*)((char*)obj->f10 + kChildFlags);
        if (flags & 0x1008) {
            obj->f390 = state + 1;
        }
        return;
    }
    if (var1 == 1) {
        SetBrightness((GameResources*)var0, 0, 8);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
        return;
    }
    if (var1 != 2) {
        return;
    }
    if (IsBrightnessTransitionActive((GameResources*)var0) != 0) {
        return;
    }
    arg0->unknown_38f_ = 4;
    arg0->unknown_390_ = 0;
    if (arg0->unknown_394_ & 2) {
        arg0->unknown_397_ = 2;
        arg0->unknown_38f_ = 2;
    }
}
