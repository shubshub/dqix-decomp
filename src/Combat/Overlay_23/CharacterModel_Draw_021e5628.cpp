#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"

extern "C" unsigned short (*CharacterColors_GetInstance(void))[2];
extern "C" int G3X_SetEdgeColorTable(int a);
extern "C" void G3_RotateY(int angle);

extern char CharacterModel_headBone;
extern char CharacterModel_arm2RBone;
extern char CharacterModel_arm2LBone;
extern char CharacterModel_weaponRBone;
extern char CharacterModel_weaponLBone;
extern char CharacterModel_chestBone;

// Two objects the caller hangs on the model's bones: chestAttachment at "chest", headAttachment at "head".
struct CharacterModelAttachments {
    Object3D* chestAttachment;
    Object3D* headAttachment;
};

// Overlay 23, originally func_ov023_021e5628 (USA/EUR 0x021e5628, JPN 0x021e580c)
extern "C" ARM void CharacterModel_Draw(CharacterModel* model, CharacterModelAttachments* attachments) {
    if (model->loading_ != 0) return;
    if (model->visible_ == 0) return;

    unsigned short (*table)[2] = CharacterColors_GetInstance();
    if (table == 0) return;

    unsigned short edgeColor = *(unsigned short*)((char*)table + 0x128);
    unsigned short edgeColors[8] = {edgeColor, edgeColor, edgeColor, edgeColor,
                                    edgeColor, edgeColor, edgeColor, edgeColor};
    G3X_SetEdgeColorTable((int)edgeColors);

    if (model->parts_[CharacterModelPart_Body].unknown_2_ >= 0) {
        model->parts_[CharacterModelPart_Body].AdvanceEffects();
        fix32_t animationTime = model->parts_[CharacterModelPart_Body].animationTime_;
        model->parts_[CharacterModelPart_Feet].SetCurrentAnimationTime(animationTime);
        model->parts_[CharacterModelPart_Legs].SetCurrentAnimationTime(animationTime);
        model->parts_[CharacterModelPart_Arms].SetCurrentAnimationTime(animationTime);
    }
    if (model->parts_[CharacterModelPart_Body].unknown_2_ <= -1) return;

    model->parts_[CharacterModelPart_Body].Draw(true);

    Model3D* bodyBones;
    Model3D* bodyModel = *(Model3D**)((char*)model + 8);
    if (bodyModel == 0) goto skipAttachedParts;
    if (!bodyModel->loaded_) bodyModel = 0;
    if (bodyModel == 0) goto skipAttachedParts;

    {
        bodyBones = model->parts_[CharacterModelPart_Body].pModel_;
        if (bodyBones == 0) return;

        int boneIndex = bodyBones->GetBoneIndex(&CharacterModel_headBone);
        if (boneIndex > -1) {
            GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
            if (attachments != 0 && attachments->headAttachment != 0) {
                attachments->headAttachment->DrawInCurrentMatrix(false);
            }
            model->parts_[CharacterModelPart_Face].SendTransformToFifo();
            model->parts_[CharacterModelPart_Face].DrawInCurrentMatrix(false);
            model->parts_[CharacterModelPart_Hair].DrawInCurrentMatrix(false);
            model->parts_[CharacterModelPart_Headgear].DrawInCurrentMatrix(false);

            if (model->holdsWithArms_ != 0) {
                boneIndex = bodyBones->GetBoneIndex(&CharacterModel_arm2RBone);
                if (boneIndex > -1 && model->parts_[CharacterModelPart_Weapon].unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
                    model->parts_[CharacterModelPart_Weapon].DrawInCurrentMatrix(false);
                }
                boneIndex = bodyBones->GetBoneIndex(&CharacterModel_arm2LBone);
                if (boneIndex > -1 && model->parts_[CharacterModelPart_Weapon].unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
                    G3_RotateY(FIX_2PI / 2);
                    model->parts_[CharacterModelPart_Weapon].DrawInCurrentMatrix(false);
                }
            } else {
                boneIndex = bodyBones->GetBoneIndex(&CharacterModel_weaponRBone);
                if (boneIndex > -1 && model->parts_[CharacterModelPart_Weapon].unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
                    model->parts_[CharacterModelPart_Weapon].DrawInCurrentMatrix(false);
                }
            }

            boneIndex = bodyBones->GetBoneIndex(&CharacterModel_weaponLBone);
            if (boneIndex > -1 && model->parts_[9].unknown_2_ > -1) {
                GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
                model->parts_[9].DrawInCurrentMatrix(false);
            }

            if (attachments != 0 && attachments->chestAttachment != 0) {
                boneIndex = bodyBones->GetBoneIndex(&CharacterModel_chestBone);
                if (boneIndex > -1) {
                    GetModelBonePositionAndDirectionMatrices(&bodyModel->renderContext_, 0, 0, boneIndex);
                    attachments->chestAttachment->DrawInCurrentMatrix(false);
                }
            }
        }
    }

skipAttachedParts:
    model->parts_[CharacterModelPart_Body].ApplyAnimations(&model->parts_[CharacterModelPart_Feet]);
    model->parts_[CharacterModelPart_Feet].Draw(true);
    model->parts_[CharacterModelPart_Body].ApplyAnimations(&model->parts_[CharacterModelPart_Legs]);
    model->parts_[CharacterModelPart_Legs].Draw(true);
    model->parts_[CharacterModelPart_Body].ApplyAnimations(&model->parts_[CharacterModelPart_Arms]);
    model->parts_[CharacterModelPart_Arms].Draw(true);
}
