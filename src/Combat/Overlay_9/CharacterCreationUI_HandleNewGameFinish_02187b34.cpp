#include "Resource/CreationEnums.h"
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/HWRegisters.h"
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "Sound/SePlayer.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"


#define BLEND_TARGET_BG_AND_OBJ (BLEND_TARGET_BG0 | BLEND_TARGET_BG1 | BLEND_TARGET_BG2 | BLEND_TARGET_BG3 | BLEND_TARGET_OBJ)
#define FX32_FROM_FLOAT(x) ((int)((x) > 0.0f ? 0.5f + 4096.0f * (x) : 4096.0f * (x) - 0.5f))

struct FinishModelFile {
    SafeAllocator* allocator_;
    const char* name_;
    unsigned char taskSlot_;
};

struct FinishModelFiles {
    FinishModelFile files[4];
};

// CharacterCreation::step_ on the new-game finish tab.
enum FinishStep
{
    FinishStep_Start = 0,        // turn the hero to the front, ease the camera, start dimming the background
    FinishStep_WaitTurn = 1,     // once turned and the camera has stopped: dim with the quad, wait for the body's animation
    FinishStep_QueueLoads = 2,
    FinishStep_WaitLoads = 3,
    FinishStep_ApplyLoads = 4,   // load the files into the body, the wings and the effect, then show them
    FinishStep_ModelsLoaded = 5, // written by ApplyLoads, which goes on to PlaySound in the same frame; no case
    FinishStep_PlaySound = 6,
    FinishStep_FadeToWhite = 7,
    FinishStep_WaitWhite = 8,    // then darken every layer behind the white
    FinishStep_FadeToBlack = 9,
    FinishStep_WaitBlack = 10,   // then set the black directly and undo the layer darkening
    FinishStep_Leave = 11,
    FinishStep_Done = 0xff,
};

// The finish's files: each one's modelTasks_ slot (CharacterCreationUI_finishModelFiles' taskSlot).
enum FinishFile
{
    FinishFile_BodyPackage = 0, // loaded into the hero's body as animation package FinishBodyPackageId
    FinishFile_Wings = 1,
    FinishFile_Effect = 2,      // a loose file; the others come from CharacterCreationUI_characterArchive
    FinishFile_Count = 3,
};

// Keys in character creation's text table: the finish's file names (the first two have a female version at
// + CreationText_FemaleOffset) and the animation the body and the wings play.
enum FinishText
{
    FinishText_Wings = 2001,
    FinishText_BodyPackage = 2002,
    FinishText_Effect = 2200,
    FinishText_Animation = 2500,
};

// How long each part of the finish takes, in ticks.
enum FinishTicks
{
    FinishTicks_Dim = 90,          // dimTimer_: CharacterCreationUI_UpdateDim darkens the background over it
    FinishTicks_ShowModels = 30,   // waitTimer_ once the wings and the effect appear
    FinishTicks_BeforeWhite = 150, // waitTimer_ after the first sound
    FinishTicks_FadeToWhite = 40,
    FinishTicks_HoldWhite = 120,   // waitTimer_ once white
    FinishTicks_FadeToBlack = 120,
};

enum
{
    FinishBodyPackageId = 1,
    FinishStartAnimationTime = 0xccc, // 0.8 (fx32) of the body's animation
};

struct Actor0209c678;
struct Container020e0310;
struct Foo0207df50;
struct FlagWord020466f4;

extern "C" Object3D* CharacterModel_GetBody(void* character);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void CharacterCreationUI_UpdateDim(void* self, unsigned int ticks);
extern "C" int CharacterCreationUI_UpdateWaitTimer(void* self, unsigned int ticks);
extern "C" void Camera_EasePositionTo(struct Camera* camera, int position, int duration);
extern "C" void Camera_EaseTargetTo(struct Camera* camera, int target, int duration);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* actor, int state);
extern "C" int Camera_IsEasing(struct Camera* camera);
extern "C" void SePlayer_LoadExtraArchiveB(void* sound, int a, int b);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void VramState_Rewind(Foo0207df50* a);
extern "C" void VramState_Restore(char* a);
extern "C" void VramState_Save(char* a);
extern "C" void SePlayer_PlayExtra(void* sound, int a, int b);
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* field, unsigned int bits);
extern "C" void GXx_SetMasterBrightness_(volatile unsigned short* reg, int brightness);
extern "C" void SePlayer_UnloadExtraArchiveB(void* sound);
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int state);

