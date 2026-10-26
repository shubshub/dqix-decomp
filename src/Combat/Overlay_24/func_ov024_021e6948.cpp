#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021e6948_3 {
    char pad0[0x21];
    unsigned char unknown_21_;
};

struct Struct_ov024_021e6948 {
    char pad0[0x138];
    struct Struct_ov024_021e6948_3* stats;
};

struct Struct_02000c9c_76;

struct Struct_ov024_021e6948_2 {
    char pad0[0x10];
    struct Struct_02000c9c_76* battle;
};

struct Struct_ov024_021e6948* GetCombatantByID(int, int);
extern "C" float func_02074938(int v);
struct GameObject;
extern "C" int func_ov024_021e67b0(GameObject*);
struct GameState;
extern "C" void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" int func_ov000_02156068(struct Struct_02000c9c_76* battle, int id, int kind, int mode);
struct Random;
int NextRandomMax(Random*, int);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);

// USA: func_ov024_021e6948
extern "C" ARM int func_ov024_021e6948(struct Struct_ov024_021e6948_2* ctx, int targetId, int a, int b) {
    float var0 = (float)a * (float)b / 8.0f;
    struct Struct_ov024_021e6948* target = GetCombatantByID((int)ctx->battle, targetId);
    if (target) {
        if (target->stats->unknown_21_ <= 3) {
            var0 = var0 * func_02074938((signed char)target->stats->unknown_21_);
        }
        if (func_ov024_021e67b0((GameObject*)target)) {
            var0 = var0 * func_02074938(1);
        }
        if (func_02086ef0((ArrayContainsByteStruct*)(GameState_GetParty((GameState*)GameState::GetInstance())), targetId) &&
            target && target->stats->unknown_21_ == 1) {
            func_ov000_0215a8d4((unsigned char*)ctx->battle, 0);
        }
    }
    if (var0 > 0 && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        var0 = NextRandomMax((Random*)ctx->battle, 2);
    }
    if (func_ov024_021dd260((Struct_ov024_021dd028_5*)target)) {
        var0 = 0.5f * var0;
    }
    return var0;
}
