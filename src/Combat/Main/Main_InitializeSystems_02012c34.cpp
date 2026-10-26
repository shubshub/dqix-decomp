#include <globaldefs.h>
#include "Input/Input.h"
#include "NitroSDK/Interrupts.h"

struct AllocatorUnion;

extern "C" {
    void InitAllModules(void);
    void func_020c36ec(void);
    void InitDisplayAndClearVram(void);
    void InitializePowerManagement(void);
    void func_020cf020(void);
    void _Z20Initialize64BitTimerv(void);
    void _Z25InitializeActiveAlarmListv(void);
    void InitializeVCountAlarmList(void);
    void _Z23InitializeResourceMutexv(void);
    unsigned int _Z28SetSpecificInterruptsEnabledj(unsigned int which);
    void _Z19SetInterruptHandlerjPKv(unsigned int mask, const void* handler);
    void _Z24EnableSpecificInterruptsj(unsigned int mask);
    int SetVBlankIrqEnable(int enable);
    void AllocatorUnion_InitMainArenaHeap(AllocatorUnion* alloc);
    void _Z23InitializeROMFilesystemi(int arg0);
    void _Z23ChangeROMLoadDMAChannelj(int channel);
    void func_020758a8(void);
    void NNS_SndInit(void);
    void InputLock_Initialize(void);
    void Main_HandleVBlank(void);
}

extern int data_020f2270;
extern unsigned char data_02114e00;
extern AllocatorUnion g_mainAllocator;
extern int data_02114e50;

// Main, originally func_02012c34 (USA 0x02012c34, EUR 0x02012c44, JPN 0x020129fc)
extern "C" ARM void Main_InitializeSystems(void) {
    InitAllModules();
    func_020c36ec();
    data_020f2270 = 0;
    InitDisplayAndClearVram();
    InitializePowerManagement();
    func_020cf020();
    _Z20Initialize64BitTimerv();
    _Z25InitializeActiveAlarmListv();
    InitializeVCountAlarmList();
    _Z23InitializeResourceMutexv();
    _Z28SetSpecificInterruptsEnabledj(0);
    _Z19SetInterruptHandlerjPKv(IRQ_MASK_LCD_VBLANK, (const void*)Main_HandleVBlank);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_LCD_VBLANK);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_DMA_0 | IRQ_MASK_DMA_1 | IRQ_MASK_DMA_2 | IRQ_MASK_DMA_3 | IRQ_MASK_TIMER_0_OVERFLOW);
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208; // REG_IME, interrupt master enable
    *ime;
    *ime = 1;
    SetVBlankIrqEnable(1);
    AllocatorUnion_InitMainArenaHeap(&g_mainAllocator);
    _Z24EnableSpecificInterruptsj(IRQ_MASK_FIFO_RECEIVE_NOT_EMPTY);
    _Z23InitializeROMFilesystemi(2);
    _Z23ChangeROMLoadDMAChannelj(2);
    func_020758a8();
    NNS_SndInit();
    g_keyManager.Initialize();
    g_touchInput.Initialize();
    InputLock_Initialize();
    data_02114e00 = 0;
    data_02114e50 = 0;
}