struct Vec3 {
    int x;
    int y;
    int z;
};

extern const Vec3 CharacterCreationUI_finishCameraPosition;
extern const Vec3 CharacterCreationUI_finishCameraTarget;
extern const FinishModelFiles CharacterCreationUI_finishModelFiles;
extern char CharacterCreationUI_characterArchive[];
extern char CharacterCreationUI_finishEffectAnimation[];
extern char g_bgmPlayer[];

// The header's CharacterCreationUI up to sex, with CharacterCreationUI_HandleSetup's field names.
struct CharacterCreation {
    SafeAllocator allocators_[R(8,9)];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
#if !defined(jpn)
    void* savedKey_;
    void* keyboard_;
    void* keyboardLayout_;
#endif
    char itemTable_[0x18];
    char texts_[0x18];
    char* textBuffer_;
    char nameFilter_[R(0x20,0x3c)];
    char layers_[6][0x20];
    char windows_[2][0xbc];
    char window0Panes_[1][0xe0];
    char window1Panes_[4][0xe0];
    void* windowBuffers_[2];
    void* mainSpriteContext_;
    void* mainSprites_;
    void* mainSpriteEntries_;
    void* subSpriteContext_;
    void* subSprites_;
    void* subSpriteEntries_;
    void* characterModels_[2];
    void* character_;
    void* nextCharacter_;
    int unknown800_;
    int targetAngle_;
    char wingsVramState_[0x70];
    Object3D wings_;
    char camera_[0x2c8];
    char navigation_[0x40];
    char grid_[0x20];
    short cursorX_, cursorY_;
    short cursorWidth_, cursorHeight_;
    short lastCursorX_, lastCursorY_;
    signed char state_;
    unsigned char step_;
    char unknownAfterStep_[2];
    int modelTasks_[FinishFile_Count];
    char finishEffectVramState_[0x70];
    Object3D finishEffect_;
    unsigned char selection_;
    unsigned char windowInput_;
    char unknownAfterWindowInput_[2];
    PartyMemberData* characterData_;
    int touchedChoice_;
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    short waitTimer_;
    short dimTimer_;
    char unknownBeforeFlags_[2];
    unsigned int flags_;
    signed char furthestState_[2];
    unsigned char vocation_;
    unsigned char sex_;
};

