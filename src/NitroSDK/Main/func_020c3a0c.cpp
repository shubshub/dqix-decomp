#include <globaldefs.h>
void AwaitDMACompletion(int);

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

extern int data_020f226c;

// USA: func_020c3a0c
extern "C" ARM int func_020c3a0c(int channel) {
    int old = *(int*)((char*)&data_020f226c + 4);
    if (old != -1) {
        AwaitDMACompletion((int)(old));
    }
    unsigned int mask = DisableIRQInterrupts();
    *(int*)((char*)&data_020f226c + 4) = channel;
    SetIRQInterruptState(mask);
    return old;
}
