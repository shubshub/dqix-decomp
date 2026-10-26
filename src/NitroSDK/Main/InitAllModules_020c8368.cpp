#include <globaldefs.h>

extern "C" void func_020c83b0(void);
void InitializeInterProcessorCommunication(void);
void InitializeGamecardBusOwnership(void);
extern "C" void func_020c84b4(void);
void InitializeInterruptContextBlock_020c6ad4(void);
void StoreSharedMemMagicWords_020c6d48(void);
extern "C" void func_020c8a3c(void);
void SetWramCntThenReset_020cad00(void);
void InitializeVCountAlarmList(void);
void ResetTable020c9a54(void);
extern "C" void func_020c745c(void);
extern "C" void OS_InitReset(void);
extern "C" void func_020d15fc(void);
void InitializeCardReading(void);
extern "C" void InitializePowerManagement(void);
void WaitForVCountZero_020c8348(void);

// Main, originally InitAllModules020c8368 (USA 0x020c8368, EUR 0x020c8378, JPN 0x020c9e34)
ARM void InitAllModules(void) {
    func_020c83b0();
    InitializeInterProcessorCommunication();
    InitializeGamecardBusOwnership();
    func_020c84b4();
    InitializeInterruptContextBlock_020c6ad4();
    StoreSharedMemMagicWords_020c6d48();
    func_020c8a3c();
    SetWramCntThenReset_020cad00();
    InitializeVCountAlarmList();
    ResetTable020c9a54();
    func_020c745c();
    OS_InitReset();
    func_020d15fc();
    InitializeCardReading();
    InitializePowerManagement();
    WaitForVCountZero_020c8348();
}
