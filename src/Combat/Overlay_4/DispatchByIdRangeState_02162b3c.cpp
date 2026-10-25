#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
int IsIdInRange020981e4(int a, int id);
extern "C" void func_ov011_021848a0(void* p, int v);

static inline unsigned short GetCurrentZoneID(Zone3D* zone) {
    return zone->currentZoneID_;
}

// USA: func_ov004_02162b3c  (semantic: DispatchByIdRangeState_02162b3c)
extern "C" ARM int func_ov004_02162b3c(void* self) {
    Zone3D* zone = Zone3D_GetInstance();
    char* state = zone->unk_840;
    if (state != 0) {
        unsigned short id = GetCurrentZoneID(zone);
        if (IsIdInRange020981e4((int)state, id) != 0) {
            func_ov011_021848a0(self, 0x32);
        } else {
            func_ov011_021848a0(self, 0x33);
        }
    }
    return 0;
}
