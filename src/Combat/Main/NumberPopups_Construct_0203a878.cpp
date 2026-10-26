#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

extern "C" void NumberPopups_Init(void*);

extern "C" void* SprSprite_Destroy(void* obj);
extern "C" void* SprSprite_Construct(void* obj);
extern "C" void __cxa_vec_ctor(void* obj, int a, int b, void* cb1, void* cb2);

// data_02104b6c, the battle's number popups, up to its sprites.
struct NumberPopups {
    Foo02048004 numberSprites[5];
    Foo02048004 frameSprites[5];
};

// Main, originally InitTwoSubObjectsWithCallbacks0203a878 (USA 0x0203a878, EUR 0x0203a888, JPN 0x0203a2d0)
extern "C" ARM void* NumberPopups_Construct(void* numberPopups) {
    __cxa_vec_ctor(((NumberPopups*)numberPopups)->numberSprites, 5, sizeof(Foo02048004), (void*)SprSprite_Construct, (void*)SprSprite_Destroy);
    __cxa_vec_ctor(((NumberPopups*)numberPopups)->frameSprites, 5, sizeof(Foo02048004), (void*)SprSprite_Construct, (void*)SprSprite_Destroy);
    NumberPopups_Init((void*)(numberPopups));
    return numberPopups;
}
