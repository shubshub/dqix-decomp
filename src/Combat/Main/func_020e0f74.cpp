#include <globaldefs.h>

#if defined(jpn)
#define func_020e0f74 func_020e2b6c
#endif

#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"

struct FlagWord02046708;

extern "C" void *BgVram_GetInstance();
extern "C" void *Zone3D_GetInstance();
extern "C" void *GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(FlagWord02046708 *flags, unsigned int mask);
extern "C" void *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *value);
extern "C" void MapDisplay_DrawSprite(void *receiver, int x, int y, int index, unsigned char field5, unsigned char field6,
                              unsigned short arg6, unsigned char field8, int scaleX, int scaleY);

struct Struct_020e0f74 {
#if defined(jpn)
    unsigned char unknown0[0x6b9];
#else
    unsigned char unknown0[0x765];
#endif
    unsigned char unknown_765_;
    unsigned short unknown_766_;
    unsigned char unknown_768_;
};

#if defined(jpn)
enum { kSecondMarkerId = 0x2b, kThirdMarkerId = 0x38, kFourthMarkerId = 0x3b, kThirdX = 161, Enum_020e0f74_30 = 20, kFourthY = 159 };
#else
enum { kSecondMarkerId = 0x26, kThirdMarkerId = 0x33, kFourthMarkerId = 0x41, kThirdX = 5, Enum_020e0f74_30 = 30, kFourthY = 129 };
#endif

// USA: func_020e0f74
extern "C" ARM void func_020e0f74(void *receiver) {
    Struct_020e0f74 *state = static_cast<Struct_020e0f74 *>(receiver);
    GameState::GetInstance();
    BgVram_GetInstance();
    Zone3D_GetInstance();
    if (FlagWord_TestBits(static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance()), 0x41)) {
        return;
    }

    if (state->unknown_768_) {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1300;
    } else {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x200;
    }
    if (!state->unknown_765_) {
        return;
    }

    int *value = static_cast<int *>(LinkSession_GetInstance());
    int x      = 5;
    if (LinkSession_IsActive(value)) {
        x += 14;
    }
    MapDisplay_DrawSprite(receiver, x << 12, 5 << 12, 0, 0x1f, 1, 0xff, 0xff, 0x1000, 0x1000);
    MapDisplay_DrawSprite(receiver, 106 << 12, 130 << 12, 1, kSecondMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);

    if (state->unknown_766_ < 1000 && state->unknown_766_ != 0) {
        int y = Enum_020e0f74_30;
        if (LinkSession_IsActive(value)) {
            y += 11;
        }
        MapDisplay_DrawSprite(receiver, kThirdX << 12, y << 12, 2, kThirdMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawSprite(receiver, 0, kFourthY << 12, 3, kFourthMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
}
