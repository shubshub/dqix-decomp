#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021f8bd8 {
    int field_0x0;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 10;
    unsigned int unknown_6_6_ : 10;
    char unknown_8_[8];
    unsigned int flags;
    unsigned int unknown_14_0_ : 7;
    unsigned int unknown_14_7_ : 7;
    unsigned int unknown_15_6_ : 7;
    unsigned int unknown_16_5_ : 11;
    unsigned int unknown_18_0_ : 16;
    unsigned int kind : 2;
    unsigned int unknown_1a_2_ : 14;
};

// USA: func_ov024_021f8bd8
extern "C" ARM void func_ov024_021f8bd8(void* unused, float* out, GameObject* obj, Struct_ov024_021f8bd8* entry) {
    unsigned short var0 = obj->currentStats_->primaryStats.magicalMight;
    unsigned short var1 = obj->currentStats_->primaryStats.magicalMending;
    float result = 100.0f;
    if (entry->kind == 1) {
        if (entry->flags & 0x4000) {
            if (var0 <= entry->unknown_5_4_) {
                result = entry->unknown_14_7_;
            } else if (var0 >= entry->unknown_6_6_) {
                result = entry->unknown_15_6_;
            } else {
                result = (unsigned int)(int)((float)(var0 - entry->unknown_5_4_) * ((float)(entry->unknown_15_6_ - entry->unknown_14_7_) / (float)(entry->unknown_6_6_ - entry->unknown_5_4_))) + entry->unknown_14_7_;
            }
        } else if (entry->flags & 0x8000) {
            if (var1 <= entry->unknown_5_4_) {
                result = entry->unknown_14_7_;
            } else if (var1 >= entry->unknown_6_6_) {
                result = entry->unknown_15_6_;
            } else {
                result = (unsigned int)(int)((float)(var1 - entry->unknown_5_4_) * ((float)(entry->unknown_15_6_ - entry->unknown_14_7_) / (float)(entry->unknown_6_6_ - entry->unknown_5_4_))) + entry->unknown_14_7_;
            }
        }
    }
    *out = result;
}
