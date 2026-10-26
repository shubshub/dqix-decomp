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

extern "C" void VramState_Rewind(struct Foo0207df50* state);
extern "C" void VramState_Restore(char* state);
extern "C" void VramState_Save(char* state);
extern "C" void Object3D_SetRotation(void* object, struct Words021e60c4* rotation);
extern "C" void CharacterModel_GetPartModels(void* vocation, short* models, short* appearance);
extern "C" void __clear(void* buffer, unsigned long size);

struct ItemRecord
{
    void* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int type_ : 5;
    unsigned int unknown_9_1_ : 3;
};

extern "C" ItemRecord* ItemTable_Find(struct ItemTable* itemTable, int itemId);

struct CharacterModelRotation
{
    int x;
    int y;
    int z;
};

extern "C" void CharacterModel_ApplyColors(CharacterModel* self);
extern "C" void CharacterModel_SetScale(CharacterModel* self, int width, int height);

extern "C" const char CharacterModel_standCmAnimation[];
extern "C" const char CharacterModel_standAnimation[];

// Overlay 23, originally func_ov023_021e5020 (USA/EUR 0x021e5020, JPN 0x021e5204)
extern "C" ARM void CharacterModel_Update(CharacterModel* self)
{
    void* file;
    unsigned int size;

    if (self->loading_)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        self->loading_ = 0;
        for (int i = 0; i < 10; i++)
        {
            if (self->tasks_[i] > -1)
            {
                if (loader->GetTaskStatus(self->tasks_[i]))
                {
                    self->parts_[i].Destroy();
                    self->allocators_[i].Reset();
                    loader->GetLoadedFileByID(self->tasks_[i], &file, &size);
                    if (size != 0)
                    {
                        VramState_Rewind((Foo0207df50*)&self->vramStates_[i]);
                        VramState_Restore((char*)&self->vramStates_[i]);
                        self->parts_[i].SetModelFromFileCopy(&self->allocators_[i], file, size, Model3D::TextureStagingMode_Normal);
                        VramState_Save((char*)&self->vramStates_[i]);
                        if (i == CharacterModelPart_HairTexture && self->parts_[CharacterModelPart_Hair].pModel_ != NULL)
                            self->parts_[CharacterModelPart_Hair].pModel_->ApplyTexturesFromModel(self->parts_[i].pModel_);
                    }
                    loader->RemoveTask(self->tasks_[i]);
                    self->tasks_[i] = -1;
                }
                else
                {
                    self->loading_ = 1;
                }
            }
        }

        short task = self->tasks_[10];
        if (task > -1)
        {
            if (loader->GetTaskStatus(task))
            {
                loader->GetLoadedFileByID(task, &file, &size);
                if (size != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[CharacterModelPart_Body].LoadType0AnimationFromFileInMemory(0, &self->animationAllocator_, file, size);
                }
                loader->RemoveTask(task);
                self->tasks_[10] = -1;
            }
            else
            {
                self->loading_ = 1;
            }
        }

        task = self->tasks_[11];
        if (task > -1)
        {
            if (loader->GetTaskStatus(task))
            {
                loader->GetLoadedFileByID(task, &file, &size);
                if (size != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[CharacterModelPart_Body].LoadType0AnimationPackageFromBCFGScript(&self->animationAllocator_, file, size);
                }
                loader->RemoveTask(task);
                self->tasks_[11] = -1;
            }
            else
            {
                self->loading_ = 1;
            }
        }

        if (!self->loading_ && !self->colored_)
        {
            CharacterModel_ApplyColors(self);
            self->colored_ = 1;
            self->loading_ = 1;
        }

        if (!self->loading_)
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
                self->holdsWithArms_ = 0;
        }
    }
}
