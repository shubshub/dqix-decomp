#include <globaldefs.h>
#include "Util/Random.h"
#include "Input/Input.h"

struct Struct_ov000_0217b380_2 {
#if defined(jpn)
    char pad0[0x1faa];
#else
    char pad0[0x1d72];
#endif
    unsigned short flags;
};

struct Struct_ov000_02184294_3 {
#if defined(jpn)
    struct Struct_ov000_0217b380_2* menu;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    struct Struct_ov000_0217b380_2* menu;
#endif
};
extern struct Struct_ov000_02184294_3 data_ov000_02184294;

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_ov000_021761c8(char* base, int index);
extern "C" int func_ov000_02175348(void* obj, int value);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int func_ov000_0217ab48(void* obj);
extern "C" void func_ov000_02170db0(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* menu, void* obj, int state, int arg3, int arg4, int flag);

extern struct SePlayer g_sePlayer;

struct Struct_ov000_0217b380 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[4];
    signed char selection;
    char pad1e[0x1a];
    struct Struct_0205c570* window;
};

// USA: func_ov000_0217b380
extern "C" ARM int func_ov000_0217b380(struct Struct_ov000_0217b380* self, int arg1, int arg2) {
    data_ov000_02184294.menu->flags |= 0x100;
    int base = Window_GetSelectedIndex(self->window);
    self->selection = base;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)self->window, 0x14)) != 0;
    if (confirm) {
        if (Window_IsSelectionTouched((struct Obj_0205da38*)self->window, 0x14)) {
            int value = func_ov000_021761c8((char*)data_ov000_02184294.menu, base);
            int matches = func_ov000_02175348(data_ov000_02184294.menu, value);
            self->selection = NextRandomMax(GetBTRandom(), matches * 100) / 100 + (signed char)base;
        }
        SePlayer_Play(&g_sePlayer, 1, 0);
        self->unknown_18_++;
        self->unknown_10_[self->unknown_18_] = 100;
        func_ov000_02170db0(self);
    } else if (func_ov000_0217ab48(self)) {
        func_ov000_0217629c(self);
        self->unknown_10_[self->unknown_18_] = 0;
        self->unknown_18_--;
        self->selection = -1;
        func_ov000_0217ab8c(self, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.menu, self, self->unknown_10_[self->unknown_18_],
                            data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
