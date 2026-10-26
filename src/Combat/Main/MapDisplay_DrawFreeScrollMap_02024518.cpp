#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kActionStateOffset = 0x914, kVisitedIndex = 0x4c };
#define data_020e7074 data_020e7940
#define data_020e7076 data_020e7942
#define data_020e7056 data_020e7922
#define data_020e7057 data_020e7923
#else
enum { kActionStateOffset = 0x9c0, kVisitedIndex = 12 };
#endif

// Where the map script places one map piece (MapDisplay::names[pieceIndex]), in tiles from the pieces' origin
struct ForwardingRecord02024518 {
    int unknown0;
    int pieceIndex;
    int x;
    int y;
};

// The MapDisplay fields this uses (header: forwardingX/Y, forwarding, forwardingCount, scale, screenX/Y, mapState,
// mapPalette, forwardingFill, forwardingPending, flags, cameraX/Z, actionState)
struct MapReceiver02024518 {
    unsigned char unknown0[0x18];
    int piecesX;                          // in tiles; -1 on grotto floors
    int piecesY;
    unsigned char unknown20[0xc];
    ForwardingRecord02024518 *placements; // the map pieces' places (MapDisplay_LoadMapPieces loads their images)
    int placementCount;
    unsigned char unknown34[4];
    fix32_t scale;
    unsigned char unknown3c[8];
    int screenX;                          // the camera in map pixels
    int screenY;
    unsigned char unknown4c[0x6c - 0x4c];
    int grottoMap;                        // grotto floors: the 0x800-byte floor map func_02027974 draws (MapDisplay_LoadGrottoMap)
    int mapFirstTile;                     // MapDisplay_LoadMapPieces: blankTile + 1, where the map tiles start
    int blankTile;                        // MapDisplay_LoadBackgroundPattern: the empty tile after the background pattern
    unsigned char unknown78[0x55c - 0x78];
    unsigned char redrawPending;          // set when a mode has loaded
    unsigned char unknown55d[0x5a4 - 0x55d];
    int flags;                            // bit 0: draw only the party members' icons
    unsigned char unknown5a8[4];
    fix32_t cameraX;                      // world units (MapDisplay_CenterOnLeader)
    fix32_t cameraZ;
    unsigned char unknown5b4[kActionStateOffset - 0x5b4];
    unsigned char blinkPhase;             // MapDisplay_UpdateBlink
};

// The grotto floor tile ahead of the leader, per 45 degree sector of its facing (degrees, upper and lower bound;
// facings beyond +-157 use (4, -2)), and that tile's offset in world units
extern short data_020e7074[][2];
extern short data_020e7076[][2];
extern signed char data_020e7056[][2];
extern signed char data_020e7057[][2];

enum {
    kScrollMarginX = 30,  // pixels the leader may stray from the camera before it follows
    kScrollMarginUp = 20,
    kScrollMarginDown = 10,
    kMapCentreX = 0x7c,   // the map's centre on the sub screen
    kMapCentreY = 0x5c,
    kIconCapacity = 17,
};

struct List_02027878;
struct Entry_02027878;
struct Bcb8Params;
struct BattleTimer0202441c;
struct Actor02024d48;

void *BgVram_GetInstance();
extern "C" Zone3D *Zone3D_GetInstance();
int ZoneId_IsMainGrottoFloor(int id);
extern "C" void func_02027974(void *object, const unsigned char* adjacencyData, int grottoMap);
extern "C" void BgTransfers_PlaceMap(void *data, int mode, int index, int x, int y, int state, int width, int height,
                              unsigned short palette);
void BgVram_FillMap(void *owner, int mode, int index, int value);
Entry_02027878 *MapDisplay_GetMapPiece(List_02027878 *list, int index);
void BgImage_Place(Bcb8Params *params, int a, int b);
void MapDisplay_UpdateBlink(BattleTimer0202441c *receiver);
int MapDisplay_IsMemberVisible(void *receiver, int objectIndex);
int MapIcon_IsShownInBlinkPhase(CombatActionPosition* icon, int blinkPhase);
void MapDisplay_DrawSprite(void *receiver, int x, int y, int spriteIndex, unsigned char oamSlot, unsigned char priority,
                              unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);

