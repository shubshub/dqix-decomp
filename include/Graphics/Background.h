#pragma once

// One screen of a background layer: the 16-byte record an SCRN file becomes (BackgroundScreen_Flush / _Upload).
struct BackgroundScreen {
    short width_;                  // in tiles
    short height_;
    unsigned char unk_4;
    unsigned char unk_5;
    unsigned short unk_6;
    unsigned int tilesSize_;       // bytes at tiles_: the SCRN file's data size (BackgroundScreen_Flush, DeserializeAndAllocate)
    unsigned short* tiles_;        // width_ x height_ map entries
};

// A background layer (0x20 bytes): one BG of the main or sub engine, with its character data and palette, the screens
// its SCRN files became and the map that is transferred to VRAM. Background_Init clears it.
struct BackgroundGraphics {
    int characterOffset_;          // where its character data goes: the offset its CHAR load function is called with
    unsigned char unk_4[8];        // the rest of the CHAR file's header (TileHeader_Flush copies it)
    unsigned char unk_c;           // the PALT file's byte 4 (Background_LoadPalette)
    unsigned char unk_d;
    unsigned short paletteMask_;   // 0xffff loads the whole PALT file, otherwise bit N loads its 32-byte palette N
    BackgroundScreen* screens_;    // screenCapacity_ records (Background_AllocateScreens)
    unsigned short* map_;          // BackgroundMap_Columns entries a row (Background_AllocateMap)
    unsigned int mapSize_;         // the column of Background_mapSizes (Background_SetMapSize)
    unsigned char subScreen_ : 4;  // 0 main engine, 1 sub engine: the row of the [subScreen][bg] function tables
    unsigned char bgNumber_ : 4;   // BG 0-3: the column
    unsigned char screenCount_;    // screens loaded (Background_LoadFile)
    unsigned char screenCapacity_;
    unsigned char mapType_;        // the row of Background_mapSizes: 0 text, 1 affine
};

// How Background_FillRect, _SetRectPalette and _CopyScreenRect address a map: 32 entries a row, clipped at 25 rows;
// 24 rows are one 192-pixel screen.
enum BackgroundMap
{
    BackgroundMap_Columns = 32,
    BackgroundMap_ScreenRows = 24,
    BackgroundMap_Rows = 25,
};

// The palette argument that keeps each map entry's own palette (bits 12-15); any other value replaces it.
enum BackgroundPalette
{
    BackgroundPalette_Keep = 0xffff,
};

// A VRAM load function (LoadToMainBG0CharacterData, ...): (source, offset, size).
typedef void (*BackgroundLoadFunction)(const void* source, int offset, unsigned int size);

// The archive file tags, "CHAR", "PALT" and "SCRN" (Background_LoadFile, _FlushFile, _UploadFile compare 4 bytes).
extern char Background_charTag[];
extern char Background_paltTag[];
extern char Background_scrnTag[];

// The function tables, indexed [subScreen_][bgNumber_] (ROM).
// LoadToMainBG0..3CharacterData, LoadToSubBG0..3CharacterData.
extern BackgroundLoadFunction Background_loadCharacterFunctions[2][4];
// LoadToMainBGStandardPalette, LoadToSubBGStandardPalette: by subScreen_ only.
extern BackgroundLoadFunction Background_loadPaletteFunctions[2];
// LoadToMainBG0..3ScreenData, LoadToSubBG0..3ScreenData.
extern BackgroundLoadFunction Background_loadScreenFunctions[2][4];
// SetBg0..3Priority, SetSubBg0..3Priority.
extern int (*Background_setPriorityFunctions[2][4])(int priority);
// SetMainBG0..3Scroll, SetSubBG0Scroll, SetSubBg1..3Offset.
extern int (*Background_setScrollFunctions[2][4])(int x, int y);

// A map's size in bytes, [mapType_][mapSize_]: text 0x800, 0x1000, 0x1000, 0x2000; affine 0x200, 0x800, 0x2000, 0x8000.
extern unsigned int Background_mapSizes[2][4];
