#pragma once

#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Background.h"
#include "Resource/CreationSlotLayout.h"
#include "Resource/CreationEnums.h"
#include "Resource/GridCursor.h"
#include "Resource/NameFilter.h"

struct SpriteContext0205ac40;
struct Keyboard;
struct KeyboardKey;
struct B174Outer;
struct Container0205a3d0;
struct CharacterModel;
struct PartyMemberData;

// {tab, x, y, width, height, stepX, stepY, columns, rows} per tab, ending in -1. Defined in C for usa only.
extern const short CharacterCreationUI_slotLayouts[];

struct Struct_02000c9c_6 {
    int key;
    const char* text;
};

struct Container020e0310 {
    unsigned int count : 12;
    unsigned int unknown : 20;
    Struct_02000c9c_6* entries;
};

struct CreationWindow {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    BackgroundGraphics* layers;     // Window_ClearLayers / _FlushLayers / _TransferLayers loop over these
    void* panes;                    // set by Window_SetPanes
    short paneWidth;                // what Window_OpenPane copies into the pane it opens: its width and height in
    short paneHeight;               // tiles (func_0204c980: the text is width * 8 pixels wide, the map width * height)
    short unknownA4[2];
    short paneTextX;                // the pane's text x (func_0204c980 passes it to MessageSystem_FormatText)
    short unknownAa[3];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
    unsigned char paneCount;        // set by Window_SetPanes
    unsigned char count;
    unsigned char flags;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
    unsigned char pendingClose;     // pane Window_Update closes, 0xff for none (read and written as a byte)
    unsigned char unknownB9[3];
};

struct CharacterCreationUI {
#if defined(jpn)
    SafeAllocator allocators[8];
#else
    SafeAllocator allocators[9];
#endif
    SafeAllocator* modelAllocator;
    SafeAllocator* previewAllocators;
#if !defined(jpn)
    struct KeyboardKey* savedKey;   // the keyboard's key while the cursor is on the tab icons
    struct Keyboard* keyboard;
    void* keyboardLayout;           // the key list keyboard_cm.bin / keyboard_cs.bin builds
#endif
    unsigned char itemTable[0x18];  // the item records of CharacterCreationUI_itemIds, from itemdt
    Container020e0310 texts;
    unsigned char unknownBeforeTextBuffer[0x10];
    char* textBuffer;
    NameFilter nameFilter;
    BackgroundGraphics layers[6];   // main BG1 backdrop, BG2 tab highlight, BG3 summary text; sub BG0 page, BG1 selection, BG2 text
    CreationWindow windows[2];      // [0] the summary list (main screen), [1] the bottom screen's text
    unsigned char window0Panes[1][0xe0];
    unsigned char window1Panes[4][0xe0];
    void* windowBuffers[2];         // the panes' text buffers
    SpriteContext0205ac40* mainSpriteContext; // subScreen 0: 6 sprites (the summary pointer)
    B174Outer* mainSprites;
    Container0205a3d0* mainSpriteEntries;
    SpriteContext0205ac40* subSpriteContext;  // subScreen 1: 25 sprites (buttons, tab icons, cursors)
    B174Outer* subSprites;
    Container0205a3d0* subSpriteEntries;
    CharacterModel* characterModels[2]; // the two models; character and nextCharacter point at them
    CharacterModel* character;
    CharacterModel* nextCharacter;
    unsigned int unknown800;
    int targetAngle;
    unsigned char wingsVramState[0x70]; // texture/palette VRAM reserved for model
    Object3D wings;                 // new game finish: the wings and halo (d_hane)
    unsigned char camera[0x2c8];
    GridCursor navigation;          // over the tab's slots
    CreationSlotLayout grid;
    short cursorX, cursorY;
    short cursorWidth, cursorHeight;
    short lastCursorX, lastCursorY;
    signed char state;
    unsigned char step;
    unsigned char unknownAfterStep[2];
    int modelTasks[3];              // loader tasks for the new-game finish's model files
    unsigned char finishEffectVramState[0x70];
    Object3D finishEffect;          // new game finish: the glowing rings (ev999993000.chr)
    unsigned char selection;
    unsigned char windowInput;      // what windows[1]'s update returned (WindowInput)
    unsigned char unknownAfterWindowInput[2];
    PartyMemberData* characterData;
    int touchedChoice;
    int resourceTask;
    unsigned char resourceStep;
    unsigned char mode;
    short waitTimer;                // CharacterCreationUI_UpdateWaitTimer counts it down
    short dimTimer;                 // ticks left of CreationFlag_DimBackground's fade
    unsigned char unknownBeforeFlags[2];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyType[2];
    unsigned char faceStyle[2];
    unsigned char eyeColor[2];
    unsigned char skinColor[2];
    unsigned char hairStyle[2];
    unsigned char hairColor[2];
#if defined(jpn)
    char names[2][11];
    unsigned char nameLengths[2];   // two-byte characters typed, up to 5
    unsigned char keyboardChoice;
    signed char keyboardPage;
    signed char previousKeyboardPage;
    unsigned char nameTabFlushPass; // as usa's
#else
    char** names;                   // each sex's name buffer (CreationName_BufferSize)
    unsigned char nameFill;         // font-0 index of "*", padding the shown name
    unsigned char keyboardResult;   // Keyboard_Update's KeyboardResult this frame
    unsigned char nameTabFlushPass; // name tab graphics: 1 while this frame only flushes, 0 when it uploads
#endif
};
