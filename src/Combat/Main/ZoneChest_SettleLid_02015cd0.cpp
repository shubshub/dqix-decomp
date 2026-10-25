#include <globaldefs.h>
#include <NitroSDK/Matrix.h>
#include "World/Zone3D.h"

int fix32sin(int);
int fix32abs(int);

// A chest's ZoneChestRenderRecord (this file's copy of the fields it uses)
struct ChestRecord02015cd0 {
    Vector3i position;
    short angleY;
    short lidAngle;
    unsigned short counter;
    short iconTask;
    signed char opener;
    char pad15;
    unsigned char state;
    unsigned char kind;
    unsigned char special;
};

// Main, originally func_02015cd0 (USA 0x02015cd0, EUR 0x02015ce0, JPN 0x02015a9c)
extern "C" ARM int ZoneChest_SettleLid(ChestRecord02015cd0* chest) {
    if (chest->special == 0) {
        unsigned short counter = chest->counter;
        int firstDuration = 0xbff4;
        if ((float)counter <= (float)firstDuration / 4096.0f) {
            int square = (chest->counter * chest->counter) << 12;
            int coefficient = fix32_Divide(-0x800, 0x8fee0);
            chest->lidAngle = FIX32_MULTIPLY(coefficient, square) + ZoneChestLid_Lifted;
            chest->counter = chest->counter + 1;
        } else {
            int totalDuration = 0x17fe8;
            if ((float)counter <= (float)totalDuration / 4096.0f) {
                int elapsed = (int)(4096.0f * ((float)counter - (float)firstDuration / 4096.0f));
                int remaining = 0x1000 - fix32_Divide(elapsed, 0x17fe8);
                int coefficient = fix32_Divide(0xc90f, 0x17fe8);
                int angle = FIX32_MULTIPLY(coefficient, elapsed);
                if (angle > 0x647a) angle = 0x647a;
                int correction = FIX32_MULTIPLY(fix32sin(angle), 0x101);
                chest->lidAngle = FIX32_MULTIPLY(correction, remaining) + ZoneChestLid_Open;
                chest->counter = chest->counter + 1;
            } else {
                return 1;
            }
        }
    } else if (chest->special == 1) {
        if (chest->counter == 0) {
            int delta = FIX32_MULTIPLY(ZoneChestLid_Closed - chest->lidAngle, 0x333);
            chest->lidAngle += delta;
            if (fix32abs(delta) < 4) {
                chest->lidAngle = ZoneChestLid_Closed;
                chest->counter = chest->counter + 1;
                return 1;
            }
        } else {
            return 1;
        }
    }
    return 0;
}
