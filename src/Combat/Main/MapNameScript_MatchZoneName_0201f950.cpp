#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/Zone3D.h"

// A Script::Parameter (Resource/Script.h)
struct Variant02030b0c {
    int type;
    union {
        int i;
        float f;
    } value;
};
extern "C" Zone3D* Zone3D_GetInstance(void);

// The head of data_020fdc4c (CombatScriptContext): the zone name the mapname script picks (usa/eur only)
struct MapNameScriptContext {
    int palette;
    const char* nameOverride;
};
extern struct MapNameScriptContext data_020fdc4c;

// Main, originally CacheField4IfIdMatches_0201f950 (USA 0x0201f950, EUR 0x0201f960; JPN not identified)
extern "C" ARM int MapNameScript_MatchZoneName(struct Variant02030b0c* params) {
    int zoneId;
    if (data_020fdc4c.nameOverride != 0) return 1;
    zoneId = ((Script::Parameter*)params)->ToInt();
    if (zoneId == Zone3D_GetInstance()->currentZoneID_) {
        data_020fdc4c.nameOverride = ((Script::Parameter*)(params + 1))->ToString();
    }
    return 1;
}
