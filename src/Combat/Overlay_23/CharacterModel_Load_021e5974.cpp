#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"

struct ItemTable;

struct Struct_ov023_021e5974_2
{
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 8;
    unsigned int unknown_6_4_ : 12;
};

// One record of the item table (the struct tag is kept: ItemRecord_GetFileNumber's C++ symbol is
// mangled with it).
struct StructDE234_020de234
{
    PartModel_021e5974* model_;
    int unk_4;
    int unk_8;
    int unk_c;
    unsigned int maleFileNumber_ : 10;
    unsigned int femaleFileNumber_ : 10;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
    short unk_14;
    short unk_16;
    short itemId_;
};
typedef StructDE234_020de234 ItemRecord;

struct CharacterModelExtension
{
    char unknown_0_[8];
};

int GameState_GetProtagonistIndex(GameState* state);
void CharacterModel_GetPartModels(void* vocation, short* models, short* appearance);
ItemRecord* ItemTable_Find(struct ItemTable* itemTable, int itemId);
unsigned short ItemRecord_GetFileNumber(ItemRecord* item, int female);
extern "C" void CharacterModel_CancelLoads(CharacterModel* self);

extern const int CharacterModel_bodyReloadParts[5];
extern const CharacterModelExtension CharacterModel_modelExtension;
extern const char CharacterModel_textureExtension[];
extern const char CharacterModel_hairVariantsByHeadgear[10];
extern const char CharacterModel_partFileFormat[];
extern const char CharacterModel_archivePath[];
extern const char CharacterModel_animationFileFormat[];
extern const char CharacterModel_animationConfigFormat[];

// The item a part shows when nothing is equipped there (CharacterModel_GetPartModels's default body); its file
// number takes the member's bareBodyColor.
enum { BareBodyItem = 1000 };
// The arms item CharacterModel_GetPartModels falls back to when neither the arms nor defaultArms_ is set; the arms
// part then takes the body's file number.
enum { BareArmsItem = 8010 };

