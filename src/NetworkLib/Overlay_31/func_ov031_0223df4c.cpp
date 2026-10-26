#include <globaldefs.h>

extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);

// USA: func_ov031_0223df4c
extern "C" ARM void func_ov031_0223df4c() {
    MapVRAMBanksToLCDC(0x1f3);
    MIi_CpuClearFast(0, (void*)0x6800000, 0x40000);
    MIi_CpuClearFast(0, (void*)0x6880000, 0x24000);
    DisableLCDCMappedVRAMBanks();
    MIi_CpuClearFast(0x200, (void*)0x7000000, 0x400);
    MIi_CpuClearFast(0, (void*)0x5000000, 0x400);
    MIi_CpuClearFast(0x200, (void*)0x7000400, 0x400);
    MIi_CpuClearFast(0, (void*)0x5000400, 0x400);
}
