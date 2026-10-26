#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov006_021599c0_116 = 0x6c, Enum_ov006_021599c0_651 = 0x293 };
#else
enum { Enum_ov006_021599c0_116 = 0x74, Enum_ov006_021599c0_651 = 0x28b };
#endif

struct Struct_ov006_02157a60 {
    char unk_0[Enum_ov006_021599c0_116];
    char ingredients_[0x28];
    char unknown_9c_[0x64];
    char layout_[Enum_ov006_021599c0_651];
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
extern "C" int func_ov006_02153a78(void* ingredients, int arg1);
extern "C" void func_ov006_0215f9e8(Struct_ov006_02157a60* self);
extern "C" void func_ov006_0215a5dc(Struct_ov006_02157a60* self);

// USA: func_ov006_021599c0
extern "C" ARM unsigned char func_ov006_021599c0(Struct_ov006_02157a60* self) {
    int confirm = 0;
    int cancel = 0;
    int change = 0;
    if (self->unknown_393_ < 5) {
        self->unknown_393_++;
    } else {
        short var3 = func_ov023_021e2868(self->layout_);
        if (var3 == 0x49)
            change = 1;
        if (var3 == 0x4a)
            change = -1;
        if (change != 0)
            self->unknown_393_ = 0;
    }
    unsigned char count = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x49)
            change = 1;
        if (element == 0x4a)
            change = -1;
        confirm = element == 0x4e ? 1 : 0;
        cancel = element == 0x14 ? 1 : 0;
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
        while (!func_ov006_02153a78(self->ingredients_, self->count_))
            self->count_--;
        if (previous < self->count_)
            self->unknown_430_ = 1;
        if (self->count_ < previous)
            self->unknown_431_ = 1;
        func_ov006_0215f9e8(self);
        func_ov006_0215a5dc(self);
        return 1;
    }
    if (change != 0) {
        int previous = self->count_;
        self->count_ = previous + change;
        if (!func_ov006_02153a78(self->ingredients_, self->count_))
            self->count_--;
        if (self->count_ == 0)
            self->count_ = 1;
        if (self->count_ > 9)
            self->count_ = 9;
        if (previous < self->count_)
            self->unknown_430_ = 1;
        if (self->count_ < previous)
            self->unknown_431_ = 1;
        func_ov006_0215f9e8(self);
        func_ov006_0215a5dc(self);
        return 1;
    }
    if (confirm)
        return 2;
    if (cancel)
        return 3;
    return 0;
}
