#pragma once

#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CreationSlotLayout.h"

struct SpriteContext0205ac40;
struct B174Outer;
struct Container0205a3d0;

// {tab, x, y, width, height, stepX, stepY, columns, rows} per tab, ending in -1. Defined in C for usa only.
extern const short CharacterCreationUI_slotLayouts[];

// CharacterCreationUI::mode: why character creation was opened (the constructor's third argument).
enum CreationMode
{
    CreationMode_NewGame = 0,             // the hero, from the new-game flow (overlay 21)
    CreationMode_PartyMemberCreation = 1, // a new party member, in-game (overlay 3)
};

// Bits of CharacterCreationUI::flags whose meaning is known; the rest are still bare numbers.
enum CreationFlag
{
    CreationFlag_StylusRotation = 0x1, // the preview model can be spun with the stylus
    CreationFlag_ChoiceChanged = 0x10, // the input handler stored a different choice this frame
    CreationFlag_ConfirmTouched = 0x20, // the confirm button was touched this frame
    CreationFlag_BackTouched = 0x40,    // the back button was touched this frame
    CreationFlag_TabLoading = 0x80,    // set on going to a tab, cleared once its graphics have loaded
    CreationFlag_MemberCreated = 0x400, // mode 1: a party member was created (tab 9); backing out clears it
};

// CharacterCreationUI::state: the current tab. Each tab's confirm goes to the next tab and back to the
// previous one; 9-11 aren't identified yet (name entry's confirm goes to 9, the gender tab's back to 11).
enum CreationTab
{
    CreationTab_Setup = 0,
    CreationTab_Gender = 1,
    CreationTab_BodyType = 2,
    CreationTab_HairStyle = 3,
    CreationTab_HairColor = 4,
    CreationTab_Face = 5,
    CreationTab_EyeColor = 6,
    CreationTab_SkinColor = 7,
    CreationTab_NameEntry = 8,
    CreationTab_Done = 12,
};

// What CharacterCreationUI_HandleInput returns. A tab icon comes back as CreationInput_TabIcon + its tab.
enum CreationInput
{
    CreationInput_Back = -3,
    CreationInput_Confirm = -2,
    CreationInput_None = -1,
    CreationInput_TabIcon = 100,
    CreationInput_FirstTabIcon = CreationInput_TabIcon + CreationTab_Gender,
    CreationInput_LastTabIcon = CreationInput_TabIcon + CreationTab_NameEntry,
};

struct CreationTextEntry {
    int key;
    const char* text;
};

struct Container020e0310 {
    unsigned int count : 12;
    unsigned int unknown : 20;
    CreationTextEntry* entries;
};

struct CreationTileMap {
    unsigned char unknown[0x10];
    void* entries;
    void* buffer;
    unsigned int sizeIndex;
    unsigned char flags;
    unsigned char entryCount;
    unsigned char unknown1e;
    unsigned char sizeTable;
};

struct CreationWindow {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    CreationTileMap* tileMaps;
    void* elements;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char tileMapCount;
    unsigned char capacity;
    unsigned char count;
    unsigned char flags;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
    unsigned int unknownB8;
};

struct CreationNavigation {
    int count;
    int field4;
    int columns, rows;
    unsigned char mode;
    unsigned char unknown11[3];
    int page;
    int column, row;
    int* primaryDimension;
    int* secondaryDimension;
    int* primaryCursor;
    int* secondaryCursor;
    unsigned int input;
    short counter;
    unsigned char unknown36[6];
    unsigned char flags3c;
    unsigned char flags3d;
    unsigned char unknown3e[2];
};

struct CharacterCreationUI {
#if defined(jpn)
    SafeAllocator allocators[8];
#else
    SafeAllocator allocators[9];
#endif
    SafeAllocator* modelAllocator;
    SafeAllocator* previewAllocators;
#if defined(jpn)
    unsigned char unknownBeforeTexts[0xc0 - 0xa8];
#else
    unsigned char unknownBeforeTexts[0xe0 - 0xbc];
#endif
    Container020e0310 texts;
    unsigned char unknownBeforeTextBuffer[0x10];
    char* textBuffer;
#if defined(jpn)
    unsigned char unknownBeforeTileMaps[0x11c - 0xdc];
#else
    unsigned char unknownBeforeTileMaps[0x158 - 0xfc];
#endif
    CreationTileMap tileMaps[4];
    unsigned char unknownBeforeWindows[0x20];
    CreationWindow windows[2];
    unsigned char unknownBeforeSprites[0x7d8 - 0x370];
    SpriteContext0205ac40* firstSpriteContext;
    B174Outer* firstSprites;
    Container0205a3d0* firstSpriteEntries;
    SpriteContext0205ac40* spriteContext;
    B174Outer* sprites;
    Container0205a3d0* spriteEntries;
    unsigned char unknownBeforeCharacter[0x7f8 - 0x7f0];
    void* character;
    void* nextCharacter;
    unsigned int unknown800;
    int targetAngle;
    unsigned char unknownBeforeModel[0x70];
    Object3D model;
    unsigned char camera[0x2c8];
    CreationNavigation navigation;
    CreationSlotLayout grid;
    short cursorX, cursorY;
    short cursorWidth, cursorHeight;
    short lastCursorX, lastCursorY;
    signed char state;
    unsigned char step;
    unsigned char unknownBeforeSecondModel[0x7e];
    Object3D secondModel;
    unsigned char selection;
    unsigned char unknownAfterSelection[3];
    void* characterData;
    int touchedChoice;
    int resourceTask;
    unsigned char resourceStep;
    unsigned char mode;
    unsigned char unknownBeforeFlags[6];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyType[2];
    unsigned char faceStyle[2];
    unsigned char skinColor[2];
    unsigned char eyeColor[2];
    unsigned char hairStyle[2];
    unsigned char hairColor[2];
#if defined(jpn)
    char names[2][11];
    unsigned char nameFlags[2];
    unsigned char keyboardChoice;
    signed char keyboardPage;
    signed char previousKeyboardPage;
#endif
};
