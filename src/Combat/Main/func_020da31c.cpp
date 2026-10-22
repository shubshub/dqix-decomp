#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_020da31c_3 {
    unsigned char unknown_0_[8];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_, unknown_e_, unknown_f_, unknown_10_, unknown_11_;
};
struct Struct_02078398_2 {
    char unknown_0_[16];
    unsigned char unknown_10_, unknown_11_;
    short unknown_12_, unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_;
    short unknown_1e_;
    int unknown_20_, unknown_24_, unknown_28_;
    Vector3i unknown_2c_, unknown_38_, unknown_44_;
};
struct Struct_020da31c {
    Object3D unknown_0_;
    short unknown_ac_, unknown_ae_, unknown_b0_, unknown_b2_;
};
struct Struct_020da31c_2 {
    unsigned char unknown_0_[0xe8];
    Matrix4x3 unknown_e8_;
};
struct Struct_0205a180 {
    unsigned int unknown_0_;
    Struct_020da31c_2* unknown_4_;
};
extern "C" void* func_02057924();
void InitStruct02078484(InitStruct02078484Struct*);
void FindNodeAndProcess02057fb4(void*, int, void*);
void* GetInlineRecordByBattleId_02058658(void*, int);
void StoreZeroAndField0xb6ToOut(State0205a180*);
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);
extern char data_020f2884[], data_020f2887[], g_sePlayer[];

// USA: func_020da31c
extern "C" ARM void func_020da31c(Struct_020da31c_3* arg0) {
    void* var0 = func_02057924();
    GameState* var1 = GameState::GetInstance();
    if (!var0 || !var1) return;
    switch (arg0->unknown_e_) {
    case 1: {
        GameObject* var2 = var1->GetMaybeWanderingMonsterByIndex(arg0->unknown_8_);
        if (!var2) return;
        if (!(arg0->unknown_d_ & 8)) {
            Struct_02078398_2 var3;
            arg0->unknown_d_ |= 8;
            func_02078484(&var3);
            int var4 = arg0->unknown_8_;
            var3.unknown_14_ = var4;
            var3.unknown_10_ = 0;
            sprintf(var3.unknown_0_, data_020f2884, data_020f2887);
            var3.unknown_2c_.x = 0;
            var3.unknown_2c_.y = 0;
            var3.unknown_2c_.z = 0;
            var3.unknown_44_.x = 0x1000;
            var3.unknown_44_.y = 0x1000;
            var3.unknown_44_.z = 0x1000;
            func_02057fb4(var0, 0x14, &var3);
        }
        int var5 = ((Struct_020da31c*)var2)->unknown_b2_;
        int var6 = fix32SignedAngleDistance(var2->obj3D_.rotation_.y, ((Struct_020da31c*)var2)->unknown_ae_);
        if (var5 > 0x3d || var6 != 0) ++arg0->unknown_f_;
        if (arg0->unknown_f_ < 3) return;
        arg0->unknown_f_ = 0;
        Struct_02078398_2 var7;
        func_02078484(&var7);
        var7.unknown_2c_ = var2->obj3D_.position_;
        var7.unknown_38_ = var2->obj3D_.rotation_;
        var7.unknown_44_.x = 200;
        var7.unknown_44_.y = 200;
        var7.unknown_44_.z = 200;
        sprintf(var7.unknown_0_, data_020f2884, data_020f2887);
        var7.unknown_11_ |= 0x40;
        func_02057fb4(var0, 0x15, &var7);
        break;
    }
    case 2: {
        GameObject* var8 = var1->GetGameObjectByIndex(arg0->unknown_8_);
        if (!var8) return;
        if (!(arg0->unknown_d_ & 8)) {
            Struct_02078398_2 var9;
            arg0->unknown_d_ |= 8;
            func_02078484(&var9);
            int var10 = arg0->unknown_8_;
            var9.unknown_14_ = var10;
            var9.unknown_10_ = 0;
            sprintf(var9.unknown_0_, data_020f2884, data_020f2887);
            var9.unknown_2c_.x = 0;
            var9.unknown_2c_.y = 0;
            var9.unknown_2c_.z = 0;
            var9.unknown_44_.x = 0x3000;
            var9.unknown_44_.y = 0x1000;
            var9.unknown_44_.z = 0x3000;
            func_02057fb4(var0, 0x14, &var9);
        }
        if (++arg0->unknown_f_ < 7) return;
        arg0->unknown_f_ = 0;
        Struct_02078398_2 var11;
        func_02078484(&var11);
        var11.unknown_2c_ = var8->obj3D_.position_;
        var11.unknown_38_ = var8->obj3D_.rotation_;
        var11.unknown_44_.x = 225;
        var11.unknown_44_.y = 225;
        var11.unknown_44_.z = 225;
        sprintf(var11.unknown_0_, data_020f2884, data_020f2887);
        func_02057fb4(var0, 0x15, &var11);
        break;
    }
    case 3: {
        GameObject* var12 = var1->GetMaybeWanderingMonsterByIndex(arg0->unknown_8_);
        if (!var12) return;
        Struct_02078398_2 var13;
        Struct_0205a180* var14 = (Struct_0205a180*)func_02058658(var0, 0xd0);
        if (var14 && var14->unknown_4_) {
            Struct_020da31c_2* var15 = var14->unknown_4_;
            Matrix4x3 var16, var17, var18, var19;
            Mat4x3_WriteIdentity(&var16);
            Mat4x3_WriteIdentity(&var17);
            Mat4x3_ApplyTranslation(&var17, &var17, var12->obj3D_.position_.x,
                var12->obj3D_.position_.y, var12->obj3D_.position_.z);
            Mat4x3_WriteIdentity(&var18);
            Mat4x3_ApplyTranslation(&var18, &var18, 0, 0x3000, 0x800);
            var19 = RotationMatrixY(((Struct_020da31c*)var12)->unknown_ae_);
            Mat4x3_Multiply(&var18, &var19, &var16);
            Mat4x3_Multiply(&var16, &var17, &var16);
            var15->unknown_e8_ = var16;
        }
        if (!(arg0->unknown_d_ & 0x10)) {
            arg0->unknown_f_ = 0;
            arg0->unknown_10_ = 0;
            return;
        }
        ++event->ticks;
        if (event->activations < 1 && (event->flags & 0x10)) {
            if (!event->started) {
                InitStruct02078484(&effect);
                effect.position = actor->obj3D_.position_;
                effect.rotation = actor->obj3D_.rotation_;
                effect.lifetime = 90;
                effect.scale.x = 0x199;
                effect.scale.y = 0x199;
                effect.scale.z = 0x199;
                sprintf(effect.filename, data_020f2884, data_020f2887);
                effect.flags |= 0xb8;
                FindNodeAndProcess02057fb4(manager, 0x16, &effect);
                event->started = 1;
                DispatchIfField0xc4NonNeg_0205ebfc(g_sePlayer, 1, 0);
            } else {
                State0205a180* active = (State0205a180*)GetInlineRecordByBattleId_02058658(manager, 0xd0);
                if (active) {
                    StoreZeroAndField0xb6ToOut(active);
                    DispatchIfField0xc4NonNeg_0205ebfc(g_sePlayer, 1, 0);
                }
            }
            ++arg0->unknown_10_;
        } else if (arg0->unknown_f_ >= 85) {
            arg0->unknown_d_ &= ~0x10;
        }
        break;
    }
    }
}
