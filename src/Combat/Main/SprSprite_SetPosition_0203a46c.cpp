#include <globaldefs.h>

// A Foo02048004 (.spr sprite) up to its position (+0x1c).
struct Vec3Target0203a46c {
    char unk[0x1c];
    int x;
    int y;
    int z;
};

// Main, originally SetVec3At0x1c (USA 0x0203a46c, EUR 0x0203a47c, JPN 0x02039ec4)
extern "C" ARM void SprSprite_SetPosition(struct Vec3Target0203a46c* sprite, int x, int y, int z) {
    sprite->x = x;
    sprite->y = y;
    sprite->z = z;
}
