#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"

struct Foo0207df50;
struct Words021e60c4;
struct ItemTable;

void VramState_Rewind(struct Foo0207df50* state);
void VramState_Restore(char* state);
void VramState_Save(char* state);
void Object3D_SetRotation(void* object, struct Words021e60c4* rotation);
void CharacterModel_GetPartModels(void* vocation, short* models, short* appearance);
extern "C" void __clear(void* buffer, unsigned long size);

struct ItemRecord
{
    void* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 3;
};

ItemRecord* ItemTable_Find(struct ItemTable* itemTable, int itemId);

struct CharacterModelRotation
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern "C" void CharacterModel_ApplyColors(CharacterModel* self);
extern "C" void CharacterModel_SetScale(CharacterModel* self, int width, int height);

extern "C" const char CharacterModel_standCmAnimation[];
extern "C" const char CharacterModel_standAnimation[];

// Overlay 23, originally func_ov023_021e5020 (USA/EUR 0x021e5020, JPN 0x021e5204)
extern "C" ARM void CharacterModel_Update(CharacterModel* self)
{
    void* var0;
    unsigned int var1;

    if (arg0->unknown_c12_)
    {
        BackgroundLoader* var2 = BackgroundLoader::GetInstance();
        arg0->unknown_c12_ = 0;
        for (int var3 = 0; var3 < 10; var3++)
        {
            if (arg0->unknown_bf4_[var3] > -1)
            {
                if (var2->GetTaskStatus(arg0->unknown_bf4_[var3]))
                {
                    arg0->unknown_0_[var3].Destroy();
                    arg0->unknown_6b8_[var3].Reset();
                    var2->GetLoadedFileByID(arg0->unknown_bf4_[var3], &var0, &var1);
                    if (var1 != 0)
                    {
                        VramState_Rewind((Foo0207df50*)&self->vramStates_[i]);
                        VramState_Restore((char*)&self->vramStates_[i]);
                        self->parts_[i].SetModelFromFileCopy(&self->allocators_[i], file, size, Model3D::TextureStagingMode_Normal);
                        VramState_Save((char*)&self->vramStates_[i]);
                        if (i == CharacterModelPart_HairTexture && self->parts_[CharacterModelPart_Hair].pModel_ != NULL)
                            self->parts_[CharacterModelPart_Hair].pModel_->ApplyTexturesFromModel(self->parts_[i].pModel_);
                    }
                    var2->RemoveTask(arg0->unknown_bf4_[var3]);
                    arg0->unknown_bf4_[var3] = -1;
                }
                else
                {
                    arg0->unknown_c12_ = 1;
                }
            }
        }

        short var4 = arg0->unknown_bf4_[10];
        if (var4 > -1)
        {
            if (var2->GetTaskStatus(var4))
            {
                var2->GetLoadedFileByID(var4, &var0, &var1);
                if (var1 != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[CharacterModelPart_Body].LoadType0AnimationFromFileInMemory(0, &self->animationAllocator_, file, size);
                }
                var2->RemoveTask(var4);
                arg0->unknown_bf4_[10] = -1;
            }
            else
            {
                arg0->unknown_c12_ = 1;
            }
        }

        var4 = arg0->unknown_bf4_[11];
        if (var4 > -1)
        {
            if (var2->GetTaskStatus(var4))
            {
                var2->GetLoadedFileByID(var4, &var0, &var1);
                if (var1 != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[CharacterModelPart_Body].LoadType0AnimationPackageFromBCFGScript(&self->animationAllocator_, file, size);
                }
                var2->RemoveTask(var4);
                arg0->unknown_bf4_[11] = -1;
            }
            else
            {
                arg0->unknown_c12_ = 1;
            }
        }

        if (!arg0->unknown_c12_ && !arg0->unknown_c1e_)
        {
            CharacterModel_ApplyColors(self);
            self->colored_ = 1;
            self->loading_ = 1;
        }

        if (!arg0->unknown_c12_)
        {
            PartyMemberAppearance* appearance = &self->member_->appearance_;
            if (self->bodyChanged_)
            {
                if (appearance->female_ == 1 && self->forceStandAnimation_ == 0)
                {
                    if (self->parts_[CharacterModelPart_Body].unknown_2_ >= 0)
                    {
                        self->parts_[CharacterModelPart_Body].StopCurrentAnimation();
                        self->parts_[CharacterModelPart_Body].SetAnimationByName(CharacterModel_standCmAnimation, 0);
                    }
                }
                else if (self->parts_[CharacterModelPart_Body].unknown_2_ >= 0)
                {
                    self->parts_[CharacterModelPart_Body].StopCurrentAnimation();
                    self->parts_[CharacterModelPart_Body].SetAnimationByName(CharacterModel_standAnimation, 0);
                }
                CharacterModelRotation rotation = {0};
                rotation.y = self->angle_;
                Object3D_SetRotation(&self->parts_[CharacterModelPart_Body], (Words021e60c4*)&rotation);
                Object3D_SetRotation(&self->parts_[CharacterModelPart_Feet], (Words021e60c4*)&rotation);
                Object3D_SetRotation(&self->parts_[CharacterModelPart_Legs], (Words021e60c4*)&rotation);
                Object3D_SetRotation(&self->parts_[CharacterModelPart_Arms], (Words021e60c4*)&rotation);
                CharacterModel_SetScale(self, appearance->width_, appearance->height_);
            }

            short models[10];
            CharacterModel_GetPartModels((void*)self->vocation_, models, (short*)appearance);
            ItemRecord* weapon = ItemTable_Find(self->itemTable_, models[CharacterModelPart_Weapon]);
            if (weapon != NULL && weapon->type_ == 6)
                self->holdsWithArms_ = 1;
            else
                arg0->unknown_c10_ = 0;
        }
    }
}
