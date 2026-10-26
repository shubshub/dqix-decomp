#include <globaldefs.h>

// The wall polygon ZoneTerrain_PushOutOfWalls pushed the actor out of (func_ov017_02192b48 builds it from a
// ZoneTerrainSample: the three corners moved to world space, then the normal). Arrays, not Vector3fix or a
// struct of x/y/z: either makes MWCC copy through an operator=, which this function doesn't
struct WallCorners {
    int coordinates[3][3];  // corner, then x/y/z
};

struct WallNormal {
    int coordinates[3];     // x/y/z
};

struct CopySrc02033edc {
    struct WallCorners corners;
    struct WallNormal normal;
};

enum { GameObjectFlagsE0_WallHit = 0x40 };  // GameObject_GetWallHit returns the wall only while it is set

struct CopyDst02033edc {
    unsigned char unknown0[0xe0];
    unsigned char flagsE0;
    unsigned char unknownE1[3];
    struct WallCorners wallCorners;
    struct WallNormal wallNormal;
};

// Main, originally CopyBlocksSetFlag0x40 (USA 0x02033edc, EUR 0x02033eec, JPN 0x02033a14)
ARM void GameObject_SetWallHit(struct CopyDst02033edc* object, struct CopySrc02033edc* wall) {
    object->flagsE0 |= GameObjectFlagsE0_WallHit;
    object->wallCorners = wall->corners;
    object->wallNormal = wall->normal;
}