// USA: MapDisplay_DrawFreeScrollMap
// JPN: func_02023eec
// Main, originally func_02024518 (USA 0x02024518, EUR 0x02024528, JPN 0x02023eec)
extern "C" ARM void MapDisplay_DrawFreeScrollMap(MapReceiver02024518 *self) {
    int pz;
    int px;
    GameState *gameState  = GameState::GetInstance();
    GameObject *leader    = gameState->GetLeader();
    void *bgTransfers     = BgVram_GetInstance();
    Zone3D *zone          = Zone3D_GetInstance();
    int iconCount;
    int zoneId            = zone->currentZoneID_;
    Vector3i position     = leader->obj3D_.position_; // MapDisplay_CollectIcons moves it to the hero's zone list point if it has one
    CombatActionPosition icons[kIconCapacity];
    unsigned char groupCounts[32];
    memset(groupCounts, 0, sizeof(groupCounts));
    iconCount = MapDisplay_CollectIcons(icons, groupCounts, &position);

    fix32_t scale = self->scale;
    int cameraX   = (int) ((float) FIX32_MULTIPLY(self->cameraX, self->scale) / 4096.0f);
    int cameraZ   = (int) ((float) FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    int leaderX   = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int leaderZ   = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    if (leaderX - cameraX > kScrollMarginX || cameraX - leaderX > kScrollMarginX) {
        if (leaderX > cameraX) {
            self->cameraX += fix32_Divide((leaderX - cameraX - kScrollMarginX) << 12, scale);
        } else {
            self->cameraX -= fix32_Divide((cameraX - leaderX - kScrollMarginX) << 12, scale);
        }
    }
    if (leaderZ - cameraZ > kScrollMarginDown || cameraZ - leaderZ > kScrollMarginUp) {
        if (leaderZ > cameraZ) {
            self->cameraZ += fix32_Divide((leaderZ - cameraZ - kScrollMarginDown) << 12, self->scale);
        } else {
            self->cameraZ -= fix32_Divide((cameraZ - leaderZ - kScrollMarginUp) << 12, self->scale);
        }
    }
    scale         = self->scale;
    cameraX       = (int) ((float) FIX32_MULTIPLY(self->cameraX, scale) / 4096.0f);
    cameraZ       = (int) ((float) FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    self->screenX = cameraX;
    self->screenY = cameraZ;
    int tileX     = cameraX < 0 ? cameraX / 8 - 1 : cameraX / 8;
    int tileZ     = cameraZ < 0 ? cameraZ / 8 - 1 : cameraZ / 8;

    int aheadX;
    int aheadZ;
    if (ZoneId_IsMainGrottoFloor(zoneId)) {
        if (self->grottoMap == 0) return;
        if (zone->unknown_424_ == 0) {
            unsigned char *visitedTiles =
                (unsigned char*)&gameState->unk_6fc0[kVisitedIndex] + ((zoneId % 20) - 1) * 32;
            fix32_t angle = fix32_Divide(FIX32_MULTIPLY(leader->obj3D_.rotation_.y, 0xb4000), 0x3243); // radians to degrees
            if (angle > 0xb4000) angle -= 0x168000;
            angle >>= 12;
            if (-157 > angle || angle > 157) {
                aheadX = (int) ((4.0f + (float) position.x / 4096.0f) / 8.0f);
                aheadZ = (int) (((float) position.z / 4096.0f - 2.0f) / 8.0f);
            } else {
                int found = 0;
                px        = position.x;
                pz        = position.z;
                for (int i = 0; i < 7 && !found; i++) {
                    if (data_020e7074[i][0] >= angle && angle > data_020e7076[i][0]) {
                        aheadX = (int) (((float) px / 4096.0f + (float) data_020e7056[i][0]) / 8.0f);
                        aheadZ = (int) (((float) pz / 4096.0f + (float) data_020e7057[i][0]) / 8.0f);
                        found = 1;
                    }
                }
            }
            if (aheadX < 8) {
                visitedTiles[aheadZ * 2] |= 1U << aheadX;
            } else {
                visitedTiles[aheadZ * 2 + 1] |= 1U << (aheadX - 8);
            }
            int centerX = (int) ((4.0f + (float) position.x / 4096.0f) / 8.0f);
            int centerZ = (int) ((4.0f + (float) position.z / 4096.0f) / 8.0f);
            if (centerX < 8) {
                visitedTiles[centerZ * 2] |= 1U << centerX;
            } else {
                visitedTiles[centerZ * 2 + 1] |= 1U << (centerX - 8);
            }
            ActiveGrottoClass* grotto = zone->GetActiveGrotto();
            func_02027974(self, grotto->floorMap_.pMapAdjacencyData, self->grottoMap);
        }
        self->redrawPending = 0;
        BgVram_FillMap(bgTransfers, 1, 0, self->blankTile);
        int mapX        = self->piecesX - tileX;
        int mapY        = self->piecesY - tileZ + 16;
        void *subBg     = BgVram_GetInstance();
        BgTransfers_PlaceMap(subBg, 1, 0, mapX + 32, mapY, self->grottoMap, 32, 32, self->mapFirstTile);
    } else {
        self->redrawPending = 0;
        BgVram_FillMap(bgTransfers, 1, 0, self->blankTile);
        for (int i = 0; i < self->placementCount; i++) {
            Entry_02027878 *piece = MapDisplay_GetMapPiece((List_02027878*)self, self->placements[i].pieceIndex);
            if (piece) {
                BgImage_Place((Bcb8Params*)((char*)piece + 8),
                                    self->piecesX + self->placements[i].x - tileX + 32,
                                    self->piecesY + self->placements[i].y - tileZ + 16);
            }
        }
    }
    MapDisplay_UpdateBlink((BattleTimer0202441c*)self);
    for (int i = 0; i < iconCount; i++) {
        CombatActionPosition *entry = &icons[i];
        if (!MapDisplay_IsMemberVisible(self, entry->combatantId)) continue;
        fix32_t entryScale = self->scale;
        int x = (int) ((float) FIX32_MULTIPLY(entry->position.x, entryScale) / 4096.0f) - self->screenX;
        int z = (int) ((float) FIX32_MULTIPLY(entry->position.z, entryScale) / 4096.0f) - self->screenY;
        if (entry->variant >= 0) {
            int group = groupCounts[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            z += data_020e70f4[group][entry->variant][0];
        }
        if (self->flags & 1) {
            if (IsNonCombatantAction(entry->type)) continue;
        }
        if (!MapIcon_IsShownInBlinkPhase(entry, self->blinkPhase)) continue;
        MapDisplay_DrawSprite(self, (x + kMapCentreX) << 12, (z + kMapCentreY) << 12, entry->elementId, entry->type, 0,
                                 entry->palette, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawRedChestMarkers(self, self->screenX, self->screenY, kMapCentreX, kMapCentreY, 0);
    MapDisplay_DrawBattleMarkers(self, icons, iconCount, self->screenX, self->screenY, kMapCentreX, kMapCentreY, 0);
}
