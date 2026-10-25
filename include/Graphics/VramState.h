#pragma once

// The frame texture VRAM manager's state: {start, end} of each of its 5 slots (NNS_GfdGetFrmTexVramState).
struct VramStateTexture { unsigned int slotBounds[10]; };
// The frame palette VRAM manager's state: its low and high addresses (NNS_GfdGetFrmPlttVramState).
struct VramStatePalette { int bounds[2]; };

// The texture and palette VRAM state VramState_Reserve saves and reserves (0x70 bytes): the managers' state at
// reserve time (start*) and the current one, and what the allocations returned. paletteKeyOffset is the low half of
// the palette allocation's key: the reserved palette's offset in texture palette VRAM, in 8-byte units.
struct VramState {
    VramStateTexture startTexture;  // at reserve time; VramState_Rewind goes back to it
    VramStateTexture texture;       // VramState_Restore / _Save
    int textureKey;                 // what the texture allocation (NNS_GfdAllocFrmTexVram) returned
    int textureSize;                // 0 if it failed
    VramStatePalette startPalette;
    VramStatePalette palette;
    union {
        int paletteKey;             // what the palette allocation (NNS_GfdAllocFrmPlttVram) returned
        struct {
            unsigned int paletteKeyOffset : 16;
            unsigned int paletteKeyUpper : 16;
        };
    };
    unsigned int paletteSize;       // 0 if it failed
};
