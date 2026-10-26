#include <globaldefs.h>
#include "Graphics/itcm/VRAMStaging.h"

extern "C" void func_020c89c4(void);
extern "C" void func_020c89d4(void);

struct Struct_020c93bc;
extern "C" void func_020c93bc(struct Struct_020c93bc* p);

extern "C" void func_020c93d0(void*, int, int, void*, void*);
void SendStagedVRAMDataToVRAM(void*);

extern unsigned int g_stagingManagerInstance[];
extern int data_0214e5bc;

// Main, originally InitStreamAndRegisterHandler0xC0_020dc034 (USA 0x020dc034, EUR 0x020dc044, JPN 0x020dda3c)
extern "C" ARM void VRAMStagingManager_Init(void) {
    func_020c89c4();
    func_020c89d4();
    ((VRAMStagingManager*)g_stagingManagerInstance)->ZeroInitialize();
    func_020c93bc((struct Struct_020c93bc*)&data_0214e5bc);
    func_020c93d0(&data_0214e5bc, 0xc0, 0xf, (void*)SendStagedVRAMDataToVRAM, g_stagingManagerInstance);
}
