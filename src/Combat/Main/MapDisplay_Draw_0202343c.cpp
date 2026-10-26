#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#if defined(jpn)
#define func_020e0f74 func_020e2b6c
#define func_02026f34 func_02026898
#endif

#include "Resource/Brightness.h"

struct FlagWord02046708;
struct List0209497c;
struct List020949bc;
struct Obj020235c8;
struct ScrollState02027438;

extern "C" void *GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(FlagWord02046708 *flags, unsigned int mask);
extern "C" int *func_020936f8();
extern "C" int func_0209497c(List0209497c *list, int key);
extern "C" int func_020949bc(List020949bc *list, int key);
extern "C" void func_02093a58(char *list);
extern "C" void func_02093a98(char *list);
extern "C" int func_020e0a78(void *receiver);
extern "C" void func_020e0f74(void *receiver);
extern "C" void func_02026f34(void *receiver);
extern "C" void MapDisplay_DrawMapAndPanels(Obj020235c8 *receiver);
extern "C" void MapDisplay_SetMapScroll(ScrollState02027438 *receiver);

// The MapDisplay fields this reads (header names: field764, field778, loadStage, field9c3, field9c4, field9c6,
// failed, field9c8)
struct CombatUpdateReceiverView {
    unsigned char unknown0[IS_JPN ? 0x6b8 : 0x764];
    unsigned char field764;
    unsigned char unknown_765_[0x778 - 0x765];
    unsigned char field778;
    unsigned char unknown_779_[0x9c2 - 0x779];
    signed char loadStage;
    unsigned char modeLoading;       // MapDisplay_RunModeLoader runs the mode's loader while it is set
    unsigned char fadeInPending;     // the loaders set it at their end
    unsigned char unknown_9c5_;
    unsigned char holdSubScreenDark; // MapDisplay_SetHoldSubScreenDark
    unsigned char failed;            // MapDisplay_LoadLocalMap: the map script did not load
    unsigned char fadeInDelay;
};

enum { kFadeInFrames = 25 };

// Main, originally func_0202343c (USA 0x0202343c, EUR 0x0202344c, JPN 0x02022e04)
extern "C" ARM void MapDisplay_Draw(void *receiver) {
    CombatUpdateReceiverView *self = static_cast<CombatUpdateReceiverView *>(receiver);
    if (FlagWord_TestBits(static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance()), 0x41)) return;

    GameResources *resources = GetGameResources();
    // data_02109030: a queue of entries with an active and a saved half; while the map is loading an entry with
    // id 4 is moved to the saved half, and back once it has loaded
    int *requestQueue        = func_020936f8();
    if (self->modeLoading || self->loadStage <= 0) {
        if (func_0209497c(reinterpret_cast<List0209497c *>(requestQueue), 4)) {
            func_02093a58(reinterpret_cast<char *>(requestQueue));
        }
        return;
    }
    if (func_020949bc(reinterpret_cast<List020949bc *>(requestQueue), 4)) {
        func_02093a98(reinterpret_cast<char *>(requestQueue));
    }
    if (self->field764) {
        if (self->field778) {
            func_020e0a78(receiver);
            self->field778 = 0;
        }
        func_020e0f74(receiver);
    } else {
        func_02026f34(receiver);
        MapDisplay_DrawMapAndPanels(static_cast<Obj020235c8 *>(receiver));
    }
    if (func_0209497c(reinterpret_cast<List0209497c *>(requestQueue), 4)) {
        self->holdSubScreenDark  = 0;
        self->failed             = 0;
        self->fadeInPending      = 1;
        self->fadeInDelay        = 0;
    }
    // The main screen is showing and the sub screen is faded out: fade it back in
    if (IsScreenNotFullyFaded((GameResources*)resources, false) && IsScreenFullyFaded((GameResources*)resources, true)) {
        if (self->holdSubScreenDark || self->failed) return;
        if (!self->fadeInPending) return;
        if (self->fadeInDelay) {
            self->fadeInDelay--;
            return;
        }
        MapDisplay_SetMapScroll(static_cast<ScrollState02027438 *>(receiver));
        SetSubBrightness(resources, Brightness_Normal, kFadeInFrames);
        self->fadeInPending = 0;
    } else {
        if (IsBrightnessZero((GameResources*)resources, true)) self->fadeInPending = 0;
    }
}
