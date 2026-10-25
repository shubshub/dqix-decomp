#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "Combat/MapDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_02020fc4_3;
struct Struct_02024518_3;
struct Struct_02024518_2;
struct Struct_0202441c;
struct Struct_02024d48;
struct Struct_02024518 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};
void* GetData02105254_0203b628();
extern "C" void* Zone3D_GetInstance();
void SetArraySlotFlag0203b718(void*, int, int, int);
Entry_02027878* GetEntryFromList(List_02027878*, int);
void ForwardParamsToB8bc_0203bcb8(Bcb8Params*, int, int);
void AccumulateBattleTimer0202441c(BattleTimer0202441c*);
int CheckCombatantReadyForAction020243b8(void*, int);
int CheckActionAllowed(CombatActionPosition*, int);
void SetElementFields0202756c(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);

// USA: func_02025b0c
extern "C" ARM void func_02025b0c(MapDisplay* self) {
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    void* displayState = GetData02105254_0203b628();
    Zone3D_GetInstance();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count = func_020236dc(entries, groups, &position);
    int screenX;
    int cameraY;
    fix32_t scale;
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    int objectY = (int)((float)FIX32_MULTIPLY(position.y, scale) / 4096.0f);
    if (cameraY - objectY > 5 || objectY - cameraY > 5) {
        if (objectY < cameraY) {
            self->cameraZ -= fix32_Divide((cameraY - objectY - 5) << 12, scale);
        } else {
            arg0->unknown_5b0_ += fix32_Divide((var9 - var7 - 5) << 12, var8);
        }
    }
    var7 = (int)((float)FIX32_MULTIPLY(arg0->unknown_5b0_, arg0->unknown_38_) / 4096.0f);
    arg0->unknown_44_ = var6;
    arg0->unknown_48_ = var7;
    int var10 = var7 < 0 ? var7 / 8 - 1 : var7 / 8;
    arg0->unknown_55c_ = 0;
    func_0203b718(var1, 1, 0, arg0->unknown_74_);
    for (int var11 = 0; var11 < arg0->unknown_30_; ++var11) {
        Struct_02024518_3* var12 = func_02027878((Struct_02024518_2*)arg0, arg0->unknown_2c_[var11].unknown_4_);
        if (var12) {
            int var13 = arg0->unknown_1c_ + arg0->unknown_2c_[var11].unknown_c_;
            int var14 = arg0->unknown_18_ + arg0->unknown_2c_[var11].unknown_8_;
            func_0203bcb8(reinterpret_cast<Struct_02020fc4_3*>(reinterpret_cast<unsigned char*>(var12) + 8), var14 + 16, var10 + var13 + 16);
        }
    }
    func_0202441c((Struct_0202441c*)arg0);
    for (int var15 = 0; var15 < var5; ++var15) {
        Struct_020236dc* var16 = &var3[var15];
        if (!func_020243b8(arg0, var16->unknown_14_)) {
            continue;
        }
        fix32_t var17 = arg0->unknown_38_;
        int var18 = (int)((float)FIX32_MULTIPLY(var16->unknown_0_.x, var17) / 4096.0f);
        int var19 = -((int)((float)FIX32_MULTIPLY(var16->unknown_0_.y, var17) / 4096.0f) - arg0->unknown_48_);
        if (var16->unknown_f_ >= 0) {
            int var20 = var4[var16->unknown_10_] - 1;
            var18 += data_020e70f0[var20][var16->unknown_f_][0];
            var19 -= data_020e70f4[var20][var16->unknown_f_][0];
        }
        if (arg0->unknown_5a4_ & 1) {
            if (inline_02024518(var16->unknown_e_)) {
                continue;
            }
        }
        if (!func_02024d48(var16, arg0->unknown_9c0_)) {
            continue;
        }
        func_0202756c(arg0, (var18 + 0x7c) << 12, (var19 + 0x5c) << 12,
            var16->unknown_c_, var16->unknown_e_, 0, var16->unknown_d_, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(arg0, 0, arg0->unknown_48_, 0x7c, 0x5c, 1);
    func_02023d84(arg0, var3, var5, 0, arg0->unknown_48_, 0x7c, 0x5c, 1);
}
