#include <globaldefs.h>


unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" int func_020c96a8(int value);
extern "C" void HaltSystem(void);
struct Struct_020c92d0;
extern "C" void func_020c92d0(struct Struct_020c92d0* node);

// USA: func_020c93d0
extern "C" ARM void func_020c93d0(void* node, int a1, int a2, int a3, int a4) {
    unsigned int mask = DisableIRQInterrupts();
    if (node == 0 || *(int*)node != 0) {
        HaltSystem();
    }
    int var1 = *(volatile unsigned short*)0x4000006;
    int var2 = func_020c96a8(var1);
    *(int*)((char*)node + 0x1c) = 1;
    *(short*)((char*)node + 0x10) = (short)a1;
    if (a1 <= var1) var2 = var2 + 1;
    *(int*)((char*)node + 0xc) = var2;
    *(short*)((char*)node + 0x12) = (short)a2;
    *(int*)((char*)node + 0x0) = a3;
    *(int*)((char*)node + 0x4) = a4;
    *(int*)((char*)node + 0x24) = 0;
    func_020c92d0((struct Struct_020c92d0*)node);
    SetIRQInterruptState(mask);
}
