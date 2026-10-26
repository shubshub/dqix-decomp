#include <globaldefs.h>

// MapDisplay flags758 (the party member shown in each status panel) and field75c (the panel count)
#if defined(jpn)
#define data_020fdcce data_020fda36
#define LIST_VALUES 0x6ac
#define LIST_COUNT 0x6b0
#else
#define LIST_VALUES 0x758
#define LIST_COUNT 0x75c
#endif
// data_020fdcb0[0].reset: the panels' 0x20-byte shown-state records (MapDisplay_Update's State_1f9b8)
extern unsigned char data_020fdcce;

// Stores the party order (up to four member indices; more stores none) and sets each listed member's reset, so
// MapDisplay_Update drops that panel's next statsChanged
// Main, originally StoreByteList02026348 (USA 0x02026348, EUR 0x02026358, JPN 0x02025d1c)
extern "C" ARM void MapDisplay_SetPartyOrder(char* mapDisplay, unsigned char* memberIndices, int count) {
    int i;
    if ((unsigned int)count > 4) {
        mapDisplay[LIST_COUNT] = 0;
        return;
    }
    for (i = 0; i < count; i++) {
        char* p = mapDisplay + i;
        unsigned char memberIndex = memberIndices[i];
        p[LIST_VALUES] = memberIndex;
        (&data_020fdcce)[memberIndex << 5] = 1;
    }
    mapDisplay[LIST_COUNT] = count;
}

