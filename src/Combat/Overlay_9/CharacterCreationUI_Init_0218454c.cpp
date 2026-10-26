#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"
#include "World/Object3D.h"
#include "Resource/CreationSlotLayout.h"

struct Struct020dfc40;
struct InitTarget0205cfd4;
struct GridCursor;

extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" void ItemTable_Init(void* table);
extern "C" void KeyTable_Reset(Struct020dfc40* table);
extern "C" void NameFilter_Reset(void* checker);
extern "C" void Background_Init(BackgroundGraphics* background);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void WindowPane_Init(void* pane);
extern "C" void GridCursor_Init(GridCursor* cursor);
extern "C" void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout* grid);
extern "C" int Font_FindCharacterIndex(int text, int mode);

extern char CharacterCreationUI_nameFillText[];

// Overlay 9, originally func_ov009_0218454c (USA/EUR 0x0218454c, JPN 0x021855a8)
extern "C" ARM void CharacterCreationUI_Init(CharacterCreationUI* self, int vocation, int mode)
{
    self->mode = mode;
    if (self->mode == CreationMode_PartyMemberCreation)
        FlagWord_SetBits(GlobalFlags_GetInstance(), 0xf);
    self->allocators[0].ResetAllocatorPointer();
    self->allocators[1].ResetAllocatorPointer();
    self->allocators[2].ResetAllocatorPointer();
    self->allocators[3].ResetAllocatorPointer();
    self->allocators[4].ResetAllocatorPointer();
    self->allocators[5].ResetAllocatorPointer();
    self->allocators[6].ResetAllocatorPointer();
    self->allocators[7].ResetAllocatorPointer();
#if !defined(jpn)
    self->allocators[8].ResetAllocatorPointer();
#endif
    self->modelAllocator = NULL;
    self->previewAllocators = NULL;
#if !defined(jpn)
    self->keyboard = NULL;
    self->keyboardLayout = NULL;
#endif
    ItemTable_Init(&self->itemTable);
    KeyTable_Reset((Struct020dfc40*)&self->texts);
    self->textBuffer = NULL;
    NameFilter_Reset(&self->nameFilter);
    Background_Init((BackgroundGraphics*)&self->layers[0]);
    Background_Init((BackgroundGraphics*)&self->layers[1]);
    Background_Init((BackgroundGraphics*)&self->layers[2]);
    Background_Init((BackgroundGraphics*)&self->layers[3]);
    Background_Init((BackgroundGraphics*)&self->layers[4]);
    Background_Init((BackgroundGraphics*)&self->layers[5]);
    Window_Init((InitTarget0205cfd4*)&self->windows[0]);
    Window_Init((InitTarget0205cfd4*)&self->windows[1]);
    for (int i = 0; i < 1; i++)
        WindowPane_Init(self->window0Panes[i]);
    for (int i = 0; i < 4; i++)
        WindowPane_Init(self->window1Panes[i]);
    self->windowBuffers[0] = NULL;
    self->windowBuffers[1] = NULL;
    self->mainSpriteContext = NULL;
    self->mainSprites = NULL;
    self->mainSpriteEntries = NULL;
    self->subSpriteContext = NULL;
    self->subSprites = NULL;
    self->subSpriteEntries = NULL;
    self->characterModels[0] = NULL;
    self->characterModels[1] = NULL;
    self->character = NULL;
    self->nextCharacter = NULL;
    self->unknown800 = 0;
    self->targetAngle = 0;
    self->wings.Initialize();
    self->finishEffect.Initialize();
    GridCursor_Init((GridCursor*)&self->navigation);
    CharacterCreationUI_ResetTargetLayout(&self->grid);
    self->cursorX = -1;
    self->cursorY = -1;
    self->cursorWidth = -1;
    self->cursorHeight = -1;
    self->lastCursorX = -1;
    self->lastCursorY = -1;
    self->state = 0;
    self->step = 0;
    self->selection = 0;
    self->windowInput = 0;
    self->characterData = NULL;
    self->touchedChoice = -1;
    self->resourceTask = 0;
    self->resourceStep = 0;
    self->waitTimer = 0;
    self->dimTimer = 0;
    memset(&self->flags, 0, sizeof(self->flags));
    for (int i = 0; i < 2; i++)
        self->furthestState[i] = CreationTab_Gender;
    self->vocation = vocation;
    self->sex = 0;
    for (int i = 0; i < 2; i++)
    {
        self->bodyType[i] = 0;
        self->faceStyle[i] = 0;
        self->eyeColor[i] = 0;
        self->skinColor[i] = 0;
        self->hairStyle[i] = 0;
        self->hairColor[i] = 0;
#if defined(jpn)
        memset(self->names[i], 0, sizeof(self->names[i]));
        self->nameLengths[i] = 0;
#endif
    }
#if defined(jpn)
    self->keyboardChoice = 0;
    self->keyboardPage = 0;
#else
    self->names = NULL;
    self->nameFill = Font_FindCharacterIndex((int)CharacterCreationUI_nameFillText, 0);
#endif
#if defined(jpn)
    self->previousKeyboardPage = 0;
    self->nameTabFlushPass = 0;
#else
    self->nameTabFlushPass = 0;
#endif
}
