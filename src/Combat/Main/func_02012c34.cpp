#include <globaldefs.h>
#include "Input/Input.h"

struct AllocatorUnion;

extern "C" {
    void func_020c8368(void);
    void func_020c36ec(void);
    void func_020c36f0(void);
    void func_020ce270(void);
    void func_020cf020(void);
    void _Z20Initialize64BitTimerv(void);
    void _Z25InitializeActiveAlarmListv(void);
    void func_020c9288(void);
    void _Z23InitializeResourceMutexv(void);
    unsigned int _Z28SetSpecificInterruptsEnabledj(unsigned int arg0);
    void _Z19SetInterruptHandlerjPKv(unsigned int arg0, const void* arg1);
    void _Z24EnableSpecificInterruptsj(unsigned int arg0);
    int func_020c3864(int arg0);
    void func_02012d18(AllocatorUnion* arg0);
    void _Z23InitializeROMFilesystemi(int arg0);
    void _Z23ChangeROMLoadDMAChannelj(int arg0);
    void func_020758a8(void);
    void func_020bbd14(void);
    void func_020e1114(void);
    void func_02012bd8(void);
}

extern int data_020f2270;
extern unsigned char data_02114e00;
extern AllocatorUnion g_mainAllocator;
extern int data_02114e50;

// USA: func_02012c34
extern "C" ARM void func_02012c34(void) {
    func_020c8368();
    func_020c36ec();
    data_020f2270 = 0;
    func_020c36f0();
    func_020ce270();
    func_020cf020();
    _Z20Initialize64BitTimerv();
    _Z25InitializeActiveAlarmListv();
    func_020c9288();
    _Z23InitializeResourceMutexv();
    _Z28SetSpecificInterruptsEnabledj(0);
    _Z19SetInterruptHandlerjPKv(1, (const void*)func_02012bd8);
    _Z24EnableSpecificInterruptsj(1);
    _Z24EnableSpecificInterruptsj(0xf08);
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208;
    *ime;
    *ime = 1;
    _Z27SetVBlankIrqEnable_020c3864i(1);
    _Z25InitMainAllocator02012d18P14AllocatorUnion(&g_mainAllocator);
    _Z24EnableSpecificInterruptsj(0x40000);
    _Z23InitializeROMFilesystemi(2);
    _Z23ChangeROMLoadDMAChannelj(2);
    func_020758a8();
    func_020bbd14();
    g_keyManager.Initialize();
    g_touchInput.Initialize();
    func_020e1114();
    data_02114e00 = 0;
    data_02114e50 = 0;
}
