#include <globaldefs.h>
#include "Input/Input.h"
#include "NitroSDK/Interrupts.h"

struct AllocatorUnion;

extern "C" {
    void _Z14InitAllModulesv(void);
    void _Z21BlankFunction020c36ecv(void);
    void _Z23InitDisplayAndClearVramv(void);
    void InitializePowerManagement(void);
    void _Z22InitSlotSystem020cf020v(void);
    void _Z20Initialize64BitTimerv(void);
    void _Z25InitializeActiveAlarmListv(void);
    void _Z25InitializeVCountAlarmListv(void);
    void _Z23InitializeResourceMutexv(void);
    unsigned int _Z28SetSpecificInterruptsEnabledj(unsigned int which);
    void _Z19SetInterruptHandlerjPKv(unsigned int mask, const void* handler);
    void _Z24EnableSpecificInterruptsj(unsigned int mask);
    int _Z18SetVBlankIrqEnablei(int enable);
    void _Z32AllocatorUnion_InitMainArenaHeapP14AllocatorUnion(AllocatorUnion* alloc);
    void _Z23InitializeROMFilesystemi(int dmaChannel);
    void _Z23ChangeROMLoadDMAChannelj(int channel);
    void _Z31InitBattleModeAndCommit020758a8v(void);
    void NNS_SndInit(void);
    void _Z20InputLock_Initializev(void);
    void _Z17Main_HandleVBlankv(void);
}

extern int data_020f2270;
extern unsigned char data_02114e00;
extern AllocatorUnion g_mainAllocator;
extern int data_02114e50;

// Main, originally func_02012c34 (USA 0x02012c34, EUR 0x02012c44, JPN 0x020129fc)
extern "C" ARM void Main_InitializeSystems(void) {
    _Z14InitAllModulesv();
    _Z21BlankFunction020c36ecv();
    data_020f2270 = 0;
    _Z23InitDisplayAndClearVramv();
    InitializePowerManagement();
    _Z22InitSlotSystem020cf020v();
    _Z20Initialize64BitTimerv();
    _Z25InitializeActiveAlarmListv();
    _Z25InitializeVCountAlarmListv();
    _Z23InitializeResourceMutexv();
    _Z28SetSpecificInterruptsEnabledj(0);
    _Z19SetInterruptHandlerjPKv(IRQ_MASK_LCD_VBLANK, (const void*)_Z17Main_HandleVBlankv);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_LCD_VBLANK);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_DMA_0 | IRQ_MASK_DMA_1 | IRQ_MASK_DMA_2 | IRQ_MASK_DMA_3 | IRQ_MASK_TIMER_0_OVERFLOW);
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208; // REG_IME, interrupt master enable
    *ime;
    *ime = 1;
    _Z18SetVBlankIrqEnablei(1);
    _Z32AllocatorUnion_InitMainArenaHeapP14AllocatorUnion(&g_mainAllocator);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_FIFO_RECEIVE_NOT_EMPTY);
    _Z23InitializeROMFilesystemi(2);
    _Z23ChangeROMLoadDMAChannelj(2);
    _Z31InitBattleModeAndCommit020758a8v();
    NNS_SndInit();
    g_keyManager.Initialize();
    g_touchInput.Initialize();
    _Z20InputLock_Initializev();
    data_02114e00 = 0;
    data_02114e50 = 0;
}
