#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"
#include "World/Object3D.h"
#include "Resource/CreationSlotLayout.h"

struct Struct_0201099c_14 {
    char unknown_0_[0x18];
};

struct Struct_0205cfd4 {
    char unknown_0_[0xbc];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xe0];
};

struct Struct_0205bef8 {
    int unknown_0_[0x10];
};

unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ItemTable_Init(void* table);
void KeyTable_Reset(Struct020dfc40* table);
extern "C" void NameFilter_Reset(void* checker);
void Background_Init(List0204af64* background);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
extern "C" void func_0204c684(Canvas* canvas);
void GridCursor_Init(Struct_0205bef8* cursor);
void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout* grid);
int Font_FindCharacterIndex(int text, int mode);

extern char CharacterCreationUI_nameFillText[];

struct Struct_ov009_021842a0_2 {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
#else
    SafeAllocator unknown_0_[9];
#endif
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
#if !defined(jpn)
    void* savedKey_;
    void* keyboard_;
    void* keyboardLayout_;
#endif
    char itemTable_[0x18];
    Struct020dfc40 texts_;
    void* textBuffer_;
#if defined(jpn)
    char nameFilter_[0x20];
#else
    char nameFilter_[0x3c];
#endif
    List0204af64 layers_[6];
    InitTarget0205cfd4 windows_[2];
    Canvas window0Panes_[1];
    Canvas window1Panes_[4];
    void* windowBuffer0_;
    void* windowBuffer1_;
    void* mainSpriteContext_;
    void* mainSprites_;
    void* mainSpriteEntries_;
    void* subSpriteContext_;
    void* subSprites_;
    void* subSpriteEntries_;
    void* characterModels_[2];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char wingsVramState_[0x70];
    Object3D wings_;
    char camera_[0x2c8];
    Struct_0205bef8 navigation_;
    CreationSlotLayout grid_;
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastCursorX_;
    short lastCursorY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[3];
    char finishEffectVramState_[0x70];
    Object3D finishEffect_;
    unsigned char selection_;
    unsigned char windowInput_;
    char unk_d86[2];
    void* characterData_;
    int touchedChoice_;
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    short waitTimer_;
    short dimTimer_;
    char unk_d9a[2];
    unsigned int flags_;
    signed char furthestState_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char faceStyle_[2];
    unsigned char eyeColor_[2];
    unsigned char skinColor_[2];
    unsigned char hairStyle_[2];
    unsigned char hairColor_[2];
#if defined(jpn)
    char names_[2][11];
    unsigned char nameLengths_[2];
    unsigned char keyboardChoice_;
    unsigned char keyboardPage_;
    unsigned char previousKeyboardPage_;
    char nameTabFlushPass_;
#else
    char** names_;
    unsigned char nameFill_;
    unsigned char keyboardResult_;
    unsigned char nameTabFlushPass_;
    char unk_db7;
#endif
};

// Overlay 9, originally func_ov009_0218454c (USA/EUR 0x0218454c, JPN 0x021855a8)
extern "C" ARM void CharacterCreationUI_Init(CharacterCreation* self, int vocation, int mode)
{
    self->mode_ = mode;
    if (self->mode_ == CreationMode_PartyMemberCreation)
        OrBitsIntoField0_020466e4(GetDataPtr02114e04_020d6c00(), 0xf);
    self->allocators_[0].ResetAllocatorPointer();
    self->allocators_[1].ResetAllocatorPointer();
    self->allocators_[2].ResetAllocatorPointer();
    self->allocators_[3].ResetAllocatorPointer();
    self->allocators_[4].ResetAllocatorPointer();
    self->allocators_[5].ResetAllocatorPointer();
    self->allocators_[6].ResetAllocatorPointer();
    self->allocators_[7].ResetAllocatorPointer();
#if !defined(jpn)
    arg0->unknown_0_[8].ResetAllocatorPointer();
#endif
    arg0->unknown_b4_ = NULL;
    arg0->unknown_b8_ = NULL;
#if !defined(jpn)
    self->keyboard_ = NULL;
    self->keyboardLayout_ = NULL;
#endif
    ItemTable_Init(&self->itemTable_);
    KeyTable_Reset(&self->texts_);
    self->textBuffer_ = NULL;
    NameFilter_Reset(&self->nameFilter_);
    Background_Init(&self->layers_[0]);
    Background_Init(&self->layers_[1]);
    Background_Init(&self->layers_[2]);
    Background_Init(&self->layers_[3]);
    Background_Init(&self->layers_[4]);
    Background_Init(&self->layers_[5]);
    InitStruct0205cfd4(&self->windows_[0]);
    InitStruct0205cfd4(&self->windows_[1]);
    for (int i = 0; i < 1; i++)
        func_0204c684(&self->window0Panes_[i]);
    for (int i = 0; i < 4; i++)
        func_0204c684(&self->window1Panes_[i]);
    self->windowBuffer0_ = NULL;
    self->windowBuffer1_ = NULL;
    self->mainSpriteContext_ = NULL;
    self->mainSprites_ = NULL;
    self->mainSpriteEntries_ = NULL;
    self->subSpriteContext_ = NULL;
    self->subSprites_ = NULL;
    self->subSpriteEntries_ = NULL;
    self->characterModels_[0] = NULL;
    self->characterModels_[1] = NULL;
    self->character_ = NULL;
    self->nextCharacter_ = NULL;
    self->unk_800 = 0;
    self->targetAngle_ = 0;
    self->wings_.Initialize();
    self->finishEffect_.Initialize();
    GridCursor_Init(&self->navigation_);
    CharacterCreationUI_ResetTargetLayout(&self->grid_);
    self->cursorX_ = -1;
    self->cursorY_ = -1;
    self->cursorWidth_ = -1;
    self->cursorHeight_ = -1;
    self->lastCursorX_ = -1;
    self->lastCursorY_ = -1;
    self->state_ = 0;
    self->step_ = 0;
    self->selection_ = 0;
    self->windowInput_ = 0;
    self->characterData_ = NULL;
    self->touchedChoice_ = -1;
    self->resourceTask_ = 0;
    self->resourceStep_ = 0;
    self->waitTimer_ = 0;
    self->dimTimer_ = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    for (int i = 0; i < 2; i++)
        self->furthestState_[i] = CreationTab_Gender;
    self->vocation_ = vocation;
    self->sex_ = 0;
    for (int i = 0; i < 2; i++)
    {
        self->bodyType_[i] = 0;
        self->faceStyle_[i] = 0;
        self->eyeColor_[i] = 0;
        self->skinColor_[i] = 0;
        self->hairStyle_[i] = 0;
        self->hairColor_[i] = 0;
#if defined(jpn)
        memset(self->names_[i], 0, sizeof(self->names_[i]));
        self->nameLengths_[i] = 0;
#endif
    }
#if defined(jpn)
    self->keyboardChoice_ = 0;
    self->keyboardPage_ = 0;
#else
    self->names_ = NULL;
    self->nameFill_ = Font_FindCharacterIndex((int)CharacterCreationUI_nameFillText, 0);
#endif
#if defined(jpn)
    self->previousKeyboardPage_ = 0;
    self->nameTabFlushPass_ = 0;
#else
    self->nameTabFlushPass_ = 0;
#endif
}
