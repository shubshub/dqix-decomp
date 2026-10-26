#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void *Zone3D_GetInstance(void);
int ZoneId_IsGrotto(int zoneId);
int ZoneId_IsMainGrottoFloor(int zoneId);
void MapDisplay_DrawSprite(void *receiver, int x, int y, int spriteIndex, unsigned char oamSlot, unsigned char priority,
                              unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);

#if defined(jpn)
enum { Enum_02024000_0 = 0x20, Enum_02024000_0_2 = -0xac, Enum_02024000_28620 = 0x6d8c };
#else
enum { Enum_02024000_0 = 0, Enum_02024000_0_2 = 0, Enum_02024000_28620 = 0x6fcc };
#endif

struct Struct_02024000_3 {
    fix32_t unknown_0_[9];
    fix32_t unknown_24_;
    fix32_t unknown_28_;
    fix32_t unknown_2c_;
    fix32_t unknown_30_;
};

struct Struct_02024000_4 {
    unsigned char unknown_0_[0x1c8 + Enum_02024000_0];
    unsigned char *unknown_1c8_;
    unsigned char *unknown_1cc_;
    int unknown_1d0_;
    int unknown_1d4_;
    unsigned char unknown_1d8_;
    unsigned char unknown_1d9_;
    unsigned char unknown_1da_;
    unsigned char unknown_1db_;
    Struct_02024000_3 unknown_1dc_[2];
};

struct Struct_02024000 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0x23ec + Enum_02024000_0 - 2];
    Struct_02024000_4 unknown_23ec_;
};

// The MapDisplay fields this reads (header: scale, screenX, screenY, field9ba)
struct MapDisplayGrotto_02024000 {
    unsigned char unknown0[0x38];
    fix32_t scale;
    unsigned char unknown3c[8];
    int screenX;
    int screenY;
    unsigned char unknown4c[0x9ba + regionalReceiver - 0x4c];
    unsigned char treasureRevealed; // set once overlay 2's command 0xd5 has loaded the red chests (MapDisplay_LoadRedChests)
};

// Sprites (MapDisplay::records) and the OAM slots they are drawn into; positions in 20.12 pixels, the map's centre at (124, 92)
enum {
    kUpStairSprite = 24,
    kUpStairOamSlot = 0x40,
    kDownStairSprite = 25,
    kDownStairOamSlot = 0x41,
    kGrottoSprite = 26,
    kGrottoOamSlot = 0x42,
    kGrottoIconX = 0xbc000,
    kGrottoIconY = 0x3000,
    kMapCentreX = 0x7c000,
    kMapCentreY = 0x5c000,
    kFloorTiles = 16, // a grotto floor is 16 x 16 tiles, one visited bit each (2 bytes a row, 32 a floor)
};

static inline fix32_t inline_02024000(fix32_t arg0, fix32_t arg1) {
    return FIX32_MULTIPLY(arg0, arg1);
}

static inline Struct_02024000_3 *inline_02024000_2(Struct_02024000_4 *arg0, int arg1) {
    return arg0->unknown_1dc_ + arg1 - 1;
}

// Main, originally func_02024000 (USA 0x02024000, EUR 0x02024010, JPN 0x020239c8)
extern "C" ARM void MapDisplay_DrawGrottoIcons(void *receiver) {
    MapDisplayGrotto_02024000 *state = static_cast<MapDisplayGrotto_02024000 *>(receiver);
    GameState *game = GameState::GetInstance();
    ZoneRecord *zone = static_cast<ZoneRecord *>(Zone3D_GetInstance());
    unsigned short zoneId = zone->zoneId;
    if (!ZoneId_IsGrotto(zoneId)) {
        return;
    }
    MapDisplay_DrawSprite(receiver, kGrottoIconX, kGrottoIconY, kGrottoSprite, kGrottoOamSlot, 0, 0xff, 0xff, 0x1000, 0x1000);
    if (!ZoneId_IsMainGrottoFloor(zoneId)) {
        return;
    }
    unsigned char *visited = reinterpret_cast<unsigned char *>(game) + regionalVisited + (zoneId % 20 - 1) * 32;
    GrottoFloor *grotto = &zone->grotto;
    GrottoStair *upStair = GetStair(grotto, 1);
    unsigned char upX = grotto->upStairX;
    unsigned char upY = grotto->upStairY;
    unsigned char downX = grotto->downStairX;
    unsigned char downY = grotto->downStairY;
    bool upVisited = false;
    bool downVisited = false;
    GrottoStair *downStair = GetStair(grotto, 2);
    for (int row = 0; row < kFloorTiles; row++) {
        for (int col = 0; col < kFloorTiles; col++) {
            bool seen;
            if (col < 8) {
                seen = (visited[row * 2] & (1 << col)) != 0;
            } else {
                var16 = (var4[var14 * 2 + 1] & (1 << (var15 - 8))) != 0;
            }
            if (var15 == var7 && var14 == var8 && var16) {
                var11 = true;
            }
            if (var15 == var9 && var14 == var10 && var16) {
                var12 = true;
            }
        }
    }
    if (upVisited) {
        int y = MultiplyFixed(upStair->worldZ, state->scale) - (state->screenY << 12) + kMapCentreY;
        int x = MultiplyFixed(upStair->worldX, state->scale) - (state->screenX << 12) + kMapCentreX;
        MapDisplay_DrawSprite(receiver, x, y, kUpStairSprite, kUpStairOamSlot, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    if (!downVisited && !state->treasureRevealed) {
        return;
    }
    int y = MultiplyFixed(downStair->worldZ, state->scale) - (state->screenY << 12) + kMapCentreY;
    int x = MultiplyFixed(downStair->worldX, state->scale) - (state->screenX << 12) + kMapCentreX;
    MapDisplay_DrawSprite(receiver, x, y, kDownStairSprite, kDownStairOamSlot, 1, 0xff, 0xff, 0x1000, 0x1000);
}
