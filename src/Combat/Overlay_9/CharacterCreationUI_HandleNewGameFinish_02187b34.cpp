#include "Resource/CreationEnums.h"
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "Sound/SePlayer.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

#define REG_BLDCNT 0x04000050
#define REG_BLDCNT_SUB 0x04001050
#define BLEND_TARGET_BG_AND_OBJ (BLEND_TARGET_BG0 | BLEND_TARGET_BG1 | BLEND_TARGET_BG2 | BLEND_TARGET_BG3 | BLEND_TARGET_OBJ)
#define FX32_FROM_FLOAT(x) ((int)((x) > 0.0f ? 0.5f + 4096.0f * (x) : 4096.0f * (x) - 0.5f))

struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_[4];
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x488];
    Struct_ov009_02187b34 unknown_488_;
};

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

struct Struct_02109bf4_4;
struct Struct_0201099c_3;
struct Struct_0203d028;
struct Struct_02038598_4;

extern "C" Object3D* CharacterModel_GetBody(void* character);
unsigned int* GetDataPtr02114e04_020d6c00();
extern "C" void CharacterCreationUI_UpdateDim(void* self, unsigned int ticks);
extern "C" int CharacterCreationUI_UpdateWaitTimer(void* self, unsigned int ticks);
void Camera_EasePositionTo(char* camera, int position, int duration);
void Camera_EaseTargetTo(char* camera, int target, int duration);
void DispatchContextByState0209c678(Actor0209c678* actor, int state);
int Camera_IsEasing(char* camera);
void SetForwardAndStore0205ebc0(void* sound, int a, int b);
const char* KeyTable_Get(Container020e0310* texts, int id);
void CopyInternalFields0207df50(Foo0207df50* a);
void VramState_Restore(char* a);
void VramState_Save(char* a);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);
extern "C" void func_020c39a0(volatile unsigned short* reg, int brightness);
void ForwardField0xc0_0205ebec(void* sound);
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);

struct Struct_ov009_0218aa28 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern const Vec3 CharacterCreationUI_finishCameraPosition;
extern const Vec3 CharacterCreationUI_finishCameraTarget;
extern const FinishModelFiles CharacterCreationUI_finishModelFiles;
extern char CharacterCreationUI_characterArchive[];
extern char CharacterCreationUI_finishEffectAnimation[];
extern char data_02109bf4[];

