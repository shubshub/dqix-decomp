#include <globaldefs.h>

#if defined(jpn)
#define func_020e0f74 func_020e2b6c
#endif

#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"

struct FlagWord02046708;

void *BgVram_GetInstance();
extern "C" void *Zone3D_GetInstance();
void *GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708 *flags, unsigned int mask);
extern "C" void *LinkSession_GetInstance();
int LinkSession_IsActive(int *value);
void MapDisplay_DrawSprite(void *receiver, int x, int y, int index, unsigned char field5, unsigned char field6,
                              unsigned short field7, unsigned char field8, int scaleX, int scaleY);

struct CombatMarkerReceiverView {
#if defined(jpn)
    unsigned char unknown0[0x6b9];
#else
    unsigned char unknown0[0x765];
#endif
    unsigned char markerElementsEnabled;
    unsigned short markerValue;
    unsigned char extendedDisplayMode;
};

#if defined(jpn)
enum { kSecondMarkerId = 0x2b, kThirdMarkerId = 0x38, kFourthMarkerId = 0x3b, kThirdX = 161, kThirdY = 20, kFourthY = 159 };
#else
enum { kSecondMarkerId = 0x26, kThirdMarkerId = 0x33, kFourthMarkerId = 0x41, kThirdX = 5, kThirdY = 30, kFourthY = 129 };
#endif

// USA: func_020e0f74
extern "C" ARM void func_020e0f74(void *receiver) {
    CombatMarkerReceiverView *state = static_cast<CombatMarkerReceiverView *>(receiver);
    GameState::GetInstance();
    BgVram_GetInstance();
    Zone3D_GetInstance();
    if (FlagWord_TestBits(static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance()), 0x41)) {
        return;
    }

    if (state->extendedDisplayMode) {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1300;
    } else {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x200;
    }
    if (!state->markerElementsEnabled) {
        return;
    }

    int *value = static_cast<int *>(LinkSession_GetInstance());
    int x      = 5;
    if (LinkSession_IsActive(value)) {
        x += 14;
    }
    MapDisplay_DrawSprite(receiver, x << 12, 5 << 12, 0, 0x1f, 1, 0xff, 0xff, 0x1000, 0x1000);
    MapDisplay_DrawSprite(receiver, 106 << 12, 130 << 12, 1, kSecondMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);

    if (state->markerValue < 1000 && state->markerValue != 0) {
        int y = kThirdY;
        if (LinkSession_IsActive(value)) {
            y += 11;
        }
        MapDisplay_DrawSprite(receiver, kThirdX << 12, y << 12, 2, kThirdMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawSprite(receiver, 0, kFourthY << 12, 3, kFourthMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
}
