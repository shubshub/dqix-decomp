#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);
extern "C" unsigned int _ull_mod(unsigned long long a, unsigned long long b);

// The DS system clock in Hz (NitroSDK HW_SYSTEM_CLOCK, 0x1ff6210): the OS timestamp ticks at a 64th of it, so
// (ticks << 6) / this is seconds
enum { kSystemClockHz = 33514000 };

// GameState (this file's copy of the field it uses)
struct TimeStamp020103f0 {
    unsigned char pad0[0x3e8];
    long long mainTimestamp_;   // GameState::mainTimestamp_ (0x3e8)
};

// Main, originally ComputeElapsedPlayTimeHMS020103f0 (USA 0x020103f0, EUR 0x02010400, JPN 0x0201024c)
ARM void GameState_GetTimeSinceMainTimestamp(TimeStamp020103f0* gameState, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds) {
    unsigned long long elapsed = _ll_udiv(GetCurrentTimestamp() << 6, kSystemClockHz)
                                - _ll_udiv(gameState->mainTimestamp_ << 6, kSystemClockHz);
    unsigned long long hours = _ll_udiv(elapsed, 3600);
    unsigned int minutes = _ull_mod(_ll_udiv(elapsed, 60), 60);
    unsigned int seconds = _ull_mod(elapsed, 60);
    if (hours > 10000) hours = 9999;
    *outHours = (unsigned short)hours;
    *outMinutes = minutes;
    *outSeconds = seconds;
}