struct CharacterCreation {
    char unk_0[R(0xa0,0xb4)];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    char unk_bc[R(0xc0-0xa8,0xe0-0xbc)];
    char texts_[0x18];
    char unk_f8[R(0x7bc-0xd8,0x7f8-0xf8)];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char wingsVramState_[0x70];
    Object3D wings_;
    char camera_[0x2c8];
    char unk_bec[0xc58 - 0xbec];
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[FinishFile_Count];
    char finishEffectVramState_[0x70];
    Object3D finishEffect_;
    unsigned char selection_;
    unsigned char windowInput_;
    char unk_d86[2];
    PartyMemberData* characterData_;
    char unk_d8c[0xd96 - 0xd8c];
    short waitTimer_;
    short dimTimer_;
    char unk_d9a[2];
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
    unsigned int* globalFlags = GetDataPtr02114e04_020d6c00();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader == NULL)
        return;
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    CharacterCreationUI_UpdateDim(self, ticks);
    if (CharacterCreationUI_UpdateWaitTimer(self, ticks) > 0)
        return;

    switch (arg0->unknown_c59_)
    {
    case FinishStep_Start:
    {
        self->flags_ &= ~CreationFlag_StylusRotation;
        self->targetAngle_ = CreationAngle_Finish;
        self->flags_ |= CreationFlag_TurnToTarget;
        Vec3 position = CharacterCreationUI_finishCameraPosition;
        Vec3 target = CharacterCreationUI_finishCameraTarget;
        Camera_EasePositionTo(self->camera_, (int)&position, CreationCamera_EaseSteps);
        Camera_EaseTargetTo(self->camera_, (int)&target, CreationCamera_EaseSteps);
        self->dimTimer_ = FinishTicks_Dim;
        self->flags_ |= CreationFlag_DimBackground;
        DispatchContextByState0209c678((Actor0209c678*)data_02109bf4, 120);
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
        if (Camera_IsEasing(self->camera_) != 0)
            break;
        self->flags_ |= CreationFlag_DimWithQuad;
        if (CharacterModel_GetBody(self->character_)->normalizedAnimationTime_ >= FinishStartAnimationTime)
        {
            SetForwardAndStore0205ebc0(&g_sePlayer, 0x6f, 0x6f);
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
            if (*var21 == -1)
                continue;
            if (var4->GetTaskStatus(*var21) == 1)
            {
                unsigned int var23 = 0;
                void* var24 = NULL;
                var4->GetLoadedFileByID(*var21, &var24, &var23);
                ObjectArchiveLoadInfo var25;
                var25.unk_0 = 0;
                var25.allocator = NULL;
                var25.unk_14 = 0;
                var25.unk_18 = 0;
                var25.unk_10 = 0;
                var25.packageID = 0;
                var25.fileData = var24;
                var25.unk_8 = var23;
                switch (var22)
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
                    CopyInternalFields0207df50((Foo0207df50*)self->finishEffectVramState_);
                    VramState_Restore(self->finishEffectVramState_);
                    self->finishEffect_.LoadFromCHRArchive(&info);
                    VramState_Save(self->finishEffectVramState_);
                    break;
                }
            }
            var4->RemoveTask(*var21);
            *var21 = -1;
        }
        self->step_ = FinishStep_ModelsLoaded;
        body->StopCurrentAnimation();
        body->MaybeSetRegularAnimation(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
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
        self->wings_.MaybeSetRegularAnimation(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)body + 0x408))->position_;
        self->finishEffect_.rotation_ = rotation;
        self->finishEffect_.position_ = position;
        self->finishEffect_.StopCurrentAnimation();
        self->finishEffect_.MaybeSetRegularAnimation(CharacterCreationUI_finishEffectAnimation, 0);
#else
        Object3D* wings = &self->wings_;
        wings->SetScale(scaleX, scaleY, scaleZ);
        wings->rotation_ = rotation;
        wings->StopCurrentAnimation();
        wings->MaybeSetRegularAnimation(KeyTable_Get((Container020e0310*)self->texts_, FinishText_Animation), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)body + 0x408))->position_;
        Object3D* finishEffect = &self->finishEffect_;
        finishEffect->rotation_ = rotation;
        finishEffect->position_ = position;
        finishEffect->StopCurrentAnimation();
        finishEffect->MaybeSetRegularAnimation(CharacterCreationUI_finishEffectAnimation, 0);
#endif
        self->flags_ |= CreationFlag_ShowFinishModels;
        self->waitTimer_ = FinishTicks_ShowModels;
        self->step_ = FinishStep_PlaySound;
        break;
    }
    case FinishStep_PlaySound:
        DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
        self->waitTimer_ = FinishTicks_BeforeWhite;
        self->step_ = FinishStep_FadeToWhite;
        break;
    case FinishStep_FadeToWhite:
        OrBitsIntoField0_020466e4(globalFlags, 0x100);
        SetBrightness(resources, Brightness_White, FinishTicks_FadeToWhite);
        DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 1, 0);
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
        func_020c39a0(&REG_MASTER_BRIGHT, Brightness_Black);
        func_020c39a0(&REG_MASTER_BRIGHT_SUB, Brightness_Black);
        ClearFlags020466f4((FlagWord020466f4*)globalFlags, 0x100);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, BLEND_TARGET_BG_AND_OBJ, Brightness_Normal);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG_AND_OBJ, Brightness_Normal);
        ForwardField0xc0_0205ebec(&g_sePlayer);
        self->step_ = FinishStep_Leave;
        break;
    case FinishStep_Leave:
        self->step_ = FinishStep_Done;
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        break;
    }
}
