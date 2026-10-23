#include <globaldefs.h>
#include "Util/Random.h"
#include "Input/Input.h"

struct Struct_ov000_0217b380_2 {
#if defined(jpn)
    char unknown_0_[0x1faa];
#else
    char unknown1_0_[0x1d72];
#endif
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184294_3 {
#if defined(jpn)
    struct Struct_ov000_0217b380_2* unknown_8_;
    int unknown_0_;
    int unknown_4_;
#else
    int unknown_0_;
    int unknown_4_;
    struct Struct_ov000_0217b380_2* unknown_8_;
#endif
};
extern struct Struct_ov000_02184294_3 data_ov000_02184294;

struct Struct_0205c570;
int Window_GetSelectedIndex(struct Struct_0205c570* s);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
int GetClampedArrayField0xd1c_ov000_021761c8(char* base, int index);
int CountMatchingValues02175348(void* obj, int value);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
int CheckFlagsOrField_0217ab48_0217ab48(void* obj);
extern "C" void func_ov000_02170db0(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* menu, void* obj, int state, int arg1, int arg2, int flag);

extern struct SePlayer g_sePlayer;

struct Struct_ov000_0217b380 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[4];
    signed char unknown_1d_;
    char unknown_1e_[0x1a];
    struct Struct_0205c570* unknown_38_;
};

// USA: func_ov000_0217b380
extern "C" ARM int func_ov000_0217b380(struct MenuState0217b380* self, int arg1, int arg2) {
    data_ov000_02184294.menu->flags |= 0x100;
    int base = Window_GetSelectedIndex(self->window);
    self->selection = base;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)self->window, 0x14)) != 0;
    if (confirm) {
        if (Window_IsSelectionTouched((struct Obj_0205da38*)self->window, 0x14)) {
            int value = GetClampedArrayField0xd1c_ov000_021761c8((char*)data_ov000_02184294.menu, base);
            int matches = CountMatchingValues02175348(data_ov000_02184294.menu, value);
            self->selection = NextRandomMax(GetBTRandom(), matches * 100) / 100 + (signed char)base;
        }
        SePlayer_Play(&g_sePlayer, 1, 0);
        self->stackTop++;
        self->stack[self->stackTop] = 100;
        func_ov000_02170db0(self);
    } else if (CheckFlagsOrField_0217ab48_0217ab48(self)) {
        func_ov000_0217629c(self);
        self->stack[self->stackTop] = 0;
        self->stackTop--;
        self->selection = -1;
        func_ov000_0217ab8c(self, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.menu, self, self->stack[self->stackTop],
                            data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