// Overlay 9, originally func_ov009_02187b34 (USA/EUR 0x02187b34, JPN 0x021888f0)
extern "C" ARM void CharacterCreationUI_HandleNewGameFinish(CharacterCreation* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    Object3D* body = CharacterModel_GetBody(self->character_);
    unsigned int* globalFlags = GlobalFlags_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader == NULL)
        return;
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    CharacterCreationUI_UpdateDim(self, ticks);
    if (CharacterCreationUI_UpdateWaitTimer(self, ticks) > 0)
        return;

    switch (self->step_)
    {
    case FinishStep_Start:
    {
        self->flags_ &= ~CreationFlag_StylusRotation;
        self->targetAngle_ = CreationAngle_Finish;
        self->flags_ |= CreationFlag_TurnToTarget;
        Vec3 position = CharacterCreationUI_finishCameraPosition;
        Vec3 target = CharacterCreationUI_finishCameraTarget;
        Camera_EasePositionTo((struct Camera*)self->camera_, (int)&position, CreationCamera_EaseSteps);
        Camera_EaseTargetTo((struct Camera*)self->camera_, (int)&target, CreationCamera_EaseSteps);
        self->dimTimer_ = FinishTicks_Dim;
        self->flags_ |= CreationFlag_DimBackground;
        BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, 120);
        self->step_ = FinishStep_WaitTurn;
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < FinishFile_Count; i++)
            *task++ = -1;
        SafeAllocator* allocator = self->previewAllocators_;
        for (unsigned char i = 0; i < 2; i++, allocator++)
            allocator->Reset();
        break;
    }
    case FinishStep_WaitTurn:
        if (self->flags_ & CreationFlag_TurnToTarget)
            break;
        if (Camera_IsEasing((struct Camera*)self->camera_) != 0)
            break;
        self->flags_ |= CreationFlag_DimWithQuad;
        if (CharacterModel_GetBody(self->character_)->normalizedAnimationTime_ >= FinishStartAnimationTime)
        {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, SoundArchive_NewGameFinish, SoundArchive_NewGameFinish);
            self->step_ = FinishStep_QueueLoads;
        }
        break;
    case FinishStep_QueueLoads:
    {
        short wingsKey = self->sex_ * CreationText_FemaleOffset + FinishText_Wings;
        short bodyPackageKey = self->sex_ * CreationText_FemaleOffset + FinishText_BodyPackage;
        FinishModelFiles files = CharacterCreationUI_finishModelFiles;
        files.files[FinishFile_BodyPackage].allocator_ = self->previewAllocators_;
        files.files[FinishFile_BodyPackage].name_ = KeyTable_Get((Container020e0310*)self->texts_, bodyPackageKey);
        files.files[FinishFile_Wings].allocator_ = &self->previewAllocators_[1];
        files.files[FinishFile_Wings].name_ = KeyTable_Get((Container020e0310*)self->texts_, wingsKey);
        files.files[FinishFile_Effect].allocator_ = self->modelAllocator_;
        files.files[FinishFile_Effect].name_ = KeyTable_Get((Container020e0310*)self->texts_, FinishText_Effect);
        FinishModelFile* file = files.files;
        const char* archive = CharacterCreationUI_characterArchive;
        for (; file->allocator_ != NULL; file++)
        {
            int task;
            if (file->taskSlot_ == FinishFile_Effect)
                task = loader->QueueLoadFile(file->name_, file->allocator_);
            else
                task = loader->QueueLoadFileInGP2(archive, file->name_, file->allocator_);
            self->modelTasks_[file->taskSlot_] = task;
        }
        self->step_ = FinishStep_WaitLoads;
        break;
    }
    case FinishStep_WaitLoads:
    {
        int allLoaded = 1;
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < FinishFile_Count; i++, task++)
        {
            if (*task != -1 && loader->GetTaskStatus(*task) == 0)
                allLoaded = 0;
        }
        if (allLoaded)
            self->step_ = FinishStep_ApplyLoads;
        break;
    }
    case FinishStep_ApplyLoads:
    {
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < FinishFile_Count; i++, task++)
        {
            if (*task == -1)
                continue;
            if (loader->GetTaskStatus(*task) == 1)
            {
                unsigned int size = 0;
                void* file = NULL;
                loader->GetLoadedFileByID(*task, &file, &size);
                ObjectArchiveLoadInfo info;
                info.unk_0 = 0;
                info.allocator = NULL;
                info.unk_14 = 0;
                info.unk_18 = 0;
                info.unk_10 = 0;
                info.packageID = 0;
                info.fileData = file;
                info.fileSize = size;
                switch (i)
                {
                case FinishFile_BodyPackage:
                    info.allocator = self->previewAllocators_;
                    info.packageID = FinishBodyPackageId;
                    body->LoadFromCHRArchive(&info);
                    break;
                case FinishFile_Wings:
                    info.allocator = &self->previewAllocators_[1];
                    self->wings_.LoadFromCHRArchive(&info);
                    break;
                case FinishFile_Effect:
                    info.allocator = self->modelAllocator_;
                    VramState_Rewind((Foo0207df50*)self->finishEffectVramState_);
                    VramState_Restore(self->finishEffectVramState_);
                    self->finishEffect_.LoadFromCHRArchive(&info);
                    VramState_Save(self->finishEffectVramState_);
                    break;
                }
            }
            loader->RemoveTask(*task);
            *task = -1;
        }
        self->step_ = FinishStep_ModelsLoaded;
        body->StopCurrentAnimation();
        body->SetAnimationByName(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
        Vector3fix rotation;
        memset(&rotation, 0, sizeof(rotation));
        rotation = body->rotation_;
        PartyMemberAppearance* appearance = &self->characterData_->appearance_;
        int scaleX;
        int scaleY;
        short width = appearance->width_;
        scaleX = FX32_FROM_FLOAT(width / 4096.0f);
        scaleY = FX32_FROM_FLOAT(appearance->height_ / 4096.0f);
        int scaleZ = FX32_FROM_FLOAT(width / 4096.0f);
#if defined(jpn)
        self->wings_.SetScale(scaleX, scaleY, scaleZ);
        self->wings_.rotation_ = rotation;
        self->wings_.StopCurrentAnimation();
        self->wings_.SetAnimationByName(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)body + CharacterModelPart_Feet * sizeof(Object3D)))->position_;
        self->finishEffect_.rotation_ = rotation;
        self->finishEffect_.position_ = position;
        self->finishEffect_.StopCurrentAnimation();
        self->finishEffect_.SetAnimationByName(CharacterCreationUI_finishEffectAnimation, 0);
