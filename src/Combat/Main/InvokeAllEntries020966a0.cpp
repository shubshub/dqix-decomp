#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
void SprSprite_Unload(struct Foo02048004* obj);

struct Entry020966a0 {
    unsigned char data[0x88];
};

// USA: func_020966a0
ARM void InvokeAllEntries020966a0(struct Entry020966a0* arr) {
    int i;
    for (i = 0; i < 4; i++) {
        SprSprite_Unload((struct Foo02048004*)&arr[i]);
    }
}
