#include <globaldefs.h>


unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int StoreValueCountingDecreases_020c96a8(int value);
extern "C" void HaltSystem(void);
struct VCountAlarmNode020c92d0;
void InsertVCountAlarmNode(struct VCountAlarmNode020c92d0* node);

// USA: func_020c93d0
extern "C" ARM void func_020c93d0(void* node, int a1, int a2, int a3, int a4) {
    unsigned int mask = DisableIRQInterrupts();
    if (node == 0 || *(int*)node != 0) {
        HaltSystem();
    }
    int var1 = *(volatile unsigned short*)0x4000006;
    int var2 = func_020c96a8(var1);
    *(int*)((char*)arg0 + 0x1c) = 1;
    *(short*)((char*)arg0 + 0x10) = (short)arg1;
    if (arg1 <= var1) var2 = var2 + 1;
    *(int*)((char*)arg0 + 0xc) = var2;
    *(short*)((char*)arg0 + 0x12) = (short)arg2;
    *(int*)((char*)arg0 + 0x0) = arg3;
    *(int*)((char*)arg0 + 0x4) = arg4;
    *(int*)((char*)arg0 + 0x24) = 0;
    func_020c92d0((struct Struct_020c92d0*)arg0);
    SetIRQInterruptState(var0);
}
