#include <globaldefs.h>
#include "Resource/Brightness.h"

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
extern "C" int abs(int x);
extern "C" int _s32_div_f(int a, int b);

// Fades the sub screen out towards whichever end (black or white) its brightness is already on, over duration
// frames divided by how far it already is; within one step of the end it sets the end at once.
// The MapDisplay loaders call it with 25 frames, then wait until IsScreenNotFullyFaded(sub screen) is false.
// Main, originally func_02021428 (USA 0x02021428, EUR 0x02021438, JPN 0x0202101c)
extern "C" ARM void MapDisplay_FadeOutSubScreen(void* unusedSelf, int duration) {
    GameResources* resources = GetGameResources();
    int brightness = GetBrightness(resources, true);
    if (brightness - 1 <= Brightness_Black) {
        SetSubBrightness(resources, Brightness_Black, 0);
        return;
    }
    if (brightness + 1 >= Brightness_White) {
        SetSubBrightness(resources, Brightness_White, 0);
        return;
    }
    if (brightness > 0) {
        if (brightness < 0) brightness = 0;
        if (brightness != 0) {
            duration = _s32_div_f(duration, abs(brightness));
        }
        SetSubBrightness(resources, Brightness_White, duration);
    } else {
        if (brightness > 0) brightness = 0;
        if (brightness != 0) {
            duration = _s32_div_f(duration, abs(brightness));
        }
        SetSubBrightness(resources, Brightness_Black, duration);
    }
}
