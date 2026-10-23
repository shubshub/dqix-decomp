#pragma once

#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CreationSlotLayout.h"
#include "Resource/CreationEnums.h"

struct SpriteContext0205ac40;
struct Keyboard;
struct KeyboardKey;
struct B174Outer;
struct Container0205a3d0;

// {tab, x, y, width, height, stepX, stepY, columns, rows} per tab, ending in -1. Defined in C for usa only.
extern const short CharacterCreationUI_slotLayouts[];

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

struct CreationWindow {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    CreationTileMap* layers;        // Window_ClearLayers / _FlushLayers / _TransferLayers loop over these
    void* panes;                    // set by Window_SetPanes
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char layerCount;
    unsigned char paneCount;        // set by Window_SetPanes
    unsigned char count;
    unsigned char flags;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
    unsigned int pendingClose;      // pane Window_Update closes, 0xff for none
};

// A GridCursor over a tab's slots; field names as GridCursor_Update (the cursor's per-frame D-pad update) uses them.
struct CreationNavigation {
    int count;
    int pageCount;
    int columns, rows;
    unsigned char order;            // GridCursorOrder
    unsigned char unknown11[3];
    int page;
    int column, row;
    int* primaryDimension;
    int* secondaryDimension;
    int* primaryCursor;
    int* secondaryCursor;
    int step;                       // -1 or 1, the direction of the held key
    unsigned short heldKey;         // KEY_UP, KEY_DOWN, KEY_LEFT or KEY_RIGHT
    unsigned char rowRepeat, columnRepeat;
    unsigned char countdown;        // ticks to the next repeat
    unsigned char initialDelay;     // 20
    unsigned char repeatDelay;      // 10
    unsigned char unknown3b;
    unsigned char wrapColumns, wrapRows;
    unsigned char unknown3e[2];
};

struct CharacterCreationUI {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
#else
    SafeAllocator unknown1_0_[9];
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
#if defined(jpn)
    unsigned char nameFilter[0x20]; // jpn's name checker is a different object
#else
    unsigned char nameFilter[0x3c]; // NameFilter: the forbidden-word files and pattern characters
#endif
    CreationTileMap layers[6];      // main BG1 backdrop, BG2 tab highlight, BG3 summary text; sub BG0 page, BG1 selection, BG2 text
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
    void* characterModels[2];       // the two CharacterModels that character and nextCharacter point into
    void* character;
    void* nextCharacter;
    unsigned int unknown800;
    int targetAngle;
    unsigned char wingsVramState[0x70]; // texture/palette VRAM reserved for model
    Object3D wings;                 // new game finish: the wings and halo (d_hane)
    unsigned char camera[0x2c8];
    CreationNavigation navigation;
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
    unsigned char windowInput;      // what windows[1]'s update returned: 1 moved, 2 the stylus slid onto another item
    unsigned char unknownAfterWindowInput[2];
    void* characterData;
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
