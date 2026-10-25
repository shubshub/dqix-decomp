#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/ActorAction.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "World/ZoneObjectResourceLoading.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define data_020efb44 data_020efa34
#define data_020efb4e data_020efa3e
#define data_020efb5a data_020efa4a
#endif

static inline fix32_t inline_02038598(fix32_t arg0, fix32_t arg1) {
    return ((long long)arg0 * arg1 + 0x800LL) >> 12;
}

struct Struct_02038598_6 {
    GameObject unknown_0_;
#if defined(jpn)
    char unknown_13c_[0x1be - 0x13c];
#else
    char unknown1_13c_[0x1ca - 0x13c];
#endif
    signed char unknown_1ca_;
    char unknown_1cb_[0x252 - 0x1cb];
    unsigned char unknown_252_;
    unsigned char unknown_253_;
    char unknown_254_[0x26c - 0x254];
    Struct_02037d10 unknown_26c_;
};
struct Struct_02038598_7 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    char unknown_a_[0xe0 - 0xb6];
    Struct_02038598 unknown_34_;
};
struct Struct_02038598_2 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    Vector3fix unknown_10_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_[4];
    Vector3fix unknown_30_;
    Vector3fix unknown_3c_;
    Vector3fix unknown_48_;
    Vector3fix unknown_54_;
    char unknown_60_[0xa];
    short unknown_6a_;
    short unknown_6c_;
    char unknown_6e_[2];
};
struct Struct_02038598_3 {
    char unknown_0_[0x220];
    unsigned char unknown_220_;
    unsigned char unknown_221_;
    unsigned char unknown_222_;
    unsigned char unknown_223_;
};
struct Vec3038500;
struct Obj02033834;
struct Obj02033874;
struct Obj020397cc;
struct Bytes02033b88;
struct Foo02033b58;
struct ShortField02033ec8;
struct FlagWord020466f4 { unsigned int flags; };
struct ListHead02046b60;
struct TailList020469b4;
struct TailNode020469b4;
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_ov017_02191108(void*, int, int, int, int);
void* GlobalFlags_GetInstance();
void GameObject_SetFacing(Obj02033834*, int);
void SetVecYFromValue02033874(Obj02033874*, int);
void GameObject_DisableControl(Obj020397cc*, int);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
int CheckField0xc6Zero(ShortField02033ec8*);
void SetVec3038500_02038500(Vec3038500*, int, int, int);
void SetHalf0xc6AndCopyVec3_02033e18(void*, int*, short);
int GetField4328_0218d268(void*);
int GameState_GetProtagonistIndex(GameState*);
int ListContainsId(ListHead02046b60*, int);
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
void FlagWord_SetBits(unsigned int*, unsigned int);
void InitAndResetHeader_0219e310(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
extern const char data_020efb44[];
extern const char data_020efb4e[];
extern const char data_020efb5a[];

// USA: func_02038598
extern "C" ARM void func_02038598(ActorMotion02038598* self) {
    GameResources* resources;
    Zone3D* zone;
    ActorFields02038598* fields;
    struct SubBlock02038508* action;
    unsigned int* inputFlags;
    unsigned char side;
    ListHead02046b60* list;
    resources = GetGameResources();
    list = (ListHead02046b60*)resources->fieldTaskQueue_;
    zone = Zone3D_GetInstance();
    fields = (ActorFields02038598*)self->resources.unk_ac;
    action = &self->action;
    inputFlags = (unsigned int*)GlobalFlags_GetInstance();

    if (self->resources.obj3D_.actorIndex_ != self->actorId) return;
    if (action->active == 0) return;

    unsigned char var7 = var3->unknown_1_;

    if (state == 0) {
        ZoneFeatures::Opcode6aEntry* post = (action->reversed == 0) ? action->startNode : action->endNode;
        Vector3fix direction;
        Vector3fix_Subtract(&post->unk_8.vec, &self->resources.obj3D_.position_, &direction);
        Vector3fix_Normalize(&direction, &direction);
        int angle = fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z));
        GameObject_SetFacing((struct Obj02033834*)self, angle);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        fields->flags.active = 1;
        self->resources.obj3D_.EnableFlag(0x180);
        SetByte0xbeShiftPrev((struct Bytes02033b88*)self, 0);
        action->unknown4c = action->startNode->unk_8.vec.y;
        action->unknown50 = zone->substruct_c_.unknown_30_;
        if (fix32abs(fields->heading) - angle >= 0x333) goto Exit;
        func_ov017_021d3f00(action, 0, 0);
        action->command = 1;
        action->unknown24.vec = self->resources.obj3D_.position_;
        if (action->reversed == 0) {
            self->resources.obj3D_.SetAnimationByName(data_020efb44, 1);
            goto Exit;
        }
        if (action->reversed != 1) goto Exit;
        self->resources.obj3D_.SetAnimationByName(data_020efb44, 1);
        goto Exit;
    }

    if (state == 1) {
        GameObject_SetFacing((struct Obj02033834*)self, action->heading);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        int animationProgress = self->resources.obj3D_.normalizedAnimationTime_;

        if (var3->unknown_3_ == 0) {
            if (!arg0->unknown_0_.obj3D_.HasAnimationStopped()) {
                arg0->unknown_0_.obj3D_.AdvanceAnimations();
            }
            if (!arg0->unknown_0_.obj3D_.HasAnimationStopped()) {
                arg0->unknown_0_.obj3D_.AdvanceAnimations();
            }
        }

        if (var3->unknown_3_ == 1) {
            int var12 = var1->substruct_c_.unknown_30_;
            int var13 = (int)(((float)var11 / 4096.0f) * (float)(unsigned int)var12);
            var3->unknown_50_ = var12 - (var13 << 2);
            if (var3->unknown_50_ < 0) var3->unknown_50_ = 0;
        }

        Vector3fix var14;
        Vector3fix var15;
        if (var3->unknown_3_ == 0) {
            func_02038500((Struct_02038500*)&var15, var3->unknown_c_.unknown_0_[0], var3->unknown_c_.unknown_0_[1] + 0x51, var3->unknown_c_.unknown_0_[2]);
        } else if (var3->unknown_3_ == 1) {
            func_02038500((Struct_02038500*)&var15, var3->unknown_18_.unknown_0_[0], var3->unknown_18_.unknown_0_[1] - 0xa3, var3->unknown_18_.unknown_0_[2]);
        }

        if (!arg0->unknown_0_.obj3D_.HasAnimationStopped()) {
            int var16 = var15.z - var3->unknown_24_.unknown_0_[2];
            int var17 = var15.y - var3->unknown_24_.unknown_0_[1];
            int var18 = var15.x - var3->unknown_24_.unknown_0_[0];
            int var19 = inline_02038598(var16, var11);
            int var20 = inline_02038598(var17, var11);
            int var21 = inline_02038598(var18, var11);
            func_02038500((Struct_02038500*)&var14, var3->unknown_24_.unknown_0_[0] + var21, var3->unknown_24_.unknown_0_[1] + var20, var3->unknown_24_.unknown_0_[2] + var19);
            arg0->unknown_0_.obj3D_.position_ = var14;
        }

        if (self->resources.obj3D_.HasAnimationStopped()) {
            SetVec3038500_02038500((Vec3038500*)&nextPosition, targetPosition.x, targetPosition.y, targetPosition.z);
            self->resources.obj3D_.position_ = nextPosition;
            action->command = 2;
            self->resources.obj3D_.SetAnimationByName(data_020efb4e, 0);
            goto Exit;
        }

        func_ov017_021d3f00(var3, 0, 0);
        goto Exit;
    }

    if (state == 2) {
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        SetVecYFromValue02033874((struct Obj02033874*)self, action->heading);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);

        Vector3fix var22 = arg0->unknown_0_.obj3D_.position_;
        Vector3fix var23, var24;

        GameResources* var25 = GetGameResources();
        Struct_02038598_3* var26 = (Struct_02038598_3*)func_ov017_0218d268(var25);

        var5 = 0;
        if (g_keyManager.IsDownHeld()) {
            var5 = 1;
        } else if (g_keyManager.IsUpHeld()) {
            var5 = 2;
        }

        if ((unsigned int)g_touchInput.timeHeld_ > 5) {
            fix32_t var27 = var26->unknown_222_ << 12;
            int var28 = var26->unknown_220_;
            int var29 = var26->unknown_221_;
            fix32_t var30 = var26->unknown_223_ << 12;
            var24.x = var27;
            var24.y = var30;
            var24.z = 0;
            var23.x = var28 << 12;
            var23.y = var29 << 12;
            var23.z = 0;
            Vector3fix_Subtract(&var24, &var23, &var24);
            if (Vector3fix_Length(&var24) >= 0x8000) {
                Vector3fix_Normalize(&var24, &var24);
                if (var24.x >= -1638 && var24.x <= 1638) {
                    if (var24.y >= 0)
                        var5 = 1;
                    else
                        var5 = 2;
                }
            }
        }

        int var31 = 0;
        if (func_02046b60(var6, 4) ||
            func_02046b60(var6, 0x26) ||
            func_02046b60(var6, 1) ||
            func_02046b60(var6, 3) ||
            func_02046b60(var6, 0x3e)) {
            var31 = 1;
            var5 = 0;
        }

        if (var3->unknown_53_ == 0) var5 = 0;

        if (var5 == 1) {
            var22.y -= 0xf5;
        } else if (var5 == 2) {
            var22.y += 0xf5;
        }

        int var32 = fix32_Divide(var22.y - var3->unknown_c_.unknown_0_[1], var3->unknown_18_.unknown_0_[1] - var3->unknown_c_.unknown_0_[1]);
        func_02038500((Struct_02038500*)&var22,
            var3->unknown_c_.unknown_0_[0] + inline_02038598(var3->unknown_18_.unknown_0_[0] - var3->unknown_c_.unknown_0_[0], var32), var22.y,
            var3->unknown_c_.unknown_0_[2] + inline_02038598(var3->unknown_18_.unknown_0_[2] - var3->unknown_c_.unknown_0_[2], var32));
        arg0->unknown_0_.obj3D_.position_ = var22;

        int var33 = arg0->unknown_0_.obj3D_.MaybeGetShadowSource().y - var3->unknown_4c_;
        int var34 = inline_02038598(var33, 0x14000);
        int var35 = (int)((float)var34 / 4096.0f);
        int var36 = var1->substruct_c_.unknown_30_;
        var3->unknown_50_ = var36 - var35;
        if (var3->unknown_50_ < 0) var3->unknown_50_ = 0;

        if (var3->unknown_58_->unknown_2c_.unknown5_0_.unknown_5_ & 2) {
            var3->unknown_50_ = 0;
        }

        var3->unknown_4_ = (unsigned short)(var3->unknown_4_ + GameState::GetInstance()->GetTickCount());

        if (side == 1) {
            self->resources.obj3D_.DisableFlag(0x1000);
            self->resources.obj3D_.SetAnimationByName(data_020efb4e, 0);
            if (action->unknown54 != side || action->unknown4 > 6) {
                func_ov017_021d3f00(action, side, 0);
                action->unknown4 = 0;
            }
            if (var3->unknown_48_ != 0) {
                arg0->unknown_0_.obj3D_.SetCurrentAnimationTime(var3->unknown_48_);
                var3->unknown_48_ = 0;
            }
        } else if (side == 2) {
            self->resources.obj3D_.DisableFlag(0x1000);
            self->resources.obj3D_.SetAnimationByName(data_020efb4e, 4);
            if (action->unknown54 != side || action->unknown4 > 6) {
                func_ov017_021d3f00(action, side, 0);
                action->unknown4 = 0;
            }
            if (var3->unknown_48_ != 0) {
                arg0->unknown_0_.obj3D_.SetCurrentAnimationTime(var3->unknown_48_);
                var3->unknown_48_ = 0;
            }
        } else {
            arg0->unknown_0_.obj3D_.EnableFlag(0x1000);
            var3->unknown_48_ = arg0->unknown_0_.obj3D_.animationTime_;
            if (var3->unknown_54_ != var5 || var3->unknown_4_ > 6) {
                func_ov017_021d3f00(var3, var5, 0);
                var3->unknown_4_ = 0;
            }
        }
        var3->unknown_54_ = (unsigned char)var5;

        if (var31 != 0) goto Exit;

        if (posCopy.y < action->start.entries[1]) {
            FlagWord_SetBits(inputFlags, 0x400);
            ZoneFeatures::Opcode6aEntry* post = action->startNode;
            if (post->unk_2c.type9.unk_5 & 2) {
                action->unknown60 = post;
                action->command = 6;
                goto Exit;
            }
            action->command = 5;
            action->unknown24.vec = action->startControl.vec;
            SetHalf0xc6AndCopyVec3_02033e18(self, action->startControl.entries, fields->destinationHeading);
            SetByte0xbeShiftPrev((struct Bytes02033b88*)self, 1);
            GameObject_SetFacing((struct Obj02033834*)self, action->startHeading);
            func_ov017_021d3f00(action, 0, 0);
            goto Exit;
        }

        if (var22.y <= var3->unknown_18_.unknown_0_[1]) goto Exit;

        FlagWord_SetBits(inputFlags, 0x400);
        ZoneFeatures::Opcode6aEntry* post2 = action->endNode;
        if (post2->unk_2c.type9.unk_5 & 2) {
            action->unknown60 = post2;
            action->command = 6;
            goto Exit;
        }
        posCopy.y = action->end.entries[1];
        self->resources.obj3D_.position_ = posCopy;
        action->unknown24.vec = posCopy;
        self->resources.obj3D_.SetAnimationByName(data_020efb5a, 1);
        action->command = 4;
        func_ov017_021d3f00(action, 0, 0);
        goto Exit;
    }

    if (state == 4) {
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        int animationProgress = self->resources.obj3D_.normalizedAnimationTime_;
        if (animationProgress != 0) {
            Vector3fix fallPosition;
            fallPosition = self->resources.obj3D_.position_;
            fallPosition.y = action->unknown24.entries[1] + FX_MulInline(action->endControl.entries[1] - action->unknown24.entries[1], 0x199);
            self->resources.obj3D_.position_ = fallPosition;
            action->unknown24.vec = fallPosition;

            int var41 = var1->substruct_c_.unknown_30_;
            var3->unknown_50_ = (int)((float)(unsigned int)var41 *
                (((float)var39 / 4096.0f) * ((float)var39 / 4096.0f)));
            if (var3->unknown_50_ < 0) var3->unknown_50_ = 0;
        }

        if (self->resources.obj3D_.HasAnimationStopped()) {
            action->command = 5;
            action->unknown24.vec = action->endControl.vec;
            SetHalf0xc6AndCopyVec3_02033e18(self, action->endControl.entries, fields->destinationHeading);
            SetByte0xbeShiftPrev((struct Bytes02033b88*)self, 1);
            GameObject_SetFacing((struct Obj02033834*)self, action->endHeading);
            func_ov017_021d3f00(action, 0, 0);
            FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        }
        goto Exit;
    }

    if (state == 5) {
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        self->resources.obj3D_.EnableFlag(0x80);
        SetByteSavingPrevious((struct Foo02033b58*)self, 1);
        if (!CheckField0xc6Zero((struct ShortField02033ec8*)self)) goto Exit;
        unsigned char dispatchOnCompletion = action->unknown52;

        InitBlock02038508(action);
        self->updated = 1;
        fields->flags.active = 0;
        self->resources.obj3D_.DisableFlag(0x1180);
        func_ov017_021d3f00(action, 0, 1);
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        if (dispatchOnCompletion == 0) goto Exit;

        arg0->unknown_252_ = 1;
        func_ov017_02191108(var0, 1, 1, 1, 1);
        GameObject* var43 = GameState::GetInstance()->GetUnknownGameObject();
        if (var43 == 0) goto Exit;
        var43->obj3D_.TransitionInheritedAlpha(0x1f, 0x64);
        goto Exit;
    }

    if (state == 6) {
        GameState* bs = GameState::GetInstance();
        ActorActionEvent02038598* event = (ActorActionEvent02038598*)GetField0x3f8Address_0200fd0c(bs);
        GameResources* transitionResources = GetGameResources();
        GameState_GetProtagonistIndex(bs);
        VectorizedMemset(event, 0, 0x70);
        event->active = 1;
        event->flag8 = 1;
        event->flag9 = 1;
        event->kind = -1;
        event->ids[0] = -1;
        event->ids[1] = -1;
        event->ids[2] = -1;
        event->ids[3] = -1;
        event->index = -1;
        event->hasTransform = 0;
        event->duration = -1;

        var45->unknown_0_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_6_;
        var45->unknown_10_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_c_;
        var45->unknown_1c_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_3c_;
        var45->unknown_b_ = (unsigned char)var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_3e_;
        var45->unknown_30_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_c_;
        var45->unknown_3c_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_18_;
        var45->unknown_48_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_24_;
        var45->unknown_54_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_30_;
        var45->unknown_c_ = 1;

        if (var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_5_ & 4) {
            var45->unknown_6c_ = (const short&)var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_42_;
            var45->unknown_6a_ = var3->unknown_60_->unknown_2c_.unknown5_0_.unknown_40_;
        }
        if (var45->unknown_6c_ == -1) {
            var45->unknown_6c_ = 9999;
        }
        var45->unknown_7_ = 1;
        func_0200fcfc(var44, var45);

        InitAndResetHeader_0219e310((unsigned char*)transitionResources->unknown_ptr_array_3700[3], 0);
        AppendNodeToTail((struct TailList020469b4*)transitionResources->fieldTaskQueue_,
            (struct TailNode020469b4*)transitionResources->unknown_ptr_array_3700[3]);
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);

        func_02038508(var3);
        arg0->unknown_253_ = 1;
        var2->unknown_6_ = 0;
        var2->unknown_34_.unknown_0_0_ = 0;
        arg0->unknown_0_.obj3D_.EnableFlag(0x1000);
        arg0->unknown_0_.obj3D_.DisableFlag(0x180);
        goto Exit;
    }
    Exit:;
}
