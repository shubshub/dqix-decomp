#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021e67c8_3 {
    char unknown_0_[0x21];
    unsigned char unknown_21_;
    char unknown_22_[0x40 - 0x22];
    unsigned char unknown_40_;
};

struct Struct_ov024_021e67c8 {
    char unknown_0_[0x138];
    struct Struct_ov024_021e67c8_3* unknown_138_;
};

struct Struct_ov024_021e67c8_2 {
    char unknown_0_[0x10];
    void* unknown_10_;
};

extern "C" signed char func_ov000_02159e60(void* arg0, int arg1);
struct Struct_ov024_021e67c8* GetCombatantByID(int, int);
extern "C" float func_02074938(int arg0);
struct GameObject;
int IsCombatantFlag2Mask32_021e67b0(GameObject*);
void* GameState_GetParty(void* gs);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
extern "C" int func_ov000_02156068(void* battle, int id, int kind, int mode);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);

// USA: func_ov024_021e67c8
extern "C" ARM int func_ov024_021e67c8(struct Struct_ov024_021e67c8_2* arg0, int arg1, int arg2) {
    void* var0 = arg0->unknown_10_;
    int var1 = func_ov000_02159e60(var0, arg1);
    float var2 = (var1 + 5) * NextRandomFloatBetween((struct Random*)var0, 0.8f, 1.0f);
    if (var2 > 100.0f) {
        var2 = 100.0f;
    }
    struct Struct_ov024_021e67c8* var3 = GetCombatantByID((int)arg0->unknown_10_, arg2);
    if (var3) {
        var2 = var2 * (var3->unknown_138_->unknown_40_ / 100.0f);
    }
    if (var3) {
        if (var3->unknown_138_->unknown_21_ <= 3) {
            var2 = var2 * func_02074938((signed char)var3->unknown_138_->unknown_21_);
        }
        if (func_ov024_021e67b0((GameObject*)var3)) {
            var2 = var2 * func_02074938(1);
        }
        if (ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)(GameState_GetParty(GameState::GetInstance())), targetId) &&
            target && target->stats->rank21 == 1) {
            IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)ctx->battle, 0);
        }
    }
    if (func_ov000_02156068(arg0->unknown_10_, arg2, 0, 1)) {
        var2 = NextRandomMax((struct Random*)arg0->unknown_10_, 2);
    }
    if (func_ov024_021dd260((Struct_ov024_021dd028_5*)var3)) {
        var2 = 0.5f * var2;
    }
    return var2;
}
