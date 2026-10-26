#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if !defined(jpn)
struct BodyDimensions {
    short width, height;
};
extern BodyDimensions CharacterCreationUI_bodyDimensions[][5];
#endif

// Overlay 9, originally func_ov009_02188bf8 (USA/EUR 0x02188bf8, JPN 0x021899b0)
extern "C" ARM void CharacterCreationUI_GetBodyDimensions(unsigned char* storage, int bodyType, short* width, short* height) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
#if defined(jpn)
    if (self->sex == 0) {
        switch (bodyType) {
        case 0: *width = 0xeb8; *height = 0x109f; break;
        case 1: *width = 0xe35; *height = 0x1028; break;
        case 2: *width = 0xf0a; *height = 0xfae; break;
        case 3: *width = 0x1024; *height = 0xf33; break;
        case 4: *width = 0xf1e; *height = 0xeb4; break;
        }
    } else {
        switch (bodyType) {
        case 0: *width = 0xeb8; *height = 0x1051; break;
        case 1: *width = 0xe39; *height = 0xffb; break;
        case 2: *width = 0xee1; *height = 0xf85; break;
        case 3: *width = 0x1024; *height = 0xf33; break;
        case 4: *width = 0xeb8; *height = 0xeb4; break;
        }
    }
#else
    BodyDimensions* dimensions = &CharacterCreationUI_bodyDimensions[self->sex][bodyType];
    *width = dimensions->width;
    *height = dimensions->height;
#endif
}
