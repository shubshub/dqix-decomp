#include <globaldefs.h>
#include <GameState/GameState.h>
#include "GameState/Field3b0.h"
#include <Graphics/Vector.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;
struct Struct_0204a438;
struct Struct_02033834;
struct Struct_02010604;
struct Struct_02012050;
struct Struct_ov026_021daec8;
#if defined(jpn)
struct Struct_ov000_02160da0 { char unknown_0_[0x7902]; signed char unknown_7712_; };
#else
struct Struct_ov000_02160da0 { char unknown_0_[0x7712]; signed char unknown_7712_; };
#endif

struct Struct_ov026_021dc040 {
    char unknown_0_[0x3c];
    unsigned int unknown_3c_0_ : 30;
    unsigned int unknown_3f_6_ : 1;
    unsigned int unknown_3f_7_ : 1;
    unsigned short inline_ov026_021dc040() { return unknown_3f_6_; }
};
Object3D* GetField0x21c(S0204a438*);
int ClassifyField0x81fe_ov000_0215fc60(char*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
void SetVecYFromValue02033874(Obj02033874*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void GameState_SetCamera(GameState*, int);
void InitCombatantPosition_0216118c(void*, int);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char*);
void ClearCombatantSlot_0200fd48(GameState*, int);
void ClearByte0x63d5_02012050(FieldBlock63d5_12050*);
extern "C" {
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
int func_ov000_02160f14(Struct_ov000_02160da0*);
void func_ov026_021daec8(Struct_ov000_02161e30*, Struct_ov026_021daec8*, int);
void func_ov000_021626a0(Struct_ov000_02160da0*, int, int);
void __clear(void*, int);
}
struct Struct_ov026_021de6a0_2 { signed char unknown_0_[2]; };
extern const Struct_ov026_021de6a0_2 data_ov026_021de6a0;
extern const char data_ov026_021dee57[];

// USA: func_ov026_021dc040
extern "C" ARM int func_ov026_021dc040(SafeAllocator* allocator, BattleWork* self, BattleState* battle, PartyState* party) {
    GameState* game = GameState::GetInstance();
    S0204a438* camera = (S0204a438*)game->GetCamera();
    if (!camera) return 1;
    Object3D* animation = GetField0x21c(camera);
    if (!animation) return 1;
    GameObject* formation = game->GetGameObjectByIndex(0xcf);
    if (!formation) return 1;
    formation->obj3D_.MaybeUpdateBonePositions();
    Model3D* model = formation->obj3D_.pModel_;
    if (model) {
        short members[4];
        int count = func_ov000_0215e9fc(battle, members, 4, 0);
        if (ClassifyField0x81fe_ov000_0215fc60((char*)battle)) count = 1;
        if (count > 0) {
            Vector3fix center = {};
            int groupCounts[2] = {};
            for (int index = 0; index < count; ++index) {
                if (TestBitAt0x34_020a35e0((unsigned char*)party, members[index])) {
                    GameObject* member = GetCombatantWithFlag0x100_0200ff1c(game, members[index]);
                    if (member && member->obj3D_.pModel_) {
                        FormationStats* stats = (FormationStats*)member->baseStats_;
                        ++groupCounts[stats->GetGroup()];
                        BoneLabels labels = data_ov026_021de6a0;
                        char name[6];
                        int group = ((FormationStats*)member->baseStats_)->GetGroup();
                        sprintf(name, data_ov026_021dee57, labels.letters[group], groupCounts[group]);
                        Object3D::TrackedBoneMatrix* bone = formation->obj3D_.GetTrackedBoneMatrix(model->GetBoneIndex(name));
                        if (bone) {
                            Vector3fix position;
                            position.x = bone->matrix.translation.x;
                            position.y = bone->matrix.translation.y;
                            position.z = bone->matrix.translation.z;
                            Vector3fixMultiplyScalar(&position, 266, &position);
                            member->obj3D_.position_ = position;
                            SetVecYFromValue02033874((Obj02033874*)member, fix32_Atan2(bone->matrix.rotation.rows[2].x, bone->matrix.rotation.rows[2].z));
                            Vector3fix_Add(&center, &position, &center);
                        }
                    }
                }
            }
            Vector3fixMultiplyScalar(&var7, (int)(4096.0f * (1.0f / (float)var6)), &var7);
            int var17 = -var7.x;
            for (int var18 = 0; var18 < var6; ++var18) {
                if (func_020a35e0((unsigned char*)arg3, var5[var18])) {
                    GameObject* var19 = func_0200ff1c(var0, var5[var18]);
                    if (var19) {
                        Vector3fix var20 = var19->obj3D_.position_;
                        var20.x += var17;
                        var20.y = 204;
                        var19->obj3D_.position_ = var20;
                    }
                }
            }
        }
    }
    if (arg1->unknown_7712_ == 0 && !var2->HasAnimationStopped()) return 0;
    if (arg1->unknown_7712_ != 6) {
        for (int var21 = 0; var21 < 4; ++var21) {
            if (func_020a35e0((unsigned char*)arg3, var21)) {
                GameObject* var22 = func_0200ff1c(var0, var21);
                if (var22) {
                    var22->obj3D_.RemoveAnimationPackageByID(3);
                    func_02033b88((Struct_02010604*)var22, 0);
                    func_02033874((Struct_02033834*)var22, 0x3244);
                }
            }
        }
        GameState_SetCamera(game, func_ov000_02160f14(self));
        InitCombatantPosition_0216118c(self, 1);
        RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)self);
        func_ov026_021daec8(battle, (BattleView*)func_ov000_02160f14(self), 1);
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 1);
        allocator->Reset();
        ClearCombatantSlot_0200fd48(game, 0xcf);
        ClearByte0x63d5_02012050((FieldBlock63d5_12050*)game);
    }
    return 1;
}
