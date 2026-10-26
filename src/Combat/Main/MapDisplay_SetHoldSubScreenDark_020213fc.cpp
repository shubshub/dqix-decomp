#include <globaldefs.h>

// The MapDisplay (header field9c6). While it is set, MapDisplay_Draw does not fade the sub screen back in.
struct SetFlagStruct {
#if defined(jpn)
    char unk0[0x91a];
#else
    char unk0[0x9c6];
#endif
    unsigned char holdSubScreenDark;
};

// Main, originally SetFlag0x9c6_020213fc (USA 0x020213fc, EUR 0x0202140c, JPN 0x02020ff0)
extern "C" ARM void MapDisplay_SetHoldSubScreenDark(struct SetFlagStruct* mapDisplay, int hold) {
    mapDisplay->holdSubScreenDark = (hold != 0) ? 1 : 0;
}
