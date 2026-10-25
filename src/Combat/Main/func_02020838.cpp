#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "World/Zone3D.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void DisableSubObjVRAMBanks(void);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_02020968(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_0202099c(int arg0, int arg1, int arg2, int arg3, int arg4);

// USA: func_02020838
extern "C" ARM void func_02020838(MapDisplay* unusedContext) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    Zone3D_StructPtr_8* state = Zone3D_GetInstance()->pUnknownStruct_8_;

    DisableSubBGVRAMBanks();
    DisableSubObjVRAMBanks();
    func_020c3984(0);
    MapVRAMBanksToSubBG(0x80);

    if (var1->unknown_c_low_ == 0) {
        *var0 = (*var0 & ~0x1f00) | 0x1100;
        func_02020968(0, 0, 0xf, 0, 0);
        func_0202099c(0, 0, 0x10, 0, 0);
    } else {
        *var0 = (*var0 & ~0x1f00) | 0x1300;
        func_02020968(1, 0, 0xe, 0, 0);
        func_0202099c(0, 0, 0xd, 0, 0);
    }

    MapVRAMBanksToSubObj(0x100);

    *var0 = (*var0 & 0xffcfffef) | 0x10;

    unsigned short* var2 = (unsigned short*)0x4001008;
    var2[0] = (var2[0] & ~3) | 1;
    var2[1] = (var2[1] & ~3) | 2;
    var2[2] = (var2[2] & ~3);
    var2[3] = (var2[3] & ~3) | 3;
}
