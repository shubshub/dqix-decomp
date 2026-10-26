#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include <GameState/GameState.h>

struct Struct_02079ee0 {
    unsigned int key_ : 8;
    unsigned int unknown_1_0_ : 10;
    unsigned int unused0 : 14;
    unsigned int unused4 : 10;
    unsigned int unknown_5_2_ : 10;
    unsigned int unknown_6_4_ : 10;
    unsigned int unknown_7_6_ : 2;
};
struct Struct_ov024_021f8938 {
    unsigned int field0;
    unsigned int unused4 : 12;
    unsigned int unknown_5_4_ : 10;
    unsigned int unknown_6_6_ : 10;
    unsigned int unknown_8_0_ : 14;
    unsigned int key_ : 8;
    unsigned int unknown_a_6_ : 10;
    unsigned int fieldC;
    unsigned int flags_;
    unsigned int field14;
    unsigned int unknown_18_0_ : 16;
    unsigned int mode_ : 2;
    unsigned int unknown_1a_2_ : 14;
};
extern "C" Struct_02079ee0* func_02079ee0(void*, int);

// USA: func_ov024_021f8938
extern "C" ARM void func_ov024_021f8938(void* unused, float* value, float* arg2, int arg3, Struct_ov024_021f8938* action, GameObject* actor) {
    ActionDataTables* data = func_020797dc();
    *value = 0;
    *arg2 = 0;
    Struct_02079ee0* element = func_02079ee0(data, action->key_);
    if (element) {
        if (action->mode_ == 2) {
            int lower = action->unknown_5_4_;
            int upper = action->unknown_6_6_;
            float minimum;
            float maximum;
            int scale = 0;
            minimum = (float)element->unknown_5_2_;
            maximum = (float)element->unknown_6_4_;
            float var7;
            if (action->flags_ & 0x4000) {
                var7 = (float)(unsigned short)actor->currentStats_->primaryStats.magicalMight;
                scale = 1;
            } else if (action->flags_ & 0x8000) {
                var7 = (float)(unsigned short)actor->currentStats_->primaryStats.magicalMending;
                scale = 1;
            } else var7 = 0.5f * (minimum + maximum);
            if (scale) {
                if (var7 <= lower) *value = minimum;
                else if (var7 >= upper) *value = maximum;
                else {
                    *value = (var7 - lower) * ((maximum - minimum) / (upper - lower));
                    *value += minimum;
                }
                *arg2 = *value - (float)element->unknown_1_0_;
            } else {
                *value = 0.5f * (maximum + minimum);
                *arg2 = minimum;
            }
        } else {
            *value = 0.5f * (element->unknown_5_2_ + element->unknown_6_4_);
            *arg2 = (float)element->unknown_5_2_;
        }
    } else {
        *value = 0;
        *arg2 = 0;
    }
    if (*value < 0) *value = 0;
    else if (*value >= 32767.0f) *value = 32767.0f;
    if (*arg2 < 0) *arg2 = 0;
    else if (*arg2 >= 32767.0f) *arg2 = 32767.0f;
}
