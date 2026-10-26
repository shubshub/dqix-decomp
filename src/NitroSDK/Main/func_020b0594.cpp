#include <globaldefs.h>

#include "NitroSDK/Cache.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"

extern "C" void func_020b0334(int *array, int index, int value);

struct Struct_020b0594 {
    unsigned short height;
    unsigned short width;
    int format;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int dataSize;
    void *data;
};

struct Struct_020b0594_2 {
    int offsets[3];
    int unknown_c_;
    int unknown_10_;
    int format;
    int unknown18;
    int enabled;
    unsigned int unknown_20_;
};

// USA: func_020b0594
extern "C" ARM void func_020b0594(int resource, int offset, int arg2, void *object) {
    Struct_020b0594 *character = (Struct_020b0594 *) resource;
    Struct_020b0594_2 *state      = (Struct_020b0594_2 *) object;
    unsigned int var2                 = character->unknown_8_;

    if (arg2 != 0) {
        switch (arg2) {
            case 1: DISPCNT = (DISPCNT & 0xffcfffef) | var2; break;
            case 2: DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | var2; break;
        }
    }

    CleanInvalidateCacheRange(character->data, character->dataSize);
    switch (arg2) {
        case 0:
            MemoryMapTextureImage();
            LoadToTextureImage(character->data, offset, character->dataSize);
            MemoryUnmapTextureImage();
            break;
        case 1: LoadToMainObjVRAM(character->data, offset, character->dataSize); break;
        case 2: LoadToSubObjVRAM(character->data, offset, character->dataSize); break;
    }

    if (character->unknown_8_ == 0) {
        int var3;
        switch (character->width) {
            case 1: var3 = 0; break;
            case 2: var3 = 1; break;
            case 4: var3 = 2; break;
            case 8: var3 = 3; break;
            case 16: var3 = 4; break;
            case 32: var3 = 5; break;
            default: var3 = 0; break;
        }
        state->unknown_c_ = var3;

        int var4;
        switch (character->height) {
            case 1: var4 = 0; break;
            case 2: var4 = 1; break;
            case 4: var4 = 2; break;
            case 8: var4 = 3; break;
            case 16: var4 = 4; break;
            case 32: var4 = 5; break;
            default: var4 = 0; break;
        }
        state->unknown_10_ = var4;
    } else {
        state->unknown_c_  = character->width;
        state->unknown_10_ = character->height;
    }

    state->format      = character->format;
    state->unknown18   = 0;
    state->enabled     = 1;
    state->unknown_20_ = character->unknown_8_;
    func_020b0334(state->offsets, arg2, offset);
}
