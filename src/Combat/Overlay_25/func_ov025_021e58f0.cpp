#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/ElementLookup.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e58f0 {
#if defined(jpn)
    char unknown_0_[0xe44];
#else
    char unknown1_0_[0xec8];
#endif
    Zone3D unknown_ec8_;
    short unknown_36ec_;
};

struct Struct_ov025_021e58f0_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_ov025_021e58f0_3 {
    char unknown_0_[8];
    const char* unknown_8_;
};

struct Struct_ov025_021ef988_15 {
    char unknown_0_[0x20];
    int unknown_20_;
};

struct Struct_ov025_021ef9a8;

extern "C" Struct_ov025_021e58f0* func_ov000_02160130(void);
extern "C" Struct_ov025_021e58f0_2* func_ov017_021b8478(void* arg0);
struct Struct_02018f6c_2;
extern "C" void func_02018f6c(Struct_02018f6c_2*, short);
extern "C" void func_ov025_021e3158(Struct_ov025_021ef9a8* arg0);

extern Struct_ov025_021ef988_15 data_ov025_021ef988;
extern Struct_ov025_021ef9a8 data_ov025_021ef9a8;

// USA: func_ov025_021e58f0
extern "C" ARM int func_ov025_021e58f0(Args_021e58f0* args) {
    CombatWork_021e58f0* work = GetActiveCombatWork_ov000_02160130();
    Zone3D* zone = &work->zone;
    ZoneInfo_021e58f0* info = func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
    if (data_ov025_021ef988.phase == 0) {
        unsigned short id = info->zoneId;
        if (args->zoneName != 0) {
            List0209998c* list = (List0209998c*)GameState_GetZoneTable(GameState::GetInstance());
            Elem0209998c* elem = ZoneTable_FindEntryByMapCode(list, args->zoneName);
            if (elem == 0) {
                return 1;
            }
            var3 = var5->unknown_0_;
        }
        zone->SwitchZone(id, 0);
        data_ov025_021ef988.phase = 1;
    } else if (data_ov025_021ef988.phase == 1 && zone->unknown_424_ == 0) {
        StoreAndMaybeCopy02018f6c((Obj02018f6c*)zone, work->zoneAngle);
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    return 0;
}
