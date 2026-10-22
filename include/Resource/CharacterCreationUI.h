#pragma once

#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CreationSlotLayout.h"

struct Struct_0205ac40;
struct Struct_0205ac40_2;
struct Struct_0205a254;

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
    CreationFlag_RefreshSummary = 0x100, // rebuild the info window's list of choices (Gender: Male, ...)
    CreationFlag_MemberCreated = 0x400, // mode 1: a party member was created (tab 9); backing out clears it
    CreationFlag_NameAccepted = 0x800, // CharacterCreationUI_CheckName passed the name
    CreationFlag_RedrawPanel = 0x2000, // redraw the bottom screen's panel (the keyboard's page, a message)
    CreationFlag_RefreshName = 0x8000, // redraw the Name line of the info window
    CreationFlag_NameRejected = 0x400000, // CharacterCreationUI_CheckName refused the name: its message shows
    CreationFlag_HideButtons = 0x1000000, // leave the Confirm and Back button sprites off
};

// CharacterCreationUI::state: the current tab. Each tab's confirm goes to the next tab and back to the
// previous one; name entry's confirm goes to Confirm, and the gender tab's back to Close.
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
    CreationTab_Confirm = 9,       // yes/no on the finished character
    CreationTab_NewGameFinish = 10, // new game only: the hero turns to the front, fade out
    CreationTab_Close = 11,        // leave character creation
    CreationTab_Done = 12,
};

// A name: the buffer each sex's name is typed into, and how many characters it holds.
enum CreationName
{
    CreationName_BufferSize = 0x48,
    CreationName_MaxLength = 8,
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

struct Struct_0201099c_3 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    Struct_02000c9c_6* unknown_4_;
};

struct Struct_02000c9c_7 {
    unsigned char unknown_0_[0x10];
    void* unknown_10_;
    void* unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
};

struct Struct_ov023_021d9c7c {
    unsigned char unknown_0_[4];
    int unknown_4_[20];
    int unknown_54_[16];
    unsigned char unknown_94_[4];
    Struct_02000c9c_7* unknown_98_;
    void* unknown_9c_;
    short unknown_a0_[8];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
    unsigned int unknown_b8_;
};

struct Struct_ov009_02188c2c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_, unknown_c_;
    unsigned char unknown_10_;
    unsigned char unknown_11_[3];
    int unknown_14_;
    int unknown_18_, unknown_1c_;
    int* unknown_20_;
    int* unknown_24_;
    int* unknown_28_;
    int* unknown_2c_;
    unsigned int unknown_30_;
    short unknown_34_;
    unsigned char unknown_36_[6];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_[2];
};

struct CharacterCreationUI {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
#else
    SafeAllocator unknown1_0_[9];
#endif
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
#if defined(jpn)
    unsigned char unknown_a8_[0xc0 - 0xa8];
#else
    unsigned char unknown_bc_[0xe0 - 0xbc];
#endif
    Struct_0201099c_3 unknown_e0_;
    unsigned char unknown_e8_[0x10];
    char* unknown_f8_;
#if defined(jpn)
    unsigned char unknown_dc_[0x11c - 0xdc];
#else
    unsigned char unknown_fc_[0x158 - 0xfc];
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
    char unknown_d74_[2][11];
    unsigned char unknown_d8a_[2];
    unsigned char unknown1_d8c_;
    signed char unknown_d8d_;
    signed char unknown_d8e_;
#endif
};
