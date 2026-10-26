#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020abf60_30192 = 0x73b0 };
#else
enum { Enum_020abf60_30192 = 0x75f0 };
#endif
#include "GameState/GameState.h"



extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
struct Struct_02097430_2;
struct Struct_02097430 {
    unsigned char unknown0[0x1a];
    short unknown_1a_;
    unsigned char unknown_1c_[4];
};
extern "C" Struct_02097430* func_02097430(Struct_02097430_2* entries, int key);

struct EventFlagState {
    unsigned char unknown0[0x8c];
    unsigned char bits[0x234];
};

struct Struct_020abe84_2 {
    unsigned char unknown0[Enum_020abf60_30192];
    unsigned int records[308];
};

extern short data_020e90d4[21];

// USA: func_020abf60

extern "C" ARM int func_020abf60(void* arg0) {
    if (arg0 == 0) {
        return 0;
    }
    EventFlagState* events = static_cast<EventFlagState*>(Scenario_GetInstance());
    if (Scenario_TestFlag((int)events, events->bits, 0x796) == 0 ||
        Scenario_TestFlag((int)events, events->bits, 0x1143) != 0) {
        return 0;
    }
    Scenario_SetFlag(events, events->bits, 0x1143, 1);
    unsigned int* table = reinterpret_cast<Struct_020abe84_2*>(GameState::GetInstance())->records;
    short* keys = data_020e90d4;
    int i;
    for (i = 0; i < 0x15; i++) {
        short key = *keys;
        keys++;
        short index = func_02097430(static_cast<Struct_02097430_2*>(arg0), key)->unknown_1a_ - 1;
        table[index] |= 0x400;
    }
    return 1;
}
