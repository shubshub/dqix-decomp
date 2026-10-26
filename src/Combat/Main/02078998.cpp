#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_0202c1a4;
extern "C" int rand();
extern "C" void* __clear(void*, int);
struct Actor02076ccc;
extern "C" void* LinkSession_GetInstance();
int LinkSession_IsActive(int*);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
int GetFieldAt0x150_02053c6c(unsigned char*);
bool TrySetMode02076ccc(void*, int);
struct Vec3i021c95ec { int x, y, z; };
extern "C" void func_ov017_021c95ec(int, int, int, int, int, Vec3i021c95ec, int, unsigned char, unsigned char);

struct Struct_02078998 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
    unsigned short unknown_c_;
};
struct Struct_02078998_2 {
    Object3D unknown_0_;
    char unknown_ac_[0x13b - 0xac];
    unsigned char unknown_13b_;
    unsigned char unknown_13c_;
    char unknown_13d_[3];
    int unknown_140_;
    char unknown_144_[8];
    unsigned int unknown_14c_;
    char unknown_150_[0x166 - 0x150];
    unsigned short unknown_166_;
    char unknown_168_[8];
    int unknown_170_;
    short unknown_174_;
    char unknown_176_[4];
    unsigned char unknown_17a_;
    char unknown_17b_[0x184 - 0x17b];
    Struct_02078998* unknown_184_;
};
static inline void inline_02078998(int arg0, int arg1, int arg2, int arg3, Struct_02078998_2* arg4) {
    Struct_ov017_021c95ec var0;
    __clear(&var0, sizeof(var0));
    func_ov017_021c95ec(arg0, arg1, arg2, arg3, arg4->unknown_166_, var0, 0, 0, 0);
}

// USA: func_02078998
extern "C" ARM void func_02078998(Struct_02078998_2* arg0) {
    if (arg0->unknown_14c_ <= 225) {
        Vector3fix var0 = arg0->unknown_0_.position_;
        int var1 = arg0->unknown_0_.GetScale().y * 15;
        int var2 = (int)(1.15f * (float)arg0->unknown_0_.GetHeight());
        var2 = FIX32_MULTIPLY(var2, var1);
        var0.y = var2 + var0.y;
        arg0->unknown_174_ += (112 - arg0->unknown_14c_ * 2) * 3;
        if (arg0->unknown_174_ < 0) arg0->unknown_174_ = 0;
        var0.y += arg0->unknown_174_;
        arg0->unknown_170_ = var0.y;
        arg0->unknown_17a_ = 1;
    }
    if (self->counter <= 225) return;
    self->rising = 0;
    int* search = (int*)LinkSession_GetInstance();
    if (LinkSession_IsActive(search) && LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) return;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), self->combatantId);
    if (combatant == NULL) return;
    GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    int extraAttack = 0;
    int extraDefense = 0;
    int attack = combatant->baseStats_->primaryStats.attack;
    int defense = combatant->baseStats_->primaryStats.defense;
    if (self->attributes != NULL) {
        extraAttack = self->attributes->attack;
        extraDefense = self->attributes->defense;
    }
    int var9;
    if ((var7 + var8 > (var5 + var6) * 3 || arg0->unknown_140_ == -99) && arg0->unknown_140_ != 99) {
        switch (arg0->unknown_13b_) {
        case 0:
            func_02076ccc((Struct_02076ccc*)arg0, 12);
            var9 = 12;
            break;
        case 1:
            func_02076ccc((Struct_02076ccc*)arg0, 6);
            var9 = 6;
            break;
        case 2:
            func_02076ccc((Struct_02076ccc*)arg0, 7);
            var9 = 7;
            break;
        case 3:
            if (rand() % 2) {
                func_02076ccc((Struct_02076ccc*)arg0, 7);
                var9 = 7;
            } else {
                func_02076ccc((Struct_02076ccc*)arg0, 6);
                var9 = 6;
            }
            break;
        }
    } else {
        switch (arg0->unknown_13c_) {
        case 0:
            func_02076ccc((Struct_02076ccc*)arg0, 5);
            var9 = 5;
            break;
        case 1:
            func_02076ccc((Struct_02076ccc*)arg0, 4);
            var9 = 4;
            break;
        case 2:
            if (rand() % 2) {
                func_02076ccc((Struct_02076ccc*)arg0, 7);
                var9 = 7;
            } else {
                func_02076ccc((Struct_02076ccc*)arg0, 6);
                var9 = 6;
            }
            break;
        }
    }
    if (!LinkSession_IsActive(search) || LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) return;
    unsigned short id = self->obj.GetField06();
    int unused = self->obj.unknown_2_;
    int nibble = (self->obj.actorIndex_ - 112) % 12;
    if (nibble >= 0 && nibble < 12) {
        SendModeEvent02078998(id, nibble, unused, mode, self);
    }
}
