#include <globaldefs.h>
#include "World/Zone3D.h"



extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" void* Scenario_GetInstance(void);
int ZoneVisitedFlag_GetFieldZoneIndex(int x);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
int ZoneId_IsGrotto(int id);
int ZoneVisitedFlag_FindExtraZoneIndex(int key);
extern "C" int _s32_div_f(int a, int b);

// The scenario's flag bits start at +0x8c
enum { kScenarioFlagsOffset = 0x8c };

// Zone ids by kind: field zones (20000 + n, visited flag kFieldVisitedFlags + n through ZoneVisitedFlag_GetFieldZoneIndex), and
// zone ids 100-9999, 100 to an area (maplist9.bin: Angel Falls 1100-1112, the Observatory 4100-4107)
enum {
    kFirstFieldZoneId = 20000,
    kLastFieldZoneId = 29999,
    kFirstAreaZoneId = 100,
    kLastAreaZoneId = 9999,
    kZonesPerArea = 100,
    kAreaCount = 100,
};

// The scenario flags that record a visit: one per field zone, one per area, and one for all the grottos
enum {
    kFieldVisitedFlags = 0xa00 + 0x5a,
    kAreaVisitedFlags = 0xa00 + 0x96,
    kGrottoVisitedFlag = 0x79d,
};

// Main, originally SetBitFromValueRange0201ba68 (USA 0x0201ba68, EUR 0x0201ba78, JPN 0x0201b7e0)
ARM void Zone3D_SetVisitedFlag(void* zoneBytes) {
    Zone3D* zone = (Zone3D*)zoneBytes;
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0 || (unsigned char)zone->unknown_2820_ != 0) return;

    void* scenario = Scenario_GetInstance();
    if (zone->currentZoneID_ >= kFirstFieldZoneId && zone->currentZoneID_ <= kLastFieldZoneId) {
        int fieldIndex = ZoneVisitedFlag_GetFieldZoneIndex(zone->currentZoneID_);
        if (fieldIndex < 0) return;
        Scenario_SetFlag(scenario, (unsigned char*)scenario + kScenarioFlagsOffset, fieldIndex + kFieldVisitedFlags, 1);
        return;
    }
    if (zone->currentZoneID_ >= kFirstAreaZoneId && zone->currentZoneID_ <= kLastAreaZoneId) {
        int area = _s32_div_f(zone->currentZoneID_, kZonesPerArea);
        if (area >= kAreaCount) return;
        Scenario_SetFlag(scenario, (unsigned char*)scenario + kScenarioFlagsOffset, area + kAreaVisitedFlags, 1);
        return;
    }
    if (ZoneId_IsGrotto(zone->currentZoneID_)) {
        Scenario_SetFlag(scenario, (unsigned char*)scenario + kScenarioFlagsOffset, kGrottoVisitedFlag, 1);
        return;
    }
    int extraIndex = ZoneVisitedFlag_FindExtraZoneIndex(zone->currentZoneID_);
    if (extraIndex < 0) return;
    Scenario_SetFlag(scenario, (unsigned char*)scenario + kScenarioFlagsOffset, extraIndex + kFieldVisitedFlags, 1);
}