#else
        Object3D* wings = &self->wings_;
        wings->SetScale(scaleX, scaleY, scaleZ);
        wings->rotation_ = rotation;
        wings->StopCurrentAnimation();
        wings->SetAnimationByName(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)body + CharacterModelPart_Feet * sizeof(Object3D)))->position_;
        Object3D* finishEffect = &self->finishEffect_;
        finishEffect->rotation_ = rotation;
        finishEffect->position_ = position;
        finishEffect->StopCurrentAnimation();
        finishEffect->SetAnimationByName(CharacterCreationUI_finishEffectAnimation, 0);
#endif
        self->flags_ |= CreationFlag_ShowFinishModels;
        self->waitTimer_ = FinishTicks_ShowModels;
        self->step_ = FinishStep_PlaySound;
        break;
    }
    case FinishStep_PlaySound:
        SePlayer_PlayExtra(&g_sePlayer, 0, 0);
        self->waitTimer_ = FinishTicks_BeforeWhite;
        self->step_ = FinishStep_FadeToWhite;
        break;
    case FinishStep_FadeToWhite:
        FlagWord_SetBits(globalFlags, 0x100);
        SetBrightness(resources, Brightness_White, FinishTicks_FadeToWhite);
        SePlayer_PlayExtra(&g_sePlayer, 1, 0);
        self->step_ = FinishStep_WaitWhite;
        break;
    case FinishStep_WaitWhite:
        if (IsBrightnessTransitionActive(resources))
            break;
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, BLEND_TARGET_BG_AND_OBJ, Brightness_Black);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG_AND_OBJ, Brightness_Black);
        self->waitTimer_ = FinishTicks_HoldWhite;
        self->step_ = FinishStep_FadeToBlack;
        break;
    case FinishStep_FadeToBlack:
        if (self->waitTimer_ > 0)
        {
            unsigned int elapsed = gameState->GetTickCount();
            if (elapsed == 0)
                elapsed = 1;
            self->waitTimer_ -= elapsed;
            break;
        }
        SetBrightness(resources, Brightness_Black, FinishTicks_FadeToBlack);
        self->step_ = FinishStep_WaitBlack;
        break;
    case FinishStep_WaitBlack:
        if (IsBrightnessTransitionActive(resources))
            break;
        GXx_SetMasterBrightness_(&REG_MASTER_BRIGHT, Brightness_Black);
        GXx_SetMasterBrightness_(&REG_MASTER_BRIGHT_SUB, Brightness_Black);
        FlagWord_ClearBits((FlagWord020466f4*)globalFlags, 0x100);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, BLEND_TARGET_BG_AND_OBJ, Brightness_Normal);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG_AND_OBJ, Brightness_Normal);
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        self->step_ = FinishStep_Leave;
        break;
    case FinishStep_Leave:
        self->step_ = FinishStep_Done;
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        break;
    }
}
