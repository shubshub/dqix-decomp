#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" int LoadToMainBG0CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToMainBG2CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToMainBG3CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToSubBG0CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToSubBG1CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToSubBG2CharacterData(int source, int offset, unsigned int size);
extern "C" int LoadToSubBG3CharacterData(int source, int offset, unsigned int size);

// bgTransfers (data_02105254) starts with each screen's next free byte in BG character VRAM; the next free tile
// index of each screen follows 0x20 bytes later.
// Main, originally DispatchCharTransfer0203b784 (USA 0x0203b784, EUR 0x0203b794, JPN 0x0203b1dc)
extern "C" ARM int BgTransfers_LoadTiles(int* bgTransfers, int screen, int bg, int source, unsigned int size, unsigned int tileCount) {
    int* tileCursors = (int*)((char*)bgTransfers + 0x20);
    int byteOffset = bgTransfers[screen];
    bgTransfers[screen] = byteOffset + size;
    int firstTile = *(int*)((char*)&bgTransfers[screen] + 0x20);
    int tileCursor = tileCursors[screen];
    tileCursors[screen] = tileCursor + tileCount;
    CleanInvalidateCacheRange((void*)source, size);
    switch (screen) {
    case 0:
        switch (bg) {
        case 0: LoadToMainBG0CharacterData(source, byteOffset, size); break;
        case 1: LoadToMainBG1CharacterData(source, byteOffset, size); break;
        case 2: LoadToMainBG2CharacterData(source, byteOffset, size); break;
        case 3: LoadToMainBG3CharacterData(source, byteOffset, size); break;
        }
        break;
    case 1:
        switch (bg) {
        case 0: LoadToSubBG0CharacterData(source, byteOffset, size); break;
        case 1: LoadToSubBG1CharacterData(source, byteOffset, size); break;
        case 2: LoadToSubBG2CharacterData(source, byteOffset, size); break;
        case 3: LoadToSubBG3CharacterData(source, byteOffset, size); break;
        }
        break;
    }
    return firstTile;
}
