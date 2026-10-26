#include <globaldefs.h>
#include "Combat/MapDisplay.h"

// {5, 6, 7, 8, -1}: indices into MapDisplay::records, ended by a negative entry
extern signed char data_020e7039;

void SpriteContext_SetSpriteObjMode(int spriteContext, void* sprite, int objMode);

enum { ObjMode_Normal = 0 };

// USA: func_02026ebc
ARM void ApplyBitfieldsForTableEntries02026ebc(void* displayPtr) {
    MapDisplay* display = (MapDisplay*)displayPtr;
    unsigned char i = 0;
    signed char spriteIndex;
    while ((spriteIndex = (&data_020e7039)[i]) >= 0) {
        SpriteContext_SetSpriteObjMode((int)&display->entryList, &display->records[spriteIndex], ObjMode_Normal);
        i = (unsigned char)(i + 1);
    }
}
