#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020341e0 func_02034104
#endif

struct Struct_02077788 {
    Object3D unknown_0_;
    char unknown_ac_[2];
    short unknown_ae_;
    char unknown_b0_[0xb2 - 0xb0];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x154 - 0xb6];
    int unknown_154_;
    char unknown_158_[0x166 - 0x158];
    unsigned short unknown_166_;
    char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
};

extern "C" void* func_0202ae18(void);
extern "C" Vector3fix func_020341e0(void* obj);
extern "C" int func_020322c0(int a, int* b, int c);
extern "C" void func_020794f8(void* obj, int a, int b);
int CheckField0NonZero_0202b7d8(int* obj);
struct SearchStruct0202c1a4;
struct BitFlag02033f44;
struct Obj02033834;
struct Obj02033b68;
struct Outer02077a20;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int GetField0xe4IfFlag0x40(struct BitFlag02033f44* obj);
void GameObject_SetFacing(struct Obj02033834* obj, int angle);
void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
void TrySetMode02076ccc(void* obj, int mode);
int GetField0x8OrDefault02077a20(struct Outer02077a20* obj);
int GetIntField0x264_02039760(void* obj);

// USA: func_02077788
extern "C" ARM void func_02077788(struct Struct_02077788* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0202ae18();
    GameObject* var2 = var0->GetPartyMemberByIndex(arg0->unknown_166_);
    if (var2 == 0) {
        return;
    }

    Vector3fix pos = func_020341e0(combatant);
    Vector3fix delta;
    Vector3fix_Subtract(&pos, &self->object.position_, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    int var6 = func_02033f44((struct Struct_02033f44*)arg0);
    int var7 = 0;
    if (var6 != 0) {
        int var8 = arg0->unknown_ae_;
        if (func_020322c0(var6, &var8, var8) < 0x199) {
            var7 = 1;
        }
    }
    if (var7) {
        func_02076ccc(arg0, 1);
        arg0->unknown_154_ = 0;
        if (func_0202b7d8((int*)var1)) {
            func_020794f8(arg0, 0, 0);
        }
        return;
    }

    unsigned short var9 = arg0->unknown_166_;
    if (var2->obj3D_.unknown_0_ & 0x1000) {
        var9 = 0;
    }
    if (!func_0202b7d8((int*)var1) || var9 == func_0202c1a4((struct Struct_0202c1a4*)var1)) {
        Vector3fix var10 = func_020341e0(var2);
        int var11 = var2->obj3D_.GetRadius();
        int var12 = arg0->unknown_0_.GetScale().x * 15;
        int var13 = func_02077a20((struct Struct_02077788_2*)arg0) >> 1;
        long long var14 = (long long)var13 * var12;
        int var15 = (var11 >> 1) + (int)((var14 + 0x800) >> 12);
        int var16 = Vector3fix_Distance(&var10, &arg0->unknown_0_.position_);
        if ((var16 != 0 && var15 > var16) || var16 > 0x7800) {
            func_02076ccc(arg0, 1);
            arg0->unknown_154_ = 0;
            arg0->unknown_17b_ = 1;
            if (func_0202b7d8((int*)var1)) {
                func_020794f8(arg0, 1, 0);
            }
            return;
        }
    }

    if (func_0202b7d8((int*)var1) && func_0202c1a4((struct Struct_0202c1a4*)var1) != 0) {
        return;
    }
    if (static_cast<unsigned char>(var2->unk_ac[0xc0 - 0xac]) == 6 ||
        func_02039760(var0->GetProtagonist()) == 2) {
        func_02076ccc(arg0, 1);
        arg0->unknown_154_ = 0;
        if (func_0202b7d8((int*)var1) && func_0202c1a4((struct Struct_0202c1a4*)var1) == 0) {
            func_020794f8(arg0, 0, 0);
        }
    }
}
