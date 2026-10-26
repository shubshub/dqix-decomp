#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
extern "C" void SprSprite_Unload(struct Foo02048004* obj);

struct Struct_020966a0 {
    unsigned char data[0x88];
};

// USA: func_020966a0
extern "C" ARM void func_020966a0(struct Struct_020966a0* arr) {
    int i;
    for (i = 0; i < 4; i++) {
        SprSprite_Unload((struct Foo02048004*)&arr[i]);
    }
}
