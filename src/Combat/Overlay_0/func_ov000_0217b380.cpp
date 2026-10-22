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
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
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
extern "C" ARM int func_ov000_0217b380(struct Struct_ov000_0217b380* arg0, int arg1, int arg2) {
    data_ov000_02184294.unknown_8_->unknown_1d72_ |= 0x100;
    int var0 = func_0205d794(arg0->unknown_38_);
    arg0->unknown_1d_ = var0;
    int var1 = g_keyManager.TestKeysPressed(0x601);
    int var2 = (var1 | func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) != 0;
    if (var2) {
        if (func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) {
            int var3 = func_ov000_021761c8((char*)data_ov000_02184294.unknown_8_, var0);
            int var4 = func_ov000_02175348(data_ov000_02184294.unknown_8_, var3);
            arg0->unknown_1d_ = NextRandomMax(GetBTRandom(), var4 * 100) / 100 + (signed char)var0;
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
