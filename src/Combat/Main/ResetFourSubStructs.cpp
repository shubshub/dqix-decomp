#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
void SprSprite_Unload(struct Foo02048004* obj);

// USA: func_02012fa4
ARM void ResetFourSubStructs_02012fa4(char* base) {
    signed char i;
    for (i = 0; i < 4; i++) {
        SprSprite_Unload((struct Foo02048004*)(base + i * 0x88));
        SprSprite_Init((struct Foo02048004*)(base + i * 0x88));
    }
}
