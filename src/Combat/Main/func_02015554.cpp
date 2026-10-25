#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Graphics/Animation3D.h"
#include "Graphics/Vector.h"
#include "World/ZoneResourceTree.h"

struct SePlayer;
void SePlayer_Play(SePlayer *, int, int);
int IsAnimationActive0209ca2c(void *);

extern SePlayer g_sePlayer;
extern char g_bgmPlayer[];
extern char data_020ef1f3[];
extern char data_020ef1f8[];
extern char data_020ef1fe[];
extern char data_020ef204[];

// USA: func_02015554
extern "C" ARM void func_02015554(void *arg0, void *arg1) {
    Struct_02015554 *var0 = static_cast<Struct_02015554 *>(arg1);
    GameState *var1               = GameState::GetInstance();
    Struct_02012ff0 *var2     = var0->unknown_24_;
    if (!var2 || !var2->unknown_4_) return;
    fix32_t var3 = var1->GetAnimationDeltaTime();
    if (var2->unknown_0_ == 0) {
        if (var2->unknown_8_) var2->unknown_8_->AdvanceTimer(var3);
        if (var2->unknown_c_) var2->unknown_c_->AdvanceTimer(var3);
        if (var2->unknown_10_) var2->unknown_10_->AdvanceTimer(var3);
        if (var2->unknown_14_) var2->unknown_14_->AdvanceTimer(var3);

        short var4 = var0->unknown_38_;
        if (var4 != fix32ReduceAngle0To2Pi(var0->unknown_34_)) {
            fix32_t var5 = fix32SignedAngleDistance(var4, var0->unknown_34_);
            fix32_t var6     = ((long long) var0->unknown_36_ * var3 + 0x800) >> 12;
            if (var5 > 0) {
                if (var5 < var6)
                    var0->unknown_38_ = var0->unknown_34_;
                else
                    var0->unknown_38_ += var6;
            } else if (var5 < 0) {
                if (-var5 < var6)
                    var0->unknown_38_ = var0->unknown_34_;
                else
                    var0->unknown_38_ -= var6;
            }
            var0->unknown_38_ = fix32ReduceAngle0To2Pi(var0->unknown_38_);
        } else if (var0->unknown_36_ != 0) {
            if (var0->unknown_2_ & 0x10) {
                var0->unknown_36_ = 0;
            } else if (var0->unknown_2_ & 0x80) {
                var0->unknown_2_ &= ~0x80;
                var0->unknown_36_ = 0;
            } else if (var0->unknown_4_0_ > 0) {
                int var7 = var0->unknown_4_0_ - 3;
                if (var7 < 0) {
                    var7            = 0;
                    var0->unknown_36_ = 0;
                }
                var0->unknown_4_0_ = var7;
                if (var0->unknown_4_0_ == 0) var0->unknown_2_ |= 4;
            }
        }
        if (var0->unknown1_3a_ != 0) {
            if (Vector3fix_Distance(&var0->unknown_8_, &var0->unknown_3c_) < var0->unknown1_3a_) {
                var0->unknown_8_      = var0->unknown_3c_;
                var0->unknown1_3a_ = 0;
            } else {
                Vector3fix var8 = var0->unknown_48_;
                Vector3fixMultiplyScalar(&var8, var0->unknown1_3a_, &var8);
                Vector3fix_Add(&var0->unknown_8_, &var8, &var0->unknown_8_);
            }
        }
    }
    if ((entry->flags & 0x100) && entry->object) {
        if (entry->animationState == 0) {
            entry->object->SetAnimationPlaybackSpeed(0x1800, 0);
            if (entry->object->SetAnimationByName(data_020ef1f3, 1))
                SePlayer_Play(&g_sePlayer, 0x12, 0);
            else if (entry->object->SetAnimationByName(data_020ef1f8, 1))
                SePlayer_Play(&g_sePlayer, 0x62, 0);
            entry->animationState = 1;
        } else if (entry->animationState == 1) {
            if (entry->object->HasAnimationStopped()) {
                entry->delay          = 500;
                entry->animationState = 2;
            }
        } else if (entry->animationState == 2) {
            unsigned int deltaTime = state->GetEffectiveDeltaTime();
            if (deltaTime < entry->delay) {
                entry->delay -= deltaTime;
            } else if (!IsAnimationActive0209ca2c(g_bgmPlayer)) {
                if (entry->object->SetAnimationByName(data_020ef1fe, 5))
                    SePlayer_Play(&g_sePlayer, 0x13, 0);
                else if (entry->object->SetAnimationByName(data_020ef204, 5))
                    SePlayer_Play(&g_sePlayer, 0x62, 0);
                entry->flags &= ~0x100;
            }
        }
    }
}
