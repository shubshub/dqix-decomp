#if defined(jpn)
enum { kNativeIdOffset = 0x72be };
#else
enum { kNativeIdOffset = 0x74fe };
#endif

#include <globaldefs.h>
#include "Util/Random.h"

int RTC_GetTime(int a);
extern "C" void OS_GetMacAddress(void* macAddress);
unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _u32_div_f(unsigned int a, unsigned int b);
extern char data_020ef0ca;

// Main, originally func_020120f0 (USA 0x020120f0, EUR 0x02012100, JPN 0x02011e6c)
extern "C" ARM void GameState_CreateNativeId(unsigned char* gameState) {
    struct Random rng;
    CreateRandom(&rng, &data_020ef0ca, 0);

    int slotBuf[3];
    RTC_GetTime((int)slotBuf);

    unsigned char macAddress[6];
    OS_GetMacAddress(macAddress);

    unsigned long long seeds[6];
    seeds[0] = (unsigned int)slotBuf[0];
    seeds[1] = (unsigned int)slotBuf[1];
    seeds[2] = (unsigned int)slotBuf[2];

    seeds[3] = (unsigned int)_u32_div_f((unsigned int)GetCurrentTimestamp() << 6, 0x82ea);
    seeds[4] = (unsigned int)_u32_div_f((unsigned int)GetCurrentTimestamp() * 0xfa00, 0x82ea);

    int macLowWord = (macAddress[5] << 24) | (macAddress[4] << 16) | (macAddress[3] << 8) | macAddress[2];
    seeds[5] = (long long)macLowWord;

    int i;
    for (i = 0; i < 6; i++) {
        SeedRandom(&rng, seeds[i]);
        *(gameState + i + kNativeIdOffset) = (unsigned char)NextRandom(&rng);
    }
}
