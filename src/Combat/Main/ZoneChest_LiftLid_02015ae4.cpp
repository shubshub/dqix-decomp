#include <globaldefs.h>
#include <NitroSDK/Matrix.h>
#include "World/Zone3D.h"

struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
int fix32sin(int);
extern int g_sePlayer;

// A chest's ZoneChestRenderRecord (this file's copy of the fields it uses)
struct Obj02015ae4 {
    Vector3i position;
    short angleY;
    unsigned short lidAngle;
    unsigned short counter;
};

// Main, originally func_02015ae4 (USA 0x02015ae4, EUR 0x02015af4, JPN 0x020158b0)
extern "C" ARM int ZoneChest_LiftLid(Obj02015ae4* self) {
    unsigned short counter = self->counter;
    int firstDuration = 0xbff4;
    if ((float)counter <= (float)firstDuration / 4096.0f) {
        if (counter == 0) SePlayer_Play((SePlayer*)&g_sePlayer, 13, 0);
        else if (counter == 16) SePlayer_Play((SePlayer*)&g_sePlayer, 14, 0);
        unsigned int currentCounter = self->counter;
        int square = (self->counter * currentCounter) << 12;
        int coefficient = fix32_Divide(-7290, 0x8fee0);
        self->lidAngle = FIX32_MULTIPLY(coefficient, square) + ZoneChestLid_Closed;
        self->counter = self->counter + 1;
    } else {
        unsigned int elapsedCounter = self->counter;
        int firstDuration = 0xbff4;
        int elapsed = (int)(4096.0f * ((float)self->counter - (float)firstDuration / 4096.0f));
        int totalDuration = 0x17fe8;
        if ((float)elapsedCounter <= (float)totalDuration / 4096.0f) {
            int remaining = 0x1000 - fix32_Divide(elapsed, 0x17fe8);
            int coefficient = fix32_Divide(0xc90f, 0x17fe8);
            int angle = FIX32_MULTIPLY(coefficient, elapsed);
            if (angle > 0x647a) angle = 0x647a;
            int correction = FIX32_MULTIPLY(fix32sin(angle), -0x101);
            self->lidAngle = FIX32_MULTIPLY(correction, remaining) + ZoneChestLid_Lifted;
            self->counter = self->counter + 1;
        } else {
            self->lidAngle = ZoneChestLid_Lifted;
            return 1;
        }
    }
    return 0;
}
