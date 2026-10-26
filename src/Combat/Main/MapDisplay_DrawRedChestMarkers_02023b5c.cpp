#include <globaldefs.h>

#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/HWRegisters.h"

extern "C" void Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsGuest(void* p);
// 1 while red chest i still holds its item and its opened flag (scenario, ID + 0x212) is not set
int MapDisplay_IsRedChestUnopened(char* base, int index);
void MapDisplay_DrawSprite(void *receiver, int x, int y, int spriteIndex, unsigned char oamSlot, unsigned char priority,
                              unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);

// One red chest of this map (func_02026780 builds them from treasure.nsarc, AppendRecord020269e4 adds them)
struct MarkerEntry02023b5c {
    unsigned char unknown0[0x10];
    Vector3i position;
};

#if defined(jpn)
enum { regionalOffset = -0xac };
#else
enum { regionalOffset = 0 };
#endif

struct MarkerReceiver02023b5c {
    unsigned char unknown0[0x38];
    fix32_t scale;
    unsigned char unknown3c[0x77c - 0x3c + regionalOffset];
    int zoneNames;    // the zones whose red chests are loaded (MapDisplay_AllocateRedChestZones)
    unsigned char redChestCount;
    unsigned char unknown781[3];
    MarkerEntry02023b5c redChests[(0x9b4 - 0x784) / 0x1c];
    int blinkTimer;
    unsigned char unknown9b8[2];
    unsigned char shown; // MapDisplay_LoadRedChests sets it once the red chests have loaded
};

enum {
    kBlinkPeriod = 0x300,   // ms
    kMarkerSprite = 0x17,
    kMarkerOamSlotBase = 0x60, // + the red chest's index
};

// Main, originally func_02023b5c (USA 0x02023b5c, EUR 0x02023b6c, JPN 0x02023524)
extern "C" ARM void MapDisplay_DrawRedChestMarkers(void *receiver, int originX, int originY, int xOffset, int yOffset, unsigned char useHeight) {
    MarkerReceiver02023b5c *self = static_cast<MarkerReceiver02023b5c *>(receiver);
    Zone3D_GetInstance();
    if (!self->zoneNames) return;
    if (LinkSession_IsGuest(LinkSession_GetInstance())) return;
    self->blinkTimer = (self->blinkTimer + GameState::GetInstance()->GetEffectiveDeltaTime()) % kBlinkPeriod;
    int alpha = abs((self->blinkTimer - 0x180) / 0x18) + 2;
    if (alpha > 16) alpha = 16;
    bool subScreen = true;
    unsigned char count = self->redChestCount;
    for (int i = 0; i < count; i++) {
        if (!MapDisplay_IsRedChestUnopened(static_cast<char *>(receiver), i)) continue;
        Vector3i position;
        position = self->redChests[i].position;
        fix32_t scale = self->scale;
        int x         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(position.x, scale)) / 4096.0f) - originX;
        int y         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(position.z, scale)) / 4096.0f) - originY;
        if (useHeight) {
            y = -(static_cast<int>(static_cast<float>(FIX32_MULTIPLY(position.y, scale)) / 4096.0f) - originY);
        }
        if (!self->shown) continue;
        ColorEffect_ConfigureAlphaBlend(subScreen ? REG_BLDCNT_SUB : REG_BLDCNT, 0, 3, alpha, 16 - alpha);
        MapDisplay_DrawSprite(receiver, (x + xOffset) << 12, (y + yOffset) << 12, kMarkerSprite,
                                 static_cast<unsigned char>(i + kMarkerOamSlotBase), 1, 0xff, 0xff, 0x1000, 0x1000);
    }
}
