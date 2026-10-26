#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov006_02157a60 {
    char unk_0[R(0x94, 0x9c)];
    char unknown_9c_[0x64];
    char layout_[R(0x293, 0x28b)];
    unsigned char count_;
    char unknown_38c_[0x7];
    unsigned char unknown_393_;
    char unknown_394_[0x9c];
    unsigned char unknown_430_;
    unsigned char unknown_431_;
};

extern "C" short func_ov023_021e2868(void* layout);
extern "C" short func_ov023_021e29d0(void* layout);
extern "C" unsigned short func_02081f20(void* repeat, int ticks);
extern "C" unsigned short func_ov006_021599ac(void** repeat);
extern "C" void func_ov006_02159320(Struct_ov006_02157a60* self);
extern "C" void func_ov006_021593b0(Struct_ov006_02157a60* self);

// USA: func_ov006_02159834
extern "C" ARM int func_ov006_02159834(Struct_ov006_02157a60* self) {
    int confirm = 0;
    int cancel = 0;
    int change = 0;
    if (self->unknown_393_ < 5) {
        self->unknown_393_++;
    } else {
        short var3 = func_ov023_021e2868(self->layout_);
        if (var3 == 0x76)
            change = 1;
        if (var3 == 0x77)
            change = -1;
        if (change != 0)
            self->unknown_393_ = 0;
    }
    unsigned char count = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x76)
            change = 1;
        if (element == 0x77)
            change = -1;
        confirm = element == 0x11 ? 1 : 0;
        cancel = element == 0x12 ? 1 : 0;
    }
    if ((unsigned short)(func_02081f20(self->unknown_9c_, GameState::GetInstance()->GetTickCount()) + 0xffff) <= 1) {
        unsigned short var6 = func_ov006_021599ac((void**)self->unknown_9c_);
        if (var6 == 0x40)
            change = 1;
        if (var6 == 0x80)
            change = -1;
        if (var6 == 0x20)
            count = 9;
        if (var6 == 0x10)
            count = 1;
    }
    if (count != 0) {
        int previous = self->count_;
        self->count_ = count;
        if (count == 9)
            func_ov006_02159320(self);
        else
            func_ov006_021593b0(self);
        self->unknown_430_ = previous < self->count_ ? 1 : 0;
        self->unknown_431_ = self->count_ < previous ? 1 : 0;
        return 1;
    }
    if (change != 0) {
        if (change > 0)
            func_ov006_02159320(self);
        else
            func_ov006_021593b0(self);
        return 1;
    }
    if (confirm)
        return 2;
    if (cancel)
        return 3;
    return 0;
}
