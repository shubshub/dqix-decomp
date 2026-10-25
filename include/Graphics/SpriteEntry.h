#pragma once

// One 0x18-byte entry of a sprite entry list ({entries, count}, SpriteContext::spriteEntries_).
struct SpriteEntry {
    unsigned char unknown0[4];
    short x, y;                     // SpriteEntryList_SetPosition
    unsigned short key;             // what SpriteEntryList_Find looks entries up by
    unsigned char unknownA[6];
    unsigned short frame;           // SpriteEntryList_PlayAnimation rewinds both to 0
    unsigned short elapsed;
    unsigned char firstObject;      // SpriteEntryList_SetFirstObject
    unsigned char flags;            // bits 0-2 the animation state, SpriteEntryFlag
    unsigned char unknown16[2];
};

// SpriteEntry::flags bits.
enum SpriteEntryFlag
{
    SpriteEntryFlag_Shown = 8,      // SpriteContext_DrawEntries draws the entry (func_0205addc tests it)
};