// Overlay 23, originally func_ov023_021e5974 (USA/EUR 0x021e5974, JPN 0x021e5b58)
extern "C" ARM void CharacterModel_Load(CharacterModel* self, PartyMemberData* member,
                                        int vocation, int unused, int force)
{
    char var0[0x80];
    char var1[0x80];
    short var2[10];
    short var3;

    if (arg1 == NULL)
        return;

    self->member_ = member;
    CharacterModel_CancelLoads(self);
    GameState* state = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    PartyMemberAppearance* appearance = &member->appearance_;
    if (vocation < 0)
        vocation = member->unk_568;
    if (vocation < 0)
        vocation = GameState_GetProtagonistIndex(state);
    self->vocation_ = vocation;
    CharacterModel_GetPartModels((void*)vocation, models, (short*)appearance);
    self->parts_[CharacterModelPart_Hair].unknown_2_ = -1;
    self->parts_[CharacterModelPart_HairTexture].unknown_2_ = -1;
    ItemTable_Find(self->itemTable_, models[CharacterModelPart_Headgear]);
    ItemRecord* items[CharacterModelPart_Count] = {0};
    items[CharacterModelPart_Body] = ItemTable_Find(self->itemTable_, models[CharacterModelPart_Body]);
    items[CharacterModelPart_Headgear] = ItemTable_Find(self->itemTable_, models[CharacterModelPart_Headgear]);
    self->angle_ = self->parts_[CharacterModelPart_Body].rotation_.y;

    arg0->unknown_c13_ = 0;
    for (int var8 = 0; var8 < 5; var8++)
    {
        int part = CharacterModel_bodyReloadParts[i];
        if (models[part] != (modelId = self->parts_[part].unknown_2_) || force != 0)
        {
            self->bodyChanged_ = 1;
            self->parts_[CharacterModelPart_Body].unknown_2_ = -1;
            self->parts_[CharacterModelPart_Feet].unknown_2_ = -1;
            self->parts_[CharacterModelPart_Arms].unknown_2_ = -1;
            self->parts_[CharacterModelPart_Legs].unknown_2_ = -1;
            break;
        }
    }

    for (int var10 = 0; var10 < 10; var10++)
    {
        if (var2[var10] < 0)
        {
            self->parts_[i].Destroy();
            self->parts_[i].unknown_2_ = -1;
            if (i == CharacterModelPart_Body)
                models[CharacterModelPart_Arms] = -1;
            continue;
        }
        ItemRecord* item = ItemTable_Find(self->itemTable_, models[i]);
        if (item == NULL)
        {
            arg0->unknown_0_[var10].Initialize();
            arg0->unknown_0_[var10].unknown_2_ = var2[var10];
            continue;
        }
        arg0->unknown_0_[var10].Destroy();
        arg0->unknown_6b8_[var10].Reset();
        bool var12;
        if (arg1 == NULL)
        {
            var12 = false;
        }
        else
        {
            int fileNumber;
            ItemRecord* body = items[CharacterModelPart_Body];
            ItemRecord* headgear = items[CharacterModelPart_Headgear];
            int female = member->appearance_.female_;
            fileNumber = ItemRecord_GetFileNumber(item, female);
            CharacterModelExtension extension = CharacterModel_modelExtension;
            char suffix[2] = {0};

            if (i == CharacterModelPart_HairTexture)
            {
                strcpy(extension.name_, CharacterModel_textureExtension);
                suffix[0] = 'a';
                suffix[1] = 0;
                fileNumber += appearance->hairColor_;
            }
            if (i == CharacterModelPart_Hair)
            {
                suffix[0] = 'a';
                suffix[1] = 0;
                if (headgear != NULL && headgear->itemId_ > -1)
                {
                    unsigned int rank = (unsigned int)ItemRecord_GetFileNumber(headgear, female) / 100;
                    if (rank < 10)
                    {
                        char hairVariant = CharacterModel_hairVariantsByHeadgear[rank];
                        if (hairVariant == 0)
                        {
                            var12 = false;
                            goto queue;
                        }
                        suffix[0] = hairVariant;
                        if (rank == 3 && female == 0 && appearance->hairStyle_ == AppearanceModel_FirstHairStyle + 1)
                            suffix[0] = 'f';
                    }
                    else
                    {
                        var12 = false;
                        goto queue;
                    }
                }
            }
            if (i == CharacterModelPart_Arms)
            {
                modelId = appearance->arms_;
                if (modelId == BareArmsItem || modelId < 0)
                    fileNumber = ItemRecord_GetFileNumber(body, female);
            }
            if (item->itemId_ == BareBodyItem)
                fileNumber += member->bareBodyColor_;
            sprintf(path, CharacterModel_partFileFormat, (char)item->letter_, fileNumber, suffix, extension.name_);
            ok = true;
        }
    queue:
        if (var12)
        {
            self->tasks_[i] = loader->QueueLoadFileInGP2(CharacterModel_archivePath, path, NULL);
            self->parts_[i].unknown_2_ = models[i];
        }
    }

    arg0->unknown_c13_ = 1;
    if (arg0->unknown_c13_)
    {
        ItemRecord* body = ItemTable_Find(self->itemTable_, models[CharacterModelPart_Body]);
        ItemRecord* weapon = ItemTable_Find(self->itemTable_, models[CharacterModelPart_Weapon]);
        unsigned char weaponId = 0;
        if (weapon != NULL)
            weaponId = weapon->model_->id_;
        if (body != NULL)
        {
            int sex = 'm';
            if (appearance->female_ == 1)
                sex = 'w';
            sprintf(anim, CharacterModel_animationFileFormat, body->model_->id_, weaponId, sex);
            self->tasks_[10] = loader->QueueLoadFileInGP2(CharacterModel_archivePath, anim, NULL);
            sprintf(anim, CharacterModel_animationConfigFormat, body->model_->id_, weaponId, sex);
            self->tasks_[11] = loader->QueueLoadFileInGP2(CharacterModel_archivePath, anim, NULL);
            if (self->parts_[CharacterModelPart_Body].pModel_ != NULL)
                self->parts_[CharacterModelPart_Body].pModel_->RemoveAnimations();
            self->parts_[CharacterModelPart_Body].RemoveAllAnimationPackages();
            self->animationAllocator_.Reset();
        }
    }
    arg0->unknown_c12_ = 1;
    arg0->unknown_c1e_ = 0;
}
